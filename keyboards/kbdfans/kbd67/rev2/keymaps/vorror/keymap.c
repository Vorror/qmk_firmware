/* Copyright 2019 Vorror
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
enum kb_layers {
  _MAIN = 0,
  _WIN,
  _ALT
};

enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

// Macros
#define M_PGUP_HOME M(0)
#define M_PGDN_END M(1)

// Tap Dance Declarations
enum {
  TD_MEDIA_NEXT_PREV = 0,
  TD_MEDIA_NEXT_PREV_WINDOWS = 1
};

// Tap Dance Definitions
#define TD_NEXT_PREV_OSX TD(TD_MEDIA_NEXT_PREV)
#define TD_NEXT_PREV_WIN TD(TD_MEDIA_NEXT_PREV_WINDOWS)
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_MEDIA_NEXT_PREV] = ACTION_TAP_DANCE_DOUBLE(KC_MFFD, KC_MRWD),
  [TD_MEDIA_NEXT_PREV_WINDOWS] = ACTION_TAP_DANCE_DOUBLE(KC_MNXT, KC_MPRV)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Home|
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |PgUp|
   * |----------------------------------------------------------------|
   * |Ctrl   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgDn|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|End |
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_MAIN] = LAYOUT_65_ansi(
  KC_GESC, KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_MPLY,                \
  KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, TD_NEXT_PREV_OSX,       \
  KC_CAPS, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  M_PGUP_HOME,            \
  KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   M_PGDN_END,             \
  KC_LCTL, KC_LALT, KC_LGUI,                KC_SPC,                          KC_RGUI, KC_RALT, MO(_ALT), KC_LEFT, KC_DOWN, KC_RGHT),

/* Keymap (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Home|
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |PgUp|
   * |----------------------------------------------------------------|
   * |Ctrl   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgDn|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|End |
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
  [_WIN] = LAYOUT_65_ansi(
  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______, _______,  _______, _______, _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______,  _______,  TD_NEXT_PREV_WIN, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,            _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,            _______,  _______, \
  _______,  _______,  KC_LCTL,                      _______,                                _______, _______, _______,  _______,  _______,  _______),

  /* Keymap Fn Layer
   * ,----------------------------------------------------------------.
   * |~ `|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
   * |----------------------------------------------------------------|
   * |Caps |   |Up |   |   |   |   |   |PSc|SLk|Pau|Up |   |     |    |
   * |----------------------------------------------------------------|
   * |      |Lef|Dow|Rig|   |   |   |   |Hom|PUp|Lef|Rig|        |    |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |End|PDn|Dow|      |PUp|    |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |Hom|PDn|End |
   * `----------------------------------------------------------------'
   */
[_ALT] = LAYOUT_65_ansi(
  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,  KC_F12,    KC_DEL,  _______,            \
    RESET,  RGB_TOG,  RGB_M_P,  RGB_M_B,  RGB_M_R,  RGB_M_SW, RGB_M_SN, RGB_M_K,  RGB_M_X,  RGB_M_G, _______, _______,  _______,  _______,  TD_NEXT_PREV_WIN,   \
  _______,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  _______,  _______,  _______, _______, _______,            KC_POWER, _______,            \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,            KC_VOLU,  _______,            \
  _______,  _______,  _______,                      _______,                                TG(_WIN),_______, _______,  _______,  KC_VOLD,  _______),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
    switch (id) {
      case 0:
        if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
          return MACRODOWN(T(HOME), END);
        } else {
          return MACRODOWN(T(PGUP), END);
        }
      case 1:
        if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
          return MACRODOWN(T(END), END);
        } else {
          return MACRODOWN(T(PGDN), END);
        }
    }
  }

  return MACRO_NONE;
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
