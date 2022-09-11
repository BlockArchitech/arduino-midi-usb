// MIDI ButtonPad
#include <MIDI_Controller.h>

const uint8_t velocity = 0b1111111; // Maximum velocity (0b1111111 = 0x7F = 127)
const uint8_t C4 = 60;              // Note number 60 is defined as middle C in the MIDI spec
const uint8_t B3 = 59;              // I didn't read the entire MIDI spec so maybe these labels are correct, I mean if middle C is 60 shouldn't B3 be 59? Knowing how confusing MIDI is, it's probably C# or something.
const uint8_t A3 = 58;
const uint8_t G3 = 57;
// TODO: Customizable notes
Digital button(2, C4, 1, velocity);
Digital button2(3, B3, 1, velocity);
Digital button3(4, A3, 1, velocity);
Digital button4(5, G3, 1, velocity);
const uint8_t Channel = 1;       // MIDI channel 1

void setup() {}

void loop() {
  /*
   * There's a couple issues with this; One being that MIDI_Controller.refresh(); Isn't very fast, and void loop() {} only runs as fast as the devices' clock.
   * We can somewhat overcome the slowness of MIDI_controller.refresh by using simple notes, and simply deny your press more than 2 buttons at a time.
   * Now another problem we have to tackle is the devices' clock. Chances are people aren't going to be pressing these things at 5000 BPM, so we should be fine.
   */
  MIDI_Controller.refresh();
}
