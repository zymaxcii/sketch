// soundSensor2.ino
// use serial plotter to view result

/*   
modified on June 5, 2018
by Arduino Examples from arduino.cc/en/Tutorial/ReadAnalogVoltage
Home 
*/ 

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
} 

