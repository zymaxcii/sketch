// servo_miniRobot
// not working

// servo_miniRobot_1_3.ino
// miniRobot.ino
// https://www.robotshop.com/community/robots/show/micro-servo-robot

/*
serial config:
Board: Arduiono Pro / Pro Mini
Port:  tty.usbseriala400eMNr
Programmer: USBtinyISP
*/


#include <Servo.h>      // servo driver

Servo servo_0;
Servo servo_1;
Servo servo_2;
Servo servo_3;

int sensorPin0 = A3;    // shoulder
int sensorPin1 = A2;    // Hand
int sensorPin2 = A1;    // elbow
int sensorPin3 = A0;    // gripper

int count0, arrayStep, arrayMax, countverz, Taster, stepsMax, steps, time = 1000, del = 1000, temp;
unsigned int  verz = 0;

long previousMillis1 = 0;
long previousMillis2 = 0;
long previousMillis3 = 0;
long previousMillis4 = 0;

long previousMicros = 0;

unsigned long currentMillis = millis();
unsigned long currentMicros = micros();

// arrays
int Delay[7] = {0,0,1,3,15,60,300};
int SensVal[4];      // sensor values
float dif[4], ist[4], sol[4],  dir[4];

int joint0[180];
int joint1[180];
int joint2[180];
int joint3[180];

int top = 179;

boolean playmode = false, Step = false;    // status


void setup()
{
  pinMode(4, INPUT_PULLUP);        // restart switch
  pinMode(5, INPUT_PULLUP);        // record step switch; double click to play mode
  
  pinMode(13, OUTPUT);      // indicator led
  digitalWrite(13, HIGH);   // sets LED on
  
  servo_0.attach(8);        // gripper
  servo_1.attach(9);        // elbow
  servo_2.attach(10);       // hand
  servo_3.attach(11);       // shoulder
  
  Serial.begin(9600);
  Serial.println("mini robot ready...");     
  delay(1000);              // original comment out
  digitalWrite(13, LOW);
}


void loop()
{
  currentMillis = millis();
  currentMicros = micros();
  
  Button();     // query switch
  
  if(!playmode) // manual lead
  {        
    if(currentMillis - previousMillis1 > 25) // 40ths of a second
    {
      if (arrayStep < top)
      {
        previousMillis1 = currentMillis;
        readPot();
        mapping();
        move_servo();
        //record();   
      } // end counter < max
    } // end step <20ms
  } // end manual lead
   
  else if(playmode) // play
  {
    if (Step) // next step read from array
    {
      digitalWrite(13, HIGH);
      if (arrayStep < arrayMax)
      {
        arrayStep += 1;
        Read();
        calculate();
        Step = 0;
        digitalWrite(13, LOW);  
      }
      else // list done. restart
      {
        arrayStep = 0; 
        calc_pause();      // read pause length from pot  
        countverz = 0;
        
        while(countverz < verz)
        {
          countverz += 1;
          calc_pause();
          digitalWrite(13, HIGH); delay(25);   
          digitalWrite(13, LOW); delay(975);
        }
      }
      //Serial.println(arrayStep);
    }
    else // carry out
    {
      if (currentMicros - previousMicros > time) // speed for servo update/step
      {
        previousMicros = currentMicros;
        play_servo(); 
      }
    }
  }// end playmode

// ---------------------------------------------------------------------------------Hardware Pause switch
    while (digitalRead(4) == LOW)               // should be 0? original true
      { 
        digitalWrite(13, HIGH); delay(500);   
        digitalWrite(13, LOW); delay(500);
        Serial.print("in read pin4 loop\n");
      }
      
// ---------------------------------------------------------------------------------- text output serial
    // serial output 1 sec
    
    if (currentMillis - previousMillis2 > 5000)
    { 
      previousMillis2 = currentMillis;
      count0 = 0;
      while (count0 < 4)
      {
        int val = SensVal[count0];
      // val = map(val, 142, 888, 0, 180);
        Serial.println(val);
        Serial.println("test");
        count0 += 1;
      }
      Serial.println(playmode); 
      Serial.println(arrayStep);    
      Serial.println(arrayMax);    
      Serial.println(" ");    
    }
}

// ---------------------------------------------------------------------------------------- subroutines

void calc_pause()
{
    readPot();
    temp = SensVal[3];
    
    if (temp < 0) temp = 0;
    temp = map(temp, 0, 680, 0 ,6); 
    verz = Delay[temp];
    
    /*    Serial.print(temp);
          Serial.print(" ");
          Serial.print(verz);
          Serial.print(" ");
          Serial.println(countverz);
    */
}


void readPot()
{
   SensVal[0] = analogRead(sensorPin0); SensVal[0] += -10;     // rotate shoulder
   SensVal[1] = analogRead(sensorPin1); SensVal[1] += 280;     // shoulder 
   SensVal[2] = analogRead(sensorPin2); SensVal[2] += -50;     // Hand
   SensVal[3] = analogRead(sensorPin3); // SensVal[3] += 0;    // gripper
   
   //Serial.print(SensVal[2]);Serial.print(" ");               // CHECK
}


void mapping()
{
  ist[0] = map(SensVal[0], 150, 900, 600, 2400);               // rotate shoulder
  ist[1] = map(SensVal[1], 1000, 100, 550, 2400);              // shoulder
  ist[2] = map(SensVal[2], 120, 860, 400, 2500);               // Hand
  ist[3] = map(SensVal[3], 1023, 0, 500, 2500);                // gripper
  
  //Serial.println(ist[2]); // CHECK
}


