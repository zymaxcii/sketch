/*
* direction_control.ino
* Brushed_H_Bridge_simple sketch
* commands from serial port control motor direction
* + or - set the direction, any other key stops the motor
* ENA must be tied to HIGH using the jumper
*/

// original pins 5 and 4
const int in1Pin = 4;
const int in2Pin = 7;
const int enAPin = 6;


// H-Bridge input pins
void setup()
{
  Serial.begin(9600);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);

  pinMode(enAPin, OUTPUT);
  
  Serial.println("+ - to set direction, any other key stops motor");
  // mega 8-bit pwm output pins 2-13, 44-46
  // below 30 motor cannot rotate
  analogWrite(enAPin, 50);  // rotate at max speed
}


void loop()
{
  if ( Serial.available())
  {
    char ch = Serial.read();
    if (ch == '+')
    {
      Serial.println("CCW");
      digitalWrite(in1Pin, LOW);
      digitalWrite(in2Pin, HIGH);
    }
    else
    {
      if (ch == '-')
      {
        Serial.println("CW");
        digitalWrite(in1Pin,HIGH);
        digitalWrite(in2Pin,LOW);
      }
      else
      {
         if (ch == '\n')
         {
           // skip do nothing
         }
         else
         {
           Serial.println(ch);
           Serial.print(": stop motor");
           digitalWrite(in1Pin,LOW);
           digitalWrite(in2Pin,LOW);
         }
      }
    }
  }
}
