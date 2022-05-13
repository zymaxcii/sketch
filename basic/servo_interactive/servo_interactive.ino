// servo_interactive.ino

//
// https://www.hackster.io/thatbobby/control-mini-pan-tilt-camera-mount-with-arduino-pro-mini-93f03d

/*****************************************************************************
* Program Name: interactiveServo
* Author: Bob
* 
* Move a servo interactively with the Arduino IDE Serial Monitor
* 
* based upon  BARRAGAN <http://barraganstudio.com>
* and Scott Fitzgerald http://www.arduino.cc/en/Tutorial/Sweep
* 
* ----------------------------------------------------------------------------
* Change History
* Date         Ver    Description
* ----------   ----   --------------------------------------------------------
* 02/25/2019   V1.0   Initial development
*****************************************************************************/

#include <Servo.h>

int    servoPIN = 12; // servo signal pin
int    servoPos = 90; // initial servo position
String inString = ""; // string to hold incomming command
Servo  servo;         // create servo object to control the servo


/*********************************************************************
 *  setup()
 *  Called once at power on
 ********************************************************************/
void setup() 
{
  servo.attach(servoPIN); // attaches the servo pin to the servo object
  servo.write(servoPos);  // set servo to initial position
  
  Serial.begin(9600);
  Serial.println("");
  Serial.println("-----------------------------------------------------------------------");
  Serial.println("- Welcome to Interactive Servo");
  Serial.println("- Open the serial monitor and ensure the Line Ending option (at bottom");
  Serial.println("- of the monitor window) is set to NewLine. To move the servo, enter a ");
  Serial.println("- number from 0 to 180(at top of monitor window)and press ENTER/SEND");
  Serial.println("-----------------------------------------------------------------------");
  Serial.print("Servo at ");
  Serial.print(servoPos);
  Serial.println(".\tNew position?");
}


/*********************************************************************
 *  loop()
 *  Main processing loop. Called after setup()
 ********************************************************************/
void loop()
{
  /* process incomming characters (command) from serial monitor */
  while (Serial.available())
  {
    char inChar = Serial.read();
    
    if (inChar == '\n')
    {
      int num = inString.toInt();
      inString = "";

      /* if valid number move servo */
      if ((num >= 0) && (num <= 180))
      {
        for (int i = servoPos; i != num; i += (servoPos < num? 1 : -1))
        {
          servo.write(i); delay(15); //move servo +/- 1 degree every 15 msec
        }
        
        servoPos = num; //update servo position
        Serial.print("Servo at ");
        Serial.print(servoPos);
        Serial.println(".\tNew position?");
      }
      else
      {
        Serial.print(num);
        Serial.println(" not valid.  Must be between 0 and 180");
      }
    }

    /* add char to command string, if string is not too long and valid digit */
    else
    {
      if (inString.length() > 2)
        continue;
        
      if (isDigit(inChar))
        inString += inChar;
    }
  }
}

