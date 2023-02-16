// hc35_ezButton_buttonCount.ino
// status: compile ok, upload ok

/*
 * Created by ArduinoGetStarted.com
 * This example code is in the public domain
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button-library
 * This example reads the number of the pressed count of a button with debounce
 * and print it to Serial Monitor
*/

// Boards to run the sketch:
// my HC-35 keypad-led-sw board
// switches s1-s4 have pullup resistors on board
// can also use the 4-switch module bought from Aliexpress

// 
// pin # Name  to Uno Pin
// =====================
// 1  S1       D10
// 2  S2       D3 (not used)
// 3  S3       D4 (not used)
// 4  VCC      VCC
// 5  GND      GND


#include <ezButton.h>


ezButton button(10);           // create ezButton object that attach to specified pin


void setup()
{
  Serial.begin(9600);
  button.setDebounceTime(50); // set debounce time to 50 ms
  button.setCountMode(COUNT_FALLING);
}


void loop()
{
  button.loop();              // MUST call loop() function first

  unsigned long count = button.getCount();
  Serial.println(count);
}

