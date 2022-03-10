#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define EE_HANDS

#ifdef TAPPING_TERM
    #undef TAPPING_TERM
    #define TAPPING_TERM 190
#endif

#define PERMISSIVE_HOLD
#define RETRO_TAPPPING
#define IGNORE_MOD_TAP_INTERRUPT

#define ONESHOT_TAP_TOGGLE 2
