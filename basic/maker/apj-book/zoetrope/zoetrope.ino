// zoetrope.ino
// chapter 10
// zoetrope: what?

// use a DC motor
// IN1, IN2 to pins 2, 3
// EN to pin 11 (PWM)
// connect potentiometer to anlog input A4
// connect direction switch to pin 6
// connect onOff switch to pin 7
// using L293D IC the code is similar to that using L298N motor driver module

// IN1, In2, EN = 2, 3, 11
const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin   = 9;

const int directionSwitchPin = 4;
const int onOffSwitchStateSwitchPin = 5;

const int potPin = A0;

int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

// init
int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;


void setup()
{
  pinMode(directionSwitchPin, INPUT_PULLUP);
  pinMode(onOffSwitchStateSwitchPin, INPUT_PULLUP);

  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);    // stop the motor
}


void loop()
{
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);

  // map 0-1023 to 0-255
  motorSpeed = analogRead(potPin)/4;

  if (onOffSwitchState != previousOnOffSwitchState)
  {
    if (onOffSwitchState == HIGH)
    {
      motorEnabled = !motorEnabled;
    }
  }
  
  if (directionSwitchState != previousDirectionSwitchState)
  {
    if (directionSwitchState == HIGH)
    {
      motorDirection = !motorDirection;
    }
  }

  if (motorDirection == 1)
  {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }
  else
  {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }

  if (motorEnabled == 1)
  {
    analogWrite(enablePin, motorSpeed);
  }
  else
  {
    analogWrite(enablePin, 0);
  }
  
  previousDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;
}
