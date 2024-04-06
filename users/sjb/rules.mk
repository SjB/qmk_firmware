LTO_ENABLE = yes
LINK_TIME_OPTIMIZATION_ENABLE = yes
BOOTMAGIC_ENABLE = lite
NKRO_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
COMBO_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
KEY_LOCK_ENABLE = no
LAYER_LOCK_ENABLE = no
SEND_STRING_ENABLE = no
UNICODE_ENABLE = no
CAPS_WORD_ENABLE = yes
REPEAT_KEY_ENABLE = yes
SB_SHIFTED_BACKSPACE = yes
SB_THUMB_TAB = no
SB_SPECIAL_KEY = yes
SB_HRL = yes # homerow layer
SB_LAYER_SWITCH_COMBO_KEY = no
SB_HR_COMBO_KEY = no
SB_THUMB_SUPER = no

SRC += sjb.c

ifeq ($(strip $(CALLUM_ONESHOT_ENABLE)), yes)
SRC += oneshot.c
OPT_DEFS += -DCALLUM_ONESHOT_ENABLE
endif

ifeq ($(strip $(LAYER_LOCK_ENABLE)), yes)
SRC += layer_lock.c
OPT_DEFS += -DLAYER_LOCK_ENABLE
endif

ifeq ($(strip $(COMBO_ENABLE)), yes)
INTROSPECTION_KEYMAP_C += combos.c
endif

ifeq ($(strip $(ENCODER_ENABLE)), yes)
SRC += encoder.c
OPT_DEFS += -DENCODER_ENABLE
endif

ifeq ($(strip $(SB_SHIFTED_BACKSPACE)), yes)
OPT_DEFS += -DSB_SHIFTED_BACKSPACE
endif

ifeq ($(strip $(SB_THUMB_TAB)), yes)
OPT_DEFS += -DSB_THUMB_TAB
endif

ifeq ($(strip $(SB_SPECIAL_KEY)), yes)
OPT_DEFS += -DSB_SPECIAL_KEY
endif

ifeq ($(strip $(SB_HRL)), yes)
OPT_DEFS += -DSB_HRL
endif

ifeq ($(strip $(SB_LAYER_SWITCH_COMBO_KEY)), yes)
OPT_DEFS += -DSB_LAYER_SWITCH_COMBO_KEY
endif

ifeq ($(strip $(SB_HR_COMBO_KEY)), yes)
OPT_DEFS += -DSB_HR_COMBO_KEY
endif

ifeq ($(strip $(SB_THUMB_SUPER)), yes)
OPT_DEFS += -DSB_THUMB_SUPER
endif
