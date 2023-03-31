// bitWrite.ino
// Demonstrate bitWrite() function call
// Don't need any GPIOs to run it
// status: compile ok, upload ok


void setup()
{
  Serial.begin(9600);
  
  // Needed for native USB port only
  while (!Serial) {}
  
  byte x = 0b10000000;    // 0b prefix indicates a binary constant
  Serial.println(x, BIN); // 10000000
  bitWrite(x, 0, 1);      // write 1 to the least significant bit of x
  Serial.println(x, BIN); // 10000001
}


void loop()
{}
