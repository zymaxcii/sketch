// L293D_Hackatronics.ino
// https://www.hackatronic.com/l293d-pin-diagram-and-functions-of-motor-driver-ic/
// DC motor

#define m1 2     // for controlling the direction of upper motor
#define m2 3     // for controlling the direction of upper motor
#define m3 4     // for controlling the direction of lower motor 
#define m4 5     // for controlling the direction of lower motor


void setup()
{
  // setup of pin mode, either they are working as Input or Output
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
}


void loop()
{
  // condition for forward
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
  delay(10000);             // delay of 10 second

  // condition for backward
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
  delay(10000);

  // condition for RIGHT
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
  delay(10000);

  // condition for LEFT
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
  delay(10000);

  // condition for STOP
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
  delay(10000);
}


