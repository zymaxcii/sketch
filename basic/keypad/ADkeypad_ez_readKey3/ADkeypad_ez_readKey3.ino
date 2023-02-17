// ADkeypad_ez_readKey3.ino
// status: compile ok, upload ok
// but not working properly
// 1 click returns 2 to 3 presses
// need to debug

/*
   Created by ArduinoGetStarted.com
   This example code is in the public domain
   Tutorial page: https://arduinogetstarted.com/library/arduino-analog-button-array-example
   reads key presses and prints it to Serial Monitor
*/


#include <ezAnalogKeypad.h>

ezAnalogKeypad buttonArray(A0);  // create ezAnalogKeypad object


void setup()
{
  Serial.begin(9600);

  // calibrate first
  buttonArray.setNoPressValue(1023);  // no button is pressed
  buttonArray.registerKey(1, 0);      // button 1 is pressed
  buttonArray.registerKey(2, 140);    // button 2 is pressed
  buttonArray.registerKey(3, 320);    // button 3 is pressed
  buttonArray.registerKey(4, 501);    // button 4 is pressed
  buttonArray.registerKey(5, 736);    // button 5 is pressed
}


void loop()
{
  unsigned char button = buttonArray.getKey();
  
  if (button)
  {
    Serial.print("The button ");
    Serial.print((int)button);
    Serial.println(" is pressed");
  }
}
