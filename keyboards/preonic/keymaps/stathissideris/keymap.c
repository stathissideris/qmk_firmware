/* Copyright 2015-2017 Jack Humbert
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

/* Compile with: */
/* util/docker_build.sh preonic/rev3:stathissideris */

#include QMK_KEYBOARD_H
#include "muse.h"

#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif // TAPPING_TERM
#define TAPPING_TERM 70

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _ASCEND
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT,

  ASCEND,

  WMOVE_UP,
  WMOVE_DOWN,
  WMOVE_LEFT,
  WMOVE_RIGHT,
  WMAX,
  WHOR,
  WVER,
  WCLO,
  WBAL,
  ARROW,
  DARROW,
  MAGIT,
  CLOCK_IN,
  CLOCK_OUT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | '    |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |Ascend|Lower |    Space    |Raise | Left | Up   | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_GRV,       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT, /*KC_DEL,*/
  KC_ESC,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  /* LSFT_T(KC_9),*/
  KC_LSFT,      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, /*LSFT_T(KC_ENT),*/
  KC_LCTL,      KC_LALT, KC_LGUI, ASCEND,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Up   | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_QUOT, /*KC_DEL,*/
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_DEL,
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT,
  BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   -  |   =  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  ->  |      |clstab|   #  |  -   |newtab|      |      |   |  |   _  |   +  | ->>  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |magit |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |  -   |      |      |      |prvtab|nxttab|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_TILD, KC_EXLM, KC_AT,      KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS,       KC_EQL,  KC_DEL,
  ARROW,   _______, LGUI(KC_W), _______, KC_MINS, LGUI(KC_T), _______, _______, KC_PIPE, KC_UNDS,       KC_PLUS, DARROW,
  _______, _______, _______,    _______, KC_MINS, MAGIT,      _______, _______, _______, _______,       _______, _______,
  _______, _______, _______,    _______, KC_MINS, _______,    _______, _______, LCTL(KC_PGUP), LCTL(KC_PGDN),  _______, _______,
  _______, _______, _______,    _______, _______, LGUI(KC_SPC), LGUI(KC_SPC), _______, KC_MNXT, KC_VOLD,       KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ->  |      |      |      |      |      |      |      |   |  |   [  |   ]  |  ->> |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   \  |   {  |   }  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |complt|prvtab|nxttab|  \   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,          KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  ARROW,   _______, _______, _______, _______, _______, _______, _______,       KC_PIPE, KC_LBRC, KC_RBRC, DARROW,
  _______, _______, _______, _______, _______, _______, _______, _______,       KC_BSLS, KC_LCBR, KC_RCBR, _______,
  _______, _______, _______, _______, _______, _______, _______, LGUI(KC_SLSH), LCTL(KC_PGUP), LCTL(KC_PGDN), KC_BSLS, _______,
  _______, _______, _______, _______, _______, LGUI(KC_SPC), LGUI(KC_SPC), _______,       KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  RGB_TOG, RGB_MOD, RGB_RMOD, RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI,   KC_F8,    KC_F9, KC_F10, RGB_M_P, KC_F12,
  _______, RESET,   DEBUG,    _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,
  _______, _______, MU_MOD,   AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______,
  _______, MUV_DE,  MUV_IN,   MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ASCEND] = LAYOUT_preonic_grid(
  _______, WMAX,    WHOR,       WVER,         _______, _______, _______, _______, _______,    LGUI(KC_LPRN), WCLO,    _______,
  _______, _______, LGUI(KC_W), LGUI(LSFT(LALT(LCTL(KC_9)))),      _______, _______, _______, _______, CLOCK_IN,   CLOCK_OUT,       WBAL,    _______,
  _______, _______, _______,    _______,      _______, MAGIT,   _______, _______, _______,    _______,       _______, _______,
  _______, _______, _______,    LGUI(KC_EQL), _______, _______, _______, _______, _______,    _______,       _______,   _______,
  _______, _______, _______,    _______,      _______, _______, _______, _______, WMOVE_LEFT, WMOVE_UP,    WMOVE_DOWN, WMOVE_RIGHT
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
   case CLOCK_IN:
      if (record->event.pressed) {
         SEND_STRING(SS_LCTL("c") SS_LCTL("x") SS_LCTL("i"));
      }
      return false;
      break;
   case CLOCK_OUT:
      if (record->event.pressed) {
         SEND_STRING(SS_LCTL("c") SS_LCTL("x") SS_LCTL("o"));
      }
      return false;
      break;
   case MAGIT:
      if (record->event.pressed) {
         SEND_STRING(SS_LCTL("c") SS_LCTL("g"));
      }
      return false;
      break;
   case LSFT_T(KC_9):
      if (record->tap.count > 0) {
         if (record->event.pressed) {
            register_code16(KC_LPRN);
         } else {
            unregister_code16(KC_LPRN);
         }
         return false;
      }
      return true;
   case ARROW:
      if (record->event.pressed) {
         SEND_STRING("->");
      }
      return false;
      break;
   case DARROW:
      if (record->event.pressed) {
         SEND_STRING("->>");
      }
      return false;
      break;
   case WMAX:
      if (record->event.pressed) {
         SEND_STRING(SS_LCTL("x") SS_TAP(X_1));
      }
      return false;
      break;
   case WHOR:
      if (record->event.pressed) {
         SEND_STRING(SS_LCTL("x") SS_TAP(X_2));
      }
      return false;
      break;
   case WVER:
      if (record->event.pressed) {
         SEND_STRING(SS_LCTL("x") SS_TAP(X_3));
      }
      return false;
      break;
   case WCLO:
      if (record->event.pressed) {
         SEND_STRING(SS_LCTL("x") SS_TAP(X_0));
      }
      return false;
      break;
   case WBAL:
      if (record->event.pressed) {
         SEND_STRING(SS_LCTL("x") "+");
      }
      return false;
      break;
   case WMOVE_UP:
      if (record->event.pressed) {
         SEND_STRING(SS_LCTL("x") SS_TAP(X_UP));
      }
      return false;
      break;
   case WMOVE_DOWN:
      if (record->event.pressed) {
         SEND_STRING(SS_LCTL("x") SS_TAP(X_DOWN));
      }
      return false;
      break;
   case WMOVE_LEFT:
      if (record->event.pressed) {
         SEND_STRING(SS_LCTL("x") SS_TAP(X_LEFT));
      }
      return false;
      break;
   case WMOVE_RIGHT:
      if (record->event.pressed) {
         SEND_STRING(SS_LCTL("x") SS_TAP(X_RIGHT));
      }
      return false;
      break;
   case QWERTY:
      if (record->event.pressed) {
         set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
   case COLEMAK:
      if (record->event.pressed) {
         set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
   case DVORAK:
      if (record->event.pressed) {
         set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
   case LOWER:
      if (record->event.pressed) {
         layer_on(_LOWER);
         update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
         layer_off(_LOWER);
         update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
   case RAISE:
      if (record->event.pressed) {
         layer_on(_RAISE);
         update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
         layer_off(_RAISE);
         update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
   case ASCEND:
      if (record->event.pressed) {
         layer_on(_ASCEND);
      } else {
         layer_off(_ASCEND);
      }
      return false;
      break;
   case BACKLIT:
      if (record->event.pressed) {
         register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
         backlight_step();
#endif
#ifdef RGBLIGHT_ENABLE
         rgblight_step();
#endif
#ifdef __AVR__
         writePinLow(E6);
#endif
      } else {
         unregister_code(KC_RSFT);
#ifdef __AVR__
         writePinHigh(E6);
#endif
      }
      return false;
      break;
   }
   return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
