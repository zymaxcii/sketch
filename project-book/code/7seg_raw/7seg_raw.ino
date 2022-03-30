// 7seg_raw.ino

// https://www.electroniclinic.com/common-anode-and-common-cathode-seven-segment-display-arduino-project-for-beginners/


int pina = 8; 
int pinb = 7; 
int pinc = 6; 
int pind = 5; 
int pine = 4; 
int pinf = 3; 
int ping = 2; 

void setup()
{
  pinMode(pina ,OUTPUT); 
  pinMode(pinb ,OUTPUT);
  pinMode(pinc ,OUTPUT);
  pinMode(pind ,OUTPUT);
  pinMode(pine ,OUTPUT);
  pinMode(pinf ,OUTPUT);
  pinMode(ping ,OUTPUT);
}


void loop()
{
  // for zero 
  digitalWrite(pina, LOW); 
  digitalWrite(pinb, LOW);
  digitalWrite(pinc, LOW);
  digitalWrite(pind, LOW);
  digitalWrite(pine, LOW);
  digitalWrite(pinf, LOW);
  digitalWrite(ping, HIGH);
  delay(1000); 

  digitalWrite(pina, HIGH); 
  digitalWrite(pinb, LOW);
  digitalWrite(pinc, LOW);
  digitalWrite(pind, HIGH);
  digitalWrite(pine, HIGH);
  digitalWrite(pinf, HIGH);
  digitalWrite(ping, HIGH);
  delay(1000); 
  
  digitalWrite(pina, LOW); 
  digitalWrite(pinb, LOW);
  digitalWrite(pinc, HIGH);
  digitalWrite(pind, LOW);
  digitalWrite(pine, LOW);
  digitalWrite(pinf, HIGH);
  digitalWrite(ping, LOW);
  delay(1000); 
  
}

