// led_8_shiftout.ino

/*
Adafruit Arduino - Lesson 4. 8 LEDs and a Shift Register
*/

// 74HC595 pins DS, SH_CP, ST_CP: 14, 11, 12
// connect pins 14, 11, 12: D2, D3, D4
int datapin  = 2; 
int clockpin = 3;
int latchpin = 4;

byte leds = 0;


void setup()
{
  pinMode(latchpin, OUTPUT);
  pinMode(datapin,  OUTPUT);
  pinMode(clockpin, OUTPUT);

//  leds = 3;
//  updateShiftRegister();
//  delay(500);
}


void loop()
{
  leds = 0;
  updateShiftRegister();
  delay(2000);

  for (int i = 0; i < 8; i++)
  {
    bitSet(leds, i);
    updateShiftRegister();
    delay(100);
  }

  delay(1000);
  leds = 0;

  for (int i = 7; i >= 0; i--)
  {
    bitSet(leds, i);
    updateShiftRegister();
    delay(100);
  }
}


void updateShiftRegister()
{
  digitalWrite(latchpin, LOW);    // active low
  shiftOut(datapin, clockpin, LSBFIRST, leds);
  digitalWrite(latchpin, HIGH);
}
