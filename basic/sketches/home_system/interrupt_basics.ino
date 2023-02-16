


volatile float startTime;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(2,INPUT_PULLUP);
pinMode(13,OUTPUT);
Serial.println("press the button when you see the light");
randomSeed(analogRead(A0));
delay(random(1000,5000));
digitalWrite(13,HIGH);
startTime=millis();
attachInterrupt(0,bang,LOW);
}


void bang(){
detachInterrupt(0);
Serial.println("BANG!");

float endTime=millis();
Serial.print("Your reaction time is: :");
Serial.print(endTime-startTime);
Serial.print(" milliseconds");



}





void loop() {
  // put your main code here, to run repeatedly:

}
