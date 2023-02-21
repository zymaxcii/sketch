// speaker_sd.ino
// https://create.arduino.cc/projecthub/HUNMAN/speaker-with-arduino-and-micro-sd-f238b8?ref=similar&ref_id=318552&offset=3
// status: compile ok, upload ok
// but additional SD module is needed


#include <SD.h>                           // include SD module library
#include <TMRpcm.h>                       // include speaker control library

#define SD_ChipSelectPin 4                // define CS pin

TMRpcm tmrpcm;                            // crete an object for speaker library


void setup()
{
  tmrpcm.speakerPin = 9;                  // define speaker pin
                                          // you must use pin 9 of the Arduino Uno and Nano
                                          // the library is using this pin
  
  if (!SD.begin(SD_ChipSelectPin))
  {
    // see if the card is present and can be initialized
    return;                               // don't do anything more if not
  }
  
  tmrpcm.setVolume(6);                    // 0 to 7. Set volume level
  tmrpcm.play("1.wav");
}


void loop(){ }