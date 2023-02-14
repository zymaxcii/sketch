// buzzer_forceSensor.ino
// status: compile ok, upload ok
// not sure how it works

/* Piezo Knock
 * -----------
 * Turn a standard piezo buzzer into a force sensor
 *
 * Created 24 October 2006
 * copyleft 2006 Tod E. Kurt <tod@todbot.com
 * http://todbot.com/
 */


int ledPin = 13;
int motorPin = 9;       // dc motor or servo?
int piezoPin = 3;

int THRESHOLD = 272;    // set minimum value that indicates a knock, original is 100

int val = 0;            // variable to store the value coming from the sensor
int t = 0;              // "time" measured for how long the knock lasts


void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("ready");      // indicate we're waiting
}


void loop()
{
  digitalWrite(ledPin,LOW);     // indicate we're waiting

  val = analogRead(piezoPin);   // read piezo
  Serial.println(val);
  
  if ( val > THRESHOLD )
  {
    // is it bigger than our minimum?
    digitalWrite(ledPin, HIGH);       // tell the world
    t = 0;
    
    while (analogRead(piezoPin) > THRESHOLD)
    {
      t++;
    } // wait for it to go LOW  (with a little hysteresis)
    
    if (t!=0)
    {
      Serial.print("knock! ");
      Serial.println(t);
      
      analogWrite(motorPin, 100);
      delay(1000);
      analogWrite(motorPin, 0);
    }
  }
}
 
