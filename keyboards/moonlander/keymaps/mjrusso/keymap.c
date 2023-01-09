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

#include "oneshot.h"
#include "appswitcher.h"

enum layers {
    BASE,
    NAV,
    NUM,
    SYM,
    FUN,
    MOUSE,
    MACRO,
    KEEB,
    SPEC // "Special" layer, with WASD + arrow keys (with the arrow keys
         // arranged in a standard inverted 'T' pattern), plus media keys and a
         // few other niceties. This is useful for a variety of activities,
         // such as gaming, navigating through slide decks, etc., because it is
         // configured to be toggled on/off (vs. only activating when a key is
         // held).
};

#define LA_NAV MO(NAV)
#define LA_NUM MO(NUM)
#define LA_SYM MO(SYM)
#define LA_FUN MO(FUN)
#define LA_MOUSE MO(MOUSE)
#define LA_MACRO MO(MACRO)
#define LA_KEEB MO(KEEB)

#define BACK LCMD(KC_LBRC) // Backwards
#define FWD LCMD(KC_RBRC) // Forwards
#define TAB_L LCMD(LSFT(KC_LBRC)) // Move to left tab
#define TAB_R LCMD(LSFT(KC_RBRC)) // Move to right tab
#define SEL_L LCMD(LSFT(KC_LEFT)) // Select all text to the left
#define SEL_R LCMD(LSFT(KC_RGHT)) // Select all text to the right
#define DEL_W LALT(KC_BSPC) // Delete word
#define SSHOT LCMD(LSFT(KC_4)) // Screenshot region
#define SCOOT LCMD(LSFT(KC_J)) // Launch Scoot
#define SNAP_L LCTL(LALT(KC_LEFT)) // Snap window to left
#define SNAP_R LCTL(LALT(KC_RGHT)) // Snap window to right
#define ONEPWD LCMD(KC_BSLS) // Launch 1Password

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,

    // Callum's custom oneshot mod implementation with no timers.
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    APP_SW_N,  // Switch to next app (cmd-tab)
    APP_SW_P,  // Switch to prev app (cmd-`)
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_moonlander(
        _______, _______, _______, _______,  _______,          _______, _______,                 _______,  _______, _______,         _______,  _______, _______, _______,
        KC_TAB,  KC_Q,    KC_W,    KC_E,     KC_R,             KC_T,    _______,                 _______,  KC_Y,    KC_U,            KC_I,    KC_O,    KC_P,     KC_GRAVE,
        KC_LCTL, KC_A,    KC_S,    KC_D,     KC_F,             KC_G,    _______,                 _______,  KC_H,    KC_J,            KC_K,    KC_L,    KC_QUOT,  _______,
        KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,             KC_B,                                       KC_N,    KC_M,            KC_COMM, KC_DOT,  KC_SLSH,  _______,
        _______, _______, _______, KC_LALT,  KC_LCMD,          KC_ESC,                           TG(SPEC),          LT(NUM, KC_SPC), LA_FUN,   _______, _______, _______,
                                             LT(NAV, KC_BSPC), _______, _______,                 _______,  _______, LT(SYM, KC_ENT)
    ),

   [NAV] = LAYOUT_moonlander(
        _______, _______, _______, _______,  _______,  _______, _______,                 _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,  _______,  _______, _______,                 _______, KC_HOME, BACK,    TAB_L,   TAB_R,   FWD,     _______,
        _______, OS_CTRL, OS_ALT,  OS_SHFT,  OS_CMD,   _______, _______,                 _______, KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, _______, _______, APP_SW_P, APP_SW_N, _______,                                   KC_END,  SEL_L,   KC_PGDN, KC_PGUP, SEL_R,   _______,
        _______, _______, _______, KC_TRNS,  KC_TRNS,           KC_TRNS,                 KC_TRNS,          KC_TRNS, KC_TRNS, _______, _______, _______,
                                             KC_TRNS,  KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS
    ),

   [NUM] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, _______,                 _______, _______, _______, _______, _______, _______, _______,
        _______, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  _______,                 _______, _______, OS_CMD,  OS_SHFT, OS_ALT,  OS_CTRL, _______,
        _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,                                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_DOT,  KC_0,             KC_TRNS,                 KC_TRNS,          KC_TRNS, KC_TRNS, _______, _______, _______,
                                            KC_MINS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS
    ),

   [SYM] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, _______,                _______, _______, _______, _______, _______, _______, _______,
        _______, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, _______,                _______, _______, OS_CMD,  OS_SHFT, OS_ALT,  OS_CTRL, _______,
        _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                                  _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_LPRN, KC_RPRN,          KC_TRNS,                KC_TRNS,          KC_TRNS, KC_TRNS, _______, _______, _______,
                                            KC_UNDS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [FUN] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, _______,
        _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   _______, _______,                 _______, _______, _______, _______, _______, _______, _______,
        _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   _______, _______,                 _______, _______, OS_CMD,  OS_SHFT, OS_ALT,  OS_CTRL, _______,
        _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   _______,                                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, DEL_W,   KC_BSPC,          KC_TRNS,                 KC_TRNS,          KC_TRNS, KC_TRNS, _______, _______, _______,
                                            KC_TAB,  KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS
   ),

   [MOUSE] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, _______,
        _______, OS_CTRL, OS_ALT,  OS_SHFT, OS_CMD,  _______, _______,                 _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
        _______, _______, _______, _______, _______, _______,                                   _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
        _______, _______, _______, KC_TRNS, KC_TRNS,          KC_TRNS,                 KC_TRNS,          KC_BTN3, KC_BTN2, _______, _______, _______,
                                            KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_BTN1
    ),

   [MACRO] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_VOLD, KC_MPRV, KC_MNXT, KC_VOLU, SSHOT,   _______,
        _______, OS_CTRL, OS_ALT,  OS_SHFT, OS_CMD,  _______, _______,           _______, _______, SNAP_L,  SNAP_R,  SCOOT,   _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, ONEPWD,  _______,
        _______, _______, _______, _______, _______,          _______,           _______,          KC_MUTE, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, KC_MPLY
    ),

    [KEEB] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,   _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, VRSN,    LED_LEVEL, RESET,   _______,
        _______, OS_CTRL, OS_ALT,  OS_SHFT, OS_CMD,  _______, _______,           _______, _______, _______, _______, _______,   RGB_TOG, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______,   RGB_MOD, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______,   _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [SPEC] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_W,    _______, _______, _______, _______,           _______, _______, _______, KC_UP,   _______, KC_MUTE, KC_VOLU,
        _______, KC_A,    KC_S,    KC_D,    _______, _______, _______,           _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_VOLD,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, KC_MPLY,
        _______, _______, _______, _______, _______,          _______,           _______,          KC_SPC,  _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, KC_ENT
    ),

};

