#include "unicode.h"

bool _seeded = false;

#if defined(UNICODEMAP_ENABLE)
const uint32_t PROGMEM unicode_map[] = {
    [CCIR] = 0x20DD,  // COMBINING CIRCLE  ⃝
    [CENT] = 0x00A2,  // ¢
    [CHEK] = 0x2713,  // ✓
    [CKEY] = 0x20E3,  // COMBINING KEYCAP  ⃣
    [CUI]  = 0x26A0,  // ⚠
    [ECKS] = 0x2716,  // ✖
    [HAS]  = 0x262D,  // ☭
    [HUN]  = 0x1F4AF, // 💯
    [IBNG] = 0x203D,  // ‽
    [IRNY] = 0x2E2E,  // ⸮
    [LALL] = 0x2200,  // ∀
    [LELM] = 0x2208,  // ∈
    [LEXI] = 0x2203,  // ∃
    [LPRO] = 0x22A2,  // ⊢
    [M4]   = 0x2669,  // ♩
    [M8]   = 0x266A,  // ♪
    [M8B]  = 0x266B,  // ♫
    [M16]  = 0x266C,  // ♬
    [NEG]  = 0x20E0,  // COMBINING NO  ⃠
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

const char *d6_map[] = {
    "⚀", "⚁", "⚂", "⚃", "⚄", "⚅"
};
const char *dance_map[] = {
    "〜(￣▽￣〜)",
    "(〜￣▽￣)〜"
};
const char *dance_more_map[] = {
    "ƪ(˘⌣˘)┐",
    "┌(˘⌣˘)ʃ"
};
const char *flip_map[] = {
    "(╯°□°）╯︵ ┻━━┻",
    "（ノ－＿－）ノ･･ ┻━━┻",
    "(ﾉꐦ⊙曲ఠ)ﾉ彡┻━┻"
};
const char *flip_back_map[] = {
    "┬──┬◡ﾉ(° -°ﾉ)",
    "┬──┬ノ( ゜-゜ノ)",
    "┬──┬ノ(ಠ_ಠノ)"
};
const char *joy_map[] = {
    "ᕕ( ᐛ )ᕗ ",
    "٩(ˊᗜˋ*)و",
    "٩( ᐛ )و"
};
const char *joy_harder_map[] = {
    "＼\\ ٩( ᐛ )و /／",
    "✧*｡٩(ˊᗜˋ*)و✧*｡"
};

const char *choice(const char *choices[], int size) {
    if (_seeded == false) {
        srand(timer_read32());
        dprintf("_seeded the roll\n");
        _seeded = true;
    }
    return choices[rand() % size];
}

const char *d6(void) {
    return choice(d6_map, 6);
}
const char *dance(bool more) {
    if (more) {
        return choice(dance_more_map, 2);
    }
    return choice(dance_map, 2);
}
const char *flip(bool flip_back) {
    if (flip_back) {
        return choice(flip_back_map, 3);
    }
    return choice(flip_map, 3);
}
const char *joy(bool harder) {
    if (harder) {
        return choice(joy_harder_map, 2);
    }
    return choice(joy_map, 3);
}

bool u_x(const char *text) {
    send_unicode_string(text);
    return false;
};
bool u_xp(bool is_shifted, const char *shifted, const char *plain) {
    send_unicode_string(is_shifted ? shifted : plain);
    return false;
};
