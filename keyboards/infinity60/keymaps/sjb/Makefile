

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE ?= no      # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE ?= no        # Mouse keys(+4700)
EXTRAKEY_ENABLE ?= yes       # Audio control and System control(+450)
CONSOLE_ENABLE ?= no         # Console for debug(+400)
COMMAND_ENABLE ?= no         # Commands for debug and configuration
KEYBOARD_LOCK_ENABLE ?= no   # Allow locking of keyboard via magic key
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE ?= no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE ?= yes           # USB Nkey Rollover
BACKLIGHT_ENABLE ?= no       # Enable keyboard backlight functionality
MIDI_ENABLE ?= no            # MIDI controls
UNICODE_ENABLE ?= no         # Unicode
BLUETOOTH_ENABLE ?= no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE ?= no           # Audio output on port C6
TAP_DANCE_ENABLE = yes
QK_FUNCTION_ENABLE = yes

ifeq (${TAP_DANCE_ENABLE},yes)
SRC += tap_dance_extra.c
endif

ifeq (${QK_FUNCTION_ENABLE},yes)
OPT_DEFS += -DUSING_QK_FUNCTION
endif

KEYMAP_VERSION = $(shell \
 if [ -d "${KEYMAP_PATH}/.git" ]; then \
  cd "${KEYMAP_PATH}" && git describe --abbrev=6 --dirty --always --tags --match 'v*' 2>/dev/null; \
 else echo QMK; fi)

KEYMAP_BRANCH = $(shell \
 if [ -d "${KEYMAP_PATH}/.git" ]; then \
  cd "${KEYMAP_PATH}"; \
 fi; \
 git rev-parse --abbrev-ref HEAD 2>/dev/null)

GIT_REV = $(shell git rev-parse --short HEAD 2>/dev/null)

OPT_DEFS += -DKEYMAP_VERSION=\"$(KEYMAP_VERSION)\\\#$(KEYMAP_BRANCH)\" -DGIT_REV=\"$(GIT_REV)\"

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
