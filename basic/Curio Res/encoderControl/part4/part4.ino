// part4.ino

#include <util/atomic.h>   // For the ATOMIC_BLOCK macro

// pan  motor: IN1 22, IN2 23, PWM 9, EncA 2, EncB 4
// tilt motor: IN1 24, IN2 25, PWM 10, EncA 3, EncB 5
#define ENCA 3   // YELLOW original 2
#define ENCB 5   // WHITE  original 3 swap them?
#define PWM 10  // original 5
#define IN2 25    // original 6 Swap IN1 and IN2 wrong
#define IN1 24    // original 7 will cause problem

// volatile: shared between ISR and normal functions
volatile int posi = 0;

long  prevT = 0;
float eprev = 0;
float eintegral = 0;


void setup()
{
  Serial.begin(9600);

  pinMode(ENCA, INPUT);
  pinMode(ENCB, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA), readEncoder, RISING);
  
  pinMode(PWM, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  //  Serial.println("target pos");
}


void loop()
{
  // set target position in terms of pulses: 1200 original
  int target = 240;
  // int target = 250*sin(prevT/1e6);

  // PID constants
  float kp = 1;
  float kd = 0.025;
  float ki = 0.0;

  // time difference
  long currT = micros();
  float deltaT = ((float) (currT - prevT))/( 1.0e6 );
  prevT = currT;

  // Read the position in an atomic block to avoid a potential
  // misread if the interrupt coincides with this code running
  int pos = 0; 
  
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
  {
    pos = posi;
  }


  // Serial.println(posi);  // posi, target
  
  // error
  int e = pos - target;
  //
    Serial.print(target);
    Serial.print(",");
    Serial.println(pos);    // e, target, pos

  // derivative
  float dedt = (e-eprev)/(deltaT);

  // integral
  eintegral = eintegral + e*deltaT;

  // control signal
  float u = kp*e + kd*dedt + ki*eintegral;

  // Serial.println(u);

  // Serial.print("error: ");
  // Serial.println(e);

  // motor power
  float pwr = fabs(u);

  // Serial.println(pwr);
  
  //  Serial.print("Motor power: ");
  //  Serial.println(pwr);
  
  // 8-bit PWM
  if( pwr > 255 )  // original 255
  {
    pwr = 255;    // original 255
  }

  // motor direction
  int dir = 1;
  
  if (u<0)
  {
    dir = -1;    // reverse
  }

  // signal the motor
  setMotor(dir, pwr, PWM, IN1, IN2);

//  Serial.print(dir);
//  Serial.print(",");
//  Serial.print(pwr);
//  Serial.print(",");
//  Serial.println(e);
  
  // store previous error
  eprev = e;

  //  Serial.print(target);
  //  Serial.print(": ");
  //  Serial.print(pos);
  //  Serial.println();
}


void setMotor(int dir, int pwmVal, int pwm, int in1, int in2)
{
  analogWrite(pwm, pwmVal);
  
  if (dir == 1)
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    
  // Serial.println("setMotor: forward");

  }
  else
  {
    if (dir == -1)
    {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);

      // Serial.println("setMotor: reverse");

    }
    else
    {
      digitalWrite(in1, LOW); // will never get executed
      digitalWrite(in2, LOW);

      // Serial.println("setMotor: stop");

    }
  }  
}


void readEncoder()
{
  int b = digitalRead(ENCB);

  if (b > 0)
  {
    posi++;
  }
  else
  {
    posi--;
  }
}
