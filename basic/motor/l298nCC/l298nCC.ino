// l298nCC.ino

// https://create.arduino.cc/projecthub/Fouad_Roboticist/dc-motors-control-using-arduino-pwm-with-l298n-h-bridge-d6ec91

// hardware setup
// 1 dc motor connected to l298n motor driver

const int IN1 = 7;
const int IN2 = 6;
const int IN3 = 5;
const int IN4 = 4;
const int ENA = 9;
const int ENB = 3;


void setup()
{
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);

}


void loop()
{
  //control speed 
  analogWrite(ENA, 255);
  analogWrite(ENB, 255); 
  
  //control direction 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
