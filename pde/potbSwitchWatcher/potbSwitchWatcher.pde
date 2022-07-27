// potb-SwitchWatcher.pde
// work hand in hand with potbSerialUpdater.ino
// not working - problem with no using /dev/ttyUSB0

// https://www.instructables.com/How-to-Make-a-Little-Switch-and-Potentiometer-Box-/

/*
 * Potentiometer and Switch Box (POTB) - SwitchWatcher
 * For more details visit: http://www.oomlout.com/ 
 * 
 * Behaviour: The program listens and connects to an Arduino via serial (USB)
 *            and then displays the state of a bevy of attached potentiometers
 *            and switches
 *
 * Example Serial Transmission:
 * "POTB Data%SWITCH_1=1 %SWITCH_2=1 %SWITCH_3=1 %TWIST_POT=0 %SHOULDER_POT=988 %ELBOW_POT=0 %WRIST_POT=0 %GRIPPER_POT=0 "
 *
 * Operation: 1. Click on the Comm port your Arduino is connected to
 *            2. Start twisting dials and see them mirror your action
 *               on screen
 *
 *
 * License: This work is licenced under the Creative Commons 
 *          Attribution-Share Alike 3.0 Unported License. To 
 *          view a copy of this licence, visit 
 *          http://creativecommons.org/licenses/by-sa/3.0/ 
 *          or send a letter to Creative Commons, 171 Second 
 *          Street, Suite 300, San Francisco, California 94105, 
 *          USA.
 *         
*/


import processing.serial.*;         // import serial library to use Serial (for talking to Arduino)

/* Serial Port Related Variables */
int serialPortIndex = -1;           // index of serial port we are using in the Serial.list() list
String[] commOptions;               // variable to store Serial.list() in so there is no need to poll 
                                    // serial ports each time we wish to refrence it (polling causes a 
                                    // jump in the arduino servos)
Serial serialPort;                  // Makes serial port addressable throughout this sketch


/* Constants to store potentiometer values in an array */
final static int TWIST_POT =    0;     // Switch Potentiometer Index
final static int SHOULDER_POT = 1;     // Shoulder Potentiometer Index
final static int ELBOW_POT =    2;     // Elbow Potentiometer Index
final static int WRIST_POT =    3;     // Wrist Potentiometer Index
final static int GRIPPER_POT =  4;     // Gripper Potentiometer Index

/* Constants to store switch values in an array */
final static int SWITCH_1= 0;          // Switch 1 Index
final static int SWITCH_2= 1;          // Switch 2 Index
final static int SWITCH_3= 2;          // Switch 3 Index

/* Switch State Holding Variables */
int[] pots = {0,0,0,0,0};              // Array for holding potentiometer values (initialise as 0)
int[] switches = {0,0,0};              // Array for holding switch values (initialise as 0)

/* Font Variables */
PFont font;                            // makes font public so it only needs to be loaded once (Arial-72)

/* Utility Variables */ 
PImage bg;                             // background image currently \WEBB-background.png

PImage twistDial; PImage shoulderDial; PImage elbowDial;  // Dial images for each potentiometer
PImage wristDial; PImage gripperDial;   

PImage switch1On;  PImage switch2On;  PImage switch3On;   // On switch images
PImage switch1Off; PImage switch2Off; PImage switch3Off;  // off switch images

/*
 * Button Related Variables
 * (buttons are implemented very roughly, bounding boxes are stored and graphic and text are
 *  drawn on the background image) ie. moving button variables will not move appearance of buttons
*/
Button comm1; Button comm2; Button comm3; Button comm4;   // buttons to choose correct serial port


/*
 * sets everything up
 */
void setup() 
{
  imageMode(CENTER);
  font = loadFont("ArialMT-72.vlw");        // Loads font we will use throught this sketch  
  bg = loadImage("POTB-background.png");    // Loads background image (stored in sketch folder)
  twistDial = loadImage("POTB-dial.png");   // Loads dial images
  
  shoulderDial = loadImage("POTB-dial.png");
  elbowDial    = loadImage("POTB-dial.png");
  wristDial    = loadImage("POTB-dial.png");
  gripperDial  = loadImage("POTB-dial.png"); 
  switch1On    = loadImage("POTB-switch-on.png");     // Loads switch on Images  
  switch2On    = loadImage("POTB-switch-on.png");
  switch3On    = loadImage("POTB-switch-on.png");
  switch1Off   = loadImage("POTB-switch-off.png");    // Loads switch off Images
  switch2Off   = loadImage("POTB-switch-off.png");
  switch3Off   = loadImage("POTB-switch-off.png");
  
  size(810, 400);                                     // Sets size of sketch window
  commOptions = Serial.list();                        // Polls Serial ports and gets a list of available ports 
  defineButtons();                                    // Defines bounding boxes for each button
  background(bg);                                     // Paints background image (this image has all the button graphics on it)
  smooth();
}


