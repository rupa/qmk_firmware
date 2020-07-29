#pragma once
#include "quantum.h"
#include "rupa.h"

#if defined(UNICODEMAP_ENABLE)
enum unicode_names {
    CHEK, // ✓
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
    OM,   // ॐ
    SMB,  // ☻
    SMW,  // ☺
    STB,  // ★
    STW,  // ☆
};
#endif

#define CUIDADO XP(CUI,HAS)
#define HIPSTER XP(IBNG,IRNY)
#define MUSIC_A XP(M4,M8)
#define MUSIC_B XP(M8B,M16)
#define SMILE   XP(SMB,SMW)
#define STARS   XP(STB,STW)
#define YEPYEP  XP(CHEK,HUN)

const char *d6(void);
