// oled_re_pong.ino
// status: compile ok, upload ok

// https://www.programmingelectronics.com/pong-arduino/?utm_id=LeadGen


#include <U8glib.h>


// Use the emum type to create unique values for our constants
enum
{
  POSITION = 0,
  SOUND,
  SPEED,
  SKEW,
  SIZE,
  LAST
};


// Define and initialize our data structure for the parameters
// The paddle position is changed simply by rotating the RE shaft when in normal game mode.
// There are 4 adjustable (i.e. customizable) parameters: sound, ball speed, skew and paddle size.
// To enter the adjustment/customization mode: press the RE switch. The parameters will cycle sequentially
// from sound->speed->skew->size and then the normal game play will be resumed with the adjusted values


struct
{
  const char *name;
  byte        minValue;
  byte        maxValue;
  byte        incValue;
  byte        activeValue;
}

params[] =
{
  {"Position", 0,  0,  2,  0},   // paddle position
  {"Sound",    0,  1,  1,  1},   // game sound
  {"Speed",    1, 19,  1,  4},   // ball speed
  {"Skew",     1, 15,  1,  1},   // ball skew
  {"Size",    10, 45,  5, 25}    // paddle size
};

const byte numParams = sizeof(params) / sizeof(params[0]);
const byte speakerPin = A3;

byte reMin, reMax, countIncr; // RE minimum, maximum and increment size for currently selected parameter
int screenWidth;              // LCD display's width in pixels
int screenHeight;             // LCD display's height in pixels
int bx, by, br;               // ball's center coordinate (x,y) and its radius respectively
byte px, py;                  // x and y coordinates of paddle's the top left corner
byte allowSound;              // enables or disables sound
int xinc;                     // ball increment in x-direction
int yinc;                     // ball increment in y-direction
byte skew;                    // current skew value
byte pHeight;                 // paddle size (i.e. height in pixels)
const byte pWidth = 6;        // paddle width (in pixels)
unsigned int gameScore = 0;   // tracks the score
boolean inAdjustMode = false; // normal game mode by default
  
char strBuf[16];              // used for string formatting

// Rotary encoder requires 3 pins
const unsigned int ROTARY_ENC_PIN_A  = 2;
const unsigned int ROTARY_ENC_PIN_B  = 3;
const unsigned int ROTARY_ENC_SWITCH = 4;

#define NO_CHANGE 0
#define TURN_CW   1
#define TURN_CCW  2

// Direction     +- ccw  -+  N  +-  cw  -+
// Index         0  1  2  3  4  5  6  7  8
byte aState[] = {3, 2, 0, 1, 3, 2, 0, 1, 3};

byte lastState = 0;
volatile int count[numParams] = {0};
unsigned int Index = 4;
volatile byte encoderStatus = NO_CHANGE;
int switchPressCount;

// Enable the display type to be used
// Currently, only 3 displays listed below have been tested
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_FAST); // for 1306 I2C (128x64)
//U8GLIB_SSD1306_ADAFRUIT_128X64 u8g(6, 7, 9, 8, 10);  // D0=6, D1=7, RES=10, DC=8, CS=9 
//U8GLIB_PCD8544 u8g(6, 7, 9, 8, 10);  // CLK=6, DIN=7, DC=8, CE=9, RST=10 // for 5110 SPI (84x48)



void setup()
{
  Serial.begin(9600);
  Serial.print("Starting Game...");

  // Acquire the display size and dump it out
  screenWidth  = u8g.getWidth();
  screenHeight = u8g.getHeight();
  Serial.print(screenWidth);
  Serial.print("x");
  Serial.println(screenHeight);
    
  // Clear the screen
  u8g.firstPage();
  
  do {} 
     while(u8g.nextPage());
   
  // These variables will hold the currently-set parameter values
  allowSound = params[SOUND].activeValue; // sets sound on/off
  xinc = params[SPEED].activeValue;       // defines the speed
  skew = params[SKEW].activeValue;        // defines the skew
  pHeight = params[SIZE].activeValue;     // defines paddle size

  // Setup paddle parameters (refers to top left corner of paddle)
  params[POSITION].minValue = 0;
  params[POSITION].maxValue = screenHeight - pHeight;
  params[POSITION].activeValue = (params[POSITION].maxValue - params[POSITION].minValue) / 2; // Center the paddle position
  setREParams(POSITION);
    
  // Initialize the RE's settings, based on the default parameter values
  for (int i = 0; i < numParams; i++)
      count[i] = params[i].activeValue;

/*      _ _
      /     \
     |   *   |  [bx,by] is the coordinate of the ball's center
      \ _ _ /
   
         |<->|   br is the ball's radius
*/

  // Configure starting parameters
  randomSeed(analogRead(1));
  br = 2;
  bx = br;
  by = random(br, screenHeight - br);
  yinc = random(-skew, skew);
  px = 0.7 * screenWidth;
  py = params[POSITION].maxValue - params[POSITION].activeValue;

  pinMode(speakerPin, OUTPUT);

  // Set up the gfx font
  u8g.setFont(u8g_font_profont10r);

  // Track the number of times the RE switch has been pressed
  switchPressCount = 0;

  pinMode(ROTARY_ENC_PIN_A,  INPUT);
  pinMode(ROTARY_ENC_PIN_B,  INPUT);
  pinMode(ROTARY_ENC_SWITCH, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(ROTARY_ENC_PIN_A), readEncoderStatus, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ROTARY_ENC_PIN_B), readEncoderStatus, CHANGE);
}


