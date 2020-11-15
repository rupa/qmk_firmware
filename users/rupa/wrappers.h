/*
Copyright 2020 rupa <rupa@lrrr.us> @rupa

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#include "rupa.h"

#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define OS_RGUI OSM(MOD_RGUI)
#define OS_RALT OSM(MOD_RALT)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_RSFT OSM(MOD_RSFT)

#define TABLWR  LT(_LOWER, KC_TAB)

#if defined(UNICODEMAP_ENABLE)
#    define BANGS   XP(IXCL,IBNG)
#    define CSHAPES XP(CCIR,CKEY)
#    define DOWNERS XP(THUD,PTDN)
#    define ECKSHAS XP(ECKS,HAS)
#    define MUSIC_A XP(M4,M8)
#    define MUSIC_B XP(M8B,M16)
#    define NOPENAH XP(NOPE,STOP)
#    define QUESTS  XP(IQMK,IRNY)
#    define SMILE   XP(SMB,SMW)
#    define STARS   XP(STB,STW)
#    define SET_UI  XP(UNIO,INTR)
#    define UPPERS  XP(THUP,PTUP)
#    define YEPYEP  XP(HUN,CHEK)
#endif

/* _QWERTY
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │Es`│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│ ` │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │TabLW│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │Del│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
 * │RAISE │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │PgU│
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │Shift   │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ ↑ │PgD│
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │Ctrl│Alt │Gui │        Space           │RAI│LOW│CAP│ ← │ ↓ │ → │
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 */
#define ____65_QWERTY______________ROW1    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_GRV
#define ____65_QWERTY______________ROW2    TABLWR,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL
#define ____65_QWERTY______________ROW3    RAISE,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP
#define ____65_QWERTY______________ROW4    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN
#define ____65_QWERTY______________ROW5    KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                    RAISE,   LOWER,   KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT

/* _RAISE
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │ ` │¡ ‽│   │ॐ  │ ¢ │ € │   │   │★  │   │☹  │  ⃠ │CSH│       │   │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │ ⚠ │SHR│ ∃ │ ® │ ™ │YUN│∪ ∩│ ∈ │ ☻ │ ⊢ │♩ ♪│♫ ♬│🚫⛔ │Ins│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
 * │      │ ∀ │ ſ │ ⚂ │FRT│ 𝄞 │HUG│JOY│KSS│LOD│CAT│BUG│ 💯 ✓   │Hme│
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │        │WAT│✖ ☭│ © │TAD│BOW│ № │MUS│DN←│DN→│¿ ⸮│      │👍 │End│
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │    │    │    │          FLIP          │   │   │   │ ☜ │👎 │ ☞ │
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 */
#define ____65_RAISE_______________ROW1    KC_GRV,  BANGS,   _______, X(OM),   X(CENT), X(EURO), _______, _______, STARS,   _______, X(FRWN), X(NEG),  CSHAPES, _______, _______
#define ____65_RAISE_______________ROW2    _______, X(CUI),  SHRUG,   X(LEXI), X(RTMK), X(TDMK), YUNO,    SET_UI,  X(LELM), SMILE,   X(LPRO), MUSIC_A, MUSIC_B, NOPENAH, KC_INS
#define ____65_RAISE_______________ROW3    _______, X(LALL), X(EFF),  DICE,    FART,    X(CLEF), HUGS,    JOY,     KISS,    LOD,     CATS,    BUGS,             YEPYEP,  KC_HOME
#define ____65_RAISE_______________ROW4    _______,          WAT,     ECKSHAS, X(CPRT), TADA,    DOMO,    X(NUM),  MUSIC,   DANCEL,  DANCER,  QUESTS,  _______, UPPERS,  KC_END
#define ____65_RAISE_______________ROW5    _______, _______, _______,                            FLIP,                      _______, _______, _______, X(PTLT), DOWNERS, X(PTRT)

/* _LOWER
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │ ` │ 𝓾 │ 𝖚 │ 𝚞 │ 𝐮 │ 𝘂 │ 𝒖 │ 𝙪 │   │   │   │   │zzz│       │   │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │   │   │   │   │   │   │   │PRT│SLK│PAU│   │   │     │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
 * │      │   │SLK│   │   │   │   │   │   │   │   │   │        │   │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │RShift  │ZAL│   │CAP│   │   │NLK│Vx │V- │V+ │   │   McL│M↑ │McR│
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │RCtl│RAlt│RGui│                        │   │   │   │M← │M↓ │M→ │
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 */
#define ____65_LOWER_______________ROW1    KC_GRV,  U_SCRPT, U_FRACT, U_MONOS, U_NORML, U_SANSN, U_ITALI, U_SANSI, _______, _______, _______, _______, ZZZZZ,   _______, _______
#define ____65_LOWER_______________ROW2    _______, _______, _______, _______, RUPA,    _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, _______, _______
#define ____65_LOWER_______________ROW3    _______, _______, KC_SLCK, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______
#define ____65_LOWER_______________ROW4    OS_RSFT,          ZALGO  , _______, KC_CAPS, _______, _______, KC_NLCK, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_BTN1, KC_MS_U, KC_BTN2
#define ____65_LOWER_______________ROW5    OS_RCTL, OS_RALT, OS_RGUI,                            _______,                   _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R

/* _ADJUST
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│       │   │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │   │   │   │   │   │   │U_m│   │   │   │   │   │RESET│   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
 * │      │   │   │   │   │   │   │   │   │   │   │   │EEPRESET│   │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │        │   │   │   │VSN│   │   │   │   │   │   │      │   │   │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │    │    │    │                        │   │   │   │   │   │   │
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 */
#define ____65_ADJUST______________ROW1    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______
#define ____65_ADJUST______________ROW2    _______, _______, _______, _______, _______, _______, _______, UC_MOD,  _______, _______, _______, _______, _______, RESET,   _______
#define ____65_ADJUST______________ROW3    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          EEP_RST, _______
#define ____65_ADJUST______________ROW4    _______,          _______, _______, _______, VRSN,    _______, _______, _______, _______, _______, _______, _______, _______, _______
#define ____65_ADJUST______________ROW5    _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______

#define ____65_ADJUST__________RGB_ROW2    _______, RGB_TOG, RGB_MOD, RGB_SPD, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   _______
#define ____65_ADJUST__________RGB_ROW3    _______, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______,          EEP_RST, _______

#define ____65_ADJUST___________BL_ROW2    _______, BL_TOGG, BL_BRTG, BL_STEP, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   _______

#define ____65_ADJUST________W_RGB_ROW2    _______, _______, _______, S1_DEC,  S1_INC,  S2_DEC,  S2_INC,  _______, _______, _______, _______, _______, _______, RESET,   _______
#define ____65_ADJUST________W_RGB_ROW3    _______, EF_DEC,  EF_INC,  H1_DEC,  H1_INC,  H2_DEC,  H2_INC,  BR_DEC,  BR_INC,  ES_DEC,  ES_INC,  _______,          EEP_RST, _______

// clang-format on
