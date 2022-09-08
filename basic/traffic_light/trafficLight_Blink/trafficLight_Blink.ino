// trafficLight_Blink.ino

//********************************************************************//
//                            BLINK                                   //
//  This code alternates simply flashes all the bulbs on and off.     //
//  Can be used to make sure the circuits are soldered correctly.     //
// Try messing with this to control individual colors and directions. //
//********************************************************************//

// Define which pin connections
#define RED_PIN 11
#define YELLOW_PIN 10
#define GREEN_PIN 9

#define NORTH 8
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
  // Since the pins are all initalize LOW, all we have to do to turn the
  // lights on is toggle the colors HIGH. Current will flow out of the
  // arduino's pins, into the color channels, through the resistors and
  // LEDs, out the direction channels and back into the arduino to
  // complete the circuit.
  //
  // Since LEDs are diodes, electricity will not flow the other direction,
  // so turning the direction pins HIGH and the colors LOW will not light
  // the LEDs. We'll make use of this fact when we control the lights
  // individually.
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

