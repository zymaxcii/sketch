// sr04_newPingTester.ino
// ultrasonic hc sr04 sensor with NewPing library

/*
 * Posted on http://randomnerdtutorials.com
 * created by http://playground.arduino.cc/Code/NewPing
*/


#include <NewPing.h>

/*
 * created by Rui Santos, http://randomnerdtutorials.com
 * Complete Guide for Ultrasonic Sensor HC-SR04
   Ultrasonic sensor Pins:
     VCC: +5VDC
     Trig : Trigger (INPUT) - Pin 9
     Echo: Echo (OUTPUT)    - Pin 8
     GND: GND
*/

// trig and echo: normal digital pins will do
#define TRIGGER_PIN 9
#define ECHO_PIN 8
#define MAX_DISTANCE 200
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance
 
void setup()
{
   Serial.begin(9600);
}


void loop()
{
   // original 50
   delay(500);
   
   unsigned int uS = sonar.ping_cm();
   Serial.print(uS);
   Serial.println("cm");
}
