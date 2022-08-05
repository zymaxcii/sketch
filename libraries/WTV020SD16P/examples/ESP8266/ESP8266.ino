/*
  Example of using the WTV020SD16P chip on an ESP8266.

  Connect the WTV020SD16P to your ESP8266 and define the pins below.

  created 3 Nov 2019
  by Thomas A. Hirsch

  original version created by ELECTRONOOBS, 14 Oct 2016.

  This example code is in the public domain.
*/

#include <Arduino.h>
#include <WTV020SD16P.h>

// Constants to define the used pins.
static const uint8_t resetPin = D1; // The pin number of the reset pin.
static const uint8_t clockPin = D6; // The pin number of the clock pin.
static const uint8_t dataPin = D7; // The pin number of the data pin.
static const uint8_t busyPin = D5; // The pin number of the busy pin.

// Instance of WTV020SD16P
WTV020SD16P wtv020sd16p(resetPin, clockPin,dataPin,busyPin);

void setup() {

}

void loop() {
  wtv020sd16p.asyncPlayVoice(0);

  ////////////////////////////////////////////
  //This are all the functions for the WTV020 module
  //Use yours and delete the others
  //Each function is explained
  ///////////////////////////////////////////
  //Plays synchronously an audio file. Busy pin is used for this method.
  //wtv020sd15p.playVoice(0); // Will triggern the wdt (watch-dog timer) due to the use of sleep() on ESP8266!
  //Plays asynchronously an audio file.
  //wtv020sd16p.asyncPlayVoice(1);
  //Plays audio file number 1 during 5 seconds.
  //wtv020sd16p.asyncPlayVoice(1);
  //delay(5000);
  //Pauses audio file number 1 during 5 seconds.
  //wtv020sd16p.pauseVoice();
  //delay(5000);
  //Resumes audio file number 1 during 5 seconds.
  //wtv020sd16p.pauseVoice();
  //delay(5000);
  //Stops current audio file playing.
  //wtv020sd16p.stopVoice();
  //Plays synchronously an audio file. Busy pin is used for this method.
  //wtv020sd16p.asyncPlayVoice(2);
  //delay(2000);
  //Mutes audio file number 2 during 2 seconds.
  //wtv020sd16p.mute();
  //delay(2000);
  //Unmutes audio file number 2 during 2 seconds.
  //wtv020sd16p.unmute();
  //delay(2000);
  //Stops current audio file playing.
  //wtv020sd16p.stopVoice();
  //Resets the chip - Will initially be called during construction.
  //wtv020sd16p.reset();
}
