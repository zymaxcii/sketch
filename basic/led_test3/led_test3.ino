// led_test3.ino
// Test 3 leds
// Blink 3 leds on and off

// 3 leds connected to D3, D4, D5
const int LED1 = 3;
const int LED2 = 4;
const int LED3 = 5;

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
