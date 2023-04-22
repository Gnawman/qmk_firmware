#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x7178
#define PRODUCT_ID      0x0002
#define DEVICE_VER      0x0001
#define MANUFACTURER    gnawman
#define PRODUCT         shingleback

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 8

/* key matrix pins */
#define MATRIX_ROW_PINS { B1, B3, B2, B6 }
#define MATRIX_COL_PINS { D1, D0, D4, C6, D7, E6, B4, B5 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

// Tapdance prefs
#define TAPPING_TERM 300
#define TAPPING_TERM_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT

//makes steno work properly
#define USE_SERIAL_PD2
#define FORCE_NKRO


/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
