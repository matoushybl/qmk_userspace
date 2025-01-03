// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define BASE 0
#define NAV 1
#define NUM 2
#define SYM 3
#define MOUSE 4
#define FN 5

const uint16_t PROGMEM fn_layer_switch[] = { LT(NUM, KC_BSPC), LT(SYM, KC_ENT), COMBO_END };

combo_t key_combos[] = {
    COMBO(fn_layer_switch, MO(FN)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,             KC_H, RCTL_T(KC_J), RSFT_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                 KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    LT(MOUSE, KC_ESC), LT(NAV, KC_SPC),  XXXXXXX,    XXXXXXX, LT(NUM, KC_BSPC) , LT(SYM, KC_ENT)
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
                                         XXXXXXX, XXXXXXX,  XXXXXXX,     _______, KC_TAB, LSFT(KC_TAB)
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
  )
};

