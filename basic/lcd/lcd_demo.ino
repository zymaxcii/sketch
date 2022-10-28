// https://forum.crystalfontz.com/threads/connect-a-cfa-634-a-seeeduino-arduino-using-i2c-with-example-sketch.5784/


//============================================================================
// This is an example use of the Crystalfontz CFA634 I2C 20x4 LCD, driven by
// an Arduino Uno or Seeeduino v4.2 set to 5v.
//
// The demonstration shows menus (stored in flash / PROGMEM) and bar graphs.
// 
// Wiring information is available in our forum:
//
//  https://forum.crystalfontz.com/showthread.php/7483
//
// There is a video of the operation in action on YouTube:
//
//  https://www.youtube.com/watch?v=lsuUchaF-FM
//
//  2018 - 11 - 01 Brent A. Crosby / Crystalfontz
//
// Display is Crystalfontz CFA634-TFH-KC
//   https://www.crystalfontz.com/product/cfa634tfhkc
//---------------------------------------------------------------------------
//This is free and unencumbered software released into the public domain.
//
//Anyone is free to copy, modify, publish, use, compile, sell, or
//distribute this software, either in source code form or as a compiled
//binary, for any purpose, commercial or non-commercial, and by any
//means.
//
//In jurisdictions that recognize copyright laws, the author or authors
//of this software dedicate any and all copyright interest in the
//software to the public domain. We make this dedication for the benefit
//of the public at large and to the detriment of our heirs and
//successors. We intend this dedication to be an overt act of
//relinquishment in perpetuity of all present and future rights to this
//software under copyright law.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//OTHER DEALINGS IN THE SOFTWARE.
//
//For more information, please refer to <http://unlicense.org/>
//============================================================================
#include <Arduino.h>
#include <Wire.h>  //I2C library
//============================================================================
//   ARD      | Port | LCD           | Color | Note
// -----------+------+---------------|-------|----------------------------
//  SCL       |  PC5 | I2C SCL Clock | Blue  | (5K resistor pull up to 5v)
//  SDA       |  PC4 | I2C SDA Data  | Green | (5K resistor pull up to 5v)
//============================================================================
#define CFA_634_I2C_ADDRESS  (42)

#define USE_PRINTF //Saves ~1600 bytes
//============================================================================
#ifdef USE_PRINTF
// ref http://playground.arduino.cc/Main/Printf
#include <stdarg.h>
void SerPrintFF(const __FlashStringHelper *fmt, ... )
  {
  char
    tmp[128]; // resulting string limited to 128 chars
  va_list
    args;
  va_start(args, fmt );
  vsnprintf_P(tmp, 128, (const char *)fmt, args);
  va_end (args);
  Serial.print(tmp);
  }
#endif
//----------------------------------------------------------------------------
// ref http://scott.dd.com.au/wiki/Arduino_Static_Strings
void SerialPrint_P(const char flash_string[])
  {
  uint8_t
    c;
  for(;0x00 != (c = pgm_read_byte(flash_string)); flash_string++)
    {
    Serial.write(c);
    }
  }
//============================================================================
//This does not depend on printf so it is small
void I2C_String_XY(uint8_t col, uint8_t row,
                   const __FlashStringHelper *flash_string )
  {
   //Start the I2C transaction
  Wire.beginTransmission(CFA_634_I2C_ADDRESS);
  //Move the cursor to col,row
  Wire.write(17);
  Wire.write(col);
  Wire.write(row);
  //Pipe out the string, up to but not incuding the null terminator
  uint8_t
    this_character;
  //Get an editable copy of the flash string pointer
  const char
    *ptr;
  ptr=(const char *)flash_string;
  //Grab the next character from the flash string. If it is not
  //null, send it out.
  while(0 != (this_character=pgm_read_byte(ptr)))
    {
    Wire.write(this_character);
    //Point to the next character in RAM
    ptr++;
    }    
  //Stop the I2C transaction
  Wire.endTransmission();
  //Give the display a little time to deal with its new life situation.
  delay(3);
  }
