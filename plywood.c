#include QMK_KEYBOARD_H

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
#   include "plywood_oled.h"

bool oled_task_user(void) {
    render_layer_state();
    return false;
}
#endif