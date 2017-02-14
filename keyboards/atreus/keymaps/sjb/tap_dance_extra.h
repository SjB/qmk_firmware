#ifndef TAP_DANCE_EXTRA_H
#define TAP_DANCE_EXTRA_H

#include "process_keycode/process_tap_dance.h"

#define TD_PRESSED_EVENT 0xFF

// kc1 is a mods and kc2 is a keycode
// ACTION_TAP_DANCE_MOD_TAP(MOD_LALT, KC_LBRC)
#define ACTION_TAP_DANCE_MOD_TAP(kc1, kc2) {                            \
    .fn = { NULL, td_mod_tap_on_finished, td_mod_tap_on_reset },        \
    .user_data = (void *)&((qk_tap_dance_pair_t) { kc1, kc2 }),         \
  }

#define ACTION_TAP_DANCE_MOD_TAP_LOCK(kc1, kc2) {                          \
    .fn = { NULL, td_mod_tap_lock_on_finished, td_mod_tap_lock_on_reset }, \
    .user_data = (void *)&((qk_tap_dance_pair_t) { kc1, kc2 }),            \
  }

#define ACTION_TAP_DANCE_TSKSWCH() {                                    \
    .fn = { NULL, td_tskswch_on_finished, td_tskswch_on_reset },        \
    .user_data = NULL,                                                  \
  }

#define ACTION_TAP_DANCE_LAYER_TAP(kc1, kc2) {                  \
    .fn = { NULL, td_layer_toggle_on_finished, td_layer_toggle_on_reset }, \
    .user_data = (void *)&((qk_tap_dance_pair_t) { kc1, kc2 }), \
  }

#define ACTION_TAP_DANCE_DOUBLE_RESTORE_MODS(kc1, kc2) {                \
    .fn = { NULL, td_pair_restore_mods_finished, td_pair_restore_mods_reset}, \
    .user_data = (void *)&((qk_tap_dance_pair_t) { kc1, kc2 }),         \
  }

#define ACTION_TAP_DANCE_SHIFT_WITH_DOUBLE(kc)          \
  ACTION_TAP_DANCE_DOUBLE_RESTORE_MODS(kc, LSFT(kc))


void td_mod_tap_on_finished(qk_tap_dance_state_t *state, void *user_data);
void td_mod_tap_on_reset(qk_tap_dance_state_t *state, void *user_data);

void td_mod_tap_lock_on_finished(qk_tap_dance_state_t *state, void *user_data);
void td_mod_tap_lock_on_reset(qk_tap_dance_state_t *state, void *user_data);

void td_tskswch_on_finished(qk_tap_dance_state_t *state, void *user_data);
void td_tskswch_on_reset(qk_tap_dance_state_t *state, void *user_data);

void td_layer_toggle_on_finished(qk_tap_dance_state_t *state, void *user_data);
void td_layer_toggle_on_reset(qk_tap_dance_state_t *state, void *user_data);

void td_pair_restore_mods_finished(qk_tap_dance_state_t *state, void *user_data);
void td_pair_restore_mods_reset(qk_tap_dance_state_t *state, void *user_data);

#endif
