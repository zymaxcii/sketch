// 7seg_raw.ino
// https://HIGH.electroniclinic.com/common-anode-and-common-cathode-seven-segment-display-arduino-project-for-beginners/

// My standard I/O connections:
// segments A,B,C,D,E,F,G,DP to digital pins 6,7,8,9,10,11,12,13
// common cathode 42056W8 pins 3,8 to GND
// pins 0,1 for serial
// pins 2,3,4,5 for switches

int pina = 6; 
int pinb = 7; 
int pinc = 8; 
int pind = 9; 
int pine = 10; 
int pinf = 11; 
int ping = 12; 


void setup()
{
  pinMode(pina, OUTPUT); 
  pinMode(pinb, OUTPUT);
  pinMode(pinc, OUTPUT);
  pinMode(pind, OUTPUT);
  pinMode(pine, OUTPUT);
  pinMode(pinf, OUTPUT);
  pinMode(ping, OUTPUT);
}


void loop()
{
  // for zero 
  // common cathode: HIGH to light up a segment
  digitalWrite(pina, HIGH); 
  digitalWrite(pinb, HIGH);
  digitalWrite(pinc, HIGH);
  digitalWrite(pind, HIGH);
  digitalWrite(pine, HIGH);
  digitalWrite(pinf, HIGH);
  digitalWrite(ping, LOW);
  delay(1000);

  // for one
  digitalWrite(pina, LOW); 
  digitalWrite(pinb, HIGH);
  digitalWrite(pinc, HIGH);
  digitalWrite(pind, LOW);
  digitalWrite(pine, LOW);
  digitalWrite(pinf, LOW);
  digitalWrite(ping, LOW);
  delay(1000); 
  
  // for two
  digitalWrite(pina, HIGH); 
  digitalWrite(pinb, HIGH);
  digitalWrite(pinc, LOW);
  digitalWrite(pind, HIGH);
  digitalWrite(pine, HIGH);
  digitalWrite(pinf, LOW);
  digitalWrite(ping, HIGH);
  delay(1000); 
  
}
