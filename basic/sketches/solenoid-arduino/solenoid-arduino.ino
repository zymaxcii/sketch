void setup() {

  pinMode(2,INPUT);
  pinMode(4,OUTPUT);

}

void loop() {

bool button = digitalRead(2);
if(!button){
  digitalWrite(4,HIGH);
  delay(3000);
  digitalWrite(4,LOW);
}
if(button){
  digitalWrite(4,LOW);
}
}
