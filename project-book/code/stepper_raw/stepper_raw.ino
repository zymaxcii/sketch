// stepper_raw.ino

// stepper_2.ino
// This is working
// what does it do?

// Boards to run the sketch:
// just connect the stepper motor connector to ULN2003 stepper motor driver
// with separate 5V power supply

// ULN2003
// 
// pin # Name to Uno Pin
// =====================
// 1  IN1     D2
// 2  IN2     D3
// 3  IN3     D4
// 4  IN4     D5


#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

int Steps = 0;
boolean Direction = false;    // true


void setup()
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}


void loop()
{
  for (int i=0; i<4096; i++)
  {
    stepper(1);
    delayMicroseconds(800);
  }
  Direction = !Direction;
}


void stepper(int xw)
{
  for (int x = 0; x < xw; x++)
  {
    switch (Steps)
    {
      case 0:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        break;

     case 1:
       digitalWrite(IN1, LOW);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, HIGH);
       digitalWrite(IN4, HIGH);
       break;

     case 2:
       digitalWrite(IN1, LOW);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, HIGH);
       digitalWrite(IN4, LOW);
       break;

     case 3:
       digitalWrite(IN1, LOW);
       digitalWrite(IN2, HIGH);
       digitalWrite(IN3, HIGH);
       digitalWrite(IN4, LOW);
       break;

     case 4:
       digitalWrite(IN1, LOW);
       digitalWrite(IN2, HIGH);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, LOW);
       break;

     case 5:
       digitalWrite(IN1, HIGH);
       digitalWrite(IN2, HIGH);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, LOW);
       break;

     case 6:
       digitalWrite(IN1, HIGH);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, LOW);
       break;

     case 7:
       digitalWrite(IN1, HIGH);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, HIGH);
       break;
    
     default:
       digitalWrite(IN1, LOW);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, LOW);
       break;
     }
  
     SetDirection();
  }
}


void SetDirection()
{
  if (Direction == 1)
  {
    Steps++;
  }
  
  if (Direction == 0)
  {
    Steps--;
  }
  
  if (Steps > 7)
  {
    Steps = 0;
  }

  if (Steps < 0)
  {
    Steps = 7;
  }
