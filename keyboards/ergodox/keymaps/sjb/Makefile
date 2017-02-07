BOOTMAGIC_ENABLE ?= no
COMMAND_ENABLE ?= no
SLEEP_LED_ENABLE = no
FORCE_NKRO = yes
DEBUG_ENABLE = no
CONSOLE_ENABLE ?= no
TAP_DANCE_ENABLE = yes
UCIS_ENABLE = no
MOUSEKEY_ENABLE = yes
QK_FUNCTION_ENABLE = yes

ifeq (${DEBUG_ENABLE},yes)
OPT_DEFS += -DDEBUG_ENABLE -DUSER_PRINT
CONSOLE_ENABLE = yes
COMMAND_ENABLE = yes
endif

ifeq (${QK_FUNCTION_ENABLE},yes)
OPT_DEFS += -DUSING_QK_FUNCTION
endif

ifeq (${FORCE_NKRO},yes)
OPT_DEFS += -DFORCE_NKRO
endif

ifeq (${SUBPROJECT},infinity)
	VISUALIZER_ENABLE = yes
endif

ifeq (${TAP_DANCE_ENABLE},yes)
SRC += tap_dance_extra.c
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
