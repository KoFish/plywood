#pragma once

enum layers {
    _BASE,
    _EXT,
    _FUN,
    _SYM,
    _NUM,
    _FIVE,
    _SIX,
};

#ifdef OLED_ENABLE
enum layer_indicator_oled {
    _MID_1 = 0x95,
    _MID_2 = 0xb5,
    _MID_3 = 0xd5,
    _MID_4 = 0xbc,
    _TOP_EMPTY = 0x94,
    _TOP_LEFT_EMPTY_1 = 0x93,
    _TOP_RIGHT_EMPTY_1 = 0x97,
    _TOP_LEFT_EMPTY_2 = 0xb3,
    _TOP_RIGHT_EMPTY_2 = 0xb6,
    _TOP_LEFT_EMPTY_3 = 0xb4,
    _TOP_RIGHT_EMPTY_3 = 0xb7,
    _TOP_LEFT_FULL_1 = 0x98,
    _TOP_RIGHT_FULL_1 = 0x9a,
    _TOP_LEFT_FULL_2 = 0xb8,
    _TOP_RIGHT_FULL_2 = 0xba,
    _TOP_LEFT_FULL_3 = 0x99,
    _TOP_RIGHT_FULL_3 = 0x9b,
    _TOP_LEFT_FULL_4 = 0xb9,
    _TOP_RIGHT_FULL_4 = 0xbb,
    _MID_LEFT_EMPTY = 0xd4,
    _MID_RIGHT_EMPTY = 0xd6,
    _MID_LEFT_FULL = 0xd9,
    _MID_RIGHT_FULL_1 = 0xda,
    _MID_RIGHT_FULL_2 = 0xdb,
    _BOTTOM_EMPTY = 0x96,
    _BOTTOM_LEFT_FULL = 0xd8,
    _BOTTOM_FULL_1 = 0x9c,
    _BOTTOM_FULL_2 = 0xdc,
};
#endif
