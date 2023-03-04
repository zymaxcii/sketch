#define pot A0
#define pwmPin 11
int potRead = 0;
int pwmOut = 0;





void setup() {
  // put your setup code here, to run once:
pinMode(pwmPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
potRead = analogRead(pot);
pwmOut = map(potRead,0,1024,0,255);
analogWrite(pwmPin,pwmOut);
delay(100);
}
