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
        KC_1,   KC_2,   KC_3,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,      KC_1,   KC_2,   KC_3,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,
        KC_A,   KC_B,   KC_C,   KC_D,   KC_E,   KC_F,   KC_G,   KC_H,   KC_I,      KC_A,   KC_B,   KC_C,   KC_D,   KC_E,   KC_F,   KC_G,   KC_H,   KC_I,
        KC_K,   KC_L,   KC_M,   KC_N,   KC_O,   KC_P,   KC_Q,   KC_R,   KC_S,      KC_K,   KC_L,   KC_M,   KC_N,   KC_O,   KC_P,   KC_Q,   KC_R,   KC_S,
        KC_U,   KC_V,   KC_W,   KC_X,   KC_Y,   KC_Z,   KC_1,   KC_2,   KC_3,      KC_U,   KC_V,   KC_W,   KC_X,   KC_Y,   KC_Z,   KC_1,   KC_2,   KC_3,
                                                        KC_5,   KC_6,   KC_7,      KC_8,   KC_9,   KC_0
    ),

    [1] = LAYOUT(
        KC_1,   KC_2,   KC_3,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,      KC_1,   KC_2,   KC_3,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,
        KC_A,   KC_B,   KC_C,   KC_D,   KC_E,   KC_F,   KC_G,   KC_H,   KC_I,      KC_A,   KC_B,   KC_C,   KC_D,   KC_E,   KC_F,   KC_G,   KC_H,   KC_I,
        KC_K,   KC_L,   KC_M,   KC_N,   KC_O,   KC_P,   KC_Q,   KC_R,   KC_S,      KC_K,   KC_L,   KC_M,   KC_N,   KC_O,   KC_P,   KC_Q,   KC_R,   KC_S,
        KC_U,   KC_V,   KC_W,   KC_X,   KC_Y,   KC_Z,   KC_1,   KC_2,   KC_3,      KC_U,   KC_V,   KC_W,   KC_X,   KC_Y,   KC_Z,   KC_1,   KC_2,   KC_3,
                                                        KC_5,   KC_6,   KC_7,      KC_8,   KC_9,   KC_0
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
    L_GAME
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)            },
    [_SYMB] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)  },
    [_NAVG] = { ENCODER_CCW_CW(KC_RIGHT, KC_LEFT),          ENCODER_CCW_CW(KC_UP, KC_DOWN)              },
    [_GAME] = { ENCODER_CCW_CW(KC_UP, KC_DOWN),             ENCODER_CCW_CW(KC_RIGHT, KC_LEFT)           },
};
#endif

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
            if (active) {
                tap_code(KC_A);
            } else {

            }
        }
        case 1: {
            if (active) {
                tap_code(KC_B);
            } else {

            }
        }
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
