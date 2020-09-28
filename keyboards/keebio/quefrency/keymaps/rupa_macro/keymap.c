#include "rupa.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_65_macro_wrapper(
        ____65_QWERTY__QUEFRENCY_M_ROW1,
        ____65_QWERTY__QUEFRENCY_M_ROW2,
        ____65_QWERTY__QUEFRENCY_M_ROW3,
        ____65_QWERTY__QUEFRENCY_M_ROW4,
        ____65_QWERTY__QUEFRENCY_M_ROW5
    ),
    [_RAISE] = LAYOUT_65_macro_wrapper(
        ____65_RAISE___QUEFRENCY_M_ROW1,
        ____65_RAISE___QUEFRENCY_M_ROW2,
        ____65_RAISE___QUEFRENCY_M_ROW3,
        ____65_RAISE___QUEFRENCY_M_ROW4,
        ____65_RAISE___QUEFRENCY_M_ROW5
    ),
    [_LOWER] = LAYOUT_65_macro_wrapper(
        ____65_LOWER___QUEFRENCY_M_ROW1,
        ____65_LOWER___QUEFRENCY_M_ROW2,
        ____65_LOWER___QUEFRENCY_M_ROW3,
        ____65_LOWER___QUEFRENCY_M_ROW4,
        ____65_LOWER___QUEFRENCY_M_ROW5
    ),
    [_ADJUST] = LAYOUT_65_macro_wrapper(
        ____65_ADJUST__QUEFRENCY_M_ROW1,
        ____65_ADJUST__QUEFRENCY_M_ROW2,
        ____65_ADJUST__QUEFRENCY_M_ROW3,
        ____65_ADJUST__QUEFRENCY_M_ROW4,
        ____65_ADJUST__QUEFRENCY_M_ROW5
    ),
};


layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
}
