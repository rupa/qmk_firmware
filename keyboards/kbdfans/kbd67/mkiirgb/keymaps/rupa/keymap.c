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

#ifdef RGB_MATRIX_ENABLE

void led_up(char r, char g, char b) {
     rgb_matrix_set_color(56, r, g, b);
}
void led_lt(char r, char g, char b) {
     rgb_matrix_set_color(64, r, g, b);
}
void led_dn(char r, char g, char b) {
     rgb_matrix_set_color(65, r, g, b);
}
void led_rt(char r, char g, char b) {
     rgb_matrix_set_color(66, r, g, b);
}
void led_gh(char r, char g, char b) {
     rgb_matrix_set_color(35, r, g, b);
     rgb_matrix_set_color(36, r, g, b);
}

void rgb_matrix_indicators_user(void) {
    uint8_t layer = get_highest_layer(layer_state);
    led_t leds = host_keyboard_led_state();

    switch (layer) {
        case _RAISE:
            led_gh(0x00, 0x00, 0xFF);
            break;
        case _LOWER:
            led_gh(0xFF, 0xFF, 0x00);
            break;
        case _ADJUST:
            led_gh(0x00, 0xFF, 0x00);
            break;
        default:
            led_gh(0x00, 0x00, 0x00);
    }

    if (leds.caps_lock) {
        led_lt(0xFF, 0x00, 0x00);
    }
    if (leds.num_lock) {
        led_dn(0x00, 0xFF, 0x00);
    }
    if (leds.scroll_lock) {
        led_rt(0x00, 0x00, 0xFF);
    }
}

void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
}

#endif
