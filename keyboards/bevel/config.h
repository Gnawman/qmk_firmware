/*
Copyright 2022 gnawman

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0x7178
#define PRODUCT_ID   0x0000
#define DEVICE_VER   0x0002
#define MANUFACTURER gnawman
#define PRODUCT      bevel

// configs for split keyboard
#define USE_SERIAL
#define SOFT_SERIAL_PIN D3
#define SPLIT_USB_DETECT
#define SPLIT_LAYER_STATE_ENABLE

/* Select hand configuration */
#define MASTER_LEFT

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 5

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 *
*/

#define DIRECT_PINS { { D4, F6, D0, F5, D1 }, { F7, C6, B1, D7, B3 }, { E6, B2, B4, B6, B5 } }
#define DIRECT_PINS_RIGHT { { D1, F5, D0, F6, D4 }, { B3, D7, B1, C6, F7 }, { B5, B6, B4, B2, E6 } }
#define UNUSED_PINS

// Tapdance prefs
#define TAPPING_TERM 300
#define TAPPING_TERM_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 */

#define FORCE_NKRO

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
