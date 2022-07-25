// limitSwitch.ino
// https://www.electroniclinic.com/arduino-uno-limit-switch-tutorial/


int Lswitch = 2; 
int led = 13; 
int flag = 0; 

void setup()
{
  Serial.begin(9600); 
  pinMode(Lswitch, INPUT); 
  pinMode(led, OUTPUT); 
}

void loop()
{
  if( (digitalRead(Lswitch) == LOW) && (flag == 0) ) 
  {
    Serial.println("door is closed"); 
flag = 1; 
delay(20); 
  }
  
    if( (digitalRead(Lswitch) == HIGH) && (flag == 1) ) 
  {
    Serial.println("door is opened"); 
flag = 0;
delay(20); 
  }
  
  if ( flag == 1 ) 
  {
    digitalWrite(led, HIGH); 
    delay(1000); 
    digitalWrite(led, LOW); 
    delay(1000); 
  }
  
    if ( flag == 1 ) 
  {
digitalWrite(led, LOW); 
  }
  
  digitalWrite(Lswitch, HIGH); 

}
