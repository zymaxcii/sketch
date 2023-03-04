/* Precise Stepper Motor Control
 *  
 *  learnelectronics
 *  11 MAY 2017
 *  
 *  www.youtube.com/c/learnelectronics
 *  arduino0169@gmail.com
 *  
 *  Stepper.h library is installed by default
 */


#include "Stepper.h"                                              //include Stepper library
#define STEPS  32                                                 //Number of steps
                   
volatile boolean TurnDetected;                                    //volatile variable needed for interupt
volatile boolean rotationdirection;                               //volatile variable for direction

const int PinCLK=2;                                               //rotary enc clock pin (used for interupt)
const int PinDT=3;                                                //rotary enc data pin (used for direction)
const int PinSW=4;                                                //rotary enc switch (used to reset stepper)

int RotaryPosition=0;                                             //int to store stepper position

int PrevPosition;                                                 //int for rot enc prev pos
int StepsToTake;                                                  //int for num of steps to move


Stepper small_stepper(STEPS, 8, 10, 9, 11);                       //Create instance of Stepper called small_stepper


void isr ()  {                                                    //interupt runs if clock goes low
  delay(4);
  if (digitalRead(PinCLK))                                        //read clock
    rotationdirection= digitalRead(PinDT);                        //read data and compare to clock
  else
    rotationdirection= !digitalRead(PinDT);                       //read data and compare to clock
  TurnDetected = true;                                            //set flag
}

void setup ()  {
  
pinMode(PinCLK,INPUT);                                            //rot enc clk set as input
pinMode(PinDT,INPUT);                                             //rot enc data set as input
pinMode(PinSW,INPUT);                                             //rot enc switcg set as input
digitalWrite(PinSW, HIGH);                                        //switch set HIGH
attachInterrupt (0,isr,FALLING);                                  //interupt 0 on pin 2, call isr, falling
}

void loop ()  {
  small_stepper.setSpeed(600);                                    //set rotation speed
  if (!(digitalRead(PinSW))) {                                    //is buton pressed
    if (RotaryPosition == 0) {                                    //has buton been pressesd prev
    } else {
        small_stepper.step(-(RotaryPosition*50));                 //if neither is true move
        RotaryPosition=0;                                         //reset position
      }
    }

  
  if (TurnDetected)  {                                            //if rot enc was moved
    PrevPosition = RotaryPosition;                                //save the last position
    if (rotationdirection) {                                      //check direction of turn
      RotaryPosition=RotaryPosition-1;}                           //counterclockwise
    else {
      RotaryPosition=RotaryPosition+1;}                           //clockwise

    TurnDetected = false;                                         //do not repeat

    
    if ((PrevPosition + 1) == RotaryPosition) {                   //move clockwise
      StepsToTake=50;                                             //num steps
      small_stepper.step(StepsToTake);                            //do move
    }

    if ((RotaryPosition + 1) == PrevPosition) {                   //move counterclockwise
      StepsToTake=-50;                                            //num steps
      small_stepper.step(StepsToTake);                            //do move
    }
  }
}
