// pinwheel.ino
// chapter 9
// pinwheel

// connect servo to pin 9
// connect toggle switch to pin 2
// toggle the switch to spin the pinwheel


const int switchPin = 6;
const int motorPin  = 11;

int switchState = 0;


void setup() 
{
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);    // or INPUT_PULLUP
}


void loop()
{
  switchState = digitalRead(switchPin);
  Serial.println(switchState);
  if (switchState == HIGH)
  {
    digitalWrite(motorPin, HIGH);
  }
  else
  {
    digitalWrite(motorPin, LOW);
  }
}
