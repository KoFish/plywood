#include QMK_KEYBOARD_H
#include "plywood_oled.h"

// LAYER OFF --------------------------------------------------------------------------------------

static const char PROGMEM LAY_TOP_LEFT_OFF_1[] = {_TOP_LEFT_EMPTY_1, _TOP_EMPTY, 0};
static const char PROGMEM LAY_TOP_RIGHT_OFF_1[] = {_TOP_EMPTY, _TOP_RIGHT_EMPTY_1, 0};
static const char PROGMEM LAY_TOP_LEFT_OFF_2[] = {_TOP_LEFT_EMPTY_2, _TOP_LEFT_EMPTY_3, 0};
static const char PROGMEM LAY_TOP_RIGHT_OFF_2[] = {_TOP_RIGHT_EMPTY_2, _TOP_RIGHT_EMPTY_3, 0};

static const char PROGMEM LAY_MID_LEFT_OFF_1[] = {_TOP_LEFT_EMPTY_1, _MID_LEFT_EMPTY, 0};
static const char PROGMEM LAY_MID_RIGHT_OFF_1[] = {_MID_RIGHT_EMPTY, _TOP_RIGHT_EMPTY_1, 0};
static const char PROGMEM LAY_MID_LEFT_OFF_2[] = {_TOP_LEFT_EMPTY_2, _TOP_LEFT_EMPTY_3, 0};
static const char PROGMEM LAY_MID_RIGHT_OFF_2[] = {_TOP_RIGHT_EMPTY_2, _TOP_RIGHT_EMPTY_3, 0};

static const char PROGMEM LAY_BOTTOM_LEFT_OFF_1[] = {_TOP_LEFT_EMPTY_1, _MID_LEFT_EMPTY, 0};
static const char PROGMEM LAY_BOTTOM_RIGHT_OFF_1[] = {_MID_RIGHT_EMPTY, _TOP_RIGHT_EMPTY_1, 0};
static const char PROGMEM LAY_BOTTOM_LEFT_OFF_2[] = {_TOP_LEFT_EMPTY_2, _BOTTOM_EMPTY, 0};
static const char PROGMEM LAY_BOTTOM_RIGHT_OFF_2[] = {_BOTTOM_EMPTY, _TOP_RIGHT_EMPTY_3, 0};

// LAYER ON ---------------------------------------------------------------------------------------

static const char PROGMEM LAY_TOP_LEFT_ON_1[] = {_TOP_LEFT_FULL_1, _TOP_LEFT_FULL_3, 0};
static const char PROGMEM LAY_TOP_RIGHT_ON_1[] = {_TOP_RIGHT_FULL_1, _TOP_RIGHT_FULL_3, 0};
static const char PROGMEM LAY_TOP_LEFT_ON_2[] = {_TOP_LEFT_FULL_2, _TOP_LEFT_FULL_4, 0};
static const char PROGMEM LAY_TOP_RIGHT_ON_2[] = {_TOP_RIGHT_FULL_2, _TOP_RIGHT_FULL_4, 0};

static const char PROGMEM LAY_MID_LEFT_ON_1[] = {_TOP_LEFT_FULL_1, _MID_LEFT_FULL, 0};
static const char PROGMEM LAY_MID_RIGHT_ON_1[] = {_MID_RIGHT_FULL_1, _MID_RIGHT_FULL_2, 0};
static const char PROGMEM LAY_MID_LEFT_ON_2[] = {_TOP_LEFT_FULL_2, _TOP_LEFT_FULL_4, 0};
static const char PROGMEM LAY_MID_RIGHT_ON_2[] = {_TOP_RIGHT_FULL_2, _TOP_RIGHT_FULL_4, 0};

static const char PROGMEM LAY_BOTTOM_LEFT_ON_1[] = {_TOP_LEFT_FULL_1, _MID_LEFT_FULL, 0};
static const char PROGMEM LAY_BOTTOM_RIGHT_ON_1[] = {_MID_RIGHT_FULL_1, _TOP_RIGHT_FULL_1, 0};
static const char PROGMEM LAY_BOTTOM_LEFT_ON_2[] = {_BOTTOM_LEFT_FULL, _BOTTOM_FULL_1, 0};
static const char PROGMEM LAY_BOTTOM_RIGHT_ON_2[] = {_BOTTOM_FULL_2, _TOP_RIGHT_FULL_3, 0};

// ------------------------------------------------------------------------------------------------

void render_plywood_layer_indicator(void) {
    oled_write_P(IS_LAYER_ON(_EXT) ? LAY_TOP_LEFT_ON_1 : LAY_TOP_LEFT_OFF_1, false);
    oled_write_char(_MID_1, false);
    oled_write_P(IS_LAYER_ON(_FUN) ? LAY_TOP_RIGHT_ON_1 : LAY_TOP_RIGHT_OFF_1, false);
    oled_write_P(IS_LAYER_ON(_EXT) ? LAY_TOP_LEFT_ON_2 : LAY_TOP_LEFT_OFF_2, false);
    oled_write_char(_MID_2, false);
    oled_write_P(IS_LAYER_ON(_FUN) ? LAY_TOP_RIGHT_ON_2 : LAY_TOP_RIGHT_OFF_2, false);

    oled_write_P(IS_LAYER_ON(_SYM) ? LAY_MID_LEFT_ON_1 : LAY_MID_LEFT_OFF_1, false);
    oled_write_char(_MID_3, false);
    oled_write_P(IS_LAYER_ON(_NUM) ? LAY_MID_RIGHT_ON_1 : LAY_MID_RIGHT_OFF_1, false);
    oled_write_P(IS_LAYER_ON(_SYM) ? LAY_MID_LEFT_ON_2 : LAY_MID_LEFT_OFF_2, false);
    oled_write_char(_MID_2, false);
    oled_write_P(IS_LAYER_ON(_NUM) ? LAY_MID_RIGHT_ON_2 : LAY_MID_RIGHT_OFF_2, false);

    oled_write_P(IS_LAYER_ON(_FIVE) ? LAY_BOTTOM_LEFT_ON_1 : LAY_BOTTOM_LEFT_OFF_1, false);
    oled_write_char(_MID_3, false);
    oled_write_P(IS_LAYER_ON(_SIX) ? LAY_BOTTOM_RIGHT_ON_1 : LAY_BOTTOM_RIGHT_OFF_1, false);
    oled_write_P(IS_LAYER_ON(_FIVE) ? LAY_BOTTOM_LEFT_ON_2 : LAY_BOTTOM_LEFT_OFF_2, false);
    oled_write_char(_MID_4, false);
    oled_write_P(IS_LAYER_ON(_SIX) ? LAY_BOTTOM_RIGHT_ON_2 : LAY_BOTTOM_RIGHT_OFF_2, false);
}

