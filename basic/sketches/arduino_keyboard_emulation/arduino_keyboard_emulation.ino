/*
 * Arduino Keyboard Emulation
 * learnelectronics
 * 13 FEB 2017
 * 
 * www.youtube.com/c/learnelectronics
 */

#include <Keyboard.h>    // This is a "built-in" library no need to install

//---------------------------------------------------------
//                           Setup
//---------------------------------------------------------



void setup() {
pinMode(3,INPUT_PULLUP);  // sets pin 3 to input & pulls it high w/ internal resistor
pinMode(4,INPUT_PULLUP);  // sets pin 4 to input & pulls it high w/ internal resistor
pinMode(5,INPUT_PULLUP);  // sets pin 5 to input & pulls it high w/ internal resistor

Serial.begin(9600);       // begin serial comms for debugging

}

//---------------------------------------------------------
//                           Loop
//---------------------------------------------------------

void loop() {
  
  
 Keyboard.begin();         //begin keyboard 
 if (digitalRead(3) == 0)  // if buton 3 is pushed
  {
    Keyboard.write('A');  // send single character "A"
    delay(200);           // delay so you don't get 20 A's
  }
  else if (digitalRead(4) == 0){  // if button 4 is pressed
    Keyboard.print("The rain in Spain falls mainly on the plain"); // send string
    delay(200);
}
  else if (digitalRead(5) == 0){  //if button 5 is pressed
    Keyboard.write(0xB0);         // send Hex value for RETURN key
    delay(200);
  }
  Keyboard.end();                 //stops keybord
}
