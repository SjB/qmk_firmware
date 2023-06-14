NKRO_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
COMBO_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
BOOTMAGIC_ENABLE = yes
KEY_LOCK_ENABLE = yes
LAYER_LOCK_ENABLE = yes
LTO_ENABLE = yes
SEND_STRING_ENABLE = yes
CAPS_WORD_ENABLE = yes

SRC += sjb.c

ifeq ($(strip $(CALLUM_ONESHOT_ENABLE)), yes)
SRC += oneshot.c
endif

ifeq ($(strip $(LAYER_LOCK_ENABLE)), yes)
SRC += layer_lock.c
endif

ifeq ($(strip $(COMBO_ENABLE)), yes)
INTROSPECTION_KEYMAP_C += combos.c
endif

ifeq ($(strip $(ENCODER_ENABLE)), yes)
SRC += encoder.c
endif
