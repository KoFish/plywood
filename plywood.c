#include QMK_KEYBOARD_H
#include "plywood.h"


#ifdef OLED_ENABLE
#   include "plywood_oled.h"

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_logo();
        //render_space();
        render_plywood_text();
        render_plywood_layer_indicator();
        render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
        render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
        render_kb_LED_state();
        return false;
    } else {
        return true;
    }
}
#endif // OLED

#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case RALT(KC_W):
        case RALT(KC_P):
        case RALT(KC_Q):
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
#endif // CAPS_WORDS

#ifdef PLYWOOD_DISABLE_POWERLIGHT
void keyboard_pre_init_user(void) {
    // Turn off power led on keyboard.
    // Set our LED pin as output
    setPinOutput(24);
    // Turn the LED off
    // (Due to technical reasons, high is off and low is on)
    writePinHigh(24);
}
#endif
