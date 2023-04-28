#include QMK_KEYBOARD_H
#include "keymap_steno.h"
#include <stdio.h>

// L0 layer switches
#define ENT_LAY1    LT(1,KC_ENT)

// home row mods
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

  [0] = LAYOUT(
             KC_W,    KC_F,    KC_P,     KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,
             R_GUI,   S_ALT,   T_SFT,    KC_G,                         KC_M,    N_SFT,   E_ALT,   I_GUI,
    A_CTL,   KC_X,    KC_C,    KC_D,                                            KC_H,    KC_K,    KC_V,     O_CTL,
    KC_Q,                      ENT_LAY1, KC_LSFT, KC_BTN1,    KC_TAB,  KC_SPC,  MO(2),                      KC_Z
  ),

  [1] = LAYOUT(
             KC_7,    KC_8,    KC_9,     _______,                      KC_LBRC, KC_SCLN, KC_SLSH, KC_BSLS,
             KC_4,    KC_5,    KC_6,     KC_0,                         KC_RBRC, KC_COMM, KC_DOT,  KC_MINS,
    KC_BSPC, KC_1,    KC_2,    KC_3,                                           KC_LPRN, KC_RPRN, KC_EQL,    QUOT_CTL,
    KC_DEL,                    _______,  _______, _______,    _______, _______, _______,                    KC_GRV
  ),

  [2] = LAYOUT(
             KC_F7,   KC_F8,   KC_F9,    KC_F10,                       _______, KC_HOME, KC_UP,   KC_END,
             KC_F4,   KC_F5,   KC_F6,    KC_F11,                       KC_ESC,  KC_LEFT, KC_DOWN, KC_RIGHT,
    KC_F12,  KC_F1,   KC_F2,   KC_F3,                                           KC_BTN1, KC_APP,  KC_BTN2,  _______,
    KC_F13,                    _______,  _______, _______,    _______, _______, _______,                    TG(3)
  ),

  [3] = LAYOUT(
             KC_1,    KC_2,    KC_3,     KC_4,                         _______, _______, _______, _______,
             KC_Q,    KC_E,    KC_F,     KC_SPC,                       _______, _______, _______, _______,
    KC_LSFT, KC_C,    KC_V,    KC_R,                                            _______, _______, _______,  _______,
    KC_LCTL,                   KC_ESC,   KC_ENT,  KC_TAB,     _______, _______, _______,                    TG(3)
  )

};

enum layer_names {
    L_BASE,
    L_SYMB,
    L_NAVG,
    L_GAME
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [L_BASE] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)            },
    [L_SYMB] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)  },
    [L_NAVG] = { ENCODER_CCW_CW(KC_RIGHT, KC_LEFT),          ENCODER_CCW_CW(KC_UP, KC_DOWN)              },
    [L_GAME] = { ENCODER_CCW_CW(KC_UP, KC_DOWN),             ENCODER_CCW_CW(KC_RIGHT, KC_LEFT)           },
};
#endif

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
            if (active) {
                tap_code(KC_A);
            } else { }
        }
        case 1: {
            if (active) {
                tap_code(KC_B);
            } else { }
        }
    }
    return true;
};

void keyboard_pre_init_user(void) {
    setPinOutput(D5);  // initialize D5 for LED
    setPinOutput(B0);  // initialize B0 for LED
};

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
