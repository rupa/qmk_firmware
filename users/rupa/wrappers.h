#pragma once
#include "rupa.h"

#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

#define A_LWR   LT(_LOWER, KC_A)

#if defined(UNICODEMAP_ENABLE)
#    define CSHAPES XP(CCIR,CKEY)
#    define CUIDADO XP(CUI,HAS)
#    define NOPENAH XP(NOPE,STOP)
#    define MUSIC_A XP(M4,M8)
#    define MUSIC_B XP(M8B,M16)
#    define SMILE   XP(SMB,SMW)
#    define STARS   XP(STB,STW)
#    define YEPYEP  XP(CHEK,HUN)
#endif

/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/

// clang-format off
#define LAYOUT_65_wrapper(...)            LAYOUT_65_ansi(__VA_ARGS__)
#define LAYOUT_65_blocker_wrapper(...)    LAYOUT_65_ansi_blocker(__VA_ARGS__)
#define KEYMAP_wrapper(...)               LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)               LAYOUT(__VA_ARGS__)

/* _QWERTY
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│~ `│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │Del│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
 * │RAISE │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │PgU│
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ ↑ │PgD│
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
 * │Ctrl│Alt │Gui │        Space           │RAIS│LWER│ │ ← │ ↓ │ → │
 * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
 */
#define ____65_QWERTY______________ROW1    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_GRV
#define ____65_QWERTY______________ROW2    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL
#define ____65_QWERTY______________ROW3    RAISE,   A_LWR,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP
#define ____65_QWERTY______________ROW4    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN
#define ____65_QWERTY______________ROW5    KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                    RAISE,   KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
#define ____65_QWERTY______BLOCKER_ROW5    KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                    RAISE,   LOWER,            KC_LEFT, KC_DOWN, KC_RGHT

/* _RAISE
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │   │ ‽ │   │   │   │   │   │   │   │   │   │  ⃠ │   │  Del  │Hme│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │   │   │   │Rup│   │   │   │   │ ॐ │☻ ☺│♩ ♪│♫ ♬│★  ☆ │Ins│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
 * │      │   │   │ ⚂ │   │   │HUG│   │   │LOD│   │NO!│ ✓  💯  │End│
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │ RShift │⚠ ☭│ ✖ │CAT│   │ᙙᙖ │ № │   │   │   │ ⸮ │   McL│M↑ │McR│
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
 * │RCtl│RAlt│RGui│                        │    │    │ │M← │M↓ │M→ │
 * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
 */
#define ____65_RAISE_______________ROW1    _______, X(IBNG), _______, _______, _______, _______, _______, _______, _______, _______, _______, NEG,     CSHAPES, KC_DEL,  KC_HOME
#define ____65_RAISE_______________ROW2    _______, _______, _______, _______, RUPA,    _______, _______, _______, _______, X(OM),   SMILE,   MUSIC_A, MUSIC_B, STARS,   KC_INS
#define ____65_RAISE_______________ROW3    _______, _______, _______, DICE,    _______, _______, HUGS,    _______, _______, LOD,     _______, NOPENAH,          YEPYEP,  KC_END
#define ____65_RAISE_______________ROW4    OS_RSFT,          CUIDADO, ECKS,    CATS   , _______, BUGS,    X(NUM),  _______, _______, _______, X(IRNY), KC_BTN1, KC_MS_U, KC_BTN2
#define ____65_RAISE_______________ROW5    OS_RCTL, OS_RALT, OS_RGUI,                            _______,                   _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
#define ____65_RAISE_______BLOCKER_ROW5    OS_RCTL, OS_RALT, OS_RGUI,                            _______,                   _______, _______,          KC_MS_L, KC_MS_D, KC_MS_R

/* _LOWER
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │   │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │   │U_s│U_f│U_m│U_n│   │uni│   │   │prs│   │   │     │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
 * │      │   │SCL│PAU│   │   │   │   │   │   │   │   │        │   │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │        │   │   │CAP│VSN│   │NUM│   │   │   │   │      │   │   │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
 * │    │    │    │                        │    │    │ │   │   │   │
 * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
 */