void keyboard_post_init_user(void) {
    // Set the default RGB matrix effect.
    //
    // For all effects, see:
    // https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
    //
    // To disable entirely, pass in `RGB_MATRIX_NONE`.
    rgb_matrix_mode_noeeprom(RGB_MATRIX_PIXEL_RAIN);
}

// Use RGB to indicate which layer we're on.
//
// For documentation, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=indicator-examples
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case 0:
            case 1:
            case 2:
            case 3:
                break;
            case 4:
            case 5:
            case 6:
            case 7:
                rgb_matrix_set_color(i, RGB_TURQUOISE);
                break;
            case 8:
                rgb_matrix_set_color(i, RGB_BLUE);
                break;
            default:
                rgb_matrix_set_color(i, RGB_OFF);
                break;
        }
    }
    return false;
}

// Defines the keys to cancel oneshot mods.
bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_NAV:
    case LA_NUM:
    case LA_SYM:
    case LA_FUN:
    case LA_MOUSE:
    case LA_MACRO:
    case LA_KEEB:
        return true;
    default:
        return false;
    }
}

// Defines keys to ignore when determining whether a oneshot mod has been used.
bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_NAV:
    case LA_NUM:
    case LA_SYM:
    case LA_FUN:
    case LA_MOUSE:
    case LA_MACRO:
    case LA_KEEB:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

bool app_switcher_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }

    update_app_switcher(
        &app_switcher_active, APP_SW_N, APP_SW_P,
        keycode, record
    );

    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );

    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );

    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );

    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;
}
