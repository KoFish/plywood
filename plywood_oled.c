#include "plywood_oled.h"

void render_layer_state(void) {
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
}