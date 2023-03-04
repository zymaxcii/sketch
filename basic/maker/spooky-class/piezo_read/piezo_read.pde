/* Piezo Knock
 * -----------
 * Turn a standard piezo buzzer into a force sensor
 *
 * Created 24 October 2006
 * copyleft 2006 Tod E. Kurt <tod@todbot.com
 * http://todbot.com/
 */


int ledPin = 13;
int piezoPin = 0;

int THRESHOLD = 100;  // set minimum value that indicates a knock

int val = 0;       // variable to store the value coming from the sensor
int t = 0;         // the "time" measured for how long the knock lasts

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("ready");      // indicate we're waiting
}


void loop() {
  digitalWrite(ledPin,LOW);     // indicate we're waiting

  val = analogRead(piezoPin);   // read piezo
  if( val >= THRESHOLD ) {      // is it bigger than our minimum?
    digitalWrite(ledPin, HIGH); // tell the world
    t = 0;
    while(analogRead(piezoPin) >= (THRESHOLD/2)) {
      t++;
    } // wait for it to go LOW  (with a little hysteresis)
    if(t!=0) 
      Serial.println(t);
  }
}
