// Header file "readButtons.h":

// read TM1638 button status
uint8_t readButtons()
{
  buttons = 0;

  digitalWrite(stb, LOW);
  shiftOut(dio, clk, LSBFIRST, 0x42);
  pinMode(dio, INPUT);

  for (uint8_t i=0; i<=3; i++)
  {
    uint8_t v = shiftIn(dio, clk, LSBFIRST) << i;
    buttons |= v;
  }

  pinMode(dio, OUTPUT);
  digitalWrite(stb, HIGH);
  return buttons;
}