//============================================================================
void I2C_show_dec3_XY(uint8_t col, uint8_t row,uint8_t input)
  {
  //Start the I2C transaction
  Wire.beginTransmission(CFA_634_I2C_ADDRESS);
  //Move the cursor to col,row
  Wire.write(17);
  Wire.write(col);
  Wire.write(row);

  uint8_t
    digit;
  uint8_t
    no_blank;
  digit=input/100U;
  if(digit != 0U)
    {
    Wire.write(digit+(uint8_t)'0');
    no_blank=1U;
    }
  else
    {
    Wire.write((uint8_t)' ');
    no_blank=0U;
    }
  input%=100U;
  /*lint --e(1960)*/
  digit=input/10U;
  if((digit|no_blank) != 0U)
    {
    Wire.write(digit+(uint8_t)'0');
    }
  else
    {
    Wire.write((uint8_t)' ');
    }
  Wire.write((input%10U) + (uint8_t)'0');
  //Stop the I2C transaction
  Wire.endTransmission();
  //Give the display some time to process the command
  delay(1);
  }
//============================================================================
#ifdef USE_PRINTF
// ref http://playground.arduino.cc/Main/Printf
void I2CPrintFFXY(uint8_t col, uint8_t row,
                  const __FlashStringHelper *fmt, ... )
  {
  //Use variable arguments to format the string
  //this includes printf lib which is big
  char
    tmp[40]; // resulting string limited to 128 chars
  va_list
    args;
  va_start(args, fmt );
  vsnprintf_P(tmp, 40, (const char *)fmt, args);
  va_end (args);
 
  //Send the formatted string to the display
  //Start the I2C transaction
  Wire.beginTransmission(CFA_634_I2C_ADDRESS);
  //Move the cursor to col,row
  Wire.write(17);
  Wire.write(col);
  Wire.write(row);
  //Pipe out the string, up to but not incuding the null terminator
  uint8_t
    this_character;
  //Get a pointer into the formatted string on the stack
  char
    *ptr;
  ptr=&tmp[0];
  //Grab the next character from the flash string. If it is not
  //null, send it out.
  while(0 != (this_character=*ptr))
    {
    Wire.write(this_character);
    //Point to the next character in RAM
    ptr++;
    }    
  //Stop the I2C transaction
  Wire.endTransmission();
  //Give the display some time to process the command
  delay(1);
  }
