// ir_controlServo.ino
// use 3 toggle switches on remote control unit to control a servo
// left, right by 2 degrees and OK to center it

/*
IR Receiver Demonstration 4
IR-Rcv-Demo4.ino
Demonstrates IR codes with Custom Remote and IR Receiver
Makes use of Repeat function
DroneBot Workshop 2017
http://dronebotworkshop.com
*/

// my standard hardware setup
// ir receiver D11
// servo D9 (pwm)
// using the standard remote supplied with the module

// Include IR Remote Library by Ken Shirriff
#include <IRremote.h>

#define ONE      0xFFA25D
#define TWO      0xFF629D
#define THREE    0xFFE21D
#define FOUR     0xFF22DD
#define FIVE     0xFF02FD
#define SIX      0xFFC23D
#define SEVEN    0xFFE01F
#define EIGHT    0xFFA857
#define NINE     0xFF906F
#define ZERO     0xFF9867
#define ASTERISK 0xFF6897
#define HASH     0xFFB04F
#define OK       0xFF38C7
#define UP       0xFF18E7
#define DOWN     0xFF4AB5
#define RIGHT    0xFF5AA5
#define LEFT     0xFF10EF


// Include Arduino Servo Library
#include <Servo.h>

// Define Sensor Pin
const int RECV_PIN = 11;

// Define Servo Pin
const int SERVO_PIN = 9;           // must be pwm pin

// Define Variable for Servo position
// Start at 90 Degrees (Center position)
int pos = 90;

// Define variable to store last code received
unsigned long lastCode;

// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;

// Create servo object
Servo myservo;


void setup()
{
  // Start the receiver
  irrecv.enableIRIn();
  
  // Attach the servo
  myservo.attach(SERVO_PIN);
  // Start with Servo in Center
  myservo.write(pos);

  Serial.begin(9600);
}


void loop() 
{
  if (irrecv.decode(&results)) // this checks to see if a code has been received
  {
    if (results.value == 0xFFFFFFFF)
    {
      // If Repeat then use last code received
      results.value = lastCode;
    }

    if (results.value == LEFT)
    {
      // Left Button Pressed
      Serial.println("left");
      lastCode = results.value;
      // Move left 2 degrees
      pos += 2;
      // Prevent position above 180
     if (pos > 180) {pos = 180;}
     myservo.write(pos);
    }
    
    if (results.value == RIGHT)
    {
      // Right Button Pressed
      Serial.println("right");
      lastCode = results.value;
      // Move Right 2 degrees
      pos -= 2;
      // Prevent position below 0
      if (pos < 0) {pos = 0;}
      myservo.write(pos);
    }

    if (results.value == OK)
    {
      // Center Button Pressed
      Serial.println("center");
      lastCode = results.value;
      // Move to Center
      pos = 90;
      myservo.write(pos);
    }
    
    // Add delay to prevent false readings
    delay(100);
    // receive the next value
    irrecv.resume();
  }
}
