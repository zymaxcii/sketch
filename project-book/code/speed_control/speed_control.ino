/*
* simpleBrush.ino
* SimpleBrushed sketch
* commands from serial port control motor speed
* digits '0' through '9' are valid where '0' is off, '9' is max speed
*/

// motor driver is connected to pin 6, original 3
const int motorPin = 6; 
int motor1pin1 = 4;
int motor1pin2 = 7;

void setup()
{
  Serial.begin(9600);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);

  // rotate in one direction
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
}


void loop()
{
  if ( Serial.available())
  {
    char ch = Serial.read();
    if(isDigit(ch)) // is ch a number?
    {
      // input a number between 0 and 9 only
      int speed = map(ch, '0', '9', 0, 255);
      analogWrite(motorPin, speed);
      Serial.print("Speed: ");
      Serial.println(speed);
    }
    else
    {
      if (ch == '\n')
      {
        // skip say nothing
      }
      else
      {
        Serial.print("Unexpected character: enter a number between 0 and 9 only ");
        Serial.println(ch);
      }
    }
  }
}
