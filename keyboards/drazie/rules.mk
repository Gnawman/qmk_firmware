# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
EXTRAFLAGS += -flto

SPLIT_KEYBOARD = yes
NKRO_ENABLE = yes
LTO_ENABLE = yes
TAP_DANCE_ENABLE = YES
EXTRAKEY_ENABLE = yes      # Audio control and System control
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes
DIP_SWITCH_ENABLE = yes

MOUSEKEY_ENABLE = NO       # Mouse keys
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
COMBO_ENABLE = NO
LEADER_ENABLE = no
MIDI_ENABLE = no
BLUETOOTH_ENABLE = no
SWAP_HANDS_ENABLE = no
UNICODE_ENABLE = no
STENO_ENABLE = no
