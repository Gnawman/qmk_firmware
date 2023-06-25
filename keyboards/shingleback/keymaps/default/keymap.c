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
#define QUOT_CTL    LCTL_T(KC_QUOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
             KC_W,    KC_F,    KC_P,    KC_B,                           KC_J,    KC_L,    KC_U,    KC_Y,
    A_CTL,   R_GUI,   S_ALT,   KC_T,    KC_G,                           KC_M,    KC_N,    E_ALT,   I_GUI,   O_CTL,
    KC_Q,    KC_X,    KC_C,    KC_D,    KC_MPLY,                                 KC_H,    KC_K,    KC_V,    KC_Z,
    KC_NO,   TG(4),   TG(3),   MO(2),   ENT_LAY1, KC_LSFT,     KC_SPC,  KC_TAB,  MO(2)
  ),

  [1] = LAYOUT(
             KC_7,    KC_8,    KC_9,    _______,                        KC_GRV, KC_SCLN, KC_SLSH, KC_BSLS,
    KC_BSPC, KC_4,    KC_5,    KC_6,    KC_0,                           KC_EQL, KC_COMM, KC_DOT,  KC_MINS, QUOT_CTL,
    KC_DEL,  KC_1,    KC_2,    KC_3,    KC_MPLY,                                 KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,
    KC_NO,   TG(4),   TG(3),   _______, _______,  _______,     _______, _______, _______
  ),

  [2] = LAYOUT(
             KC_F7,   KC_F8,   KC_F9,   KC_F10,                         _______, KC_HOME, KC_UP,   KC_END,
    KC_F13,  KC_F4,   KC_F5,   KC_F6,   KC_F11,                         KC_ESC,  KC_LEFT, KC_DOWN, KC_RIGHT, _______,
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_MPLY,                                 _______, KC_APP,  _______,  _______,
    KC_NO,   TG(4),   TG(3),   _______, _______,  _______,     _______, _______, _______
  ),

  [3] = LAYOUT(
             STN_TL,  STN_PL,  STN_HL,  STN_STR,                        STN_FR,  STN_PR,  STN_LR,  _______,
    STN_SL,  STN_KL,  STN_WL,  STN_RL,  STN_STR,                        STN_RR,  STN_BR,  STN_GR,  STN_TR,   STN_DR,
    STN_SL,  _______, _______, _______, KC_MPLY,                                 _______, _______, STN_SR,   STN_ZR,
    KC_NO,   TG(4),   TG(3),   STN_A,   STN_O,    _______,     STN_E,   STN_U,   _______
  ),

  [4] = LAYOUT(
             KC_1,    KC_2,    KC_3,    KC_4,                           _______, _______, _______, _______,
    KC_LSFT, KC_Q,    KC_E,    KC_SPC,  KC_F,                           _______, _______, _______, _______, _______,
    KC_LCTL, KC_C,    KC_V,    KC_R,    KC_MPLY,                                 _______, _______, _______, _______,
    KC_NO,   TG(4),   TG(3),   KC_ESC,  KC_I,     KC_ENT,      _______, _______, _______
  )

};

enum layer_names {
    L_BASE,
    L_SYMB,
    L_NAVG,
    L_STNO,
    L_GAME
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [L_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [L_SYMB] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [L_NAVG] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [L_STNO] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [L_GAME] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif

void keyboard_pre_init_user(void) {
    setPinOutput(D5);  // initialize D5 for LED
    setPinOutput(B0);  // initialize B0 for LED
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case L_BASE:
            writePinHigh(B0);
            writePinHigh(D5);
            break;
        case L_SYMB:
            writePinLow(B0);
            writePinHigh(D5);
            break;
        case L_NAVG:
            writePinHigh(B0);
            writePinLow(D5);
            break;
        case L_STNO:
            writePinLow(B0);
            writePinHigh(D5);
            break;
        case L_GAME:
            writePinHigh(B0);
            writePinLow(D5);
            break;
    }
    return state;
}
