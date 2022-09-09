int latchPin = 5;
int clockPin = 4;
int dataPin = 2; 
void setup ()
{
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
}
void loop()
{
 for(int a=0; a<256; a++)
    
  {
    digitalWrite(latchPin,LOW); 
    shiftOut(dataPin,clockPin,MSBFIRST,a);
   
    digitalWrite(latchPin,HIGH); 
    delay(1000);
  }
}

