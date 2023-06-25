// Copyright 2023 gnawman (@gnawman)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// configs for split keyboard
#define USE_SERIAL
#define SOFT_SERIAL_PIN D3
#define SPLIT_USB_DETECT
#define SPLIT_LAYER_STATE_ENABLE

/* Select hand configuration */
#define MASTER_LEFT

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 9

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS { D2, D1, D0, D4, B1 }
#define MATRIX_COL_PINS { C6, D7, E6, B4, B5, F4, F5, F6, F7 }

// Connects each switch in the dip switch to the GPIO pin of the MCU
#define DIP_SWITCH_PINS { B3 }

// Tapdance prefs
#define TAPPING_TERM 300
#define TAPPING_TERM_PER_KEY

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
