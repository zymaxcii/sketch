// 8ledsr_shiftout.ino

/*
Adafruit Arduino - Lesson 4. 8 LEDs and a Shift Register
*/

// 74HC595 pins DS, ST_CP, SH_CP: 14, 12, 11 (data, storage, shift register)
// pin headers bottom to top:
// 11 SH_CP D8
// 12 ST_CP D7
// 14 DS    D6
int clockpin = 8;
int latchpin = 7;
int datapin  = 6;     // bottom pin

byte leds = 0;


void setup()
{
  pinMode(latchpin, OUTPUT);
  pinMode(datapin,  OUTPUT);
  pinMode(clockpin, OUTPUT);
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
