// max7219_test.ino
// using 8-digit display

// https://digitaleclab.com/max7219-led-display-driver/


#define DIN 12
#define LOAD 11
#define CLK 10


void setup()
{
  digitalWrite(LOAD, HIGH);
  pinMode(DIN, OUTPUT);
  pinMode(LOAD, OUTPUT);
  pinMode(CLK, OUTPUT);

  // disable test mode
  send(0x0f, 0x00);

  // set shutdown register for normal operation
  send(0x0c, 0x01);

  // set decode mode for all the 8 digits
  send(0x09, 0xff);

  // set the brightness to maximum with intensity register
  send(0x0a, 0x0f);

  // set scan limit register to scan all the 8 digits
  send(0x0b, 0x07);

  // sending "HELP2349" to the display
  send(0x01, 0x0c); //digit 1, H
  send(0x02, 0x0b); //digit 2, E
  send(0x03, 0x0d); //digit 3, L
  send(0x04, 0x0e); //digit 4, 9
  send(0x05, 0x02); //digit 5, 2
  send(0x06, 0x03); //digit 6, 3
  send(0x07, 0x04); //digit 7, 4
  send(0x08, 0x09); //digit 8, 9
}


void send(byte address, byte data)
{
  digitalWrite(LOAD, LOW);
  shiftOut(DIN, CLK, MSBFIRST, address); // address
  shiftOut(DIN, CLK, MSBFIRST, data);    // data
  digitalWrite(LOAD, HIGH);
}


void loop()
{
  // put your main code here, to run repeatedly
}
