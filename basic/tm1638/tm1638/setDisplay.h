// Header file "setDisplay.h":


// Press button, set display
void setDisplay(uint8_t value, uint8_t position)
{
  pinMode(dio, OUTPUT);

  digitalWrite(stb, LOW);
  shiftOut(dio, clk, LSBFIRST, 0x44);
  digitalWrite(stb, HIGH);

  digitalWrite(stb, LOW);
  shiftOut(dio, clk, LSBFIRST, 0xC0 + (position<<1));
  shiftOut(dio, clk, LSBFIRST, value);
  digitalWrite(stb, HIGH);
}
