// read_encoder_output.ino

// original pins 3,4
#define MotFwd  4   // Motor Forward pin
#define MotRev  7   // Motor Reverse pin
#define MotEnable 6 // Motor Enable pin runs on PWM signal

// original pins 2,3
int encoderPin1 = 2; //Encoder Output 'A' must connected with intreput pin of arduino
int encoderPin2 = 3; //Encoder Otput 'B' must connected with intreput pin of arduino

volatile int lastEncoded = 0;   // Here updated value of encoder store
volatile long encoderValue = 0; // Raw encoder value


void setup()
{
  pinMode(MotEnable, OUTPUT);
  pinMode(MotFwd, OUTPUT); 
  pinMode(MotRev, OUTPUT); 
  
  Serial.begin(9600);   //initialize serial comunication

  pinMode(encoderPin1, INPUT_PULLUP); 
  pinMode(encoderPin2, INPUT_PULLUP);

  // set motor speed so that don't have to pull in and out the jumper
  analogWrite(MotEnable, 128); 
  

  // don't understand this
  //  digitalWrite(encoderPin1, HIGH);   //turn pullup resistor on
  //  digitalWrite(encoderPin2, HIGH);   //turn pullup resistor on

  // call updateEncoder() when any high/low changed seen
  // on interrupt 0 (pin 2), or interrupt 1 (pin 3) 
  attachInterrupt(digitalPinToInterrupt(encoderPin1), updateEncoder, CHANGE); 
  attachInterrupt(digitalPinToInterrupt(encoderPin2), updateEncoder, CHANGE);
}


void loop()
{

  for (int i = 0; i <= 500; i++)
  {
    digitalWrite(MotFwd, LOW); 
    digitalWrite(MotRev, HIGH);
    Serial.print("Forward  ");
    Serial.println(encoderValue);
  }

  delay(1000);

  for (int i = 0; i <= 500; i++)
  {
    digitalWrite(MotFwd, HIGH); 
    digitalWrite(MotRev, LOW);
    Serial.print("Reverse  ");
    Serial.println(encoderValue);
  }

  delay(1000);
} 


void updateEncoder()
{
  int MSB = digitalRead(encoderPin1);      // MSB = most significant bit
  int LSB = digitalRead(encoderPin2);      // LSB = least significant bit

  int encoded = (MSB << 1) | LSB;          //converting the 2 pin value to single number
  
  int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue --;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue ++;

  lastEncoded = encoded;                   //store this value for next time
}
