#include QMK_KEYBOARD_H

//defining the custom joystick buttons
enum custom_keycodes {
    JS_UP = SAFE_RANGE,
    JS_DN,
    JS_LF,
    JS_RT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
	     JS_0,   DM_REC1, TG(1), DM_PLY1,   JS_1,
    JS_2,     JS_3,                    JS_4,     JS_5,
		 JS_6,         JS_7, JS_8,          JS_9
	),
	[1] = LAYOUT(
	     JS_UP,   DM_REC1, TG(1), DM_PLY1,   JS_1,
    JS_LF,    JS_RT,                    JS_4,     JS_5,
		 JS_DN,         JS_7, JS_8,          JS_9
	)
};

enum layer_names {
    L_BASE,
    L_JOYS
};

//setting up virtual joystick
joystick_config_t joystick_axis[JOYSTICK_AXIS_COUNT] = {
    JOYSTICK_AXIS_VIRTUAL,
    JOYSTICK_AXIS_VIRTUAL
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case JS_UP:
            joystick_set_axis(1, 127);
            return false;
        case JS_DN:
            joystick_set_axis(1, -127);
            return false;
        case JS_LF:
            joystick_set_axis(0, -127);
            return false;
        case JS_RT:
            joystick_set_axis(0, 127);
            return false;
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
            writePinHigh(B0);
            writePinHigh(D5);
            break;
        case L_JOYS:
            writePinLow(B0);
            writePinHigh(D5);
            break;
    }
    return state;
}
