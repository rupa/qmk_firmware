#include "rupa.h"

#define LAYOUT_quefrency_macro_base( \
            K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F, \
            K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F, \
            K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, \
            K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, \
            K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A \
        ) \
        LAYOUT_65_with_macro( \
            KC_GESC, KC_GESC, K01,     K02,     K03,     K04,     K05,     K06,     K07,     K08,     K09,     K0A,     K0B,     K0C,     K0D,     XXXXXXX, K0E,     K0F, \
            KC_F1,   KC_F2,   K11,     K12,     K13,     K14,     K15,     K16,     K17,     K18,     K19,     K1A,     K1B,     K1C,     K1D,              K1E,     K1F, \
            KC_MUTE, KC_F3,   K21,     K22,     K23,     K24,     K25,     K26,     K27,     K28,     K29,     K2A,     K2B,     K2C,                       K2D,     K2E, \
            KC_VOLD, KC_VOLU, K31,              K32,     K33,     K34,     K35,     K36,     K37,     K38,     K39,     K3A,     K3B,     K3C,              K3D,     K3E, \
            LOWER,   KC_RGUI, K41,     K42,     K43,     KC_SPC,  KC_BSPC,                   K44,     XXXXXXX,          K45,     K46,     K47,     K48,     K49,     K4A  \
        )

#define LAYOUT_quefrency_macro_base_wrapper(...)  LAYOUT_quefrency_macro_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_quefrency_macro_base_wrapper(
        ____65_QWERTY______________ROW1,
        ____65_QWERTY______________ROW2,
        ____65_QWERTY______________ROW3,
        ____65_QWERTY______________ROW4,
        ____65_QWERTY______________ROW5
    ),
    [_RAISE] = LAYOUT_quefrency_macro_base_wrapper(
        ____65_RAISE_______________ROW1,
        ____65_RAISE_______________ROW2,
        ____65_RAISE_______________ROW3,
        ____65_RAISE_______________ROW4,
        ____65_RAISE_______________ROW5
    ),
    [_LOWER] = LAYOUT_quefrency_macro_base_wrapper(
        ____65_LOWER_______________ROW1,
        ____65_LOWER_______________ROW2,
        ____65_LOWER_______________ROW3,
        ____65_LOWER_______________ROW4,
        ____65_LOWER_______________ROW5
    ),
    [_ADJUST] = LAYOUT_quefrency_macro_base_wrapper(
        ____65_ADJUST______________ROW1,
        ____65_ADJUST______________ROW2,
        ____65_ADJUST______________ROW3,
        ____65_ADJUST______________ROW4,
        ____65_ADJUST______________ROW5
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
}
