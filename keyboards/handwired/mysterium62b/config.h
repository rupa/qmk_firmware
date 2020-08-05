#pragma once

#include "config_common.h"

#define VENDOR_ID       0x6B62
#define PRODUCT_ID      0x8769
#define DEVICE_VER      0x0001
#define MANUFACTURER    covah901
#define PRODUCT         MYSTERIUM62b
#define DESCRIPTION     Ergo keyboard that can be assembled with only through hole components

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 13

#define MATRIX_ROW_PINS { D0, D1, D5, D6, D7, }
#define MATRIX_COL_PINS { B0, B1, B2, B3, B4, A6, C4, A5, A4, A3, A2, A1, A0, }
#define UNUSED_PINS

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

#define ENCODERS_PAD_A { C3 }
#define ENCODERS_PAD_B { C2 }
#define ENCODER_RESOLUTION 4

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

#define TAP_CODE_DELAY 10
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/* Bootmagic Lite key configuration */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

#define OLED_DISPLAY_128X64
