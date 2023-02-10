// buzzer_ezbuzzer_beep.ino
// status: compile ok
// cannot hear it; not working?

/*
   Created by ArduinoGetStarted.com
   This example code is in the public domain
   Tutorial page: https://arduinogetstarted.com/library/arduino-beep-example
   Library References: https://arduinogetstarted.com/tutorials/arduino-buzzer-library
   This example uses a piezo buzzer:
   + generates a 100ms beep on background when a button is pressed 
   + without using delay() function, this is a non-blocking example
*/


#include <ezBuzzer.h>          // ezBuzzer library

const int BUTTON_PIN = 10;
const int BUZZER_PIN = 3;

int lastButtonState = HIGH;    // the previous state from the input pin
ezBuzzer buzzer(BUZZER_PIN);   // create ezBuzzer object that attach to a pin


void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}


void loop()
{
  buzzer.loop();               // MUST call buzzer.loop() function in loop()

  int currentState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && currentState == LOW)
  {
    Serial.println("The button is pressed");
    buzzer.beep(1000);          // generates a 100ms beep
  }

  lastButtonState = currentState;
}
