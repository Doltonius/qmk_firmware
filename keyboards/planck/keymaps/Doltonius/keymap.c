/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers { _QWERTY, _LOWER, _RAISE, _VIM, _VIM_SHIFT, _FN, _ADJUST2, _QWERTY2, _CONFIG };

enum planck_keycodes { QWERTY = SAFE_RANGE, BACKLIT, EXT_PLV, NEW_LINE, CUT_LINE, JOIN_LINE, DELETE_TO_END, CHANGE_LINE, GO_TO_END, FIND, DELETE_WORD, SELECT_LINE };

enum {
    TD_YY,
    TD_PP,
    TD_DD,
};

void dance_yy(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_DOWN(X_LSFT) SS_TAP(X_RIGHT) SS_UP(X_LSFT) SS_TAP(X_C) SS_TAP(X_LEFT) SS_UP(X_LGUI));
    } else {
        SEND_STRING(SS_LGUI("c"));
    }
}

void dance_pp(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_TAP(X_ENT) SS_LGUI("v"));
    } else {
        SEND_STRING(SS_LGUI("v"));
    }
}

void dance_dd(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_DOWN(X_LSFT) SS_TAP(X_RIGHT) SS_UP(X_LSFT) SS_TAP(X_X) SS_TAP(X_LEFT) SS_UP(X_LGUI) SS_TAP(X_BSPC) SS_TAP(X_DOWN) SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI));
    } else {
        SEND_STRING(SS_LGUI("x"));
    }
}

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_YY] = ACTION_TAP_DANCE_FN(dance_yy),
    [TD_PP] = ACTION_TAP_DANCE_FN(dance_pp),
    [TD_DD] = ACTION_TAP_DANCE_FN(dance_dd),
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_planck_grid(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_BSLS, OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLASH), KC_SFTENT, MO(_FN), KC_LALT, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_RGUI, KC_RALT, KC_RCTL, MO(_FN)),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_planck_grid(KC_ESC, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_BSPC, KC_TILD, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_UNDS, KC_PLUS, KC_LPRN, KC_RPRN, KC_DEL, _______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_LBRC, KC_RBRC, KC_UNDS, KC_PLUS, _______, _______, _______, _______, _______, _______, KC_SPC, KC_SPC, TO(_VIM), KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_grid(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_RBRC, KC_QUOT, _______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_LCBR, KC_RCBR, KC_MINS, KC_EQL, _______, _______, _______, _______, _______, TO(_VIM), KC_SPC, KC_SPC, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT),

    /* Adjust (Lower + Raise)
     *                      v------------------------RGB CONTROL--------------------v
     * ,-----------------------------------------------------------------------------------.
     * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */

    [_VIM] = LAYOUT_planck_grid(_______, KC_ESC, A(KC_RIGHT), A(KC_RIGHT), LSG(KC_Z), _______, TD(TD_YY), G(KC_Z), TO(_QWERTY), NEW_LINE, TD(TD_PP), KC_BSPC, LM(_QWERTY2, MOD_LCTL), GO_TO_END, _______, TD(TD_DD), FIND, G(KC_UP), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, G(KC_G), _______, MO(_VIM_SHIFT), _______, DELETE_WORD, CHANGE_LINE, SELECT_LINE, A(KC_LEFT), G(KC_G), _______, G(KC_Z), G(KC_Y), FIND, KC_ENT, MO(_FN), LM(_QWERTY2, MOD_LALT), LM(_QWERTY2, MOD_LALT), LM(_QWERTY2, MOD_LGUI), KC_PGUP, KC_SPC, KC_SPC, KC_PGDN, LM(_QWERTY2, MOD_LGUI), LM(_QWERTY2, MOD_LALT), LM(_QWERTY2, MOD_LCTL), MO(_FN)),

    [_VIM_SHIFT] = LAYOUT_planck_grid(_______, KC_ESC, A(KC_RIGHT), A(KC_RIGHT), LSG(KC_Z), _______, G(KC_C), G(KC_Z), TO(_QWERTY), NEW_LINE, G(KC_V), KC_BSPC, LM(_QWERTY2, MOD_LCTL), GO_TO_END, _______, C(KC_K), FIND, G(KC_DOWN), KC_LEFT, JOIN_LINE, KC_UP, KC_RIGHT, G(KC_G), _______, KC_TRNS, _______, DELETE_WORD, DELETE_TO_END, SELECT_LINE, A(KC_LEFT), G(KC_G), _______, G(KC_Z), G(KC_Y), FIND, KC_ENT, MO(_FN), LM(_QWERTY2, MOD_LALT), LM(_QWERTY2, MOD_LALT), LM(_QWERTY2, MOD_LGUI), KC_PGUP, KC_SPC, KC_SPC, KC_PGDN, LM(_QWERTY2, MOD_LGUI), LM(_QWERTY2, MOD_LALT), LM(_QWERTY2, MOD_LCTL), MO(_FN)),

    [_FN] = LAYOUT_planck_grid(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_PMNS, KC_CAPS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_4, KC_5, KC_6, KC_PCMM, KC_PPLS, KC_NO, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_1, KC_2, KC_3, KC_PEQL, KC_ENT, KC_TRNS, MO(_CONFIG), MO(_QWERTY2), KC_NO, KC_NO, KC_SPC, KC_SPC, KC_NLCK, KC_PSLS, KC_PAST, KC_PDOT, KC_TRNS),

    [_ADJUST2] = LAYOUT_planck_grid(_______, RESET, DEBUG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL, _______, _______, MU_MOD, AU_ON, AU_OFF, AG_NORM, AG_SWAP, QWERTY, _______, _______, _______, _______, _______, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, TERM_ON, TERM_OFF, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_QWERTY2] = LAYOUT_planck_grid(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_BSLS, OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLASH), KC_SFTENT, _______, _______, _______, _______, _______, KC_SPC, KC_SPC, _______, _______, _______, _______, _______),

    [_CONFIG] = LAYOUT_planck_grid(_______, RESET, DEBUG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL, _______, _______, MU_MOD, AU_ON, AU_OFF, AG_NORM, AG_SWAP, QWERTY, _______, _______, _______, _______, _______, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, TERM_ON, TERM_OFF, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)

};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _VIM:
            rgblight_setrgb(0x00, 0xff, 0x44);
            break;
        case _VIM_SHIFT:
            rgblight_setrgb(0x00, 0xff, 0x44);
            break;
        case _CONFIG:
            rgblight_setrgb(0xFF, 0x44, 0x00);
            break;
        default:
            rgblight_setrgb(0xAA, 0x77, 0x44);
            break;
    }
    return state;
    /* return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST2); */
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                print("mode just switched to qwerty and this is a huge string\n");
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
                backlight_step();
