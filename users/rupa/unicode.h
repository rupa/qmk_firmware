#pragma once
#include "rupa.h"

#if defined(UNICODEMAP_ENABLE)
enum unicode_names {
    CCIR, // COMBINING  ⃝
    CENT, // ¢
    CHEK, // ✓
    CKEY, // COMBINING  ⃣
    CUI,  // ⚠
    ECKS, // ✖
    HAS,  // ☭
    HUN,  // 💯
    IBNG, // ‽
    IRNY, // ⸮
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
    SMB,  // ☻
    SMW,  // ☺
    STB,  // ★
    STOP, // ⛔
    STW,  // ☆
};
#endif

// random choices
const char * d6(void);
const char * dance(bool more);
const char * flip(bool back);
const char * joy(bool harder);

bool u_x(const char *text);
bool u_xp(bool is_shifted, const char * shifted, const char *plain);
