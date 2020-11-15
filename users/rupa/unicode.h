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

#if defined(UNICODEMAP_ENABLE)
enum unicode_names {
    CCIR, // COMBINING  ⃝
    CENT, // ¢
    CHEK, // ✓
    CKEY, // COMBINING  ⃣
    CLEF, // 𝄞
    CPRT, // ©
    CUI,  // ⚠
    ECKS, // ✖
    EFF,  // ſ
    EURO, // €
    FRWN, // ☹
    HAS,  // ☭
    HUN,  // 💯
    IBNG, // ‽
    INTR, // ∩
    IQMK, // ¿
    IRNY, // ⸮
    IXCL, // ¡
    LALL, // ∀
    LELM, // ∈
    LEXI, // ∃
    LPRO, // ⊢
    M4,   // ♩
    M8,   // ♪
    M8B,  // ♫
    M16,  // ♬
    NEG,  // COMBINING  ⃠
    NOPE, // 🚫
    NUM,  // №
    OM,   // ॐ
    PTDN, // ☟
    PTLT, // ☜
    PTRT, // ☞
    PTUP, // ☝
    RTMK, // ®
    SMB,  // ☻
    SMW,  // ☺
    STB,  // ★
    STOP, // ⛔
    STW,  // ☆
    TDMK, // ™
    THUD, // 👎
    THUP, // 👍
    UNIO, // ∪
};
#endif

typedef enum combined_modes {
    CM_NULL = 0,
    CM_CIRCLE,
    CM_NO,
    CM_KEYCAP,
    CM_ZALGO,
    CM_MAX
} combined_mode_t;

combined_mode_t combined_mode;

// random choices
const char * d6(void);
const char * dance(bool more);
const char * flip(bool back);
const char * joy(bool harder);

// like X and XP
bool u_x(const char *text);
bool u_xp(bool is_shifted, const char * shifted, const char *plain);

bool combined_text(uint16_t keycode);
void cycle_combined_mode(void);
combined_mode_t set_combined_mode(combined_mode_t mode);
