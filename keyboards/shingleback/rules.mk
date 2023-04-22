# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   comment out to disable the options.
#

EXTRAFLAGS += -flto

NKRO_ENABLE = yes		    # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
MOUSEKEY_ENABLE = yes	  # Mouse keys
EXTRAKEY_ENABLE = yes	  # Audio control and System control
ENCODER_ENABLE = yes
STENO_ENABLE = yes
TAP_DANCE_ENABLE = yes

CONSOLE_ENABLE = no	    # Console for debug
COMMAND_ENABLE = no     # Commands for debug and configuration
SLEEP_LED_ENABLE = no   # Breathing sleep LED during USB suspend
BACKLIGHT_ENABLE = no  # Enable keyboard backlight functionality
AUDIO_ENABLE = no
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = NO
OLED_ENABLE = no
WPM_ENABLE = NO
COMBO_ENABLE = NO
LEADER_ENABLE = no
MIDI_ENABLE = no
BLUETOOTH_ENABLE = no
SWAP_HANDS_ENABLE = no
UNICODE_ENABLE = no
SPLIT_KEYBOARD = no

# Disable unsupported hardware
RGBLIGHT_SUPPORTED = no
AUDIO_SUPPORTED = no
