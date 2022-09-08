// pid_close_loop.ino
 
#include <PID_v1.h>

#define MotEnable 6 // Motor Enanble pin Runs on PWM signal
#define MotFwd    7 // Motor Forward pin IN2 swap to see
#define MotRev    4 // Motor Reverse pin IN1 4, 7 or 7, 4
                      
String   readString;  // This while store the user input data
int User_Input  = 0; // This while convert input string into integer

int encoderPin1 = 2; //Encoder Output 'A' must connected with intreput pin of arduino
int encoderPin2 = 3; //Encoder Otput 'B' must connected with intreput pin of arduino

volatile int   lastEncoded = 0; // Here updated value of encoder store
volatile long encoderValue = 0; // Raw encoder value

// what is the actual value for pololu 37D?
int PPR = 64;    // Encoder Pulse per revolution: original 1600 pololu: 128
int angle = 360; // Maximum degree of motion
int REV = 0;     // Set point REQUIRED ENCODER VALUE

int lastMSB = 0;
int lastLSB = 0;

// original 5,1,0.01
double kp = 1 , ki = 1 , kd = 0.01;             // modify for optimal performance
double input = 0, output = 0, setpoint = 0;
PID myPID(&input, &output, &setpoint, kp, ki, kd, DIRECT);  


void setup()
{
  pinMode(MotEnable, OUTPUT);
  pinMode(MotFwd, OUTPUT); 
  pinMode(MotRev, OUTPUT); 
  Serial.begin(9600);              //initialize serial comunication

  pinMode(encoderPin1, INPUT_PULLUP); 
  pinMode(encoderPin2, INPUT_PULLUP);

  digitalWrite(encoderPin1, HIGH); //turn pullup resistor on
  digitalWrite(encoderPin2, HIGH); //turn pullup resistor on

  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2) or interrupt 1 (pin 3) 
  attachInterrupt(digitalPinToInterrupt(encoderPin1), updateEncoder, CHANGE); 
  // attachInterrupt(digitalPinToInterrupt(encoderPin2), updateEncoder, CHANGE);
    
  TCCR1B = TCCR1B & 0b11111000 | 1;  // set 31KHz PWM to prevent motor noise

  myPID.SetMode(AUTOMATIC);          //set PID in Auto mode
  myPID.SetSampleTime(1);            // refresh rate of PID controller
  myPID.SetOutputLimits(-125, 125);  // MAX PWM value to move motor
                                     // change in value reflects change in speed of motor
}


void loop()
{
  while (Serial.available())
  {
    delay(3);                  // a small delay
    char c = Serial.read();    // storing input data
    readString += c;           // accumulate each of the characters in readString
  }
 
  // Verify that the variable contains information
  if (readString.length() >0)
  { 
    Serial.println(readString.toInt());  // printing the input data in integer form
    User_Input = readString.toInt();     // input data is store in integer form
  }

// User_Input = 65;

  // why cannot use ppr? pololu is 128
  REV = map (User_Input, 0, 360, 0, PPR); // mapping degree into pulse: original 1600 pololu: 128
  
  Serial.print("REV: "); 
  Serial.println(REV);                     // printing REV value  

  setpoint = REV;                          // PID while work to achieve this value consider as SET value
  input = encoderValue ;                   // data from encoder consider as a Process value
  
  Serial.print("encoderValue: ");
  Serial.println(encoderValue);
  
  myPID.Compute();                         // calculate new output
  pwmOut(output);  
}



void pwmOut(int out)
{
  // if REV > encoderValue motor move in forward direction                
  if (out > 0)
  {                         
    analogWrite(MotEnable, out);           // Enabling motor enable pin to reach the desire angle
    forward();                             // calling motor to move forward
  }
  else
  {
    analogWrite(MotEnable, abs(out));      // if REV < encoderValue motor move in forward direction
    reverse();                             // calling motor to move reverse
  }
  
  readString="";                           // Cleaning User input, ready for new Input
}


// Interrupt service routine
void updateEncoder()
{
  int MSB = digitalRead(encoderPin1);      //MSB = most significant bit
  int LSB = digitalRead(encoderPin2);      //LSB = least significant bit

  int encoded = (MSB << 1) | LSB;          //converting the 2 pin value to single number
  int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue --;

  lastEncoded = encoded;                   //store this value for next time
}


void forward ()
{
  digitalWrite(MotFwd, HIGH); 
  digitalWrite(MotRev, LOW); 
}


void reverse ()
{
  digitalWrite(MotFwd, LOW); 
  digitalWrite(MotRev, HIGH); 
}


void finish ()
{
  digitalWrite(MotFwd, LOW); 
  digitalWrite(MotRev, LOW); 
}
