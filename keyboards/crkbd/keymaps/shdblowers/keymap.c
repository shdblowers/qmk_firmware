/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sendstring_uk.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    UK_Q,    UK_W,    UK_E,    UK_R,    UK_T,                         UK_Y,    UK_U,    UK_I,    UK_O,   UK_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    UK_A,    UK_S,    UK_D,    UK_F,    UK_G,                         UK_H,    UK_J,    UK_K,    UK_L, UK_SCLN, UK_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    UK_Z,    UK_X,    UK_C,    UK_V,    UK_B,                         UK_N,    UK_M, UK_COMM,  UK_DOT, UK_SLSH, KC_LEAD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TAB,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_LGUI
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    UK_1,    UK_2,    UK_3,    UK_4,    UK_5,                         UK_6,    UK_7,    UK_8,    UK_9,    UK_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TAB, _______,  KC_SPC,     KC_ENT,   MO(3), KC_LGUI
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, UK_EXLM, UK_DQUO,  UK_PND,  UK_DLR, UK_PERC,                      UK_CIRC, UK_AMPR, UK_ASTR, UK_LPRN, UK_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      UK_MINS,  UK_EQL, UK_HASH, KC_LCBR, KC_RCBR,  UK_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      UK_UNDS, UK_PLUS, UK_BSLS, KC_LBRC, KC_RBRC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TAB,   MO(3),  KC_SPC,     KC_ENT, _______, KC_LGUI
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TAB, _______,  KC_SPC,     KC_ENT, _______, KC_LGUI
                                      //`--------------------------'  `--------------------------'
  )
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_LSFT) {
      SEND_STRING(SS_TAP(X_CAPS));
    }
    SEQ_TWO_KEYS(KC_C, KC_C) {
      SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    }
    SEQ_TWO_KEYS(KC_B, KC_B) {
      SEND_STRING(SS_LALT("d") "https://bitbucket.org/\n");
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
    SEQ_TWO_KEYS(KC_T, KC_Y) {
      if((rand() % 2) == 0) {
        SEND_STRING("Thank You!");
      } else {
        SEND_STRING("Cheers!");
      }
    }
    SEQ_TWO_KEYS(KC_E, KC_M) {
      SEND_STRING("steven@shdblowers.com");
    }
  }
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60][3] = {
  {
    ' ',
    ' ',
    ' '
  },
  {
    ' ',
    ' ',
    ' '
  },
  {
    ' ',
    ' ',
    ' '
  },
  {
    ' ',
    ' ',
    ' '
  },
  {
    'a',
    ' ',
    ' '
  },
  {
    'b',
    ' ',
    ' '
  },
  {
    'c',
    ' ',
    ' '
  },
  {
    'd',
    ' ',
    ' '
  },
  {
    'e',
    ' ',
    ' '
  },
  {
    'f',
    ' ',
    ' '
  },
  {
    'g',
    ' ',
    ' '
  },
  {
    'h',
    ' ',
    ' '
  },
  {
    'i',
    ' ',
    ' '
  },
  {
    'j',
    ' ',
    ' '
  },
  {
    'k',
    ' ',
    ' '
  },
  {
    'l',
    ' ',
    ' '
  },
  {
    'm',
    ' ',
    ' '
  },
  {
    'n',
    ' ',
    ' '
  },
  {
    'o',
    ' ',
    ' '
  },
  {
    'p',
    ' ',
    ' '
  },
  {
    'q',
    ' ',
    ' '
  },
  {
    'r',
    ' ',
    ' '
  },
  {
    's',
    ' ',
    ' '
  },
  {
    't',
    ' ',
    ' '
  },
  {
    'u',
    ' ',
    ' '
  },
  {
    'v',
    ' ',
    ' '
  },
  {
    'w',
    ' ',
    ' '
  },
  {
    'x',
    ' ',
    ' '
  },
  {
    'y',
    ' ',
    ' '
  },
  {
    'z',
    ' ',
    ' '
  },
  {
    '1',
    ' ',
    ' '
  },
  {
    '2',
    ' ',
    ' '
  },
  {
    '3',
    ' ',
    ' '
  },
  {
    '4',
    ' ',
    ' '
  },
  {
    '5',
    ' ',
    ' '
  },
  {
    '6',
    ' ',
    ' '
  },
  {
    '7',
    ' ',
    ' '
  },
  {
    '8',
    ' ',
    ' '
  },
  {
    '9',
    ' ',
    ' '
  },
  {
    '0',
    ' ',
    ' '
  },
  {
    'R',
    'e',
    't'
  },
  {
    'E',
    's',
    'c'
  },
  {
    'B',
    'k',
    's'
  },
  {
    'T',
    'a',
    'b'
  },
  {
    'S',
    'p',
    'c'
  },
  {
    '-',
    ' ',
    ' '
  },
  {
    '=',
    ' ',
    ' '
  },
  {
    '[',
    ' ',
    ' '
  },
  {
    ']',
    ' ',
    ' '
  },
  {
    '\\',
    ' ',
    ' '
  },
  {
    '#',
    ' ',
    ' '
  },
  {
    ';',
    ' ',
    ' '
  },
  {
    '\'',
    ' ',
    ' '
  },
  {
    '`',
    ' ',
    ' '
  },
  {
    ',',
    ' ',
    ' '
  },
  {
    '.',
    ' ',
    ' '
  },
  {
    '/',
    ' ',
    ' '
  },
  {
    ' ',
    ' ',
    ' '
  },
  {
    ' ',
    ' ',
    ' '
  },
  {
    ' ',
    ' ',
    ' '
  }
};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name[3] = {' ', ' ', ' '};
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }

  if (keycode < 60) {
    name[0] = code_to_name[keycode][0];
    name[1] = code_to_name[keycode][1];
    name[2] = code_to_name[keycode][2];
  }

  if (keycode == 224) {
    name[0] = 'C';
    name[1] = 't';
    name[2] = 'l';
  }

  if (keycode == 225) {
    name[0] = 'S';
    name[1] = 'h';
    name[2] = 't';
  }

  if (keycode == 227) {
    name[0] = 'M';
    name[1] = 'e';
    name[2] = 't';
  }

  if (keycode == 230) {
    name[0] = 'A';
    name[1] = 'l';
    name[2] = 't';
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%03d : %c%c%c",
           record->event.key.row, record->event.key.col,
           keycode, name[0], name[1], name[2]);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
