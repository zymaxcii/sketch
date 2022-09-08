// robot_pan_tilt.ino
// https://www.youtube.com/watch?v=-cuxyNSaGRo

#define MY_BLUETOOTH Serial2   // Hardware Serial of Arduino Mega

// for Serial

char robotMode;
int  SpeedOrPosition=0;

// for DC Motor

#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(4);
AF_DCMotor motor4(3);

int motorSpeed = 60;          // 60 = LOWEST SPEED

int motor1State=RELEASE;
int motor2State=RELEASE;
int motor3State=RELEASE;
int motor4State=RELEASE;

// for Servo

#include <Servo.h>

Servo LRServo;                // Servo for LeftRight. Server0 connetor -> Digital Pin9
Servo UDServo;                // Servo for Up and Down. Server1 connetor -> Digital Pin X

boolean isServoMode = false;

int LRcenter = 83;            // 6WD car=80, ITX car=83
int UDcenter = 90;
int LRposition = LRcenter;
int UDposition = UDcenter;

void setup()
{
  Serial.begin(9600);

  // Bluetooth setting
  MY_BLUETOOTH.begin(9600);
  Serial.println("bluetooth start");   // Send test message to other device
  MY_BLUETOOTH.setTimeout(100);        // 씨리얼통신 값받는데 기다리는시간.

  // turn on motor

  motor1.run(motor1State);
  motor2.run(motor2State);
  motor3.run(motor3State);
  motor4.run(motor4State);

  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);

  LRServo.attach(9);       
  UDServo.attach(10);

  isServoMode = true;                   // re-postion servo
}


void loop()
{
  if (MY_BLUETOOTH.available() >0 )
  {
     // read from Bluetooth, USB serial or Smth...
     // The bytes array should be like: F2, F90, F250
     robotMode = MY_BLUETOOTH.read();                   // read first byte

     // read rest of bytes as string. this code make slow to response
     SpeedOrPosition = MY_BLUETOOTH.readString().toInt();
  
     Serial.print("Mode:");
     Serial.println(robotMode);
     Serial.print("Speed:");
     Serial.println(SpeedOrPosition);

     switch (robotMode)
     {
        // DC모터 제어
        case 'F':  
              motorSpeed = constrain(SpeedOrPosition, 60, 255); // 60 is mininum speed
              motor4State = FORWARD;
              motor3State = FORWARD;
              motor2State = FORWARD;
              motor1State = FORWARD;
              break;  

        case 'B': 
              motorSpeed = constrain(SpeedOrPosition, 60, 255); // 60 is mininum speed
              motor4State = BACKWARD;
              motor3State = BACKWARD;
              motor2State = BACKWARD;
              motor1State = BACKWARD;
              break;        

        case 'L':  
              motorSpeed = constrain(SpeedOrPosition, 60, 255); // 60 is mininum speed
              motor4State = BACKWARD;
              motor3State = FORWARD;
              motor2State = FORWARD;
              motor1State = BACKWARD;
              break;    

        case 'R':
              motorSpeed = constrain(SpeedOrPosition, 60, 255); // 60 is mininum speed
              motor4State = FORWARD;
              motor3State = BACKWARD;
              motor2State = BACKWARD;
              motor1State = FORWARD;
              break;

       case 'S':
              // Stop Motor
              motorSpeed = 0;
              motor4State = RELEASE;
              motor3State = RELEASE;
              motor2State = RELEASE;
              motor1State = RELEASE;

              isServoMode = true;     
              LRposition = 95;     
              UDposition = 100;    
              break;
      
       case 'f':
              // Servo All Center
              isServoMode = true;     
              LRposition = LRcenter;    
              UDposition = UDcenter ;    
              break;

       case 'r':
              // Move LRservo
              isServoMode = true;     
              LRposition = LRcenter-constrain(SpeedOrPosition, 0, 90);   // 앱에서 0~100까지의 값이 옴
              break;  

      case 'l':
              // Move LRservo
              isServoMode = true;     
              LRposition = LRcenter+constrain(SpeedOrPosition, 0, 90);   // 앱에서 0~100까지의 값이 옴
              break;  

       case 'u':
              // Move UDservo
              isServoMode = true;        
              UDposition = UDcenter+constrain(SpeedOrPosition, 0, 60);   // 앱에서 0~100까지의 값이 옴
              break;  

       case 'd':
              // Move UDservo
              isServoMode = true;        
              UDposition= UDcenter-constrain(SpeedOrPosition, 0, 15);
              //앱에서 0~100까지의 값이 옴. 서보 보호를 위해 하각 20도로 제한
              break;  

        case 'a':
              // Special only for NewsRobot. right->left->right->front
              LRServo.write(LRcenter+30);    // right  
              delay(400);                    // time for motorf
              LRServo.write(LRcenter-30);    // left                 
              delay(400);    

              LRServo.write(LRcenter+30);    // right  
              delay(400);                    // time for motor 
              LRServo.write(LRcenter);       // front                      
              delay(300);                                        
              break;  

        case 'b':
             // Special only for NewsRobot. down->front->down->front
             UDServo.write(UDcenter-15);      // down                      
             delay(400);                      // time for motor
             UDServo.write(UDcenter+5);       // front                           
             delay(400);    

             UDServo.write(UDcenter-15);      // down        
             delay(400);    
             UDServo.write(UDcenter+5);       // front                        
             delay(400);                                        
             break;  
        }  // end switch
  } //end if

  // Motor Move 
  motor4.run(motor4State);
  motor3.run(motor3State);
  motor2.run(motor2State);
  motor1.run(motor1State);

  motor3.setSpeed(motorSpeed);  
  motor4.setSpeed(motorSpeed);   
  motor2.setSpeed(motorSpeed);  
  motor1.setSpeed(motorSpeed);  
  // End Motor Move

  if (isServoMode==true)
  {
     LRServo.write(LRposition);     
     delay(100);                              // time for Move 
     UDServo.write(UDposition);                              
     delay(100);                              // time for Move
     isServoMode = false;
  }
}

