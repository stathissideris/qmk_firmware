/* Copyright 2021 REPLACE_WITH_YOUR_NAME
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

/* util/docker_build.sh winry25tc:blender */

#include QMK_KEYBOARD_H

enum preonic_layers {
  _BASE,
  _RAISE
};

enum preonic_keycodes {
  BASE = SAFE_RANGE,
  RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_ESC,  KC_TAB,  KC_1,    KC_2,         KC_3,
        _______, _______, KC_G,    KC_S,         KC_R,
        KC_P7,   KC_P5,   KC_X,    KC_Y,         KC_Z,
        KC_P1,   KC_P3,   KC_PMNS, KC_PPLS,      KC_ENT,
        KC_P0,   KC_PDOT, KC_PSLS, LSFT(KC_GRV), RAISE
    ),

    [_RAISE] = LAYOUT(
        _______,           _______,     _______,    _______,    _______,
        _______,           _______,     _______,    _______,    _______,
        LCTL(KC_P7),       _______,     LSFT(KC_X), LSFT(KC_Y), LSFT(KC_Z),
        LCTL(KC_P1),       LCTL(KC_P3), RGB_HUI,    RGB_MOD,    RGB_TOG,
        LCTL(LALT(KC_P0)), _______,     _______,    _______,    _______
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
   case RAISE:
      if (record->event.pressed) {
         layer_on(_RAISE);
       } else {
         layer_off(_RAISE);
       }
      return false;
      break;
   }
   return true;
};
