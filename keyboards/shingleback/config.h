#pragma once

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 8

/* key matrix pins */
#define MATRIX_ROW_PINS { B1, B3, B2, B6 }
#define MATRIX_COL_PINS { D1, D0, D4, C6, D7, E6, B4, B5 }

#define DIP_SWITCH_PINS { F4, F7 }

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

//makes steno work properly
#define USE_SERIAL_PD2
#define FORCE_NKRO
