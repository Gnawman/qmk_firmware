// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// home row mods
#define A_CTL       LCTL_T(KC_A)
#define O_CTL       LCTL_T(KC_O)
#define R_GUI       LGUI_T(KC_R)
#define I_GUI       LGUI_T(KC_I)
#define S_ALT       LALT_T(KC_S)
#define E_ALT       LALT_T(KC_E)
#define QUOT_CTL    LCTL_T(KC_QUOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_8x5(
                 KC_ENT,   KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_TAB,
    G(S(KC_S)),  A_CTL,    R_GUI,   S_ALT,   KC_T,    KC_G,                      KC_M,    KC_N,    E_ALT,   I_GUI,   O_CTL,
    QK_BOOT,     KC_Q,     KC_X,    KC_C,    KC_D,    KC_LSFT, MO(1),   MO(2),   KC_SPC,  KC_H,    KC_K,    KC_V,    KC_Z
    ),

    [1] = LAYOUT_ortho_8x5(
                 _______,  KC_7,    KC_8,    KC_9,    _______,                   KC_GRV,  KC_SCLN, KC_SLSH, KC_BSLS, _______,
    G(S(KC_S)),  KC_BSPC,  KC_4,    KC_5,    KC_6,    KC_0,                      KC_EQL,  KC_COMM, KC_DOT,  KC_MINS, QUOT_CTL,
    QK_BOOT,     KC_DEL,   KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC
    ),

    [2] = LAYOUT_ortho_8x5(
                 KC_F14,   KC_F7,   KC_F8,   KC_F9,   KC_F11,                    _______, KC_HOME, KC_UP,   KC_END,  _______,
    G(S(KC_S)),  KC_F13,   KC_F4,   KC_F5,   KC_F6,   KC_F10,                    KC_ESC,  KC_LEFT, KC_DOWN, KC_RIGHT,_______,
    QK_BOOT,     KC_F12,   KC_F1,   KC_F2,   KC_F3,   _______, _______, _______, _______, KC_PGUP, KC_APP,  KC_PGDN, _______
    )
};

enum layer_names {
    L_BASE,
    L_SYMB,
    L_NAVG
};

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
    }
    return state;
}