/* The sketches main loop */
void draw()
{
  background(bg);
  //-- call draw routines
  drawCommBox();                                      // Draws elements in the Comm Box (box 1)
  drawDialBox();                                      // Draws all the elements in the dial box
  //-- call working routines
  String data = pollSerialPort();                     // Polls the Serial port to see if there is any data
  
  if (data !=null)
  {
    loadVariables(data);
  }        // if there is data load that data into the variables
}


// ----------------------------------------------------------------------------
// Start of draw routines (split up just to make code nicer to read)

/*
 * The draw update routine (executed every cycle) for items in the comm box (box 1)
*/
void drawCommBox()
{
  fill(0,0,0);                                          // Set the fill to black
  textFont(font, 15);                                   // Set the font to the right size
  
  for (int i = 0; i < commOptions.length; i++)
  {
    // For each comm option
    text(commOptions[i], 100, 102 + i*70);              // Writes the name of each comm option beside 
                                                        // the appropriate button
  }
  
  /* Draw the dot beside the currently active comm port */
  if (serialPortIndex != -1)
  {
    //checks to see if a comm port has been chosen
    fill(0,147,221);                                    // Set fill to cyan
    ellipse(180, 96 + 70 * serialPortIndex, 30, 30);    // Draw a circle beside the currently active Comm port
  } 
}


/* draw update routine (executed every cycle) for items in the dial box */
void drawDialBox()
{
  // Update TwistPot
  translate(520, 145); 
  float rotateValue = getPotValue(TWIST_POT) * 0.264; rotate(radians(rotateValue));  
  image(twistDial,0,0);    
  rotate(radians(-rotateValue)); translate(-520, -145);
  
  // Update Shoulder Pot
  translate(672, 145); 
  rotateValue = getPotValue(SHOULDER_POT) * 0.264; rotate(radians(rotateValue));  
  image(shoulderDial,0,0);    
  rotate(radians(-rotateValue)); translate(-672, -145);
  
  // Update Elbow Pot
  translate(672, 299); 
  rotateValue = getPotValue(ELBOW_POT) * 0.264; rotate(radians(rotateValue));  
  image(elbowDial,0,0);    
  rotate(radians(-rotateValue)); translate(-672, -299);
  
  // Update Wrist Pot
  translate(519, 299); 
  rotateValue = getPotValue(WRIST_POT) * 0.264; rotate(radians(rotateValue));  
  image(wristDial,0,0);    
  rotate(radians(-rotateValue)); translate(-519, -299);  
  
  // Update Gripper Pot
  translate(367, 299); 
  rotateValue = getPotValue(GRIPPER_POT) * 0.264; rotate(radians(rotateValue));  
  image(gripperDial,0,0);    
  rotate(radians(-rotateValue)); translate(-367, -299);
  
  // switch1
  if (getSwitchValue(SWITCH_1) == 1)
  {
    image(switch1On,325,79);      
  }
  else
  {
    image(switch1Off,334,79);
  }
  
  // switch2
  if (getSwitchValue(SWITCH_2) == 1)
  {
    image(switch2On,325,137);      
  }
  else
  {
    image(switch2Off,334,137);
  }
  
  // switch3
  if (getSwitchValue(SWITCH_3) == 1)
  {
    image(switch3On,325,195);      
  }
  else
  {
    image(switch3Off,334,195);
  }
}


// End of Draw routines
// -------------------------------------------------------------

// -------------------------------------------------------------
// Start of Service routines

/*
 * mousePressed is called everytime the mouse is pressed this 
 * checks if the mouse is inside any of the button bounding boxes
 * and if it is the appropriate routine is called
*/
void mousePressed()
{
    if (comm1.pressed())      {updateSerialPort(0);}       // Changes to the comm port at index 0 in Serial.list()
    else if (comm2.pressed()) {updateSerialPort(1);}       // Changes to the comm port at index 1 in Serial.list()
    else if (comm3.pressed()) {updateSerialPort(2);}       // Changes to the comm port at index 2 in Serial.list()
    else if (comm4.pressed()) {updateSerialPort(3);}       // Changes to the comm port at index 3 in Serial.list()
    background(bg);                                        // Repaint the background image (this image has all the button graphics on it)
}


/*
 * Looks to see if there is any data in the serial port buffer
 * if there is it returns one string of data
*/
String pollSerialPort()
{
  String data = null;
  if (serialPort != null)
  {
    // if a serial port has been defined
    if (serialPort.available() > 1)
    {               
      //if there is serial data
      data = serialPort.readStringUntil(char(13));          // read a line of data
    }
  }
  return data;                                              // return either null or one line of data
}


/*
 * returns the state of the switch switchNum 
*/
int getSwitchValue(int switchNum)
{
  return switches[switchNum];
}


/*
 * returns the value of the potentiometer at index potNum
*/
int getPotValue(int potNum)
{
  return pots[potNum];
}