void readEncoderStatus()
{
  byte currState;

  // We form our current state value by assigning the signal
  // from pin A to bit1 and signal from pin B to bit0
  currState = (digitalRead(ROTARY_ENC_PIN_A) * 2) + digitalRead(ROTARY_ENC_PIN_B);

  if (currState != lastState)
  {
    // New state detected.
    // Check if we're moving in the clockwise direction
    if (currState == aState[Index+1])
    {
      Index++;
      if (8 == Index)
      {
        // Successfully completed the sequence of 3->2->0->1->3 for cw
        // Increment the count and reset the index to the nominal setting
        count[switchPressCount] += countIncr;
        if (count[switchPressCount] > reMax)
          count[switchPressCount] = reMax;
        Index = 4;
        encoderStatus = TURN_CW;
      }
    }
    // Check if we're moving in the counterclockwise direction
    else if (currState == aState[Index-1])
    {
      Index--;
      if (0 == Index)
      {
        // Successfully completed the sequence of 3->1->0->2->3 for ccw
        // Decrement the count and reset the index to the nominal setting
        count[switchPressCount] -= countIncr;
        if (count[switchPressCount] < reMin)
          count[switchPressCount] = reMin;
        Index = 4;
        encoderStatus = TURN_CCW;
      }
    }
    lastState = currState;
  }
}


void setREParams(int paramIndex)
{
  countIncr = params[paramIndex].incValue;
  reMin = params[paramIndex].minValue;
  reMax = params[paramIndex].maxValue;
}

void CheckEncoder()
{
  // If encoder shaft was turned, print out the current status
  if (encoderStatus != NO_CHANGE)
  {
    int countTemp;
    
    noInterrupts();     // Disable interrupts
    countTemp = count[switchPressCount];  // Save the variable
    interrupts();       // Re-enable interrupts
    Serial.print(encoderStatus == TURN_CW ? "CW   [" : "CCW  [");
    Serial.print(switchPressCount);
    Serial.print("] ");
    Serial.println(countTemp);  // Use the saved variable
    encoderStatus = NO_CHANGE;
  }

  if (!digitalRead(ROTARY_ENC_SWITCH))
  {
    // Switch was pushed (active LOW). 
    // Reset the count and debounce the switch contacts
    switchPressCount++;
    delay(100);
    while (!digitalRead(ROTARY_ENC_SWITCH));
    delay(100);
  }
}


void playSound(int frequency, int duration)
{
  if (allowSound)
  {
    tone(speakerPin, frequency, duration);
  }
}


void wallSound()
{
  playSound(4000, 50);
}


void paddleSound()
{
  playSound(2000, 50);
}


void scoreSound()
{
  int del = 300, hiFreq = 1250, loFreq = 200;

  for (int i = 0; i < 2; i++)
  {
    playSound(hiFreq, 450);
    delay(del);
    playSound(loFreq, 450);
    delay(del);
  }
}


// This function checks RE switch counter and displays adjustment values
// for sound, speed, skew and size - depending on the counter's value
void CheckAdjustMode(void)
{
  switch (switchPressCount)
  {
    case SOUND:
    case SPEED:
    case SKEW:
    case SIZE:
      // Set the proper adjustment range for this parameter
      setREParams(switchPressCount);
            
      // Save the selected RE value for this parameter
      params[switchPressCount].activeValue = count[switchPressCount];
            
      // Form the string and display in the top right corner of the display
      sprintf(strBuf, "%s:%d", params[switchPressCount].name, params[switchPressCount].activeValue);
      u8g.drawStr(screenWidth-u8g.getStrPixelWidth(strBuf), u8g.getFontAscent(), strBuf);
            
      // Update the selected values for the next screen draw
      allowSound = params[SOUND].activeValue;
      xinc = (xinc < 0) ? -params[SPEED].activeValue: params[SPEED].activeValue;
      skew = params[SKEW].activeValue;
      pHeight = params[SIZE].activeValue;
      inAdjustMode = true;
      break;
            
    case LAST:
      // Exiting customization; restore to normal game play
      switchPressCount = 0;
      params[switchPressCount].maxValue = screenHeight - pHeight;
      setREParams(switchPressCount);
      inAdjustMode = false;
      break;
            
    default:
      inAdjustMode = false;
      break;
  }
}


