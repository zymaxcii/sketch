// pot_led.ino
// Adafruit Arduino - Lesson 8. Analog Inputs - LEDs
// looks like this sketch is using ledsr module - to check it out

int potPin = 0;     // A0
int latchPin = 5;
int clockPin = 6;
int dataPin  = 4;
int leds = 0;


void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin,  OUTPUT);
  pinMode(clockPin, OUTPUT);
}


void loop()
{
  int reading    = analogRead(potPin);
  int numLEDSLit = reading / 114;      // 1023 / 9
  leds = 0;

// version 1
//  for (int i = 0; i < numLEDSLit; i++)
//  {
//    bitSet(leds, i);
//  }
//  updateShiftRegister();

  // version 2 indicate position lit
  bitSet(leds, numLEDSLit);
  updateShiftRegister();
}


void updateShiftRegister()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

