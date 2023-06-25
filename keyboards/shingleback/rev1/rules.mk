# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   comment out to disable the options.
#

EXTRAFLAGS += -flto

STENO_ENABLE = yes
DIP_SWITCH_ENABLE = yes
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes

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