#endif  
//============================================================================
void Bar_Graph(uint8_t graph_index,
               uint8_t style,
               uint8_t start_column,
               uint8_t end_column,
               uint8_t bar_length,
               uint8_t row)
  {
  Wire.beginTransmission(CFA_634_I2C_ADDRESS);
#if 1
  //Use built-in bar graph command
  //Bar command
  Wire.write(18);
  Wire.write(graph_index);
  Wire.write(style);
  Wire.write(start_column);
  Wire.write(end_column);
  Wire.write(bar_length);
  Wire.write(row);
  Wire.endTransmission();
  //Give the display some time to process the command
  delay(5);
#else
  //Or do it the old fashioned way.
  //The first character will be varaible width.
  //Set the second character to full width.
  Wire.beginTransmission(CFA_634_I2C_ADDRESS);
  Wire.write(25); //custom character command
  Wire.write((graph_index<<1)+1);
  Wire.write(style & 0x80 ? 0x7F : 0); //Top Line
  Wire.write(style & 0x40 ? 0x7F : 0);
  Wire.write(style & 0x10 ? 0x7F : 0);
  Wire.write(style & 0x20 ? 0x7F : 0);
  Wire.write(style & 0x08 ? 0x7F : 0);
  Wire.write(style & 0x04 ? 0x7F : 0);
  Wire.write(style & 0x02 ? 0x7F : 0);
  Wire.write(style & 0x01 ? 0x7F : 0); //Bottom Line
  Wire.endTransmission();
  //Give the display some time to process the command
  delay(1);

  uint8_t
    i;
  //Write the characters in the bar area. The full width to the left,
  //the variable width character, then blanks.
  //Start the I2C transaction
  Wire.beginTransmission(CFA_634_I2C_ADDRESS);
  //Move the cursor to col,row
  Wire.write(17);
  Wire.write(start_column);
  Wire.write(row);
  //Fill in the solid characters.
  for(i=start_column;i<(bar_length/6);i++)
    //Second special character (solid);
    Wire.write(128+(graph_index<<1)+1);
  //Put in the partial, variable character
  Wire.write(128+(graph_index<<1));
  //Fill the rest of the area with blanks
  for(i++;i<=end_column;i++)
    Wire.write(' ');
  Wire.endTransmission();
  //Give the display some time to process the command
  delay(1);
  //Now set the partial bar width to the remainder
  uint8_t
    horizontal_mask;
  horizontal_mask = (0x3F << (6-(bar_length%6)) & 0x3F);

  Wire.beginTransmission(CFA_634_I2C_ADDRESS);
  Wire.write(25); //custom character command
  Wire.write((graph_index<<1));
  Wire.write(style & 0x80 ? horizontal_mask : 0); //Top Line
  Wire.write(style & 0x40 ? horizontal_mask : 0);
  Wire.write(style & 0x10 ? horizontal_mask : 0);
  Wire.write(style & 0x20 ? horizontal_mask : 0);
  Wire.write(style & 0x08 ? horizontal_mask : 0);
  Wire.write(style & 0x04 ? horizontal_mask : 0);
  Wire.write(style & 0x02 ? horizontal_mask : 0);
  Wire.write(style & 0x01 ? horizontal_mask : 0); //Bottom Line
  Wire.endTransmission();
  //Give the display some time to process the command
  delay(1);
#endif
  }
//============================================================================
void Bar_Graph_Demo(void)
  {
  //Build up the base screen
  //Start the I2C transaction
  Wire.beginTransmission(CFA_634_I2C_ADDRESS);
  //Clear the LCD
  Wire.write(12);
  Wire.endTransmission();
  //Give the display some time to process the command
  delay(3);
  
  //                  "01234567890123456789"
  I2C_String_XY(0,0,F("Speed:       123 kph"));  
  I2C_String_XY(0,2,F("Temperature: 123 oC "));  
  //Insert the superscript 0 for degree
  I2C_String_XY(17,2,F("\x1E\x01\x80"));  

  uint8_t
    speed_position;
  uint8_t
    speed_direction;

  speed_position=0;
  speed_direction=1;

  uint16_t
    updates;
  for(updates=0;updates<1000;updates++)
    {
#ifdef USE_PRINTF
    //Print the speed, numeric value
    I2CPrintFFXY(13,0,F("%3d"),speed_position);
    //Print the temp, numeric value
    I2CPrintFFXY(13,2,F("%3d"),80+(speed_position/6));
#else
    //Print the speed, numeric value
    I2C_show_dec3_XY(13,0,speed_position);
    ///Print the temp, numeric value
    I2C_show_dec3_XY(13,2,80+(speed_position/6));
#endif
    //Draw speed bar. 1px = 2KMH
    Bar_Graph(0,                //graph_index
              0x7E,             //style
              0,                //start_column,
              19,               //end_column,
              speed_position/2, //bar_length,
              1);               //row
    //Draw Temp 1px = 1 deg C
    Bar_Graph(1,                     //graph_index
              0x3C,                  //style
              0,                     //start_column,
              19,                    //end_column,
              80+(speed_position/6), //bar_length,
              3);                    //row
    if(speed_direction)
      {
      //speeding up  
      if(speed_position<239)
        {
        speed_position++;
        }
      else
        {
        //start slowing down
        speed_direction=0;
        }
      }
    else
      {
      //slowing down
      if(48<speed_position)
        {
        speed_position--;
        }
      else
        {
        //start speeding up
        speed_direction=1;
        }
      }
    }
  }
