// motion_detector.ino

/*********
  Rui Santos
  Relay.ino
  Complete project details at http://randomnerdtutorials.com  
*********/

// relay pin is controlled with D8
// active wire is connected to normally Closed and common
int relay = 8;
volatile byte relayState = LOW;    // used with ISR

// PIR Motion Sensor is connected to D2
// driven by interrupt
int PIRInterrupt = 2;

// timer Variables
long lastDebounceTime = 0;  
long debounceDelay = 10000;


void setup()
{
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);      // active low
  // PIR motion sensor set as an input
  pinMode(PIRInterrupt, INPUT);
  // Triggers detectMotion function on rising mode to turn the relay on
  // if the condition is met
  attachInterrupt(digitalPinToInterrupt(PIRInterrupt), detectMotion, RISING);
  
  Serial.begin(9600);
  Serial.println("Program starting...");
}


void loop()
{
  // if 10 seconds have passed, the relay is turned off
  if((millis() - lastDebounceTime) > debounceDelay && relayState == HIGH)
  {
    digitalWrite(relay, HIGH);
    relayState = LOW;
    Serial.println("OFF");
  }
  delay(50);
}


// interrupt service routine
void detectMotion()
{
  Serial.println("Motion");
  if(relayState == LOW)
  {
    digitalWrite(relay, LOW);
  }
  relayState = HIGH;  
  Serial.println("ON");
  lastDebounceTime = millis();
}
