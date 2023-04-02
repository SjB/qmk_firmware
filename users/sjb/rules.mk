NKRO_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
COMBO_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
BOOTMAGIC_ENABLE = yes
KEY_LOCK_ENABLE = yes
LTO_ENABLE = yes
SEND_STRING_ENABLE = yes
CAPS_WORD_ENABLE = yes

SRC += layer_lock.c \
	   sjb.c \
	   oneshot.c \
	   combos.c \
	   encoder.c
