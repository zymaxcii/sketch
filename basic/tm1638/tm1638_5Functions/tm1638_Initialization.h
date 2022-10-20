// tm1638_Initialization.h
// Initialize the led-key module


void TM1638_Initialization()
{
  // activate TM1638 & set brightness of display to max
  digitalWrite(stb, LOW);
  shiftOut(dio, clk, LSBFIRST, 0x8F);
  digitalWrite(stb, HIGH);
  
  // set auto increment mode to reset LEDs and displays
  digitalWrite(stb, LOW);
  shiftOut(dio, clk, LSBFIRST, 0x40);
  digitalWrite(stb, HIGH);
  
  digitalWrite(stb, LOW);
  shiftOut(dio, clk, LSBFIRST, 0xc0);

  for (int i=0; i<16; i++) shiftOut(dio, clk, LSBFIRST, 0x00);
  digitalWrite(stb, HIGH);
  
  
  // set single address mode
  digitalWrite(stb, LOW);
  shiftOut(dio, clk, LSBFIRST, 0x44);
  digitalWrite(stb, HIGH);
}
