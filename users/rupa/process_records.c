#include "rupa.h"

uint16_t processed_keycode;

__attribute__((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {

        processed_keycode = keycode;
        // mask out mod taps
        if (
            (keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
            (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)
        ) {
            processed_keycode &= 0xFF;
        }

        bool is_shifted = get_mods() & MOD_MASK_SHIFT;
        switch(processed_keycode) {
            case VRSN:
                send_string_with_delay_P(PSTR(
                    "# " QMK_KEYBOARD "/" QMK_KEYMAP ":" QMK_VERSION " " QMK_BUILDDATE "\n"
                ), TAP_CODE_DELAY);
                return false;

            case BUGS:
                return u_xp(is_shifted, "ᙙᙖ", "ଳ");
            case CATS:
                return u_xp(is_shifted, "ⓛ ᆽ ⓛ ", "ㅇㅅㅇ");
            case DANCE:
                return u_x(dance(is_shifted));
            case DICE:
                return u_x(d6());
            case DOMO:
                return u_xp(is_shifted, "(シ_ _)シ", "m(_ _)m");
            case FART:
                return u_x("⊥ʶ∀Ⅎ");
            case FLIP:
                return u_x(flip(is_shifted));
            case HUGS:
                return u_xp(is_shifted, "(づ￣ ³￣)づ", "(っಠ‿ಠ)っ");
            case JOY:
                return u_x(joy(is_shifted));
            case RNDM:
                return false;
            case KISS:
                return u_xp(is_shifted, "꒒ ০ ⌵ ୧ ♡", "( ˘ ³˘)♥");
            case LOD:
                return u_xp(is_shifted, "( ͡ಠ ʖ̯ ͡ಠ)", "ಠ_ಠ");
            case MUSIC:
                return u_xp(is_shifted, "(˳˘ ɜ˘)˳ ♬ ♪♫", "(´▽｀)ノ♫");
            case RUPA:
                return u_xp(is_shifted, "Śrīrūpa", "rūpa");
            case SHRUG:
                return u_xp(is_shifted, "⋌ ༼ •̀ ⌂ •́ ༽⋋", "¯\\_(ツ)_/¯");
            case TADA:
                return u_xp(is_shifted, "☆ *･゜ﾟ･*(^O^)/*･゜ﾟ･*☆", "＼＼(゜ロ＼＼)Ξ(／／ロ゜)／／");
            case WAT:
                return u_xp(is_shifted, "༼  ຶཽཀ  ຶཽ༽", "ヽ༼⊙_⊙༽ﾉ");
            case YUNO:
                return u_xp(is_shifted, "o(^^o)", "щ(゜ロ゜щ)");
            case ZALGO:
                set_combined_mode(CM_ZALGO);
                break;
            case ZZZZZ:
                cycle_combined_mode();
                return false;

#if defined(UNICODE_SCRIPT_MODE_ENABLE)
            // script modes
            case U_FRACT:
                return set_script_mode(F_FRACT);
            case U_ITALI:
                return set_script_mode(F_ITALI);
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
                    return script_mode_translate(is_shifted, processed_keycode);
                }
                if (combined_mode != CM_NULL && combined_text(processed_keycode)) {
                    return false;
                }
#endif
            }
    }
    return process_record_keymap(keycode, record);
}
