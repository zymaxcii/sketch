// 8led_sweep_with_blink.ino
// https://create.arduino.cc/projecthub/burcakcubukcu/8-led-sweep-bf2d08
// 2024-03-07

// my standard pin assignments for 8 leds on uno and nano: 6,7,8,9,10,11,12,13
// pins 2,3,4,5 for switches; pin 2 with interrupt
//int ledPin0 = 13;
//int ledPin1 = 12;
//int ledPin2 = 11;
//int ledPin3 = 10;
//int ledPin4 = 9;
//int ledPin5 = 8;
//int ledPin6 = 7;
//int ledPin7 = 6;


// with 8-led module and nano: 6,7,8,9,10,11,12,13
// pins 2,3,4,5 for switches; pin 2 with interrupt
int ledPin0 = 13;
int ledPin1 = 12;
int ledPin2 = 11;
int ledPin3 = 10;
int ledPin4 = 9;
int ledPin5 = 8;
int ledPin6 = 7;
int ledPin7 = 6;

int blinkTime = 1000;  // 300


void setup()
{
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
}


void loop()
{
  digitalWrite(ledPin0, HIGH);
  delay(blinkTime);
  digitalWrite(ledPin0, LOW);
  delay(blinkTime);
  
  digitalWrite(ledPin1, HIGH);
  delay(blinkTime);
  digitalWrite(ledPin1, LOW);
  delay(blinkTime);
  
  digitalWrite(ledPin2, HIGH);
  delay(blinkTime);
  digitalWrite(ledPin2, LOW);
  delay(blinkTime);
  
  digitalWrite(ledPin3, HIGH);
  delay(blinkTime);
  digitalWrite(ledPin3, LOW);
  delay(blinkTime);
  
  digitalWrite(ledPin4, HIGH);
  delay(blinkTime);
  digitalWrite(ledPin4, LOW);
  delay(blinkTime);
  
  digitalWrite(ledPin5, HIGH);
  delay(blinkTime);
  digitalWrite(ledPin5, LOW);
  delay(blinkTime);
  
  digitalWrite(ledPin6, HIGH);
  delay(blinkTime);
  digitalWrite(ledPin6, LOW);
  delay(blinkTime);
  
  digitalWrite(ledPin7, HIGH);
  delay(blinkTime);
  digitalWrite(ledPin7, LOW);
  delay(blinkTime);
  
  
  digitalWrite(ledPin7, HIGH);
  delay(blinkTime);
  digitalWrite(ledPin7, LOW);
  delay(blinkTime);
  
  digitalWrite(ledPin6, HIGH);
  delay(blinkTime);
  digitalWrite(ledPin6, LOW);
  delay(blinkTime);
  
  digitalWrite(ledPin5, HIGH);
  delay(blinkTime);
  digitalWrite(ledPin5, LOW);
  delay(blinkTime);
  
  digitalWrite(ledPin4, HIGH);
  delay(blinkTime);
  digitalWrite(ledPin4, LOW);
  delay(blinkTime);
  
  digitalWrite(ledPin3, HIGH);
  delay(blinkTime);
  digitalWrite(ledPin3, LOW);
  delay(blinkTime);
  
  digitalWrite(ledPin2, HIGH);
  delay(blinkTime);
  digitalWrite(ledPin2, LOW);
  delay(blinkTime);
  
  digitalWrite(ledPin1, HIGH);
  delay(blinkTime);
  digitalWrite(ledPin1, LOW);
  delay(blinkTime);
  
  digitalWrite(ledPin0, HIGH);
  delay(blinkTime);
  digitalWrite(ledPin0, LOW);
  delay(blinkTime);
}
