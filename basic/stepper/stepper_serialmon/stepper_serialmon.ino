// stepper_serialmon.ino

// stepper_1.ino
//
// not working

/*
* Stepper sketch
** stepper is controlled from the serial port
* a numeric value followed by '+' or '-' steps the motor
* http://www.arduino.cc/en/Reference/Stepper
*/

// Boards to run the sketch:
// just connect the stepper motor connector to ULN2003 stepper motor driver
// with separate 5V power supply

// ULN2003
// 
// pin # Name to Uno Pin
// =====================
// 1  IN1     D2
// 2  IN2     D3
// 3  IN3     D4
// 4  IN4     D5


#include <Stepper.h>

// change this to number of steps on your motor
// 24
#define STEPS 2048

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 2, 4, 3, 5);

int steps = 0;

void setup()
{
  stepper.setSpeed(30);
  Serial.begin(9600);
  // set the speed of the motor to 30 RPMs
}


void loop()
{
  if ( Serial.available() )
  {
    char ch = Serial.read();

    if (isDigit(ch))
    {
      // is ch a number?
      steps = steps * 10 + ch - '0';
      // yes, accumulate the value
    }
    else
    {
      if (ch == '+')
      {
        stepper.step(steps);
        steps = 0;
      }
      else
      {
        if (ch == '-')
        {
          stepper.step(steps * -1);
          steps = 0;
        }
        else
        {
          if (ch == 's')
          {
            stepper.setSpeed(steps);
            Serial.print("Setting speed to ");
            Serial.println(steps);
            steps = 0;
          }
        }
      }
    }
  }
}
