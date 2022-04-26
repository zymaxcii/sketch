// 8led_onOffSwitch.ino
// Turn led on or off with 2 switches

/*
Adafruit Arduino - Lesson 6. Inputs
*/

// my standard pin assignments for 8 leds on uno and nano: 6,7,8,9,10,11,12,13
// pins 2,3,4,5 for switches; pin 2 with interrupt
int ledPin = 6;
int buttonApin = 2;
int buttonBpin = 3;
byte leds = 0;


void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
}


void loop()
{
  if (digitalRead(buttonApin) == LOW)
  {
    digitalWrite(ledPin, HIGH);
  }
  //  else
  //  {
  //    digitalWrite(ledPin, LOW);
  //  }

  if (digitalRead(buttonBpin) == LOW)
  {
    digitalWrite(ledPin, LOW);
  }
}
