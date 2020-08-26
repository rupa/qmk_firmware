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
