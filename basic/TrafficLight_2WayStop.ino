// https://someplacein.space/trafficlight/

// https://someplacein.space › trafficlight › TrafficLight_2WayStop.ino
// Someplace in Space
// Too large, the lights will strobe; // too small, the lights will get dim
// Try tuning this to get the // best visual results
// int cycleDelay = 10; 
// we'll use this to keep track of time while we're fiddling with the bulbs
// unsigned long stopwatch = 0; void setup(){ pinMode(RED_PIN, OUTPUT); 
// pinMode(YELLOW_PIN, OUTPUT); pinMode(GREEN_PIN, OUTPUT ...



//********************************************************************//
//                  2 WAY  STOP TRAFFIC LIGHT                         //
//  This code alternates between red north & south and yellow east &  //
//  west.                                                             //
//                                                                    //
//********************************************************************//

// Define which pin connections
#define RED_PIN 11
#define YELLOW_PIN 10
#define GREEN_PIN 9

#define NORTH 8
#define SOUTH 7
#define EAST 6
#define WEST 5


// 'cycleDelay' controls how long we keep each direction lit 
// before switching to the next. Too large, the lights will strobe;
// too small, the lights will get dim. Try tuning this to get the
// best visual results.
int cycleDelay = 10;


// we'll use this to keep track of time while we're fiddling with the bulbs
unsigned long stopwatch = 0;

void setup(){
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(NORTH, OUTPUT);
  pinMode(SOUTH, OUTPUT);
  pinMode(EAST, OUTPUT);
  pinMode(WEST, OUTPUT);
}

void loop(){
  stopwatch = millis();
  while (millis()-stopwatch < 1000){
    // ENABLE NORTH AND DISABLE SOUTH EAST WEST
    digitalWrite(NORTH, LOW);
    digitalWrite(SOUTH, HIGH);
    digitalWrite(EAST, HIGH);
    digitalWrite(WEST, HIGH);
    // ILLUMINATE RED EXTINGUISH YELLOW GREEN
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    // PAUSE FOR A MOMENT TO LET THE LIGHT SHINE BEFORE WE TURN IT OFF
    delay(cycleDelay);
    
    // ENABLE SOUTH AND DISABLE NORTH EAST WEST
    digitalWrite(NORTH, HIGH);
    digitalWrite(SOUTH, LOW);
    digitalWrite(EAST, HIGH);
    digitalWrite(WEST, HIGH);
    // ILLUMINATE RED EXTINGUISH YELLOW GREEN
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    // PAUSE FOR A MOMENT TO LET THE LIGHT SHINE BEFORE WE TURN IT OFF
    delay(cycleDelay);
  }
  
  stopwatch = millis();
  while (millis()-stopwatch < 1000){
    // ENABLE EAST AND DISABLE NORTH SOUTH WEST
    digitalWrite(NORTH, HIGH);
    digitalWrite(SOUTH, HIGH);
    digitalWrite(EAST, LOW);
    digitalWrite(WEST, HIGH);
    // ILLUMINATE YELLOW EXTINGUISH RED GREEN
    digitalWrite(RED_PIN, LOW);
    digitalWrite(YELLOW_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    // PAUSE FOR A MOMENT TO LET THE LIGHT SHINE BEFORE WE TURN IT OFF
    delay(cycleDelay);
    
    // ENABLE WEST AND DISABLE NORTH SOUTH EAST
    digitalWrite(NORTH, HIGH);
    digitalWrite(SOUTH, HIGH);
    digitalWrite(EAST, HIGH);
    digitalWrite(WEST, LOW);
    // ILLUMINATE YELLOW EXTINGUISH RED GREEN
    digitalWrite(RED_PIN, LOW);
    digitalWrite(YELLOW_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    // PAUSE FOR A MOMENT TO LET THE LIGHT SHINE BEFORE WE TURN IT OFF
    delay(cycleDelay);
  }
}