/*
 * Prints all values to the debug window
*/
void printState()
{
 print("POTB Data ");
 print("Switch 1 = ");
 print(getSwitchValue(SWITCH_1));
 print(" Switch 2 = ");
 print(getSwitchValue(SWITCH_2));
 print(" Switch 3 = ");
 print(getSwitchValue(SWITCH_3));
 print(" Twist Pot = ");
 print(getPotValue(TWIST_POT));
 print(" Shoulder Pot = ");
 print(getPotValue(SHOULDER_POT));
 print(" Elbow Pot = ");
 print(getPotValue(ELBOW_POT));
 print(" Wrist Pot = ");
 print(getPotValue(WRIST_POT));
 print(" Gripper Pot = ");
 print(getPotValue(GRIPPER_POT)); 
 println();  
}


/*
 * receives a String of data from the arduino of form:
 * //POTB Data%SWITCH_1=1 %SWITCH_2=1 %SWITCH_3=1 %TWIST_POT=0 %SHOULDER_POT=988 %ELBOW_POT=0 %WRIST_POT=0 %GRIPPER_POT=0
 * and then parses it into the variables to hold the values
*/
void loadVariables(String data)
{
  String cS = "%SWITCH_1=";  
  String temp = data.substring(data.indexOf(cS));
  temp = temp.substring(cS.length(),temp.indexOf(" ")); 
  switches[SWITCH_1] = int(temp);
  
  cS = "%SWITCH_2=";  
  temp = data.substring(data.indexOf(cS));
  temp = temp.substring(cS.length(),temp.indexOf(" ")); 
  switches[SWITCH_2] = int(temp);
  
  cS = "%SWITCH_3=";  
  temp = data.substring(data.indexOf(cS));
  temp = temp.substring(cS.length(),temp.indexOf(" ")); 
  switches[SWITCH_3] = int(temp);
  
  cS = "%TWIST_POT=";  
  temp = data.substring(data.indexOf(cS));
  temp = temp.substring(cS.length(),temp.indexOf(" ")); 
  pots[TWIST_POT] = int(temp);
  
  cS = "%SHOULDER_POT=";  
  temp = data.substring(data.indexOf(cS));
  temp = temp.substring(cS.length(),temp.indexOf(" ")); 
  pots[SHOULDER_POT] = int(temp);
  
  cS = "%ELBOW_POT=";  
  temp = data.substring(data.indexOf(cS));
  temp = temp.substring(cS.length(),temp.indexOf(" ")); 
  pots[ELBOW_POT] = int(temp);
  
  cS = "%WRIST_POT=";  
  temp = data.substring(data.indexOf(cS));
  temp = temp.substring(cS.length(),temp.indexOf(" ")); 
  pots[WRIST_POT] = int(temp);
  
  cS = "%GRIPPER_POT=";  
  temp = data.substring(data.indexOf(cS));
  temp = temp.substring(cS.length(),temp.indexOf(" ")); 
  pots[GRIPPER_POT] = int(temp);
}


// End of Service Routines
// -------------------------------------------------------------

// -------------------------------------------------------------
// Start of setup routines (routines called once or not very often)

/*
 * Defines all the bounding boxes for the buttons used in this sketch
*/
void defineButtons()
{
  comm1 = new Button(30, 65,  60, 60); // Defines the comm1 button
  comm2 = new Button(30, 135, 60, 60); // Defines the comm2 button
  comm3 = new Button(30, 205, 60, 60); // Defines the comm3 button
  comm4 = new Button(30, 275, 60, 60); // Defines the comm1 button
}


/*
 * updates the serial port being used to communicate with the arduino
 * portIndex is the index of the port we wish to use in Serial.list();
 * as Serial.list() is loaded into memory at startup adding serial ports 
 * after startup could cause unexcpected operation
*/
void updateSerialPort(int portIndex)
{
  if (commOptions.length > portIndex)
  {
    // if the passed portIndex is a valid index in Serial.list() 
    // (ie. not option three in a list of two)
    serialPortIndex = portIndex;                  // set the serialPortIndex variable to the new serialport index 
                                                  // (this is used to display the dot beside the active port)
  }
  
  if (serialPortIndex != -1)
  {
    // check to make sure a port has been chosen sometime previous
    if (serialPort != null)
    {
      serialPort.stop();
    }  // if a Serial port is already being used stop it before loading a new one 
    
    
    // looks like this is the problem - mty
    serialPort = new Serial(this, Serial.list()[serialPortIndex], 9600);  
    // Create a new Serial object to comunicate with the Arduino 9600 Baud
  }
}

// End of setup/not very commonly called routines
// -------------------------------------------------------------------------------------


// Example button and RectButton code from processing.org example with some changes 
// made mostly to simplify and remove roll over animation
// http://processing.org/learning/topics/buttons.html (2008-09-23)
class Button
{
  int x, y;  int width, height;
  Button(int ix, int iy, int iwidth, int iheight)
  {
    x = ix;  y = iy;  width = iwidth;  height = iheight;
  }
  
  boolean pressed()
  {
    if(overRect()) { return true; } 
    else           { return false;}    
  }

  boolean overRect()
  {
    if (mouseX >= x && mouseX <= x+width && mouseY >= y && mouseY <= y+height) { return true; } 
    else { return false; }
  }
}

