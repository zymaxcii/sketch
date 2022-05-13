// hc35_multipleButtonAll.ino
// All means debounce, state and events

/*
 * Created by ArduinoGetStarted.com
 * This example code is in the public domain
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button-library
 * This example:
 *   + uses debounce for multiple buttons
 *   + reads state of multiple buttons
 *   + detects the pressed and released events of multiple buttons
 */

// Boards to run the sketch:
// my HC-35 keypad-led-sw board
// switches s1-s4 have pullup resistors on board

// 
// pin # Name  to Uno Pin
// =====================
// 1  S1       D2
// 2  S2       D3
// 3  S3       D4
// 4  VCC      VCC
// 5  GND      GND


#include <ezButton.h>

ezButton button1(2);  // create ezButton object that attach to pin 2
ezButton button2(3);
ezButton button3(4);


void setup()
{
  Serial.begin(9600);
  button1.setDebounceTime(50); // set debounce time to 50 ms
  button2.setDebounceTime(50);
  button3.setDebounceTime(50);
}


void loop()
{
  button1.loop();              // MUST call loop() function first
  button2.loop();
  button3.loop();

  int btn1State = button1.getState();
  int btn2State = button2.getState();
  int btn3State = button3.getState();
  
  Serial.print("button 1 state: ");
  Serial.println(btn1State);
  
  Serial.print("button 2 state: ");
  Serial.println(btn2State);
  
  Serial.print("button 3 state: ");
  Serial.println(btn3State);

  if (button1.isPressed())
  {
    Serial.println("The button 1 is pressed");
  }
  
  if (button1.isReleased())
  {
    Serial.println("The button 1 is released");
  }
  
  if (button2.isPressed())
  {
    Serial.println("The button 2 is pressed");
  }
  
  if (button2.isReleased())
  {
    Serial.println("The button 2 is released");
  }
  
  if (button3.isPressed())
  {
    Serial.println("The button 3 is pressed");
  }
  
  if (button3.isReleased())
  {
    Serial.println("The button 3 is released");
  }
}
