// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
//

#include QMK_KEYBOARD_H
#include "features/achordion.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }
    // Your macros ...

    return true;
}

void housekeeping_task_user(void) {
    achordion_task();
}

uint16_t achordion_streak_chord_timeout(uint16_t tap_hold_keycode, uint16_t next_keycode) {
    if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
        return 0; // Disable streak detection on layer-tap keys.
    }

    // Otherwise, tap_hold_keycode is a mod-tap key.
    uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
    if ((mod & MOD_LSFT) != 0) {
        return 100; // A shorter streak timeout for Shift mod-tap keys.
    } else {
        return 240; // A longer timeout otherwise.
    }
}

#define BASE 0
#define NAV 1
#define NUM 2
#define SYM 3
#define MOUSE 4
#define FN 5
#define SHORTCUTS 6

// unused for now
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define HOME_M RGUI_T(KC_SCLN)

#define L_THUMB_OUTER LT(MOUSE, KC_ESC)
#define L_THUMB_INNER LT(NAV, KC_SPC)
#define R_THUMB_INNER LT(NUM, KC_BSPC)
#define R_THUMB_OUTER LT(FN, KC_ENT)
#define SHORTCUT_KEY LT(SHORTCUTS, KC_Z)

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
    // skip thumb keys
    switch (tap_hold_keycode) {
        case L_THUMB_INNER:
        case L_THUMB_OUTER:
        case R_THUMB_INNER:
        case R_THUMB_OUTER:
        case SHORTCUT_KEY:
            return true;
    }
    return achordion_opposite_hands(tap_hold_record, other_record);
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,             KC_H, RCTL_T(KC_J), RSFT_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LT(SHORTCUTS, KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,                                 KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    LT(MOUSE, KC_ESC), LT(NAV, KC_SPC),  XXXXXXX,    XXXXXXX, LT(NUM, KC_BSPC) , LT(FN, KC_ENT)
                                      //`--------------------------'  `--------------------------'

  ),

  [NAV] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, XXXXXXX,                              KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, CW_TOGG,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, XXXXXXX,  XXXXXXX,     _______, KC_DEL, LSFT(KC_TAB)
                                      //`--------------------------'  `--------------------------'
  ),

  [NUM] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_MINUS,  KC_7, KC_8,  KC_9, KC_LBRC,                                    KC_RBRC, KC_UNDS, KC_PIPE, KC_TILD, KC_PLUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LGUI_T(KC_SCLN), LALT_T(KC_4), LSFT_T(KC_5), LCTL_T(KC_6), KC_LPRN,        KC_RPRN, RCTL_T(KC_MINS), RSFT_T(KC_EQL), RSFT(KC_TAB), RGUI_T(KC_TAB),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_1, KC_2, KC_3, KC_LCBR,                                       KC_RCBR, KC_QUOT, KC_DQUO, KC_GRV, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_DOT,  KC_0,  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [SYM] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_AMPR, KC_ASTR, KC_LPRN, XXXXXXX,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_DLR, KC_PERC, KC_CIRC, XXXXXXX,                              XXXXXXX, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_EXLM, KC_AT, KC_HASH, XXXXXXX,                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX,  XXXXXXX, _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [MOUSE] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              MS_BTN3, MS_BTN4, MS_BTN5, MS_BTN6, MS_BTN7,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, XXXXXXX,                              MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, MS_BTN8,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, XXXXXXX,  _______,     _______, MS_BTN1, MS_BTN2
                                      //`--------------------------'  `--------------------------'
  ),

  [FN] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_F10, KC_F7, KC_F8,  KC_F9, XXXXXXX,                                    _______, KC_BRIGHTNESS_UP, KC_BRIGHTNESS_UP, _______, KC_MEDIA_PLAY_PAUSE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F11, KC_F4, KC_F5, KC_F6, XXXXXXX,                                     KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F12, KC_F1, KC_F2, KC_F3, XXXXXXX,                                     _______, KC_AUDIO_MUTE, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,  _______,  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
  [SHORTCUTS] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, LCTL(KC_Z), LCTL(KC_E),  LCTL(KC_R), LCTL(KC_T),                  _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, LCTL(KC_S), LCTL(KC_D), LCTL(KC_F), LCTL(KC_A),                   _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_B),                   _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT,  _______,  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};
// clang-format on
