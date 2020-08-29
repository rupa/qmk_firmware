#pragma once
#include QMK_KEYBOARD_H
#include "version.h"
#include "process_records.h"
#include "unicode.h"
#include "wrappers.h"

enum userspace_layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum userspace_custom_keycodes {
    VRSN = SAFE_RANGE,
    BUGS,
    CATS,
    DANCE,
    DICE,
    DOMO,
    FART,
    FLIP,
    HUGS,
    JOY,
    KISS,
    LOD,
    MUSIC,
    RNDM,
    RUPA,
    SHRUG,
    TADA,
    U_FRACT,
    U_ITALI,
    U_MONOS,
    U_NORML,
    U_SANSI,
    U_SANSN,
    U_SCRPT,
    WAT,
    YUNO,
    ZALGO,
    ZZZZZ,
    NEXT_SAFE_RANGE
};

enum userspace_font_choices {
    F_FRACT = 0,
    F_ITALI,
    F_MONOS,
    F_NORML,
    F_SANSI,
    F_SANSN,
    F_SCRPT
};

typedef struct font_t {
    uint32_t upper_alpha;
    uint32_t lower_alpha;
    uint32_t zero_glyph;
} font_t;

const font_t* get_script_mode(void);
bool set_script_mode(int fc);
bool script_mode_translate(bool is_shifted, uint32_t keycode);

#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define OS_RGUI OSM(MOD_RGUI)
#define OS_RALT OSM(MOD_RALT)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_RSFT OSM(MOD_RSFT)
