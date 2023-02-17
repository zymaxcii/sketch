// ADkeypad_ez_readKey.ino
// status: compile ok, upload ok
// but not working properly; 1 press returns 2 or 3 values

/*
   Created by ArduinoGetStarted.com
   This example code is in the public domain
   Tutorial page: https://arduinogetstarted.com/library/arduino-analog-keypad-example
   This example reads the pressed key from analog keypad and prints it to Serial Monitor
*/


#include <ezAnalogKeypad.h>

ezAnalogKeypad keypad(A0);  // create ezAnalogKeypad object


void setup()
{
  Serial.begin(9600);

  // run the calibration example, press key one-by-one to get the analog values
  // add more if your keypad has more
  keypad.setNoPressValue(1023);    // analog value when no key is pressed
  keypad.registerKey('1', 0);      // key 'sw1' is pressed
  keypad.registerKey('2', 140);    // key 'sw2' is pressed
  keypad.registerKey('3', 320);    // key 'sw3' is pressed
  keypad.registerKey('4', 501);    // key 'sw4' is pressed
  keypad.registerKey('5', 736);    // key 'sw5' is pressed

  keypad.setDebounceTime(500);     // critical, original set to 100
}


void loop()
{
  unsigned char key = keypad.getKey();
  
  if (key)
  {
    Serial.println(key);
  }
}
