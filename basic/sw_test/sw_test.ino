// sw_test.ino
// switch test

// my standard pin assignments for 8 leds on uno and nano: 6,7,8,9,10,11,12,13
// pins 2,3,4,5 for switches; pin 2 with interrupt
const int switchPin = 2;
int switchVal = 0;


void setup()
{
  pinMode(switchPin, INPUT_PULLUP);    // nc: normally closed
  Serial.begin(9600);
}


void loop()
{
  switchVal = digitalRead(switchPin);
  Serial.println(switchVal);
  delay(20);
}