#endif
#ifdef KEYBOARD_planck_rev5
                writePinLow(E6);
#endif
            } else {
                unregister_code(KC_RSFT);
#ifdef KEYBOARD_planck_rev5
                writePinHigh(E6);
#endif
            }
            return false;
            break;
        case NEW_LINE:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_TAP(X_ENT));
            } else {
                layer_move(_QWERTY);
            }
            break;
        case CUT_LINE:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_TAP(X_BSPC) SS_UP(X_LGUI) SS_TAP(X_BSPC) SS_TAP(X_DOWN) SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI));
            }
            break;
        case CHANGE_LINE:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_DOWN(X_LGUI) SS_TAP(X_BSPC) SS_UP(X_LGUI));
            } else {
                SEND_STRING(SS_TAP(X_BSPC));
                layer_move(_QWERTY);
            }
        case JOIN_LINE:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_TAP(X_SPC) SS_TAP(X_DEL));
            }
            break;
        case DELETE_TO_END:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LSFT) SS_TAP(X_RIGHT) SS_TAP(X_BSPC) SS_UP(X_LSFT) SS_UP(X_LGUI));
            } else {
                layer_move(_QWERTY);
            }
            break;
        case GO_TO_END:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI));
            } else {
                layer_move(_QWERTY);
            }
            break;
        case FIND:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("f"));
            } else {
                layer_move(_QWERTY);
            }
            break;
        case DELETE_WORD:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_RIGHT) SS_TAP(X_BSPC) SS_UP(X_LALT));
            }
            break;
        case SELECT_LINE:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_DOWN(X_LSFT) SS_TAP(X_RIGHT) SS_UP(X_LSFT) SS_UP(X_LGUI));
            }
            break;
    }
    return true;
}

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo += 1;
            } else {
                muse_tempo -= 1;
            }
        }
    } else {
        if (clockwise) {
#ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_DOWN);
#else
            tap_code(KC_PGDN);
#endif
        } else {
#ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_UP);
#else
            tap_code(KC_PGUP);
#endif
        }
    }
    return true;
}

