#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

// Local Moonlander keymap: the same layout as ../voyager-local (2026-10-26).
// Layer 0: Colemak-DH base, 1: numbers and symbols (hold either outer thumb key),
// 2: F-keys, arrows, Home/End/PgUp/PgDn, media, QK_BOOT top right (hold Space).
// Off on all layers: the 3-key inner columns, the 5-key bottom row, the red
// thumb keys and the innermost thumb keys. Outer thumb keys = Space/FN and
// Enter, middle thumb keys = Down/Up with the number layer.
// Enter: tap = Enter, hold = Meta (xmonad mod), next to Meta on G and M.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_NO,                                          KC_NO,          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           CW_TOGG,
    KC_TAB,         KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_NO,                                          KC_NO,          KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCLN,        KC_DELETE,
    KC_BSPC,        KC_A,           MT(MOD_LSFT, KC_R),MT(MOD_LALT, KC_S),MT(MOD_LCTL, KC_T),MT(MOD_LGUI, KC_G),   KC_NO,                                          KC_NO,          MT(MOD_RGUI, KC_M),MT(MOD_RCTL, KC_N),MT(MOD_LALT, KC_E),MT(MOD_RSFT, KC_I),KC_O,           KC_QUOTE,
    KC_LEFT,        KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                                                                           KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RIGHT,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    LT(2, KC_SPACE),LT(1, KC_DOWN), KC_NO,                                                                                                          KC_NO,          LT(1, KC_UP),   MT(MOD_RGUI, KC_ENTER)
  ),
  [1] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_BSLS,        KC_EXLM,        KC_TILD,        KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_COLN,        KC_PIPE,        KC_NO,          KC_NO,
    KC_MINUS,       KC_PLUS,        KC_LBRC,        KC_LCBR,        KC_LPRN,        KC_UNDS,        KC_NO,                                          KC_NO,          KC_MINUS,       KC_RPRN,        KC_RCBR,        KC_RBRC,        KC_SCLN,        KC_DQUO,
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_NO,                                          KC_NO,          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_QUOTE,
    KC_PLUS,        KC_ASTR,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                                                        KC_CIRC,        KC_AMPR,        KC_COMMA,       KC_DOT,         KC_SLASH,       KC_GRAVE,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_SPACE,       KC_TRANSPARENT, KC_NO,                                                                                                          KC_NO,          KC_TRANSPARENT, KC_ENTER
  ),
  [2] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          QK_BOOT,
    KC_NO,          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_F11,         KC_F12,         KC_NO,          KC_NO,
    KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_NO,                                          KC_NO,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_NO,
    KC_NO,          KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         KC_NO,                                                                          KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRANSPARENT, KC_NO,          KC_NO,                                                                                                          KC_NO,          KC_NO,          KC_NO
  ),
};

// Chordal Hold handedness. Outer columns, red keys and thumb clusters are '*'
// (as on the Voyager: T + Backspace = Ctrl+Backspace, thumbs never become taps).
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_moonlander(
  '*', 'L', 'L', 'L', 'L', 'L', 'L',      'R', 'R', 'R', 'R', 'R', 'R', '*',
  '*', 'L', 'L', 'L', 'L', 'L', 'L',      'R', 'R', 'R', 'R', 'R', 'R', '*',
  '*', 'L', 'L', 'L', 'L', 'L', 'L',      'R', 'R', 'R', 'R', 'R', 'R', '*',
  '*', 'L', 'L', 'L', 'L', 'L',                'R', 'R', 'R', 'R', 'R', '*',
  'L', 'L', 'L', 'L', 'L', '*',                '*', 'R', 'R', 'R', 'R', 'R',
  '*', '*', '*',                                              '*', '*', '*'
);

// Pinky and ring mods (R I) need a longer hold.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MT(MOD_LSFT, KC_R):
    case MT(MOD_RSFT, KC_I):
      return TAPPING_TERM + 50;
  }
  return TAPPING_TERM;
}

// Space is time-only, like kanata on the laptop: a space-letter roll never
// turns into an F-key. Everything else uses permissive hold.
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  return keycode != LT(2, KC_SPACE);
}


extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

// One solid colour per layer {hue, sat, val}, the same as on the Voyager.
static const uint8_t PROGMEM layer_colors[][3] = {
  [0] = {139, 184,  94},
  [1] = {164, 227, 112},
  [2] = { 87, 245, 200},  // #08c811
};

void set_layer_color(int layer) {
  HSV hsv = {
    .h = pgm_read_byte(&layer_colors[layer][0]),
    .s = pgm_read_byte(&layer_colors[layer][1]),
    .v = pgm_read_byte(&layer_colors[layer][2]),
  };
  RGB rgb = hsv_to_rgb_with_value(hsv);
  rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) {
    switch (biton32(layer_state)) {
      case 0:
      case 1:
      case 2:
        set_layer_color(biton32(layer_state));
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
    // this makes sure that modifiers are always applied to the key that was pressed.
    if (IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
      if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;
  }
  return true;
}
