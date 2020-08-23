/*
 * amended from ../d4mation/
 */
#include "zalgo.h"

bool zalgo_enabled = false;

bool get_zalgo_mode(void) {
    return zalgo_enabled;
}

bool toggle_zalgo_mode(void) {
    zalgo_enabled = !zalgo_enabled;
    dprintf("toggle_zalgo_mode: %b\n", zalgo_enabled);
    return true;
}

bool zalgo_text(uint16_t keycode) {
    if (keycode < KC_A || (keycode > KC_0 && keycode < KC_MINUS) || keycode > KC_SLASH) {
        return false;
    }

    int number = (rand() % (8 + 1 - 2)) + 2;
    unsigned int index;

    tap_code(keycode);
    unicode_input_start();
    for (index=0; index<number; index++) {
        uint16_t hex = (rand() % (0x036F + 1 - 0x0300)) + 0x0300;
        register_hex(hex);
    }
    unicode_input_finish();
    return true;
}
