#include "unicode.h"

#if defined(UNICODEMAP_ENABLE)
const uint32_t PROGMEM unicode_map[] = {
    [CHEK] = 0x2713,  // ✓
    [CUI]  = 0x26A0,  // ⚠
    /*
    [DI1]  = 0x2680,  // ⚀
    [DI2]  = 0x2681,  // ⚁
    [DI3]  = 0x2682,  // ⚂
    [DI4]  = 0x2683,  // ⚃
    [DI5]  = 0x2684,  // ⚄
    [DI6]  = 0x2685,  // ⚅
    */
    [HAS]  = 0x262D,  // ☭
    [HUN]  = 0x1F4AF, // 💯
    [IBNG] = 0x203D,  // ‽
    [IRNY] = 0x2E2E,  // ⸮
    [M4]   = 0x2669,  // ♩
    [M8]   = 0x266A,  // ♪
    [M8B]  = 0x266B,  // ♫
    [M16]  = 0x266C,  // ♬
    [OM]   = 0x0950,  // ॐ
    [SMB]  = 0x263A,  // ☻
    [SMW]  = 0x263B,  // ☺
    [STB]  = 0x2605,  // ★
    [STW]  = 0x2606,  // ☆
};
#endif
