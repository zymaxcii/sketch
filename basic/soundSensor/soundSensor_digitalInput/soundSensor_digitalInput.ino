
// https://electropeak.com/learn/interfacing-ky-037-sound-sensor-with-arduino/

/*   
modified on Spe 2, 2020
by MohammedDamirchi
Home 
*/ 
const int mic =  3;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the digital pin as an input:
  pinMode(mic, INPUT);
}

void loop() {
  // check if the mic digitalout is high.
  if (digitalRead(mic) == HIGH) {
    Serial.println("hearing something");
  }
}
