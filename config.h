#ifdef OLED_ENABLE
#   undef OLED_FONT_H
#   define OLED_FONT_H "plywood_font.c"
#endif

#ifdef CAPS_WORD_ENABLE
#   define BOTH_SHIFTS_TURNS_ON_CAPS_WORDS
#endif

#ifdef BACKLIGHT_ENABLE
#   define BACKLIGHT_BREATHING
#   define BREATHING_PERIOD 2
#endif

#ifdef RGB_MATRIX_ENABLE
#   define ENABLE_RGB_MATRIX_BREATHING
#   define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#   define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#   define RGB_DISABLE_WHEN_USB_SUSPENDED
#   define RGB_MATRIX_DEFAULT_MODE              RGB_MATRIX_CUSTOM_PLYWOOD
#   define RGB_MATRIX_DEFAULT_HUE               10
#   define RGB_MATRIX_DEFAULT_SPD               64
#   define RGB_MATRIX_SPD_STEP                  8
#endif

#ifdef LEADER_ENABLE
#   define LEADER_TIMEOUT 300
#endif

#ifdef WPM_ENABLE
#   define WPM_SAMPLE_SECONDS   8
#   define WPM_SAMPLE_PERIODS   25
#   define WPM_LAUNCH_CONTROL
#endif

#define TAPPING_TERM 200
#define ONESHOT_TIMEOUT 800
#define ONESHOT_TAP_TOGGLE 3
#define PLYWOOD_UNDERGLOW_VARIATION 8
#define PLYWOOD_KEYLIGHT_SHIFT (0xFF - 42)
#define PLYWOOD_KEYLIGHT_LAYER_SELECT_SHIFT (42 + 43)
#define PLYWOOD_DISABLE_POWERLIGHT

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_OLED_ENABLE
#define SPLIT_MODS_ENABLE
