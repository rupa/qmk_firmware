#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FN 3
#define _ADJUST 4
#define _NUMPAD 5

#define FUNCT MO(_FN)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define F_FN  LT(_FN, KC_F)
#define G_NP  LT(_NUMPAD, KC_G)

/*
" ......      ...... \n"
" ......      ...... \n"
" ......      ...... \n"
" ......      ...... \n"
" ...... .  . ...... \n"
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
    KC_GRV,  KC_A,    KC_S,    KC_D,    F_FN,    G_NP,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_UP,   KC_COMM, KC_DOT,  KC_SLSH,
    KC_LCTL, KC_LALT, KC_LGUI, LOWER,   RAISE,   KC_SPC,  FUNCT,   KC_MUTE, KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, LOWER,   RAISE
  ),

  [_LOWER] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, KC_MINS, KC_EQL,  KC_DEL,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   _______, _______, _______, _______, _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                    KC_F12,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, KC_UNDS, KC_PLUS, KC_DEL,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_FN] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______ ,KC_DEL,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    KC_CAPS, _______, _______, _______, _______, _______,                   _______, KC_MUTE, KC_PGUP, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END,  _______, _______
  ),

  [_ADJUST] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    _______, KC_F11,  KC_F12,  _______, _______, _______,                   _______, _______, _______, _______, KC_PSCR, _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   _______, _______, _______, _______, _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                    KC_F12,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_NUMPAD] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   KC_NLCK, KC_P7,   KC_P8,   KC_P9,   _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, KC_P4,   KC_P5,   KC_P6,   _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, KC_P1,   KC_P2,   KC_P3,   _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, KC_P0,   KC_PCMM, KC_PDOT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
#ifdef OLED_DRIVER_ENABLE
                oled_task_user();
#endif
                tap_code(clockwise ? KC_VOLU : KC_VOLD);
        }
    }
}

#ifdef OLED_DRIVER_ENABLE

// for a 20x8 char screen

static void render_keymap(void) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            if (get_mods()&MOD_MASK_SHIFT) {
                oled_write_P(PSTR("[Layer]     [QWERTY]\n"\
                                  " e!@#$%      ^&*()B \n"\
                                  " tQWERT      YUIOP\" \n"\
                                  " ~ASDFG      HJKL:r \n"\
                                  " sZXCVB      NMu<>? \n"\
                                  " caglr  F  M  ldrlr \n"), false);
            } else {
                oled_write_P(PSTR("[Layer]     [qwerty]\n"\
                                  " E12345      67890B \n"\
                                  " Tqwert      yuiop' \n"\
                                  " `asdfg      hjkl;R \n"\
                                  " Szxcvb      nmU,./ \n"\
                                  " CAGLR  F  M  LDRLR \n"), false);
            }
            break;
        case _LOWER:
            oled_write_P(PSTR("[Layer]      [Lower]\n"\
                              " ......      ...-=D \n"\
                              " ......      ...[]\\ \n"\
                              " .12345      6..... \n"\
                              " .78901      2..... \n"\
                              " ...... .  . ...... \n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("[Layer]      [Raise]\n"\
                              " ......      ..._+D \n"\
                              " ......      ...{}| \n"\
                              " ......      ...... \n"\
                              " ......      ...... \n"\
                              " ...... .  . ...... \n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("[Layer]   [Function]\n"\
                              " ......      .....D \n"\
                              " ......      ...... \n"\
                              " ......      ...... \n"\
                              " C.....      .MU... \n"\
                              " ...... .  . .HDE.. \n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("[Layer]     [Adjust]\n"\
                              " .12345      67890. \n"\
                              " .12...      ....P. \n"\
                              " .12345      6..... \n"\
                              " .78901      2..... \n"\
                              " ...... .  . ...... \n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("[Layer]     [numpad]\n"\
                              " ......      N789.. \n"\
                              " ......      .456.. \n"\
                              " ......      .123.. \n"\
                              " ......      .0cd.. \n"\
                              " ...... .  . ...... \n"), false);
            break;
        default:
            oled_write_P(PSTR("[Layer]  [SBG 18 66]\n"\
                              "sarva-dharman parity\n"\
                              "ajya mam ekam sharan\n"\
                              "am vraja, aham tvam \n"\
                              "sarva-papebhyo moksh\n"\
                              "ayishyami ma shuchah\n"\
                              "                    \n"), false);
    }
}

static void render_locks(void) {
    led_t led_state = host_keyboard_led_state();
    oled_write_P(PSTR(" ["), false);
    oled_write_P((led_state.caps_lock ? PSTR("CAPS") : PSTR("    ")), led_state.caps_lock);
    oled_write_P(PSTR("] ["), false);
    oled_write_P((led_state.num_lock ? PSTR("NUM") : PSTR("   ")), led_state.num_lock);
    oled_write_P(PSTR("] ["), false);
    oled_write_P((led_state.scroll_lock ? PSTR("SCR") : PSTR("   ")), led_state.scroll_lock);
    oled_write_P(PSTR("] "), false);
}

/*
void rbg(const char *data, bool invert) {
    int a, b = 0;
    uint8_t c = pgm_read_byte(data);
    while (c != 0) {
        oled_write_char(c, invert);
        c = pgm_read_byte(++data);
        if (a++ >= 20) {
            a = 0;
            oled_write_char('\n', invert);
            if (b++ >= 8) {
                return;
            }
        };
    }
}
*/

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

void oled_task_user(void) {
    render_keymap();
    render_locks();
}
#endif
