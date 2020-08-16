#pragma once
#include "rupa.h"

#if defined(UNICODEMAP_ENABLE)
enum unicode_names {
    CCIR, //
    CHEK, // ✓
    CKEY, //
    CUI,  // ⚠
    ECKS, // ✖
    /*
    DI1,  // ⚀
    DI2,  // ⚁
    DI3,  // ⚂
    DI4,  // ⚃
    DI5,  // ⚄
    DI6,  // ⚅
    */
    HAS,  // ☭
    HUN,  // 💯
    IBNG, // ‽
    IRNY, // ⸮
    M4,   // ♩
    M8,   // ♪
    M8B,  // ♫
    M16,  // ♬
    NEG,  //  ⃠
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

const char *d6(void);