void record()
{
  joint0[arrayStep] = ist[0];
  joint1[arrayStep] = ist[1];
  joint2[arrayStep] = ist[2];
  joint3[arrayStep] = ist[3];
}


void Read()
{
  sol[0] = joint0[arrayStep];
  sol[1] = joint1[arrayStep];
  sol[2] = joint2[arrayStep];
  sol[3] = joint3[arrayStep];
}


void move_servo()
{
  // connections mapped
  servo_0.writeMicroseconds(ist[3]); // gripper
  servo_1.writeMicroseconds(ist[2]); // hand
  servo_2.writeMicroseconds(ist[0]); // shoulder
  servo_3.writeMicroseconds(ist[1]); // elbow
}


// ------------------------------------------------------------ calculate individual steps
void calculate()
{
  // calculate distance
  dif[0] = abs(ist[0]-sol[0]);
  dif[1] = abs(ist[1]-sol[1]);
  dif[2] = abs(ist[2]-sol[2]);
  dif[3] = abs(ist[3]-sol[3]);

  // find the greatest way
  stepsMax = max(dif[0],dif[1]);
  stepsMax = max(stepsMax,dif[2]);
  stepsMax = max(stepsMax,dif[3]);
  //Serial.println(stepsMax); 
      
  if (stepsMax < 500)           // slow if maxstep < 400
    del = 1200;
  else
    del = 600;
      
  // calculate single step (step + pos/neg)
  if (sol[0] < ist[0]) dir[0] = 0-dif[0]/stepsMax; else dir[0] = dif[0]/stepsMax;
  if (sol[1] < ist[1]) dir[1] = 0-dif[1]/stepsMax; else dir[1] = dif[1]/stepsMax;
  if (sol[2] < ist[2]) dir[2] = 0-dif[2]/stepsMax; else dir[2] = dif[2]/stepsMax;
  if (sol[3] < ist[3]) dir[3] = 0-dif[3]/stepsMax; else dir[3] = dif[3]/stepsMax;
  //Serial.println(dir4);
}


void play_servo()
{
  steps += 1;
  if (steps < stepsMax)
    {
      time = del*5;                        // approach ramp: original comment out?
      if(steps == 20) time = del*4;          // approach ramp up
      else if(steps == 40) time = del*3;
      else if(steps == 80) time = del*2;
      else if(steps == 100) time = del-1;
      
      if (steps == stepsMax-200) time = del*2;        // stop ramp down
      else if(steps == stepsMax-80) time = del*3;
      else if(steps == stepsMax-40) time = del*4;
      else if(steps == stepsMax-20) time = del*5;
      
      ist[0] += dir[0];                       // set new pos
      ist[1] += dir[1];
      ist[2] += dir[2];
      ist[3] += dir[3];

      // connections mapped
      servo_0.writeMicroseconds(ist[3]);      // gripper 
      servo_1.writeMicroseconds(ist[2]);      // hand
      servo_2.writeMicroseconds(ist[0]);      // shoulder
      servo_3.writeMicroseconds(ist[1]);      // elbow
    }
    else
    {
      Step = 1;                               // next step read from array
      steps = 0;                              // servo intermediate steps
    }
}


// generates lists with servo data (milliseconds)
void data_out()
{
  int i = 0;
  while(i < arrayMax)
  {
    digitalWrite(13, HIGH);
    i += 1;
    Serial.print(joint0[i]); Serial.print(", ");
  }
  Serial.println("Joint0");
  i = 0;
  
  while(i < arrayMax)
  {
    digitalWrite(13, HIGH);
    i += 1;
    Serial.print(joint1[i]); Serial.print(", ");
  }
  Serial.println("Joint1");
  i = 0;
  
  while(i < arrayMax)
  {
    digitalWrite(13, HIGH);
    i += 1;
    Serial.print(joint2[i]); Serial.print(", ");
  }
  Serial.println("Joint2");
  i = 0;
  
  while(i < arrayMax)
  {
    digitalWrite(13, HIGH);
    i += 1;
    Serial.print(joint3[i]); Serial.print(", ");
  }
  Serial.println("Joint3");
}


void Button()
{
  if (digitalRead(5) == LOW)            // original false
  {
    delay(20);
    Serial.print("I am in button()");
    if (digitalRead(5) == HIGH)           // button released: original true
    {
      if (Taster == 0)                    // taster is button in German
      {
        Taster = 1;
        previousMillis3 = currentMillis;
        Serial.print("Status Record "); Serial.println(Taster); 
      }
      else if ((Taster == 1) && (currentMillis - previousMillis3 < 250))
      {
        Taster = 2;
        Serial.println(Taster); 
      }
      /*else if ((Taster == 2) && (currentMillis - previousMillis3 < 500))
      {
        Taster = 3;
        Serial.println(Taster); 
      }*/
    }
  }
    
    if ((Taster == 1) && (currentMillis - previousMillis3 > 1000)) // array describe
    {
      arrayStep += 1;
      arrayMax = arrayStep;
      record();
      Taster = 0;
      playmode = false;
      Serial.print("Record Step: "); Serial.println(arrayStep);
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
    }
    else if (Taster == 2)
    {
      arrayStep = 0;
      playmode = true;
      Taster = 0;
      Step = 1;
      Serial.println("playmode ");
      data_out();
      delay(250);   
      digitalWrite(13, LOW);    
    }
    /*if (Taster == 3)
    {
      // ++ arrayStep
      // playmode = 1;
      Taster = 0;
      Serial.println("Clear ");
    }*/
    if (currentMillis - previousMillis3 > 2000) // Clear button status
    {
      Taster = 0;
      Serial.println("restart ");
    }
}
