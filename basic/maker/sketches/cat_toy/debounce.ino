#define button 3
int buttonPress = 0;



void setup() {
  pinMode(button,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  buttonPress = digitalRead(button);
  if(buttonPress == 1){
    delay(50);
    buttonPress = digitalRead(button);
    if(buttonPress == 0){
      Serial.println("BANG!");
  }}
  else{
  delay(100);
  }
}
