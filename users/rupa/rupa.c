#include <print.h>
#include "rupa.h"

// https://en.wikipedia.org/wiki/Mathematical_Alphanumeric_Symbols
font_t fraktu_bold = {0x1D56C, 0x1D586, 0x1D7D8}; // doublestruck numbers
font_t italic_bold = {0x1D468, 0x1D482, 0x1D7CE}; // bold numbers
font_t monosp_bold = {0x1D670, 0x1D68A, 0x1D7F6};
font_t sans_i_bold = {0x1D63C, 0x1D656, 0x1D7EC}; // sans bold numbers
font_t sans_n_bold = {0x1D5D4, 0x1D5EE, 0x1D7EC};
font_t script_bold = {0x1D4D0, 0x1D4EA, 0x1D7CE}; // bold numbers

/*
font_t doublestruc = {0x1D538, 0x1D552, 0x1D7D8};
uint_32 []snowflakes = {
  // doublestruck
  0x1D53B, // C
  0x1D540, // H
  0x1D546, // N
  0x1D548, // P
  0x1D549, // Q
  0x1D54A, // R
  0x1D552, // Z
};
*/

// Maps A-Z, a-z, and 0-9 to other unicode ranges. We also map space to EN
// SPACE for some reason :)
uint32_t map_alnum(font_t *f, bool is_shifted, uint32_t keycode) {
    switch (keycode) {
        case KC_SPACE:
            return (is_shifted ? 0 : 0x2002); // EN SPACE
        case KC_0:
            return (is_shifted ? 0 : f->zero_glyph);
        case KC_A ... KC_Z:
            return (is_shifted ? f->upper_alpha : f->lower_alpha) + keycode - KC_A;
        case KC_1 ... KC_9:
            return (is_shifted ? 0 : f->zero_glyph + keycode - KC_1 + 1);
        default:
            return 0;
    }
}

bool script_mode_translate(font_t *translator, bool is_shifted, uint32_t keycode) {
    uint32_t translated = map_alnum(translator, is_shifted, keycode);
    if (translated == 0) return true;
    dprintf("script_mode_translate: %u => %d\n", keycode, translated);
    register_unicode(translated);
    return false;
}
