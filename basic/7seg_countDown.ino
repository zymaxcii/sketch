// 7seg_countDown.ino
// https://create.arduino.cc/projecthub/ajayrajan69/seven-segment-display-countdown-using-arduino-uno-code-4b83d3


int A = 7; //Defines all pins on the Arduino Uno board in order of connection.
int B = 6;
int C = 4; // DOT is pin 5, not used in this example.
int D = 3;
int E = 2;
int F = 8;
int G = 9;

//Hexadecimal format based upon the A-G, 0-9 Chart in excel and the wiring
// of the segment (refer to the on/off table image below)
byte num0 = 0x3F;
byte num1 = 0x6;
byte num2 = 0x5B;
byte num3 = 0x4F;
byte num4 = 0x66;
byte num5 = 0x6D;
byte num6 = 0x7C;
byte num7 = 0x7;
byte num8 = 0x7F;
byte num9 = 0x6F;


// turn on the correct pins to display numbers passed to it
// through the variable “num”
void on(byte num)
{
  int result = bitRead(num, 0); // Read the first binary entry in num and stores it in result.
  if (result == 1) // Check to see if this segment should be on.
  {digitalWrite(A, HIGH);} // Turns on the segment.
else // Otherwise, it turns it off.
{digitalWrite(A, LOW);} // Turns segment off.
result = bitRead( num, 1); // Same thing for the 6 remaining segments.
if (result == 1)
{digitalWrite(B, HIGH);}
else
{digitalWrite(B, LOW);}
result = bitRead( num, 2);
if (result == 1)
{digitalWrite(C, HIGH);}
else
{digitalWrite(C, LOW);}
result = bitRead( num, 3);
if (result == 1)
{digitalWrite(D, HIGH);}
else
{digitalWrite(D, LOW);}
result = bitRead( num, 4);
if (result == 1)
{digitalWrite(E, HIGH);}
else
{digitalWrite(E, LOW);}

result = bitRead( num, 5);
if (result == 1)
{digitalWrite(F, HIGH);}
else
{digitalWrite(F, LOW);}

result = bitRead( num, 6);
if (result == 1)
{digitalWrite(G, HIGH);}
else
{digitalWrite(G, LOW);}
}


void setup()
{
  pinMode(A, OUTPUT); // Making all pins outputs
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(10,OUTPUT);
}


void loop()
{
  on(num0); // Passing “num0” to the function “on()” defined above to display “0”
  delay(500); // Delay for 1 second to see the “0”

  on(num1); // Change to “1”
  delay(500);

  on(num2);
  delay(500);

  on(num3);
  delay(500);

  on(num4);
  delay(500);

  on(num5);
  delay(500);

  on(num6);
  delay(500);

  on(num7);
  delay(500);

  on(num8);
  delay(500);

  on(num9);
  delay(500);
}
