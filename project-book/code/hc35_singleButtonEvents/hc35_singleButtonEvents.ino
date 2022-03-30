// hc35_singleButtonEvents.ino

/*
 * Created by ArduinoGetStarted.com
 * This example code is in the public domain
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button-library
 * This example detects the pressed and released events of a button without debounce
 */


// Boards to run the sketch:
// my HC-35 keypad-led-sw board
// switches s1-s4 have pullup resistors on board

// 
// pin # Name  to Uno Pin
// =====================
// 1  S1       D2
// 2  VCC      VCC
// 5  GND      GND


#include <ezButton.h>

ezButton button(2);        // create ezButton object that attach to pin 2

void setup()
{
  Serial.begin(9600);
}


void loop()
{
  button.loop();           // MUST call loop() function first

  if (button.isPressed())
  {
    Serial.println("The button is pressed");
  }
  
  if (button.isReleased())
  {
    Serial.println("The button is released");
  }
}
