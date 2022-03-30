// bitWrite.ino
// Demonstrate bitWrite() function call
// Don't need any boards to run it


void setup()
{
  Serial.begin(9600);
  
  // wait for serial port to connect. Needed for native USB port only
  while (!Serial) {}
  
  byte x = 0b10000000;    // the 0b prefix indicates a binary constant
  Serial.println(x, BIN); // 10000000
  bitWrite(x, 0, 1);      // write 1 to the least significant bit of x
  Serial.println(x, BIN); // 10000001
}

void loop()
{}
