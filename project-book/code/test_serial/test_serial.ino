// test_serial.ino

String readString;
int User_Input = 0;
int REV = 0;
int PPR = 16;


void setup()
{
  Serial.begin(9600);
}


void loop()
{
  while (Serial.available())
  {
    delay(3);                  // a small delay
    char c = Serial.read();    // storing input data
    readString += c;           // accumulate each of the characters in readString
  }

  Serial.println(readString);
  
  // Verify that the variable contains information
  if (readString.length() >0)
  { 
    Serial.println(readString.toInt());  // printing the input data in integer form
    User_Input = readString.toInt();     // input data is store in integer form
  }

  // why cannot use ppr? pololu is 128
  REV = map (User_Input, 0, 360, 0, PPR); // mapping degree into pulse: original 1600 pololu: 128
  
  Serial.print("this is REV: "); 
  Serial.println(REV);     
}
