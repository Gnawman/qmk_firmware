#pragma once

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 8

/* key matrix pins */
#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { B1, B3, B2, B6, F4, F5, F6, F7 }

#define ENCODER_DIRECTION_FLIP

#define TAPPING_TERM 400
#define TAPPING_TERM_PER_KEY

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

//makes steno work properly
#define USE_SERIAL_PD2
#define FORCE_NKRO
