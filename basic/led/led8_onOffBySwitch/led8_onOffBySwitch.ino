// led8_onOffBySwitch.ino
// Turn led on or off with switches

// Adafruit Arduino - Lesson 6. Inputs

// With the 8 led module and 4 switch module
int ledPin = 39;
int buttonApin = 10;
int buttonBpin = 11;
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
