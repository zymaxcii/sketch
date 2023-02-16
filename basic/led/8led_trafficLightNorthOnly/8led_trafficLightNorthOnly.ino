// 8led_trafficLightNorthOnly.ino

//********************************************************************//
//                  North One Way Traffic Signal                      //
//  Runs through the green->yellow->red->green cycle on the north     //
//  facing bulbs. Also includes the UK pattern as well.               //
//                                                                    //
//********************************************************************//


#define UK_PATTERN true    // false

#define OFF 8
#define RED 4
#define YELLOW 2
#define GREEN 1

// my standard pin assignments for 8 leds on uno and nano: 6,7,8,9,10,11,12,13
// pins 2,3,4,5 for switches; pin 2 with interrupt
#define RED_PIN 6
#define YELLOW_PIN 7
#define GREEN_PIN 8

// not used in code
#define NORTH 8    // conflict
#define SOUTH 9
#define EAST 10
#define WEST 11


void setup()
{
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(NORTH, OUTPUT);
  pinMode(SOUTH, OUTPUT);
  pinMode(EAST, OUTPUT);
  pinMode(WEST, OUTPUT);
  
  // We're only going to use the north direction for this program, so we'll
  // turn off the other directions using the trick we learned about in
  // TrafficLight_Blink.ino
  digitalWrite(SOUTH, HIGH);
  digitalWrite(EAST, HIGH);
  digitalWrite(WEST, HIGH);
}


void loop()
{
  // Everybody like's when traffic lights are green, so we'll start with green
  // Turn off red and yellow, and turn on green
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  
  // Wait a bit for traffic to flow
  delay(3000);
  
  // Alright, light's about to turn red, so switch off the green and turn on yellow
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  
  // Wait a bit
  delay(1000);
  
  // Traffic's seen the yellow for a bit, now we can turn on red
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  
  // Wait a bit while we pretend the other direction turns green
  delay(3000);
  
  // OK, so other direction turned green and back to red, so we can turn back to green
  // Figure out which traffic pattern we're using
  if (UK_PATTERN)
  {
    // UK_PATTERN is true, so we'll do the red+yellow combo before turning green
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(YELLOW_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    delay(1000);
  }
  else
  {
    // UK_PATTERN is false, so we'll do nothing here and go directly to green
  }
  
  // End of the loop, so back to the top
  
  // To do two directions, try turning on the south direction in "void setup()"
  // To add more directions we do the same thing, except we switch which directions
  // are enabled while changing the colors at the same time. Between this and
  // TrafficLight_2WayStop.ino you should be able to get a full 4-way traffic light.
}
