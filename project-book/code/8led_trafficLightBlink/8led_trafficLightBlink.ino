// 8led_trafficLightBlink.ino

//********************************************************************//
//                            BLINK                                   //
//  This code simply flashes all the bulbs on and off.     //
//  Can be used to make sure the circuits are soldered correctly.     //
// Try messing with this to control individual colors and directions. //
//********************************************************************//

// my standard pin assignments for 8 leds on uno and nano: 6,7,8,9,10,11,12,13
// pins 2,3,4,5 for switches; pin 2 with interrupt
#define RED_PIN 6
#define YELLOW_PIN 7
#define GREEN_PIN 8

// not used in the code
#define NORTH 8    // conflict
#define SOUTH 7
#define EAST 6
#define WEST 5


void setup()
{
  // Set all pins as outputs, they initalize LOW
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  
  pinMode(NORTH, OUTPUT);
  pinMode(SOUTH, OUTPUT);
  pinMode(EAST, OUTPUT);
  pinMode(WEST, OUTPUT);
}


void loop()
{
  // Turn all the lights on
  //
  // Since LEDs are diodes, electricity will not flow the other direction,
  // so turning the direction pins HIGH and the colors LOW will not light
  // the LEDs. We'll make use of this fact when we control the lights
  // individually
  
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(YELLOW_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  
  // Wait a second so we as mere humans can see that they are on
  delay(1000);
  
  // Turn all the lights off
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  
  // Wait a second so we can see they're off
  delay(1000);
  
  // And do it again, since we're inside "void loop()"
}
