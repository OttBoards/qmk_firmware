 /* Copyright 2023 @ Jesse Grantman
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

enum my_keycodes {
    FILUP = SAFE_RANGE,
    CTLD,
    CMD,
    AD,
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case FILUP:  // Types ../ to go up a directory on the shell.
      if (record->event.pressed) {
        SEND_STRING("../");
      }
      return false;
    
    case CTLD:  // Sends CTRL+D
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_D)));
      }
      return false;
    
    case CMD:  // Opens Command Prompt
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LGUI)"CMD" SS_DELAY(500) SS_TAP(X_ENT)));
      }
      return false;

    case AD:  // Opens Active Directory Users and Computers
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LGUI)"ADUC" SS_DELAY(500) SS_TAP(X_ENT)));
      }
      return false;
  }
  return true;
}

enum layers {
    BASE,
    FUNC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_numpad_6x4(
        FILUP,   CMD,      CTLD,    AD,
        KC_RSFT, KC_PSLS,  KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,    KC_P9,   KC_NO,
        KC_P4,   KC_P5,    KC_P6,   KC_PCCM,
        KC_P1,   KC_P2,    KC_P3,   KC_NO,
        KC_P0,   KC_NO,    KC_PDOT, KC_PENT),

    [FUNC] = LAYOUT_numpad_6x4(
        FILUP,   CMD,     CTLD,     AD,
        KC_RSFT, KC_NO,   KC_NO,    KC_NO,
        KC_HOME, KC_UP,   KC_PGUP,  KC_NO,
        KC_LEFT, KC_P5,   KC_RIGHT, KC_NO,
        KC_END,  KC_DOWN, KC_PGDN,  KC_NO,
        KC_INS,  KC_NO,   KC_DEL,   KC_NO),
}          

