/* Copyright 2022 gnawman
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
#include "keymap_steno.h"
#include <stdio.h>

// L0 layer switches
#define SPC_SFT     LSFT_T(KC_SPACE)
#define ENT_LAY1    LT(1,KC_ENT)
#define TAB_LAY2    LT(2,KC_TAB)

// L0 home row mods
#define A_CTL       LCTL_T(KC_A)
#define O_CTL       LCTL_T(KC_O)
#define R_GUI       LGUI_T(KC_R)
#define I_GUI       LGUI_T(KC_I)
#define S_ALT       LALT_T(KC_S)
#define E_ALT       LALT_T(KC_E)
#define T_SFT       LSFT_T(KC_T)
#define N_SFT       LSFT_T(KC_N)
#define QUOT_CTL    LCTL_T(KC_QUOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [0] = LAYOUT(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                          KC_J,     KC_L,     KC_U,      KC_Y,    KC_Z,
        A_CTL,   R_GUI,   S_ALT,   T_SFT,   KC_G,                          KC_M,     N_SFT,    E_ALT,     I_GUI,   O_CTL,
                 KC_X,    KC_C,    KC_D,    ENT_LAY1, KC_LSFT,   KC_SPACE, TAB_LAY2, KC_H,     KC_K,      KC_V
    ),

    [1] = LAYOUT(
        KC_DEL,  KC_7,    KC_8,    KC_9,  KC_DOT,                          _______, KC_SCLN, KC_SLASH, KC_BSLASH, KC_GRAVE,
        KC_BSPC, KC_4,    KC_5,    KC_6,  KC_0,                            KC_EQL,  KC_COMM, KC_DOT,   KC_MINS,   QUOT_CTL,
                 KC_1,    KC_2,    KC_3,  _______,    _______,    _______, KC_LBRC, KC_LPRN, KC_RPRN,  KC_RBRC
    ),

    [2] = LAYOUT(
        RESET,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                       _______, KC_HOME, KC_UP,    KC_END,    _______,
        _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,                       KC_ESC,  KC_LEFT, KC_DOWN,  KC_RIGHT,  _______,
                 KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,    _______, _______, _______, KC_APP,   TG(3)
    ),

    [3] = LAYOUT(
        STN_SL,  STN_TL,  STN_PL,  STN_HL,  STN_STR,                      STN_FR,  STN_PR,  STN_LR,   STN_TR,    STN_DR,
        STN_SL,  STN_KL,  STN_WL,  STN_RL,  STN_STR,                      STN_RR,  STN_BR,  STN_GR,   STN_SR,    STN_ZR,
                 _______, _______, STN_A,   STN_O,   _______,    STN_E,   STN_U,   _______, _______,  TG(3)
    )
};

// tapping term per key code
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ENT_LAY1:
            return 180;
        case SPC_SFT:
            return 180;
        default:
            return TAPPING_TERM;
    }
}

enum layer_names {
    L_BASE,
    L_SYMB,
    L_NAVG,
    L_STNO
};

void keyboard_pre_init_user(void) {
    setPinOutput(D5);  // initialize D5 for LED
    setPinOutput(B0);  // initialize B0 for LED
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case L_BASE:
            writePinHigh(D5);
            writePinHigh(B0);
            break;
        case L_SYMB:
            writePinHigh(D5);
            writePinLow(B0);
            break;
        case L_NAVG:
            writePinHigh(B0);
            writePinLow(D5);
            break;
        case L_STNO:
            writePinLow(B0);
            writePinLow(D5);
            break;
    }
    return state;
}
