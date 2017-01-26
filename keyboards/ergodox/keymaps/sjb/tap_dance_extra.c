#include "action.h"
#include "action_layer.h"
#include "action_util.h"
#include "quantum.h"
#include "tap_dance_extra.h"
#include "wait.h"

void td_mod_tap_on_finished(qk_tap_dance_state_t *state, void *user_data) {
    qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;

    if (state->pressed) {
        register_mods(pair->kc2);
        state->count = TD_PRESSED_EVENT; // magic number for reset
    } else if (state->count == 1) {
        register_code(pair->kc1);
    } else if (state->count == ONESHOT_TAP_TOGGLE) {
        register_mods(pair->kc2);
    }
}

void td_mod_tap_on_reset(qk_tap_dance_state_t *state, void *user_data) {
    qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;
    if (state->count == ONESHOT_TAP_TOGGLE) {
        return;
    }

    if (state->count == 1) {
        unregister_code(pair->kc1);
        unregister_mods(pair->kc2);
    }

    if (state->count == TD_PRESSED_EVENT) {
        unregister_mods(pair->kc2);
    }
}

void td_tskswch_on_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        register_code(KC_LGUI); 
        unregister_code(KC_LGUI);
        wait_ms(250);
        register_code(KC_LALT);
        state->count = 3;
    } else {
        switch (state->count) {
            case 1:
                register_code16(LGUI(KC_TAB));
                break;
            case 2:
                register_code16(LALT(KC_F6));
                break;
        }
    }
}

void td_tskswch_on_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            unregister_code16(LGUI(KC_TAB));
            break;
        case 2:
            unregister_code16(LALT(KC_F6));
            break;
        case 3:
            unregister_mods(MOD_BIT(KC_LALT));
            break;
    }
}

void td_layer_toggle_on_finished(qk_tap_dance_state_t *state, void *user_data) {
    qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;

    if (state->count == 1) {
        register_code16(pair->kc1);
    } else if (state->count == 2) {
        if (IS_LAYER_ON(pair->kc2)) {
            layer_off(pair->kc2);
        } else {
            layer_on(pair->kc2);
        }
    }
}

void td_layer_toggle_on_reset(qk_tap_dance_state_t *state, void *user_data) {
    qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;

    if (state->count == 1) {
        unregister_code16(pair->kc1);
    }
}

#define tp_get_mods(kc) ((uint8_t)(kc >> 8) & 0x1f)

void tp_register_code(uint16_t kc) { 
    uint8_t mods = tp_get_mods(kc);
    if (mods) {
        add_macro_mods(mods);
    }
    register_code(kc);
}

void tp_unregister_code(uint16_t kc) {
    uint8_t mods = tp_get_mods(kc);
    if (mods) {
        del_macro_mods(mods);
    }
    unregister_code(kc);
}

void td_pair_restore_mods_finished(qk_tap_dance_state_t *state, void *user_data) {
    qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;

    if (state->count == 1) {
        tp_register_code(pair->kc1);
    } else if (state->count == 2) {
        tp_register_code(pair->kc2);
    }
}

void td_pair_restore_mods_reset(qk_tap_dance_state_t *state, void *user_data) {
    qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;
  
    if (state->count == 1) {
        tp_unregister_code(pair->kc1);
    } else if (state->count == 2) {
        tp_unregister_code(pair->kc2);
    }
}
