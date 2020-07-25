#include "rupa.h"

#if defined(UNICODE_SCRIPT_MODE_ENABLE)
font_t *translator = NULL;
#endif

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool is_shifted = get_mods()&MOD_MASK_SHIFT;
    if (record->event.pressed) {
        switch(keycode) {
            case VRSN:
                send_string_with_delay_P(PSTR(
                    "# " QMK_KEYBOARD "/" QMK_KEYMAP ":" QMK_VERSION " " QMK_BUILDDATE "\n"
                ), TAP_CODE_DELAY);
                return false;

            case LOD:
                send_unicode_string((is_shifted ? "¯\\_(ツ)_/¯" : "ಠ_ಠ"));
                return false;
            case RUPA:
                send_unicode_string((is_shifted ? "Śrīrūpa" : "rūpa"));
                return false;

#if defined(UNICODE_SCRIPT_MODE_ENABLE)
            // script modes
            case U_FRACT:
                translator = (translator == &fraktu_bold ? NULL : &fraktu_bold);
                return true;
            case U_ITALI:
                translator = (translator == &italic_bold ? NULL : &italic_bold);
                return true;
            case U_MONOS:
                translator = (translator == &monosp_bold ? NULL : &monosp_bold);
                return true;
            case U_NORML:
                translator = (translator == &math_normal ? NULL : &math_normal);
                return true;
            case U_SANSI:
                translator = (translator == &sans_i_bold ? NULL : &sans_i_bold);
                return true;
            case U_SANSN:
                translator = (translator == &sans_n_bold ? NULL : &sans_n_bold);
                return true;
            case U_SCRPT:
                translator = (translator == &script_bold ? NULL : &script_bold);
                return true;

            default:
                if (translator != NULL) {
                    return script_mode_translate(translator, is_shifted, keycode);
                }
#endif
            }
    }
    return true;
}
