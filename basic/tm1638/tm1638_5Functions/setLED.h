// setLED.h

// Button press, set LED
void setLed(int value, int position)
{
  pinMode(dio, OUTPUT);
  
  // command byte to set single address mode
  digitalWrite(stb, LOW);
  shiftOut(dio, clk, LSBFIRST, 0x44);
  digitalWrite(stb, HIGH);
  
  // turn ON LED due to button press
  digitalWrite(stb, LOW);
  shiftOut(dio, clk, LSBFIRST, 0xC1 + (position<<1));
  shiftOut(dio, clk, LSBFIRST, value);
  digitalWrite(stb, HIGH);
}