void loop()
{
  static int frameCount = 0;
  boolean lostPoint = false;
      
  CheckEncoder();

  // Determine the paddle location
  py = params[POSITION].maxValue - constrain(count[POSITION], params[POSITION].minValue, params[POSITION].maxValue);
    
  // If the ball reached the left wall, reverse its direction
  if (xinc <= 0 && bx <= br)
  {
    xinc *= -1;
    wallSound();
  }

  // See if the ball hit the paddle...
  if((xinc > 0) && (bx+br >= px) && (by+br >= py) && (by <= py+pHeight+br) && (bx-br <= px+pWidth))
  {
    // Reverse its x-direction
    xinc *= -1;

    // Reverse its y-direction, depending on where ball touched paddle
    // top 3/7 of paddle bounces ball in 1 direction and bottom 3/7 of paddle 
    // bounces it in oppo direction
    // (with some randomness thrown in, as a function of skew)
    if (by <= py + (3 * pHeight) / 7)
      yinc = -random(1, skew + 1); // Add some randomness to ball motion, based on current skew setting
    if (by >= py + (4 * pHeight) / 7)
      yinc = random(1, skew + 1);  // Add some randomness to ball motion, based on current skew setting

    paddleSound();
  }

  // Check if the ball is clear of the top and bottom walls
  if (by+yinc >= (screenHeight-br) ||   // is the ball above the bottom wall, or
     (by+yinc <= br))                   // is the ball below the top wall
  {
    // ...bounce it off the wall
    yinc *= -1;
    wallSound();
  }

  // See if the ball missed the paddle and reached the right side.
  // If so, update score and relaunch it from the left side.
  if (bx >= screenWidth)
  {
    xinc = params[SPEED].activeValue;
    yinc = random(-skew, skew);
    bx = px - ((px / xinc) *  xinc);
    by = random(br, screenHeight-br);

    if (inAdjustMode == false)
    {
      // We're not in adjustment mode; allow the score to be reflected.
      gameScore++;
      lostPoint = true;
      Serial.println("Lost Point - incremented gameScore.");
    }
  }
  else
  {
    // Advance the ball in the horizontal and vertical directions
    bx += xinc;
    by += yinc;
  }
      
  u8g.firstPage();
  do {
    if (lostPoint == false)
    {
      // Draw normal screens: regular play or adjust screens
      if (!(frameCount++ % 2))
      {
        // Check the Adjust Mode on alternate frames; this gives better performance
        CheckAdjustMode();
      }

      // Draw the borders
      u8g.drawLine(0, 0, screenWidth-1, 0);
      u8g.drawLine(0, 0, 0, screenHeight-1);
      u8g.drawLine(0, screenHeight-1, screenWidth-1, screenHeight-1);

      // Make things look different when in adjust mode vs play mode
      if (inAdjustMode == true)
      {
        u8g.drawCircle(bx, by, br, U8G_DRAW_ALL); // Draw the ball as a circle
        u8g.drawFrame(px, py, pWidth, pHeight);   // Draw the paddle as a frame
      }
      else
      {
        u8g.drawDisc(bx, by, br, U8G_DRAW_ALL);   // Draw the ball as a disc (i.e. solid circle)
        u8g.drawRBox(px, py, pWidth, pHeight, 2); // Draw paddle as solid box; use rounded corners with a radius of 2
      }

      sprintf(strBuf, "%d", gameScore);
      u8g.drawStr((px+pWidth+screenWidth-u8g.getStrPixelWidth(strBuf))/2, screenHeight/2, strBuf);
    }
    else
    {
      // Display the "You Lose" screen
      u8g.setFont(u8g_font_gdb20r); // switch to bigger font
      strcpy (strBuf, "TRY");
      u8g.drawStr((screenWidth-u8g.getStrPixelWidth(strBuf))/2, screenHeight/2, strBuf);
      strcpy (strBuf, "AGAIN!");
      u8g.drawStr((screenWidth-u8g.getStrPixelWidth(strBuf))/2, screenHeight, strBuf);
      u8g.setFont(u8g_font_profont10r); // switch back to our normal font
     }
  } while (u8g.nextPage());

  if (lostPoint == true)
  {
    // Play annoying sound and let the user see the "You Lose" screen.
    scoreSound();
    delay(200);
  }
}
