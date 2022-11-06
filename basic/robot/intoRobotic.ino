// https://www.intorobotics.com/how-to-control-servo-motors-with-arduino-no-noise-no-vibration/


#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();


#define MIN_PULSE_WIDTH 135
#define MAX_PULSE_WIDTH 470
#define DEFAULT_PULSE_WIDTH 150
#define FREQUENCY 50


const uint8_t servoA = 0;
const uint8_t servoB = 1;
const uint8_t servoC = 2;
const uint8_t servoD = 3;
const uint8_t servoE = 4;

const uint8_t delayServo = 25;


void controlServo0(uint8_t oldPos, uint8_t newPos)
{
  if (oldPos <= newPos) switchServo = UP; else switchServo = DOWN;

  switch (switchServo) {
    case UP: {
        for (uint8_t pos = oldPos; pos <= newPos; pos += 1) {
          delay(delayServo);
          pwm.setPWM(0, 0, angleToPulse(pos));
        }
        break;
      }
    case DOWN: {
        for (uint8_t pos = oldPos; pos >= newPos; pos -= 1) {
          delay(delayServo);
          pwm.setPWM(0, 0, angleToPulse(pos));
        }
        break;
      }
  }
}


void controlServo1(uint8_t oldPos, uint8_t newPos)
{
  if (oldPos <= newPos) switchServo = UP; else switchServo = DOWN;

  switch (switchServo) {
    case UP: {
        for (uint8_t pos = oldPos; pos <= newPos; pos += 1) {
          delay(delayServo);
          pwm.setPWM(1, 0, angleToPulse(pos));
        }
        break;
      }
    case DOWN: {
        for (uint8_t pos = oldPos; pos >= newPos; pos -= 1) {
          delay(delayServo);
          pwm.setPWM(1, 0, angleToPulse(pos));
        }
        break;
      }
  }
}


void controlServo2(uint8_t oldPos, uint8_t newPos)
{
  if (oldPos <= newPos) switchServo = UP; else switchServo = DOWN;

  switch (switchServo) {
    case UP: {
        for (uint8_t pos = oldPos; pos <= newPos; pos += 1) {
          delay(delayServo);
          pwm.setPWM(2, 0, angleToPulse(pos));
        }
        break;
      }
    case DOWN: {
        for (uint8_t pos = oldPos; pos >= newPos; pos -= 1) {
          delay(delayServo);
          pwm.setPWM(2, 0, angleToPulse(pos));
        }
        break;
      }
  }
}

void controlServo3(uint8_t oldPos, uint8_t newPos)
{
  if (oldPos <= newPos) switchServo = UP; else switchServo = DOWN;

  switch (switchServo) {
    case UP: {
        for (uint8_t pos = oldPos; pos <= newPos; pos += 1) {
          delay(delayServo);
          pwm.setPWM(3, 0, angleToPulse(pos));
        }
        break;
      }
    case DOWN: {
        for (uint8_t pos = oldPos; pos >= newPos; pos -= 1) {
          delay(delayServo);
          pwm.setPWM(3, 0, angleToPulse(pos));
        }
        break;
      }
  }
}

void controlServo4(uint8_t oldPos, uint8_t newPos)
{
  if (oldPos <= newPos) switchServo = UP; else switchServo = DOWN;

  switch (switchServo) {
    case UP: {
        for (uint8_t pos = oldPos; pos <= newPos; pos += 1) {
          delay(delayServo);
          pwm.setPWM(4, 0, angleToPulse(pos));
        }
        break;
      }
    case DOWN: {
        for (uint8_t pos = oldPos; pos >= newPos; pos -= 1) {
          delay(delayServo);
          pwm.setPWM(4, 0, angleToPulse(pos));
        }
        break;
      }
  }
}

void robotServoExample() {
  controlServo0(140, 140); 
  controlServo1(145, 145); 
  controlServo3(85, 85); 
  controlServo4(155, 155);
}

void setup() {
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
}

void loop() {
	robotServoExample();
}
