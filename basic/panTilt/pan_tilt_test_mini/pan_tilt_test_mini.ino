// pan_tilt_test_mini.ino
//
// https://www.hackster.io/thatbobby/control-mini-pan-tilt-camera-mount-with-arduino-pro-mini-93f03d

/*****************************************************************************
* Program Name: miniPanTileTest
* Author: Bob
* 
* Cycle pan and tilt through a range of motions
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
Servo pan;              // create servo object to control the yaw servo
Servo tilt;             // create servo object to control the pitch servo

/*********************************************************************
 *  setup()
 *  Called once at power on
 ********************************************************************/
void setup()
{
  Serial.begin(9600);
  Serial.println("");
  pan.attach(12);   // attach servo on pin 12 to the servo object
  tilt.attach(13);  // attach servo on pin 13 to the servo object
}


/*********************************************************************
 *  loop()
 *  Main processing loop. Called after setup()
 ********************************************************************/
void loop()
{
  /* Check left/right and center movement */
  Serial.println("Pan Control");
  for (int i=90;  i<180; i++) { pan.write(i); delay(25); }
  for (int i=180; i>0;   i--) { pan.write(i); delay(25); }
  for (int i=0;   i<90;  i++) { pan.write(i); delay(25); }
  
  /* Check up/down and center movement */
  Serial.println("Tilt Control");
  for (int i=90;  i<145; i++) { tilt.write(i); delay(25); }
  for (int i=145; i>10;   i--) { tilt.write(i); delay(25); }
  for (int i=10;   i<90;  i++) { tilt.write(i); delay(25); }

  /* Move both servos at the same time(ish) */
  int pmin = 10;  // right
  int pmax = 170; // left
  int ppos = 90;  // current position
  int pinc = 1;   // movement increment in degrees

  int tmin = 10;  // top
  int tmax = 145; // bot
  int tpos = 90;  // current position
  int tinc = 3;   // movement increment in degrees

  /* go through cycle twice */
  Serial.println("Dual Control");
  for (int i=0; i<(180*2); i++)
  {
    ppos += pinc;                              // increment to next position
    if (ppos > pmax) {ppos = pmax; pinc = -1;} // check for limit, change direction if necessary
    if (ppos < pmin) {ppos = pmin; pinc = 1;}  // check for limit, change direction if necessary
  
    tpos += tinc;                              // increment to next position
    if (tpos > tmax) {tpos=tmax; tinc = -3;}   // check for limit, change direction if necessary
    if (tpos < tmin) {tpos=tmin; tinc = 3;}    // check for limit, change direction if necessary
  
    pan.write(ppos);                           // move servo
    delay(20);
    tilt.write(tpos);                          // move other servo
    delay(20);                                 // some delay
  }
  
  /* set pan/tilt to center */
  for (int i = ppos;  i!=90; i+=(ppos < 90 ? 1 : -1)) { pan.write(i); delay(25); }
  for (int i = tpos;  i!=90; i+=(tpos < 90 ? 1 : -1)) { tilt.write(i); delay(25); }
  delay(10000);                                // wait 10 seconds and do again
}

