#include "rupa.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_65_blocker_wrapper(
        ____65_QWERTY______________ROW1,
        ____65_QWERTY______________ROW2,
        ____65_QWERTY______________ROW3,
        ____65_QWERTY______________ROW4,
        ____65_QWERTY______BLOCKER_ROW5
    ),
    [_RAISE] = LAYOUT_65_blocker_wrapper(
        ____65_RAISE_______________ROW1,
        ____65_RAISE_______________ROW2,
        ____65_RAISE_______________ROW3,
        ____65_RAISE_______________ROW4,
        ____65_RAISE_______BLOCKER_ROW5
    ),
    [_LOWER] = LAYOUT_65_blocker_wrapper(
        ____65_LOWER_______________ROW1,
        ____65_LOWER_______________ROW2,
        ____65_LOWER_______________ROW3,
        ____65_LOWER_______________ROW4,
        ____65_LOWER_______BLOCKER_ROW5
    ),
    [_ADJUST] = LAYOUT_65_blocker_wrapper(
        ____65_ADJUST______________ROW1,
        ____65_ADJUST__________RGB_ROW2,
        ____65_ADJUST__________RGB_ROW3,
        ____65_ADJUST______________ROW4,
        ____65_ADJUST______BLOCKER_ROW5
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void rgb_matrix_indicators_user(void) {
    // u,l,d,r: 65,64,65,66
    //uint8_t layer = get_highest_layer(layer_state);
    //uint8_t mods = get_mods();
    led_t leds = host_keyboard_led_state();

    if (leds.caps_lock) {
        rgb_matrix_set_color(64, 0xFF, 0x00, 0x00);
    }
    if (leds.num_lock) {
        rgb_matrix_set_color(65, 0x00, 0xFF, 0x00);
    }
    if (leds.scroll_lock) {
        rgb_matrix_set_color(66, 0x00, 0x00, 0xFF);
    }
}

void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
}
