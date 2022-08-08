// dcMotor_control.ino
// https://www.instructables.com/DC-Motor-and-Encoder-for-Position-and-Speed-Contro/


const byte Mo[4] = {10, 5, 11, 6};
const byte So[4] = {2, 4, 3, 7};
const float encod = 6.2;

const byte fa1 = A4;
const byte fa2 = A5;
const byte SW1 = 8;
const byte SW2 = 9;
byte FR1 = 0;
byte FR2 = 0;
bool go1 = false;
bool go2 = false;
long vP1;
long vP2;
long nSS1 = 0;
long nSS2 = 0;
float RPM1 = 0;
float RPM2 = 0;
long anT1 = 0;
long anT2 = 0;

volatile byte Est1;
volatile byte Est2;

void EstSS1(void);
void EstSS2(void);
void pGroRPM(void);
void CalcRPM(void);
void PotSwRead(void);
void MotorCtrl(void);


void setup()
{  
  Serial.begin(9600);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  for (byte i=0;i<4;i++) pinMode(So[i], INPUT);
  attachInterrupt(digitalPinToInterrupt(So[0]), EstSS1, RISING);
  attachInterrupt(digitalPinToInterrupt(So[2]), EstSS2, RISING);
}


void loop()
{
    pGroRPM();
    {
        CalcRPM();
        PotSwRead();
        MotorCtrl();
    }
}


void EstSS1()
{
    Est1 = PIND;
    nSS1++;
}


void EstSS2()
{
    Est2 = PIND;
    nSS2++;
}


void pGroRPM()
{
    unsigned long acT2 = millis();
    if ((acT2-anT2) >= 50)
    {
      anT2 = acT2;
      char val3[82];
      char val1[40];
      char val2[40];
      char strR[5];
      char strL[5];

      go1 = ((Est1 >> 2)&1)&((Est1 >> 4)&1); // Arduino
      go2 = ((Est2 >> 3)&1)&((Est2 >> 7)&1); // Arduino
     

      dtostrf(RPM1, 4, 0, strR);
      dtostrf(RPM2, 4, 0, strL);
      if(RPM1==0) sprintf(val1,"M1 %s RPM, Stopped         ", strR);
      else if(go1){
        sprintf(val1,"M1 %s RPM, Clockwise       ", strR);
      }
      else{sprintf(val1,"M1 %s RPM, CounterClockwise", strR);
        }
      if(RPM2==0) sprintf(val2,"  M2 %s RPM, Stopped", strL);
      else if(go2){
        sprintf(val2,"  M2 %s RPM, Clockwise", strL);
      }
      else{sprintf(val2,"  M2 %s RPM, CounterClockwise", strL);
        }
      sprintf(val3,"%s%s", val1, val2);
      Serial.println(val3);
    }
}


void CalcRPM()
{
    unsigned long acT1 = millis();
    if ((acT1-anT1) >= 50){
        anT1 = acT1;
        RPM1 = (1-2*FR1)*nSS1*20/encod;
        RPM2 = (2*FR2-1)*nSS2*20/encod;
        nSS1=0;
        nSS2=0;
    }
}


void PotSwRead()
{
    FR1 = digitalRead(SW1);
    FR2 = digitalRead(SW2);
    vP1 = analogRead(fa1);
    vP1 = vP1*255/1024;
    vP2 = analogRead(fa2);
    vP2 = vP2*255/1024;
}

void MotorCtrl(){
    analogWrite(Mo[0+FR1], vP1);
    analogWrite(Mo[2+FR2], vP2);
    analogWrite(Mo[1-FR1], 0);
    analogWrite(Mo[3-FR2], 0);
}
