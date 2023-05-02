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

// custom keycode example
/*
#define SPC_SFT     LSFT_T(KC_SPACE)
#define ENT_LAY1    LT(1,KC_ENT)
#define TAB_LAY2    LT(2,KC_TAB)
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [0] = LAYOUT(
        KC_F10, KC_F11, KC_F12,   KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,       KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    KC_EQL,     KC_BSPC, KC_0,   KC_BSLS,
        KC_F7,  KC_F8,  KC_F9,    KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_MINS,    KC_7,    KC_8,   KC_9,
        KC_F4,  KC_F5,  KC_F6,    KC_CAPS, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,       KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,    KC_4,    KC_5,   KC_6,
        KC_F1,  KC_F2,  KC_F3,    KC_DEL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,       KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_LSFT,    KC_1,    KC_2,   KC_3,
                                                            KC_LCTL, KC_RGUI, KC_LSFT,    KC_SPC, KC_ENT, KC_LALT
    ),

    [1] = LAYOUT(
        _______, _______, _______,   _______, _______, _______, _______, _______, _______,   _______, _______, _______, KC_LBRC, KC_RBRC, _______,  _______, _______, _______,
        _______, _______, _______,   _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,  KC_HOME, KC_UP,   KC_END,
        _______, _______, _______,   _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,  KC_LEFT, KC_DOWN, KC_RGHT,
        _______, _______, _______,   _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,  _______, KC_APP, _______,
                                                                _______, _______, _______,   _______, _______, _______
    ),

    [2] = LAYOUT(
        KC_1,   KC_2,   KC_3,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,      KC_1,   KC_2,   KC_3,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,
        KC_A,   KC_B,   KC_C,   KC_D,   KC_E,   KC_F,   KC_G,   KC_H,   KC_I,      KC_A,   KC_B,   KC_C,   KC_D,   KC_E,   KC_F,   KC_G,   KC_H,   KC_I,
        KC_K,   KC_L,   KC_M,   KC_N,   KC_O,   KC_P,   KC_Q,   KC_R,   KC_S,      KC_K,   KC_L,   KC_M,   KC_N,   KC_O,   KC_P,   KC_Q,   KC_R,   KC_S,
        KC_U,   KC_V,   KC_W,   KC_X,   KC_Y,   KC_Z,   KC_1,   KC_2,   KC_3,      KC_U,   KC_V,   KC_W,   KC_X,   KC_Y,   KC_Z,   KC_1,   KC_2,   KC_3,
                                                        KC_5,   KC_6,   KC_7,      KC_8,   KC_9,   KC_0
    ),

    [3] = LAYOUT(
        KC_1,   KC_2,   KC_3,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,      KC_1,   KC_2,   KC_3,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,
        KC_A,   KC_B,   KC_C,   KC_D,   KC_E,   KC_F,   KC_G,   KC_H,   KC_I,      KC_A,   KC_B,   KC_C,   KC_D,   KC_E,   KC_F,   KC_G,   KC_H,   KC_I,
        KC_K,   KC_L,   KC_M,   KC_N,   KC_O,   KC_P,   KC_Q,   KC_R,   KC_S,      KC_K,   KC_L,   KC_M,   KC_N,   KC_O,   KC_P,   KC_Q,   KC_R,   KC_S,
        KC_U,   KC_V,   KC_W,   KC_X,   KC_Y,   KC_Z,   KC_1,   KC_2,   KC_3,      KC_U,   KC_V,   KC_W,   KC_X,   KC_Y,   KC_Z,   KC_1,   KC_2,   KC_3,
                                                        KC_5,   KC_6,   KC_7,      KC_8,   KC_9,   KC_0
    )
};

// tapping term per key code example
/*
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
*/

enum layer_names {
    L_BASE,
    L_SYMB,
    L_NAVG,
    L_GAME
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [L_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),   ENCODER_CCW_CW(KC_PGUP, KC_PGDN)   },
    [L_SYMB] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),   ENCODER_CCW_CW(KC_PGUP, KC_PGDN)   },
    [L_NAVG] = { ENCODER_CCW_CW(KC_RIGHT, KC_LEFT),  ENCODER_CCW_CW(KC_UP, KC_DOWN)     },
    [L_GAME] = { ENCODER_CCW_CW(KC_UP, KC_DOWN),     ENCODER_CCW_CW(KC_RIGHT, KC_LEFT)  },
};
#endif

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if(active) { tap_code16(KC_MUTE); } else { }
            break;
        case 1:
            if(active) { tap_code16(TG(1)); } else { }
            break;
    }
    return true;
}

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
        case L_GAME:
            writePinLow(B0);
            writePinLow(D5);
            break;
    }
    return state;
}
