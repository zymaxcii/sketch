// led_onOffSwitch.ino
// Turn led on or off with switches

/*
Adafruit Arduino - Lesson 6. Inputs
*/

int ledPin = 41;                // LED D1
int buttonApin = 33;            // switch s1
int buttonBpin = 32;            // switch s2
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

