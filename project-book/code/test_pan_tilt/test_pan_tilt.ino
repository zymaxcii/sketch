// pan_control.ino
// to control the pan DC brushed motor
// responds to left, right switches and speed potentiometer
// as a first programming attempt

// pan  motor: IN1 22, IN2 23, PWM 9
const int panMotorIN1 = 22;
const int panMotorIN2 = 23;
const int panMotorEN  = 9;

// tilt motor: IN1 24, IN2 25, PWM 10
const int tiltMotorIN1 = 24;
const int tiltMotorIN2 = 25;
const int tiltMotorEN  = 10;

// pan motor limit switches
const int panZero  = 31;
const int panRight = 32;
const int panLeft  = 33;

// tilt motor limit switches
const int tiltZero = 34;
const int tiltUp   = 35;
const int tiltDown = 36;

// motor control toggle switches
const int leftButton  = 41;
const int rightButton = 42;
const int upButton    = 43;
const int downButton  = 44;

// motor control toggle switch values
int leftBtnStatus  = 0;
int rightBtnStatus = 0;
int upBtnStatus    = 0;
int downBtnStatus  = 0;

// pan motr limit switch values
int panZeroStatus  = 0;
int panRightStatus = 0;
int panLeftStatus  = 0;

// tilt motor limit switch values
int tiltZeroStatus = 0;
int tiltUpStatus   = 0;
int tiltDownStatus = 0;

// speed potentiometer value analog input
int speed;


void setup()
{

// H-Bridge input pins
  Serial.begin(9600);

  // pan motor
  pinMode(panMotorIN1, OUTPUT);
  pinMode(panMotorIN2, OUTPUT);
  pinMode(panMotorEN,  OUTPUT);
  
  // tilt motor
  pinMode(tiltMotorIN1, OUTPUT);
  pinMode(tiltMotorIN2, OUTPUT);
  pinMode(tiltMotorEN,  OUTPUT);
  
  // Serial.println("+ - to set direction, any other key stops motor");
  // mega 8-bit pwm output pins 2-13, 44-46
  // below 30 motor cannot rotate
  

  // set up motor control toggle switches
  pinMode(leftButton,  INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(upButton,    INPUT_PULLUP);
  pinMode(downButton,  INPUT_PULLUP);

  // set up pan motor limit switches
  pinMode(panZero,  INPUT_PULLUP);
  pinMode(panRight, INPUT_PULLUP);
  pinMode(panLeft,  INPUT_PULLUP);
  
  // set up tilt motor limit switches
  pinMode(tiltZero, INPUT_PULLUP);
  pinMode(tiltUp,   INPUT_PULLUP);
  pinMode(tiltDown, INPUT_PULLUP);

  // motor speed
  analogWrite(panMotorEN,  37);  // rotate at max speed
  analogWrite(tiltMotorEN, 37);  // rotate at max speed 
}


void loop()
{
260
speed = analogRead(A0);

  panZeroStatus  = digitalRead(panZero);  
  panRightStatus = digitalRead(panRight);  
  panLeftStatus  = digitalRead(panLeft);  

  tiltZeroStatus  = digitalRead(tiltZero);  
  tiltUpStatus    = digitalRead(tiltUp);  
  tiltDownStatus  = digitalRead(tiltDown);  


  Serial.print(leftBtnStatus);
  Serial.print(",");
  Serial.print(rightBtnStatus);
  Serial.print(",");
  Serial.print(upBtnStatus);
  Serial.print(",");
  Serial.print(downBtnStatus);
  Serial.print(",");

  Serial.print(speed);
  Serial.print(",");


  Serial.print(panZeroStatus);
  Serial.print(",");
  Serial.print(panRightStatus);
  Serial.print(",");
  Serial.print(panLeftStatus);
  Serial.print(",");

  Serial.print(tiltZeroStatus);
  Serial.print(",");
  Serial.print(tiltUpStatus);
  Serial.print(",");
  Serial.println(tiltDownStatus);

  // delay(300);
  
  // read left and right control switches
  leftBtnStatus  = digitalRead(leftButton);  
  rightBtnStatus = digitalRead(rightButton);  
  
  // active low
  if ( leftBtnStatus == LOW )
  {
    Serial.println("CCW");
    digitalWrite(panMotorIN1, LOW);
    digitalWrite(panMotorIN2, HIGH);
  }
   
  else
  {
      // active low
      if (rightBtnStatus == LOW)
      {
        Serial.println("CW");
        digitalWrite(panMotorIN1, HIGH);
        digitalWrite(panMotorIN2, LOW);
      }
      else
      {
        Serial.print(": stop motor");
        digitalWrite(panMotorIN1, LOW);
        digitalWrite(panMotorIN2, LOW);
      }
  }


  // read up and down control switches
  upBtnStatus   = digitalRead(upButton);  
  downBtnStatus = digitalRead(downButton);  
  
  // active low
  if ( upBtnStatus == LOW )
  {
    Serial.println("CCW");
    digitalWrite(tiltMotorIN1, LOW);
    digitalWrite(tiltMotorIN2, HIGH);
  }
   
  else
  {
      // active low
      if (downBtnStatus == LOW)
      {
        Serial.println("CW");
        digitalWrite(tiltMotorIN1, HIGH);
        digitalWrite(tiltMotorIN2, LOW);
      }
      else
      {
        Serial.print(": stop motor");
        digitalWrite(tiltMotorIN1, LOW);
        digitalWrite(tiltMotorIN2, LOW);
      }
  }
  
}