/* bool dip_switch_update_user(uint8_t index, bool active) { */
/*     switch (index) { */
/*         case 0: { */
/* #ifdef AUDIO_ENABLE */
/*             static bool play_sound = false; */
/* #endif */
/*             if (active) { */
/* #ifdef AUDIO_ENABLE */
/*                 if (play_sound) { PLAY_SONG(plover_song); } */
/* #endif */
/*                 layer_on(_ADJUST2); */
/*             } else { */
/* #ifdef AUDIO_ENABLE */
/*                 if (play_sound) { PLAY_SONG(plover_gb_song); } */
/* #endif */
/*                 layer_off(_ADJUST2); */
/*             } */
/* #ifdef AUDIO_ENABLE */
/*             play_sound = true; */
/* #endif */
/*             break; */
/*         } */
/*         case 1: */
/*             if (active) { */
/*                 muse_mode = true; */
/*             } else { */
/*                 muse_mode = false; */
/*             } */
/*     } */
/*     return true; */
/* } */

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}

extern rgblight_config_t rgblight_config;
void                     keyboard_post_init_user(void) { rgblight_setrgb(0xAA, 0x77, 0x44); }

enum combo_events { JK_ESC, QUOT, DQUOT, LRB, LRS, LRP, TOVIM, COMBO_LENGTH };

uint16_t COMBO_LEN = COMBO_LENGTH;  // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM jk_esc[] = {KC_J, KC_K, COMBO_END};

const uint16_t PROGMEM quot[] = {KC_SCLN, KC_BSLS, COMBO_END};

const uint16_t PROGMEM dquot[] = {KC_L, KC_SCLN, KC_BSLS, COMBO_END};

const uint16_t PROGMEM lrb[] = {KC_M, KC_COMM, COMBO_END};

const uint16_t PROGMEM lrs[] = {KC_P, KC_BSPC, COMBO_END};

const uint16_t PROGMEM lrp[] = {KC_C, KC_V, COMBO_END};

const uint16_t PROGMEM tovim[] = {KC_PGUP, KC_PGDN, COMBO_END};

combo_t key_combos[] = {[JK_ESC] = COMBO_ACTION(jk_esc), [QUOT] = COMBO_ACTION(quot), [DQUOT] = COMBO_ACTION(dquot), [LRB] = COMBO_ACTION(lrb),
                        [LRS] = COMBO_ACTION(lrs),       [LRP] = COMBO_ACTION(lrp),   [TOVIM] = COMBO_ACTION(tovim)

};

/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case JK_ESC:
            if (pressed) {
                SEND_STRING(SS_TAP(X_ESC));
            }
            break;
        case QUOT:
            if (pressed) {
                SEND_STRING("'");
            }
            break;
        case DQUOT:
            if (pressed) {
                SEND_STRING("\"");
            }
            break;
        case LRB:
            if (pressed) {
                SEND_STRING("{}" SS_TAP(X_LEFT));
            }
            break;
        case LRS:
            if (pressed) {
                SEND_STRING("[]" SS_TAP(X_LEFT));
            }
            break;
        case LRP:
            if (pressed) {
                SEND_STRING("()" SS_TAP(X_LEFT));
            }
            break;
        case TOVIM:
            if (pressed) {
                layer_move();
            }
            break;
    }
}