#define ____65_LOWER_______________ROW1    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
#define ____65_LOWER_______________ROW2    _______, _______, U_SCRPT, U_FRACT, U_MONOS, U_NORML, _______, UC_MOD,  _______, _______, KC_PSCR, _______, _______, _______, _______
#define ____65_LOWER_______________ROW3    _______, _______, KC_SLCK, KC_PAUS, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______
#define ____65_LOWER_______________ROW4    _______,          _______, _______, KC_CAPS, VRSN,    _______, KC_NLCK, _______, _______, _______, _______, _______, _______, _______
#define ____65_LOWER_______________ROW5    _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
#define ____65_LOWER_______BLOCKER_ROW5    _______, _______, _______,                            _______,                   _______, _______,          _______, _______, _______

/* _ADJUST
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │RST│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│       │   │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │RGB│RGB│RGB│RGB│RGB│RGB│RGB│RGB│   │   │   │   │RESET│   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
 * │      │   │   │   │   │   │   │   │   │   │   │   │EEP RSET│   │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │        │   │   │   │   │   │   │Mut│V- │V+ │   │      │   │   │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
 * │    │    │    │                        │    │    │ │   │   │   │
 * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
 */
#define ____65_ADJUST______________ROW1    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______
#define ____65_ADJUST______________ROW2    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   _______
#define ____65_ADJUST______________ROW3    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          EEP_RST, _______
#define ____65_ADJUST______________ROW4    _______,          _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______
#define ____65_ADJUST______________ROW5    _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
#define ____65_ADJUST______BLOCKER_ROW5    _______, _______, _______,                            _______,                   _______, _______,          _______, _______, _______

#define ____65_ADJUST______RGB_____ROW2    _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, RESET,   _______
#define ____65_ADJUST______RGB_____ROW3    _______, RGB_M_P, RGB_M_B, _______, _______, _______, _______, _______, _______, _______, _______, _______,          EEP_RST, _______

#define ____65_ADJUST______BL______ROW2    _______, BL_TOGG, BL_BRTG, BL_STEP, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   _______

/*
#define LAYOUT_blocker_base( \
    K01,     K02,     K03,     K04,     K05,     K06,     K07,     K08,     K09,     K0A,     K0B,     K0C,     K0D,     K0E,     K0F, \
    K11,     K12,     K13,     K14,     K15,     K16,     K17,     K18,     K19,     K1A,     K1B,     K1C,     K1D,     K1E,     K1E, \
    K21,     K22,     K23,     K24,     K25,     K26,     K27,     K28,     K29,     K2A,     K2B,     K2C,              K2D,     K2E, \
    K31,              K32,     K33,     K34,     K35,     K36,     K37,     K38,     K39,     K3A,     K3B,     K3C,     K3D,     K3E, \
    K41,     K42,     K43,                                K44,                       K45,     K46,              K47,     K48,     K49 \
  ) \
  LAYOUT_blocker_wrapper( \
    K01,     K02,     K03,     K04,     K05,     K06,     K07,     K08,     K09,     K0A,     K0B,     K0C,     K0D,     K0E,     K0F, \
    K11,     K12,     K13,     K14,     K15,     K16,     K17,     K18,     K19,     K1A,     K1B,     K1C,     K1D,     K1E,     K1E, \
    K21,     K22,     K23,     K24,     K25,     K26,     K27,     K28,     K29,     K2A,     K2B,     K2C,              K2D,     K2E, \
    K31,              K32,     K33,     K34,     K35,     K36,     K37,     K38,     K39,     K3A,     K3B,     K3C,     K3D,     K3E, \
    K41,     K42,     K43,                                K44,                       K45,     K46,     KC_CTL,  K47,     K48,     K49 \
  )
#define LAYOUT_blocker_base_wrapper(...)  LAYOUT_blocker_base(__VA_ARGS__)
*/

// clang-format on
