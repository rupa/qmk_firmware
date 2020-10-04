#include "rupa.h"

#define LAYOUT_65_ansi_blocker_base( \
            K01,     K02,     K03,     K04,     K05,     K06,     K07,     K08,     K09,     K0A,     K0B,     K0C,     K0D,     K0E,     K0F, \
            K11,     K12,     K13,     K14,     K15,     K16,     K17,     K18,     K19,     K1A,     K1B,     K1C,     K1D,     K1E,     K1F, \
            K21,     K22,     K23,     K24,     K25,     K26,     K27,     K28,     K29,     K2A,     K2B,     K2C,              K2D,     K2E, \
            K31,              K32,     K33,     K34,     K35,     K36,     K37,     K38,     K39,     K3A,     K3B,     K3C,     K3D,     K3E, \
            K41,     K42,     K43,                                K44,                       K45,     K46,     K47,     K48,     K49,     K4A  \
        ) \
        LAYOUT_65_ansi_blocker( \
            K01,     K02,     K03,     K04,     K05,     K06,     K07,     K08,     K09,     K0A,     K0B,     K0C,     K0D,     K0E,     K0F, \
            K11,     K12,     K13,     K14,     K15,     K16,     K17,     K18,     K19,     K1A,     K1B,     K1C,     K1D,     K1E,     K1F, \
            K21,     K22,     K23,     K24,     K25,     K26,     K27,     K28,     K29,     K2A,     K2B,     K2C,              K2D,     K2E, \
            K31,              K32,     K33,     K34,     K35,     K36,     K37,     K38,     K39,     K3A,     K3B,     K3C,     K3D,     K3E, \
            K41,     K42,     K43,                                K44,                       K45,     K46,              K48,     K49,     K4A  \
        )

#define LAYOUT_65_blocker_base_wrapper(...)  LAYOUT_65_ansi_blocker_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_65_blocker_base_wrapper(
        ____65_QWERTY______________ROW1,
        ____65_QWERTY______________ROW2,
        ____65_QWERTY______________ROW3,
        ____65_QWERTY______________ROW4,
        ____65_QWERTY______________ROW5
    ),
    [_RAISE] = LAYOUT_65_blocker_base_wrapper(
        ____65_RAISE_______________ROW1,
        ____65_RAISE_______________ROW2,
        ____65_RAISE_______________ROW3,
        ____65_RAISE_______________ROW4,
        ____65_RAISE_______________ROW5
    ),
    [_LOWER] = LAYOUT_65_blocker_base_wrapper(
        ____65_LOWER_______________ROW1,
        ____65_LOWER_______________ROW2,
        ____65_LOWER_______________ROW3,
        ____65_LOWER_______________ROW4,
        ____65_LOWER_______________ROW5
    ),
    [_ADJUST] = LAYOUT_65_blocker_base_wrapper(
        ____65_ADJUST______________ROW1,
        ____65_ADJUST__________RGB_ROW2,
        ____65_ADJUST__________RGB_ROW3,
        ____65_ADJUST______________ROW4,
        ____65_ADJUST______________ROW5
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef RGB_MATRIX_ENABLE

#define RGB_LED_U 56
#define RGB_LED_L 64
#define RGB_LED_D 65
#define RGB_LED_R 66
#define RGB_LED_LAST_COL 14, 29, 43, 57

void set_last_col(char r, char g, char b) {
     uint8_t keys[] = {RGB_LED_LAST_COL};
     for (int i=0; i<sizeof(keys)/sizeof(uint8_t); i++) {
         rgb_matrix_set_color(keys[i], r, g, b);
     }
}

void rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
        case _RAISE:
            set_last_col(RGB_MAGENTA);
            break;
        case _LOWER:
            set_last_col(RGB_CYAN);
            break;
        case _ADJUST:
            set_last_col(RGB_YELLOW);
            break;
        default:
            set_last_col(0x00, 0x00, 0x00);
    }

    led_t leds = host_keyboard_led_state();
    if (leds.caps_lock) {
        rgb_matrix_set_color(RGB_LED_L, RGB_MAGENTA);
    }
    if (leds.num_lock) {
        rgb_matrix_set_color(RGB_LED_D, RGB_MAGENTA);
    }
    if (leds.scroll_lock) {
        rgb_matrix_set_color(RGB_LED_R, RGB_MAGENTA);
    }
}

void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
}

#endif
