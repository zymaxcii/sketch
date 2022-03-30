// servo_angles.ino
//
// https://builtjustbecause.blog/the-servo-motor-and-an-easy-rig-for-position-angles/
// The Servo Motor And An Easy Rig For Position Angles

// Made by Drew Z 13 Nov 2021
// Released under GPL v3 as a derivative work of GPL v2x or later

#include <Servo.h>

Servo HS422;

int HS422_min = 0;
int HS422_max = 180;
int HS422_mid = 90;
int HS422_angle;
boolean Terminal_input = false;


void setup()
{
  Serial.begin(9600);
  HS422.attach(4);
  HS422.write(HS422_mid);
  delay(20);
}


void loop()
{
  HS422_angle = Angle_From_Terminal();
  //Serial.println(HS422_angle);
  
  if (HS422_angle >= HS422_min && HS422_angle <= HS422_max && Terminal_input == true)
  {
    Serial.println(HS422_angle);
    HS422.write(HS422_angle);
    delay(20);
    Terminal_input = false;
  }
  
  if (HS422_angle < HS422_min || HS422_angle > HS422_max && Terminal_input == true)
  {
    Serial.print("Between ");
    Serial.print(HS422_min);
    Serial.print(" and ");
    Serial.println(HS422_max);
    Terminal_input = false;
  }
}  


int Angle_From_Terminal()
{
  int from_keyboard;
  int angle = 0;
  int store;
  int index;
  int place;

  if (Serial.available() > 0)
  {
    while (Serial.available() > 0)
    {  
      // Serial.print(Serial.available());
      // Serial.print('\t');
      place = 1;
      
      for (index = 1; index < Serial.available(); index++)
      {
        place *= 10;
      }
      //Serial.print(place);
      //Serial.print('\t');
      
      from_keyboard = Serial.read();
      store = from_keyboard - 48;
      
      angle += (store * place);
    }
    
    //Serial.println(angle);
    Terminal_input = true;
    return(angle);  
  }
  delay(1000);      
}

