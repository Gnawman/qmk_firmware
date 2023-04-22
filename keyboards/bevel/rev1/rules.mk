# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina



# Build Options
#   change yes to no to disable
#
EXTRAFLAGS += -flto

MOUSEKEY_ENABLE = NO       # Mouse keys
EXTRAKEY_ENABLE = NO       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = NO
AUDIO_ENABLE = no           # Audio output
OLED_ENABLE = no
WPM_ENABLE = NO
ENCODER_ENABLE = NO
COMBO_ENABLE = NO
LEADER_ENABLE = no
MIDI_ENABLE = no
BLUETOOTH_ENABLE = no
SWAP_HANDS_ENABLE = no
UNICODE_ENABLE = no


SPLIT_KEYBOARD = yes
NKRO_ENABLE = yes
LTO_ENABLE = yes
STENO_ENABLE = yes
TAP_DANCE_ENABLE = YES
