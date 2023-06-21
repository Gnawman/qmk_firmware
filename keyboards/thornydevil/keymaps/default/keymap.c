#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
	     JS_0,   DM_REC1, TG(1), DM_PLY1,   JS_1,
    JS_2,     JS_3,                    JS_4,     JS_5,
		 JS_6,         JS_7, JS_8,          JS_7
	),
	[1] = LAYOUT(
	     JS_0,   DM_REC1, TG(1), DM_PLY1,   JS_1,
    JS_2,     JS_3,                    JS_4,     JS_5,
		 JS_6,         JS_7, JS_8,          JS_7
	)
};

enum layer_names {
    L_BASE,
    L_JOYS
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
        case L_JOYS:
            writePinLow(B0);
            writePinLow(D5);
            break;
    }
    return state;
}
