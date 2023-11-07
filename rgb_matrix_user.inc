RGB_MATRIX_EFFECT(PLYWOOD)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static uint8_t PLYWOOD_state;
static void PLYWOOD_complex_init(effect_params_t* params) {
  PLYWOOD_state = 1;
}
static bool PLYWOOD_complex_run(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  HSV hsv = rgb_matrix_config.hsv;
  RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
  for (uint8_t i = led_min; i < led_max; i++) {
    RGB_MATRIX_TEST_LED_FLAGS();
    if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_KEYLIGHT)) {
        rgb_matrix_set_color(i, 0, rgb.g, 0);
    } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
        rgb_matrix_set_color(i, rgb.r, 0, 0);
    } else {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }

  return rgb_matrix_check_finished_leds(led_max);
}
static bool PLYWOOD(effect_params_t* params) {
  if (params->init) PLYWOOD_complex_init(params);
  return PLYWOOD_complex_run(params);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS