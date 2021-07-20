/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
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
#include "version.h"

enum layers {
    BASE,
    NAV,
    NUM,
    SYM,
    FUN,
    MOUSE,
    MACRO,
    KEEB
};

#define LA_NAV MO(NAV)
#define LA_NUM MO(NUM)
#define LA_FUN MO(FUN)
#define LA_MOUSE MO(MOUSE)
#define LA_MACRO MO(MACRO)
#define LA_KEEB MO(KEEB)


enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [BASE] = LAYOUT_moonlander(
        KC_GRAVE, _______, _______, _______, _______, _______, _______,                 _______, _______, _______,         _______,         _______, _______, _______,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,                 _______, KC_Y,    KC_U,            KC_I,            KC_O,    KC_P,    _______,
        KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,                 _______, KC_H,    KC_J,            KC_K,            KC_L,    KC_QUOT, _______,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                      KC_N,    KC_M,            KC_COMM,         KC_DOT,  KC_SLSH, _______,
        KC_LCTL,  _______, _______, KC_LOPT, KC_LCMD,          LA_KEEB,                 LA_KEEB,          LT(NUM, KC_SPC), LT(FUN, KC_ESC), _______, _______, _______,
                                             LT(NAV, KC_BSPC), LA_MOUSE, LA_MACRO,      LA_NUM,  LA_NAV,  LT(SYM, KC_ENT)

    ),

   //TODO right hand side
   [NAV] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LSFT, KC_LCTL, KC_LOPT, KC_LCMD, _______, _______,                _______, _______, KC_RCMD, KC_ROPT, KC_RCTL, KC_RSFT, _______,
        _______, _______, _______, _______, _______, _______,                                  _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_TRNS, KC_TRNS,          KC_TRNS,                KC_TRNS,          KC_TRNS, KC_TRNS, _______, _______, _______,
                                            KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS
    ),


   [NUM] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, _______,                _______, _______, _______, _______, _______, _______, _______,
        _______, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  _______,                _______, _______, KC_RCMD, KC_ROPT, KC_RCTL, KC_RSFT, _______,
        _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,                                  _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_DOT,  KC_0,             KC_TRNS,                KC_TRNS,          KC_TRNS, KC_TRNS, _______, _______, _______,
                                            KC_MINS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS
    ),

   [SYM] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, _______,                _______, _______, _______, _______, _______, _______, _______,
        _______, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, _______,                _______, _______, KC_RCMD, KC_ROPT, KC_RCTL, KC_RSFT, _______,
        _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                                  _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_LPRN, KC_RPRN,          KC_TRNS,                KC_TRNS,          KC_TRNS, KC_TRNS, _______, _______, _______,
                                            KC_UNDS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS
    ),


   // TODO
   [FUN] = LAYOUT_moonlander(
        _______, _______, _______,  _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, _______,                _______, _______, _______, _______, _______, _______, _______,
        _______, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, _______,                _______, _______, KC_RCMD, KC_ROPT, KC_RCTL, KC_RSFT, _______,
        _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                                  _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_LPRN, KC_RPRN,          KC_TRNS,                KC_TRNS,          KC_TRNS, KC_TRNS, _______, _______, _______,
                                            KC_UNDS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS
    ),

   // TODO
   [MOUSE] = LAYOUT_moonlander(
        _______, _______, _______,  _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, _______,                _______, _______, _______, _______, _______, _______, _______,
        _______, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, _______,                _______, _______, KC_RCMD, KC_ROPT, KC_RCTL, KC_RSFT, _______,
        _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                                  _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_LPRN, KC_RPRN,          KC_TRNS,                KC_TRNS,          KC_TRNS, KC_TRNS, _______, _______, _______,
                                            KC_UNDS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS
    ),

   // TODO
    [MACRO] = LAYOUT_moonlander(
        LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, RESET,
        VRSN, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, KC_MPLY,
        _______, _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN2,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    // TODO
    [KEEB] = LAYOUT_moonlander(
        LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        VRSN, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, RESET, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, KC_MPLY,
        _______, _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN2,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}
