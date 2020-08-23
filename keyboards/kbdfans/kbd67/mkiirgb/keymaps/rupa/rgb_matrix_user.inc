// !!! DO NOT ADD #pragma once !!! //

RGB_MATRIX_EFFECT(perkey_party)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

const int leds[] = {0, 56, 64, 65, 66};

static void perkey_party_math(effect_params_t* params) {
    rgb_matrix_set_color(
        leds[rand() % 5],
        rand() % 0xff,
        rand() % 0xff,
        rand() % 0xff
    );
}

static bool perkey_party(effect_params_t* params) {
    if (!params->init) {
        // Change one LED every tick, make sure speed is not 0
        if (scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 16)) % 10 == 0) {
            perkey_party_math(params);
        }
        return false;
    }
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    srand(timer_read32());
    rgb_matrix_set_color_all(0x00, 0x00, 0x00);
    return led_max < DRIVER_LED_TOTAL;
}

#endif