//============================================================================
// Menu Data in flash
// ref: https://playground.arduino.cc/Main/PROGMEM
const char Menu_Item_00[] PROGMEM = "Red";
const char Menu_Item_01[] PROGMEM = "Orange";
const char Menu_Item_02[] PROGMEM = "Yellow";
const char Menu_Item_03[] PROGMEM = "Green";
const char Menu_Item_04[] PROGMEM = "Blue";
const char Menu_Item_05[] PROGMEM = "Purple";
const char Menu_Item_06[] PROGMEM = "Brown";
const char Menu_Item_07[] PROGMEM = "Magenta";
const char Menu_Item_08[] PROGMEM = "Tan";
const char Menu_Item_09[] PROGMEM = "Cyan";
const char Menu_Item_10[] PROGMEM = "Olive";
const char Menu_Item_11[] PROGMEM = "Maroon";
const char Menu_Item_12[] PROGMEM = "Navy";
const char Menu_Item_13[] PROGMEM = "Silver";
const char Menu_Item_14[] PROGMEM = "Lime";
const char Menu_Item_15[] PROGMEM = "Teal";
const char Menu_Item_16[] PROGMEM = "Indigo";
const char Menu_Item_17[] PROGMEM = "Violet";
const char Menu_Item_18[] PROGMEM = "Pink";
const char Menu_Item_19[] PROGMEM = "Black";
const char Menu_Item_20[] PROGMEM = "White";
const char Menu_Item_21[] PROGMEM = "Gray";

//Flash array of pointers to access the unequal length strings in flash above.
const char * const Menu_Strings[22] PROGMEM = {
  Menu_Item_00,Menu_Item_01,Menu_Item_02,Menu_Item_03,Menu_Item_04,Menu_Item_05,Menu_Item_06,
  Menu_Item_07,Menu_Item_08,Menu_Item_09,Menu_Item_10,Menu_Item_11,Menu_Item_12,Menu_Item_13,
  Menu_Item_14,Menu_Item_15,Menu_Item_16,Menu_Item_17,Menu_Item_18,Menu_Item_19,Menu_Item_20,
  Menu_Item_21};
//----------------------------------------------------------------------------
void Menu_Demo_Show_Choices(uint8_t top_choice)
  {
  uint8_t
    line;
  for(line=0;line<=3;line++)
    {
    //Start the I2C transaction
    Wire.beginTransmission(CFA_634_I2C_ADDRESS);
    //Move the cursor to col,row
    Wire.write(17);
    Wire.write(11);   //col
    Wire.write(line); //row
    
    //Pipe out the string, up to but not incuding the null terminator
    uint8_t
      this_character;
    //Get an editable copy of the flash string pointer
    const char
      *ptr;
    ptr=(char*)pgm_read_word(&(Menu_Strings[top_choice+line]));
    //Grab the next character from the flash string. If it is not
    //null, send it out.
    //Keep track of the number of trailing blanks that we need
    //to send. The menu field is 8 wide.
    uint8_t
      trailing_blanks_needed;
    trailing_blanks_needed=8;
    while(0 != (this_character=pgm_read_byte(ptr)))
      {
      Wire.write(this_character);
      //Point to the next character in RAM
      ptr++;
      //We need one less trailing blank.
      trailing_blanks_needed--;
      }
    while(trailing_blanks_needed)
      {
      Wire.write(' ');
      trailing_blanks_needed--;
      }
    //Stop the I2C transaction
    Wire.endTransmission();
    //Give the display a little time to deal with its new life situation.
    delay(3);
    }
  }
