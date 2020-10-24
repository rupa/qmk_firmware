#include "unicode.h"

bool _seeded = false;

#if defined(UNICODEMAP_ENABLE)
const uint32_t PROGMEM unicode_map[] = {
    [CCIR] = 0x20DD,  //
    [CHEK] = 0x2713,  // ✓
    [CKEY] = 0x20E3,  //
    [CUI]  = 0x26A0,  // ⚠
    [ECKS] = 0x2716,  // ✖
    [HAS]  = 0x262D,  // ☭
    [HUN]  = 0x1F4AF, // 💯
    [IBNG] = 0x203D,  // ‽
    [IRNY] = 0x2E2E,  // ⸮
    [M4]   = 0x2669,  // ♩
    [M8]   = 0x266A,  // ♪
    [M8B]  = 0x266B,  // ♫
    [M16]  = 0x266C,  // ♬
    [NEG]  = 0x20E0,  //  ⃠
    [NOPE] = 0x1F6AB, // 🚫
    [NUM]  = 0x2116,  // №
    [OM]   = 0x0950,  // ॐ
    [SMB]  = 0x263A,  // ☻
    [SMW]  = 0x263B,  // ☺
    [STB]  = 0x2605,  // ★
    [STOP] = 0x26D4,  // ⛔
    [STW]  = 0x2606,  // ☆
};
#endif

const char *dice_map[] = { "⚀", "⚁", "⚂", "⚃", "⚄", "⚅" };

const char *d6(void) {
    if (_seeded == false) {
        srand(timer_read32());
        dprintf("_seeded the roll\n");
        _seeded = true;
    }
    return dice_map[rand() % 6];
}
