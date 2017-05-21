#include "preonic.h"
#include "action_layer.h"
#include "eeconfig.h"
#ifdef AUDIO_ENABLE
#include "audio.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = {
    {ALL_T(KC_F1), ALL_T(KC_1),  ALL_T(KC_2),  ALL_T(KC_3),  ALL_T(KC_4),  ALL_T(KC_5),   ALL_T(KC_6),    ALL_T(KC_7),    ALL_T(KC_8),   ALL_T(KC_9),   ALL_T(KC_0),   ALL_T(KC_F20) },
    {ALL_T(KC_F2), ALL_T(KC_Q),  ALL_T(KC_W),  ALL_T(KC_E),  ALL_T(KC_R),  ALL_T(KC_T),   ALL_T(KC_Y),    ALL_T(KC_U),    ALL_T(KC_I),   ALL_T(KC_O),   ALL_T(KC_P),   ALL_T(KC_F21) },
    {ALL_T(KC_F3), ALL_T(KC_A),  ALL_T(KC_S),  ALL_T(KC_D),  ALL_T(KC_F),  ALL_T(KC_G),   ALL_T(KC_H),    ALL_T(KC_J),    ALL_T(KC_K),   ALL_T(KC_L),   ALL_T(KC_F17), ALL_T(KC_F22) },
    {ALL_T(KC_F4), ALL_T(KC_Z),  ALL_T(KC_X),  ALL_T(KC_C),  ALL_T(KC_V),  ALL_T(KC_B),   ALL_T(KC_N),    ALL_T(KC_M),    ALL_T(KC_F13), ALL_T(KC_F15), ALL_T(KC_F18), ALL_T(KC_F23) },
    {ALL_T(KC_F5), ALL_T(KC_F6), ALL_T(KC_F7), ALL_T(KC_F8), ALL_T(KC_F9), ALL_T(KC_F10), ALL_T(KC_F11),  ALL_T(KC_F12),  ALL_T(KC_F14), ALL_T(KC_F16), ALL_T(KC_F19), ALL_T(KC_F24) }
  }
};

float tone_startup[][2] = {
  {NOTE_B5, 20},
  {NOTE_B6, 8},
  {NOTE_DS6, 20},
  {NOTE_B6, 8}
};

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
float music_scale[][2]  = SONG(MUSIC_SCALE_SOUND);

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const qk_tap_dance_action_t tap_dance_actions[] = {
};

/*bool process_record_user(uint16_t keycode, keyrecord_t *record) {*/
  /*return true;*/
  /*[>switch (keycode) {<]*/
    /*[>case QWERTY:<]*/
      /*[>return true;<]*/
  /*[>}<]*/
/*};*/

void matrix_init_user(void) {
  startup_user();
}

void startup_user()
{
  _delay_ms(20); // gets rid of tick
  PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
  PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
  _delay_ms(150);
  stop_all_notes();
}

void music_on_user(void)
{
  music_scale_user();
}

void music_scale_user(void)
{
  PLAY_NOTE_ARRAY(music_scale, false, 0);
}

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
