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

#ifdef LEADER_ENABLE
#   define LEADER_TIMEOUT 300
#endif

#define TAPPING_TERM 200
#define ONESHOT_TIMEOUT 300
#define ONESHOT_TAP_TOGGLE 3