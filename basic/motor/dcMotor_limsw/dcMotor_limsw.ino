// dcMotor_limsw.ino
// compile error

// https://github.com/makertut/DIY-Motion-Control
// Arduino DIY Motion Control  Linear slide  with Speed control
// DC motor with limit switches?

// defines pins numbers
const int stepPin = 5;
const int dirPin = 2;
const int enPin = 8;
const int LimitSwitch_LEFT_Pin  = 10;
const int LimitSwitch_RIGHT_Pin = 11;

//

int val;
int encoder0PinA = 3;
int encoder0PinB = 4;
int encoder0Pos = 0;
int encoder0PinALast = LOW;
int n = LOW;
int maxKnob = 10;
int stepperSpeed = 1000;
int maxSpeed     = 400;
int minSpeed     = 1000;


void setup()
{
  Serial.begin(9600);

  pinMode (encoder0PinA, INPUT);
  pinMode (encoder0PinB, INPUT);

  pinMode(LimitSwitch_LEFT_Pin , INPUT);
  pinMode(LimitSwitch_RIGHT_Pin , INPUT);

  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);

  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);

  // Set Dir to Home switch
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction


}


void loop()
{
    int leftSw  = digitalRead( LimitSwitch_LEFT_Pin);
    int rightSw = digitalRead( LimitSwitch_RIGHT_Pin);
   
    if( (leftSw  == HIGH && (digitalRead(dirPin) == HIGH)) ||
        (rightSw == HIGH && (digitalRead(dirPin) == LOW)) )
    {
      motorStep(1);
    }
   
    else if( leftSw == LOW && (digitalRead(dirPin) == HIGH) ){
          digitalWrite(dirPin,LOW);
          delay(2000);
    }
    else if( rightSw == LOW && (digitalRead(dirPin) == LOW ) ){
          digitalWrite(dirPin,HIGH);
          delay(2000);
    }

    getKnob();
 
}


void motorStep( int MAX)
{
  for(int x = 0; x < MAX; x++)
  {
        digitalWrite(stepPin,HIGH);
        delayMicroseconds(stepperSpeed);
        digitalWrite(stepPin,LOW);
        delayMicroseconds(stepperSpeed);
      }
}


void getKnob()
{
     n = digitalRead(encoder0PinA);
  if ((encoder0PinALast == LOW) && (n == HIGH)) {
    if (digitalRead(encoder0PinB) == LOW) {
      encoder0Pos--;
    } else {
      encoder0Pos++;
    }
    if( encoder0Pos > maxKnob ){
         encoder0Pos = maxKnob;
    }
    else if( encoder0Pos < 0 ){
         encoder0Pos = 0;
    }

    int r= encoder0Pos * 100;

    r = minSpeed - r;
    r = (r < maxSpeed)?maxSpeed : r;

    stepperSpeed = r;
   
    Serial.print (encoder0Pos);
    Serial.println();

    Serial.print ( r );
  }
  encoder0PinALast = n;
}
