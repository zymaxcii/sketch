// 8led_test3.ino
// Test 3 leds
// Blink 3 leds on and off

// my standard pin assignments for 8 leds on uno and nano: 6,7,8,9,10,11,12,13
// pins 2,3,4,5 for switches; pin 2 with interrupt
const int LED1 = 6;
const int LED2 = 7;
const int LED3 = 8;

// time delay intervals
const int interval1 = 1000;
const int interval2 = 1500;

// active low leds
#define ON LOW
#define OFF HIGH


void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}


void loop()
{
  digitalWrite(LED1, ON);     // all 3 leds on
  digitalWrite(LED2, ON);
  digitalWrite(LED3, ON);
  delay(interval1);
  
  digitalWrite(LED1, OFF);     // all 3 leds off
  digitalWrite(LED2, OFF);
  digitalWrite(LED3, OFF);
  delay(interval2);
}
