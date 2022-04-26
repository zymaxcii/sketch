// test-buttons.ino

const int panZero  = 31;
const int panRight = 32;
const int panLeft  = 33;

const int tiltZero = 34;
const int tiltUp   = 35;
const int tiltDown = 36;


const int leftButton  = 41;
const int rightButton = 42;
const int upButton    = 43;
const int downButton  = 44;


int leftBtnStatus  = 0;
int rightBtnStatus = 0;
int upBtnStatus    = 0;
int downBtnStatus  = 0;

int panZeroStatus  = 0;
int panRightStatus = 0;
int panLeftStatus  = 0;

int tiltZeroStatus = 0;
int tiltUpStatus   = 0;
int tiltDownStatus = 0;

int speed;

void setup()
{
  pinMode(leftButton,  INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(upButton,    INPUT_PULLUP);
  pinMode(downButton,  INPUT_PULLUP);

  pinMode(panZero,  INPUT_PULLUP);
  pinMode(panRight, INPUT_PULLUP);
  pinMode(panLeft,  INPUT_PULLUP);
  
  pinMode(tiltZero, INPUT_PULLUP);
  pinMode(tiltUp,   INPUT_PULLUP);
  pinMode(tiltDown, INPUT_PULLUP);
  Serial.begin(9600);
}


void loop()
{
  leftBtnStatus  = digitalRead(leftButton);  
  rightBtnStatus = digitalRead(rightButton);  
  upBtnStatus    = digitalRead(upButton);  
  downBtnStatus  = digitalRead(downButton);  

  speed = analogRead(A0);

  panZeroStatus  = digitalRead(panZero);  
  panRightStatus = digitalRead(panRight);  
  panLeftStatus    = digitalRead(panLeft);  

  tiltZeroStatus  = digitalRead(tiltZero);  
  tiltUpStatus = digitalRead(tiltUp);  
  tiltDownStatus    = digitalRead(tiltDown);  


  Serial.print(leftBtnStatus);
  Serial.print(",");
  Serial.print(rightBtnStatus);
  Serial.print(",");
  Serial.print(upBtnStatus);
  Serial.print(",");
  Serial.print(downBtnStatus);
  Serial.print(",");

  Serial.print(speed);
  Serial.print(",");


  Serial.print(panZeroStatus);
  Serial.print(",");
  Serial.print(panRightStatus);
  Serial.print(",");
  Serial.print(panLeftStatus);
  Serial.print(",");

  Serial.print(tiltZeroStatus);
  Serial.print(",");
  Serial.print(tiltUpStatus);
  Serial.print(",");
  Serial.println(tiltDownStatus);

  delay(300);
}
