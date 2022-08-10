// stepper_28byj_48_slim.ino
// https://www.bluetin.io/dc-motors/28byj-48-stepper-motor-driver-code/#more-806

// mty: low level? not using any stepper library

/*
 * File: stepper_28byj_48_slim.ino
 * 28BYJ-48 stepper motor using the ULN2003 interface normally 
 * supplied with this stepper
 *
 * Simple 28BYJ-48 Stepper Driver
 * Version 0.01
 * Last Edit: 15/11/2018
 *
# MIT License
# 
# Copyright (c) 2018 Mark A Heywood
# Author: Mark A Heywood
# https://www.bluetin.io/
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
 */


//+++++++++++ Variables +++++++++++++++
// Track current stepper phase by index
int phaseIndex = 0;

//++++++++++++++ Initialise Constants ++++++++++++++++
// Stepper port pin assignment. Default 0b11110000 on port D
const uint8_t STEPPERPORT = 0xF0;

// Serial port pins mask for port D
const uint8_t SERIALMASK = 0x03;

// Motor 8-phase sequence lookup list
// pins 7, 6, 5, 4 (0011, 0010, 0110, 0100, 1100, 1000, 1001, 0001)

const uint8_t STEPPERPHASES8[8] = {0x30, 0x20, 0x60, 0x40, 0xC0, 0x80, 0x90, 0x10};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++


void phase8 (bool isClockwise)
{
  // Clear stepper pins
  PORTD = PORTD & SERIALMASK;

  // Alter rotation direction
  bool rotateDirection;

  if (isClockwise == true)
  {
    rotateDirection = true;
  }
  else
  {
    rotateDirection = false;
  }
  
  if (rotateDirection == true)
  {
    // Output the next stepper phase - Clockwise
    PORTD = PORTD | STEPPERPHASES8[phaseIndex];

    if (phaseIndex == 7)
    {
      phaseIndex = 0;
    }
    else
    {
      phaseIndex++;
    }
  }
  else
  {
    // Output the next stepper phase - Counter Clockwise
    PORTD = PORTD | STEPPERPHASES8[phaseIndex];
    if (phaseIndex == 0)
    {
      phaseIndex = 7;
    }
    else
    {
      phaseIndex--;
    }
  }
}


void setup()
{
  // Set stepper pins to output
  DDRD = DDRD | STEPPERPORT;
}


long timeNow;
long timeInterval = 2000;
bool rotateDirection = true;
long savedTime = micros();

void loop()
{
  timeNow = micros();
  if (timeNow - savedTime > timeInterval)
  {
    phase8(rotateDirection);
    savedTime = micros();
  }
}
