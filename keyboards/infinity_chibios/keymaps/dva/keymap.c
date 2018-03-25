#include "infinity_chibios.h"

#define _QWERTY 0
#define _FN 1
#define _ULCK 2

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define CLT_ESC CTL_T(KC_ESC)

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| \ | ` |
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| BSp |
     * |-----------------------------------------------------------|
     * |Contro|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| Enter  |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Fn |
     * |-----------------------------------------------------------|
     * | Hyper|Alt| Gui |         Space         |  Gui |Alt|   |   |
     * `-----------------------------------------------------------'
     */

    [_QWERTY] = KEYMAP(
      KC_ESC,  KC_1,    KC_2,    KC_3, KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV, \
      KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, \
      CLT_ESC, KC_A,    KC_S,    KC_D, KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,  \
      KC_LSPO, KC_Z,    KC_X,    KC_C, KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, MO(_FN), \
      KC_HYPR, KC_LALT, KC_LGUI,                    KC_SPC,                     KC_RGUI,KC_RALT ,KC_HYPR, KC_HYPR),

    /* Layer 1: HHKB mode (HHKB Fn)
     * ,-----------------------------------------------------------.
     * |Pwr| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |   |Psc|Slk|Pus|Up |   |Backs|
     * |-----------------------------------------------------------|
     * |      |VoD|VoU|Mut|   |   |  *|  /|Hom|PgU|Lef|Rig|Enter   |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |  +|  -|End|PgD|Dow|      |   |
     * `-----------------------------------------------------------'
     * |     |   |     |      Play/Pause       |     |   |   |     |
     * `-----------------------------------------------------------'
     */
    [_FN] = KEYMAP(
      DEBUG,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,   \
      KC_CAPS, _______,_______,_______,_______,_______,_______,_______,KC_PSCR,_______,_______, KC_UP, _______, KC_BSPC,      \
      _______, KC_VOLD,KC_VOLU,KC_MUTE,_______,_______,KC_PAST,KC_PSLS,KC_HOME,KC_PGUP,KC_LEFT,KC_RGHT,KC_PENT,            \
      _______, _______,_______,_______,_______,_______,KC_PPLS,KC_PMNS,KC_END, KC_PGDN,KC_DOWN,M(_ULCK),_______,            \
      _______, _______,_______,         KC_MPLY,               _______,_______,_______,_______),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case _ULCK:
      if (record->event.pressed) {
        /* time.heals.nothing */
        return MACRO( I(10), T(T), T(I), T(M), T(E), T(DOT), T(H), T(E), T(A), T(L), T(S), T(DOT), T(N), T(O), T(T), T(H), T(I), T(N), T(G), T(ENTER), END);
      }
      break;
  }
  return MACRO_NONE;
};
