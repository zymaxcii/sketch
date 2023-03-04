/* Theremin
 * --------
 *
 *
 * Created 24 October 2006
 * copyleft 2006 Tod E. Kurt <tod@todbot.com
 * http://todbot.com/
 */

int potPin = 0;    // select the input pin for the potentiometer
int speakerPin = 7;

int val = 0;

void setup() {
  pinMode(speakerPin, OUTPUT); 
  beginSerial(9600);
  Serial.println("ready");
}

void loop() {
  digitalWrite(speakerPin, LOW);
  
  val = analogRead(potPin);    // read value from the sensor
  val = val*2;                 // process the value a little
  //val = val/2;                 // process the value a little
   
  for( int i=0; i<500; i++ ) {  // play it for 50 cycles
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(val);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(val);
  }
}
