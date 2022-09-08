// l298n-2.ino

// https://www.bluetin.io/guides/l298n-h-bridge-dc-motor-driver-guide/

///////////////// Define Pins /////////////////
// Motor A, Left Side
const uint8_t pwmLeft = 9;

// ENA - Enable and PWM
const uint8_t leftForward = 7;

// IN1 - Forward Drive
const uint8_t leftReverse = 6;
// IN2 - Reverse Drive
// Motor B, Right Side
const uint8_t pwmRight = 3;
// ENB - Enable and PWM
const uint8_t rightForward = 5;
// IN3 - Forward Drive
const uint8_t rightReverse = 4;
// IN4 - Reverse Drive

//////////////// Start Functions //////////////////
// All Stop
void allStop()
{
  digitalWrite(leftForward, LOW);
  digitalWrite(leftReverse, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightReverse, LOW);
  analogWrite(pwmLeft, 0);
  analogWrite(pwmRight, 0);
}

void allForward()
{
  digitalWrite(leftForward, HIGH);
  digitalWrite(leftReverse, LOW);
  digitalWrite(rightForward, HIGH);
  digitalWrite(rightReverse, LOW);
  analogWrite(pwmLeft, 255);
  analogWrite(pwmRight, 255);
}


void allReverse()
{
  digitalWrite(leftForward, LOW);
  digitalWrite(leftReverse, HIGH);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightReverse, HIGH);
  analogWrite(pwmLeft, 255);
  analogWrite(pwmRight, 255);
  }
  

void skidsteerLeft()
{
  digitalWrite(leftForward, LOW);
  digitalWrite(leftReverse, HIGH);
  digitalWrite(rightForward, HIGH);
  digitalWrite(rightReverse, LOW);
  analogWrite(pwmLeft, 255);
  analogWrite(pwmRight, 255);
 }
  
  
void skidsteerRight()
{
  digitalWrite(leftForward, HIGH);
  digitalWrite(leftReverse, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightReverse, HIGH);
  analogWrite(pwmLeft, 255);
  analogWrite(pwmRight, 255);
  }

  
//////////////// End Functions //////////////////
void setup()
{
  // Set pins to motor driver (L298) to outputs
  pinMode(pwmLeft, OUTPUT);
  pinMode(leftForward, OUTPUT);
  pinMode(leftReverse, OUTPUT);
  pinMode(pwmRight, OUTPUT);
  pinMode(rightForward, OUTPUT);
  pinMode(rightReverse, OUTPUT);
}

void loop()
{
  allStop();  // Stop all dc motors
  delay(1000);
  allForward(); // Drive dc motors forward
  delay(2000);
  allReverse(); // Drive dc motors in reverse
  delay(2000);
  skidsteerLeft();   // Skidsteer spin left direction
  delay(2000);
  skidsteerRight(); // Skidsteer spin right direction
  delay(2000);
}
