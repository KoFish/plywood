#pragma once

#include "plywood.h"

#ifdef OLED_ENABLE
void render_plywood_layer_indicator(void);
void render_plywood_text(void);

// FROM LILY:
void render_kb_LED_state(void);
void render_logo(void);
void render_mod_status_ctrl_shift(uint8_t modifiers);
void render_mod_status_gui_alt(uint8_t modifiers);
void render_space(void);
#endif