#include "rupa.h"

__attribute__((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        bool is_shifted = get_mods()&MOD_MASK_SHIFT;
        switch(keycode) {
            case VRSN:
                send_string_with_delay_P(PSTR(
                    "# " QMK_KEYBOARD "/" QMK_KEYMAP ":" QMK_VERSION " " QMK_BUILDDATE "\n"
                ), TAP_CODE_DELAY);
                return false;
            case BUGS:
                send_unicode_string("ᙙᙖ");
                return false;
            case CATS:
                send_unicode_string("=＾● ⋏ ●＾=");
                return false;
            case HUGS:
                send_unicode_string((is_shifted ? "(シ_ _)シ" : "(っಠ‿ಠ)っ"));
                return false;
            case LOD:
                send_unicode_string((is_shifted ? "¯\\_(ツ)_/¯" : "ಠ_ಠ"));
                return false;
            case RUPA:
                send_unicode_string((is_shifted ? "Śrīrūpa" : "rūpa"));
                return false;
            case DICE:
                send_unicode_string(d6());
                return false;

#if defined(UNICODE_SCRIPT_MODE_ENABLE)
            // script modes
            case U_FRACT:
                return set_script_mode(F_FRACT);
            case U_ITALI:
                return set_script_mode(F_FRACT);
            case U_MONOS:
                return set_script_mode(F_MONOS);
            case U_NORML:
                return set_script_mode(F_NORML);
            case U_SANSI:
                return set_script_mode(F_SANSI);
            case U_SANSN:
                return set_script_mode(F_SANSN);
            case U_SCRPT:
                return set_script_mode(F_SCRPT);

            default:
                if (get_script_mode() != NULL) {
                    return script_mode_translate(is_shifted, keycode);
                }
#endif
            }
    }
    return process_record_keymap(keycode, record);
}
