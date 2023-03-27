#define EE_HANDS

// When USB_VBUS_PIN is not defined, SPLIT_USB_DETECT is used.
#undef USB_VBUS_PIN
//#define USB_VBUS_PIN GP2K

/* Handedness. */
//#define SPLIT_HAND_PIN GP28
//#define SPLIT_HAND_PIN_LOW_IS_LEFT // High -> right, Low -> left.

#ifdef RGBLIGHT_ENABLE
# define RGB_DI_PIN GP23
# define RGBLED_NUM  2
# define RGBLED_SPLIT { 1, 1 }
# define RGBLIGHT_SPLIT
# define RGBLIGHT_LAYERS
# define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
# define RGBLIGHT_LIMIT_VAL 100
# define RGBLIGHT_SLEEP
# define RGBLIGHT_LAYER_BLINK
#endif
