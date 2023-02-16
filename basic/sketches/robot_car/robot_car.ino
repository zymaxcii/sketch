/* Obst. Avoid. Robot Vehicle
 *  learnelectronics
 *  17 JAN 2017
 */



#include <NewPing.h>

#define TRIGGER_PIN  7                              // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     6                              // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 400                            // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define ledForward 5                                // Green LED for forward mode set to pin 5
#define ledBack 4                                   // Red LED for backwards mode set to pin 4
#define ledTurn 3                                   // Blue LED for turn mode set to pin 3
#define alarm 2                                     // Beeperfor stop mode set to pin 2


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.


//--- Declared variables

int leftmotorForward = 8;                           // pin 8 --- left motor (+) red wire

int leftmotorBackward = 11;                         // pin 11 --- left motor (-) black wire

int leftmotorspeed = 9;                             // pin 9 --- left motor speed signal

int rightmotorForward = 12;                         // pin 12 --- right motor (+) red wire

int rightmotorBackward = 13;                        // pin 13 --- right motor (-) black

int rightmotorspeed = 10;                           // pin 10 --- right motor speed signal

//--- Speeds and Timers


int Runtime = 1000;                                 // How long Runtime actions will last

int Slow = 90;                                     // slow speed (of 255 max)

int Fast = 150;                                     // fast speed (of 255 max)

int avoid = 0;                                      //varible for sonar return


//------------------------------------------------------

void setup()                                        //all pins set for output 
{

pinMode(leftmotorForward, OUTPUT);

pinMode(leftmotorBackward, OUTPUT);

pinMode(leftmotorspeed, OUTPUT);

pinMode(rightmotorForward, OUTPUT);

pinMode(rightmotorBackward, OUTPUT);

pinMode(rightmotorspeed, OUTPUT);

pinMode(ledForward, OUTPUT);

pinMode(ledBack, OUTPUT);

pinMode(ledTurn, OUTPUT);

pinMode(alarm, OUTPUT);


}

// ---Main Program Loop -----------------------------

void loop()

{

avoid = (sonar.ping_cm());                          //check the sonar

if (avoid > 0 && avoid <10){                        //if object closer than 10cm (~4in)
  Stop();                                           //stop moving
  goBackward();                                     //back up
  //delay(Runtime);                                   //how long action lasts
  turn();                                           //turn
  //delay(Runtime);                                   //how long action lasts
}
else{                                               //if it's clear
  goForward();                                      //go forward
  //delay(Runtime);                                   //how long action lasts
}                                                   //back to beginning of loop


}

//----- "Sub-rutine" Voids called by the main loop

void goForward()

{

digitalWrite(ledForward, HIGH);                     // Green LED for forward mode turn on

analogWrite(leftmotorspeed,Fast);                   //Enable left motor by setting speed

analogWrite(rightmotorspeed,Fast);                  //Enable left motor by setting speed

digitalWrite(leftmotorBackward,LOW);                // Drives LOW outputs down first to avoid damage

digitalWrite(rightmotorBackward,LOW);               // Drives LOW outputs down first to avoid damage

digitalWrite(leftmotorForward,HIGH);                // Left motor forward engage

digitalWrite(rightmotorForward,HIGH);               // Right motor forward engage

delay(500);                                        // Continue

digitalWrite(ledForward, LOW);                      // Green LED for forward mode turn off

}

void goBackward()

{


digitalWrite(ledBack, HIGH);

analogWrite(leftmotorspeed,Slow);

analogWrite(rightmotorspeed,Slow);

digitalWrite(leftmotorForward,LOW);

digitalWrite(rightmotorForward,LOW);

digitalWrite(leftmotorBackward,HIGH);               //

digitalWrite(rightmotorBackward,HIGH);

delay(1000);

digitalWrite(ledBack, LOW);


}

void Stop() // Sets speed pins to LOW disabling both motors

{

digitalWrite(alarm, HIGH);                          // Beeper on

digitalWrite(leftmotorspeed,LOW);                   // power off left motor

digitalWrite(rightmotorspeed,LOW);                  // power off right motor

delay(500);                                         // wait 1/2 second

digitalWrite(alarm, LOW);                           // beeper off

}

void turn()

{

digitalWrite(ledTurn, HIGH);                    // turn LED on

analogWrite(leftmotorspeed,Fast);               //Enable left motor by setting speed

analogWrite(rightmotorspeed,Fast);              //Enable left motor by setting speed

digitalWrite(leftmotorBackward,LOW);            // Drives LOW outputs down first to avoid damage

digitalWrite(rightmotorBackward,LOW);

digitalWrite(leftmotorBackward,HIGH);

digitalWrite(rightmotorForward,HIGH);

delay(500);                                    // wait 1 second

digitalWrite(ledTurn, LOW);                     // turn LED off



}








/*----Ardunio to Shield Pinout Controls-----

Are using a Seeed motor shield to drive 2 DC motors

Seeed motor shield uses Arduino pins 8->13

Pin 9 sets the enable and speed of shield outputs 1 & 2

Pin 10 sets the enable and speed of shield outputs 3 & 4

Pin 8 from Uno controls the state of shield output 1

Pin 11 from Uno controls the state of shield output 2

Pin 12 from Uno controls the state of shield output 3

Pin 13 from Uno controls the state of shiled output 4

*/
