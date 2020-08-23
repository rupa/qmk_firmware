// !!! DO NOT ADD #pragma once !!! //

//RGB_MATRIX_EFFECT(all_leds_off)
RGB_MATRIX_EFFECT(arrows_yay)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

//static bool all_leds_off(effect_params_t* params) {
//    RGB_MATRIX_USE_LIMITS(led_min, led_max);
//
//    rgb_matrix_sethsv(0x00, 0x00, 0x00);
//
//    return led_max < DRIVER_LED_TOTAL;
//}

static uint8_t rgb_global_state;
static void arrows_yay_init(effect_params_t* params) {
    rgb_global_state = 0;
}

static bool arrows_yay_run(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    switch(rgb_global_state++) {
        case 0:
            rgb_matrix_set_color(56, RGB_CYAN);
            rgb_matrix_set_color(64, RGB_GOLD);
            rgb_matrix_set_color(65, RGB_BLUE);
            rgb_matrix_set_color(66, RGB_YELLOW);
            break;
        case 1:
            rgb_matrix_set_color(66, 0xff, 0x00, 0x00);
            rgb_matrix_set_color(56, 0x00, 0xff, 0x00);
            rgb_matrix_set_color(64, 0x00, 0x00, 0xff);
            rgb_matrix_set_color(65, 0xff, 0xff, 0x00);
            break;
        case 2:
            rgb_matrix_set_color(65, 0xff, 0x00, 0x00);
            rgb_matrix_set_color(66, 0x00, 0xff, 0x00);
            rgb_matrix_set_color(56, 0x00, 0x00, 0xff);
            rgb_matrix_set_color(64, 0xff, 0xff, 0x00);
            break;
        case 3:
            rgb_matrix_set_color(64, 0xff, 0x00, 0x00);
            rgb_matrix_set_color(65, 0x00, 0xff, 0x00);
            rgb_matrix_set_color(66, 0x00, 0x00, 0xff);
            rgb_matrix_set_color(56, 0xff, 0xff, 0x00);
            break;
        default:
            rgb_global_state = 0;
    }

    return led_max < DRIVER_LED_TOTAL;
}

static bool arrows_yay(effect_params_t* params) {
    if (params->init) arrows_yay_init(params);
    return arrows_yay_run(params);
}

#endif
