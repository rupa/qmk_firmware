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
#define ____65_QWERTY______________ROW5    KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                    RAISE,   LOWER,   KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT
#define ____65_QWERTY______BLOCKER_ROW5    KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                    RAISE,   LOWER,            KC_LEFT, KC_DOWN, KC_RGHT

/* _RAISE
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │   │ ‽ │   │   │ ¢ │   │   │   │★  │   │ ☻ │  ⃠ │CSH│  Del  │Hme│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │   │WAT│ ∃ │Rup│TAD│YUN│   │ ∈ │ ॐ │   │♩ ♪│♫ ♬│     │Ins│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
 * │      │ ∀ │SHR│ ⚂ │FRT│   │HUG│JOY│KSS│LOD│   │NO!│ ✓  💯  │End│
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │ RShift │⚠ ☭│ ✖ │CAT│BOW│BUG│ № │MUS│DNC│ ⊢ │ ⸮ │   McL│M↑ │McR│
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
 * │RCtl│RAlt│RGui│          FLIP          │    │    │ │M← │M↓ │M→ │
 * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
 */
#define ____65_RAISE_______________ROW1    _______, X(IBNG), _______, _______, X(CENT), _______, _______, _______, STARS,   _______, SMILE,   X(NEG),  CSHAPES, KC_DEL,  KC_HOME
#define ____65_RAISE_______________ROW2    _______, _______, WAT,     X(LEXI), RUPA,    TADA,    YUNO,    _______, X(LELM), X(OM),   _______, MUSIC_A, MUSIC_B, _______, KC_INS
#define ____65_RAISE_______________ROW3    _______, X(LALL), SHRUG,   DICE,    FART,    _______, HUGS,    JOY,     KISS,    LOD,     _______, NOPENAH,          YEPYEP,  KC_END
#define ____65_RAISE_______________ROW4    OS_RSFT,          CUIDADO, X(ECKS), CATS,    DOMO,    BUGS,    X(NUM),  MUSIC,   DANCE,   X(LPRO), X(IRNY), KC_BTN1, KC_MS_U, KC_BTN2
#define ____65_RAISE_______________ROW5    OS_RCTL, OS_RALT, OS_RGUI,                            FLIP,                      _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
#define ____65_RAISE_______BLOCKER_ROW5    OS_RCTL, OS_RALT, OS_RGUI,                            FLIP,                      _______, _______,          KC_MS_L, KC_MS_D, KC_MS_R

/* _LOWER
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │   │   │   │   │   │   │   │   │   │   │   │   │zzz│       │   │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │u_f│u_i│u_m│u_n│usi│usn│u_s│   │   │PRT│   │   │     │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
 * │      │   │SLK│PAU│   │   │   │   │   │   │   │   │        │   │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │        │ZAL│   │CAP│VSN│   │NLK│   │   │   │   │      │   │   │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
 * │    │    │    │                        │    │    │ │   │   │   │
 * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
 */
#define ____65_LOWER_______________ROW1    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ZZZZZ,   _______, _______
#define ____65_LOWER_______________ROW2    _______, U_FRACT, U_ITALI, U_MONOS, U_NORML, U_SANSI, U_SANSN, U_SCRPT, _______, _______, KC_PSCR, _______, _______, _______, _______
#define ____65_LOWER_______________ROW3    _______, _______, KC_SLCK, KC_PAUS, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______
#define ____65_LOWER_______________ROW4    _______,          ZALGO  , _______, KC_CAPS, VRSN,    _______, KC_NLCK, _______, _______, _______, _______, _______, _______, _______
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
 * │        │   │   │   │   │   │   │Mut│V- │V+ │   │U MODE│   │   │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
 * │    │    │    │                        │    │    │ │   │   │   │
 * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
 */
#define ____65_ADJUST______________ROW1    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______
#define ____65_ADJUST______________ROW2    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   _______
#define ____65_ADJUST______________ROW3    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          EEP_RST, _______
#define ____65_ADJUST______________ROW4    _______,          _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, UC_MOD,  _______, _______
#define ____65_ADJUST______________ROW5    _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
#define ____65_ADJUST______BLOCKER_ROW5    _______, _______, _______,                            _______,                   _______, _______,          _______, _______, _______

#define ____65_ADJUST__________RGB_ROW2    _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, RESET,   _______
#define ____65_ADJUST__________RGB_ROW3    _______, RGB_M_P, RGB_M_B, _______, _______, _______, _______, _______, _______, _______, _______, _______,          EEP_RST, _______

#define ____65_ADJUST___________BL_ROW2    _______, BL_TOGG, BL_BRTG, BL_STEP, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   _______

// clang-format on
