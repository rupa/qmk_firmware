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
void led_keys(char r, char g, char b) {
     //uint8_t keys[] = {0, 14, 29, 35, 36, 43, 57, 61};
     uint8_t keys[] = {14, 29, 43, 57};
     for (int i=0; i<sizeof(keys)/sizeof(uint8_t); i++) {
         rgb_matrix_set_color(keys[i], r, g, b);
     }
}

void rgb_matrix_indicators_user(void) {
    led_t leds = host_keyboard_led_state();

    switch (get_highest_layer(layer_state)) {
        case _RAISE:
            led_keys(RGB_MAGENTA);
            break;
        case _LOWER:
            led_keys(RGB_CYAN);
            break;
        case _ADJUST:
            led_keys(RGB_YELLOW);
            break;
        default:
            led_keys(0x00, 0x00, 0x00);
    }

    if (leds.caps_lock) {
        led_lt(RGB_MAGENTA);
    }
    if (leds.num_lock) {
        led_dn(RGB_MAGENTA);
    }
    if (leds.scroll_lock) {
        led_rt(RGB_MAGENTA);
    }
}

void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
}

#endif
