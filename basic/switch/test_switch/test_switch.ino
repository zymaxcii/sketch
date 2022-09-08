const int switchPin = 8;
int switchVal = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT_PULLUP);    // nc: normally closed
  Serial.begin(9600);
}


void loop() {
  switchVal = digitalRead(switchPin);
  
  Serial.println(switchVal);
  delay(20);
}