//----------------------------------------------------------------------------
void Menu_Demo_Base_screen(void)
  {
  //Build up the base screen
  //Start the I2C transaction
  Wire.beginTransmission(CFA_634_I2C_ADDRESS);
  //Clear the LCD
  Wire.write(12);
  Wire.endTransmission();
  //Give the display some time to process the command
  delay(3);
  //Build up the base screen
  //                  "01234567890123456789"
  //                  "Use ud to >magenta <"
  //                  "to choose |red     |"
  //                  "the color |pink    |"
  //                  "e to set. |hot pink|"
  I2C_String_XY(0,0,F("Use \xDE\xE0 to           "));  
  I2C_String_XY(0,1,F("to choose           "));  
  I2C_String_XY(0,2,F("the color           "));  
  I2C_String_XY(0,3,F("\x1E\x01\x1C to set.           "));  
  }
//----------------------------------------------------------------------------
void Menu_Demo_Set_Highlight_Line(uint8_t active_line)
  {
  uint8_t
    line;
  for(line=0;line<=3;line++)
    {
    I2C_String_XY(10,line,(line == active_line)?F("\x1E\x01\x10"):F("\xFE"));  
    I2C_String_XY(19,line,(line == active_line)?F("\x1E\x01\x11"):F("\xFE"));  
    }
  }
//----------------------------------------------------------------------------
void Menu_Demo(void)
  {
  Menu_Demo_Base_screen();

  //The item selected 0~21
  uint8_t
    menu_position;
  uint8_t
    menu_direction;
  //The line the pointers are on 0~3
  uint8_t
    pointer_position;

  menu_position=0;
  menu_direction=1;
  pointer_position=0;
  uint16_t
    updates;
  for(updates=0;updates<70;updates++)
    {
    Menu_Demo_Show_Choices(menu_position-pointer_position);
    Menu_Demo_Set_Highlight_Line(pointer_position);

    delay(400);

    if(menu_direction)
      {
      //moving down in the list  
      if(menu_position < 21)
        {
        menu_position++;
        if(pointer_position<3)
          pointer_position++;
        }
      else
        {
        //start moving back up
        menu_direction=0;
        }
      }
    else
      {
      //moving up in the list
      if(0 < menu_position)
        {
        menu_position--;
        if(0<pointer_position)
          pointer_position--;
        }
      else
        {
        //start moving back down
        menu_direction=1;
        }
      }
    }  //for updates
  }
//============================================================================
void setup()
  {
  //Debug output (Ctrl+shift+M)
  Serial.begin(115200);  // start serial for output

#ifdef USE_PRINTF
  SerPrintFF(F("Begin (with printf)\n"));
#else
  Serial.println("Begin (no printf)");
#endif

  //Enable/configure I2C
  Wire.begin();

  //Give it time to boot, in case we are coming from power-up.
  delay(500);

  //Reboot, just in case the last time we ran the code we left the
  //display all messed up, and we were not power-cycled.
  //Start the I2C transaction
  Wire.beginTransmission(CFA_634_I2C_ADDRESS);
  Wire.write(' ');
  Wire.write(' ');
  Wire.write(' ');
  Wire.write(' ');
  Wire.write(' ');
  Wire.write(' ');
  Wire.write(' ');
  Wire.write(' ');
  Wire.write(' ');
  Wire.write(26);
  Wire.write(26);
  Wire.endTransmission();
  //Give it time to re-boot
  delay(80);

  // (Optional) Delay to see the logo screen
  delay(2000);

  //Default settings for our demo
  //Start the I2C transaction
  Wire.beginTransmission(CFA_634_I2C_ADDRESS);
  //Hide the cursor
  Wire.write(4);
  //Turn Scroll Off
  Wire.write(20);
  //Turn Wrap Off
  Wire.write(24);
  //Clear the LCD
  Wire.write(12);
  Wire.endTransmission();
  //Give it time to clear
  delay(5);
  }
//============================================================================
void loop()
  {
  Menu_Demo();
  Bar_Graph_Demo();
  }
//============================================================================

