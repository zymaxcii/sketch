// 8led_sweep_with_blink.ino
// https://create.arduino.cc/projecthub/burcakcubukcu/8-led-sweep-bf2d08

int ledPin0 = 9;
int ledPin1 = 8;
int ledPin2 = 7;
int ledPin3 = 6;
int ledPin4 = 5;
int ledPin5 = 4;
int ledPin6 = 3;
int ledPin7 = 2;

int blinkTime = 300;

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
