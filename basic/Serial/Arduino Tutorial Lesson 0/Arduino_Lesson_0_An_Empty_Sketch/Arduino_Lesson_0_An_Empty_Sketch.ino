/*
Title: Lesson 0. how big is an empty Sketch anyway
 
Description:  Reading a line of text from the Serial Port and sending to a command process function.

Date created: 27 May 2014
Created By: Peter Oakes

Additional Comments:

Feel free to use and abuse as you wish, I imply NO Warranty

NOTE: defines take no program space untill used so use instead of ints etc when it will never change

Lessons Available
lesson 0. How big is an Empty Sketch anyway
Lesson 1. Reading the Serial input a line at time
Lesson 2. Parsing the line using  "if else if" statements
Lesson 3. Improved parsing and reduced SRAM consumption - "Case" Statements
lesson 4. Reading the Ethernet input a line at time (WEB Query)
lesson 5. Combining Serial and Ehernet into a common sketch
lesson 6. Advanced parsing of commands without "If" or "Case" statements
lesson 7. Adding input buttons to the command control


*/

// Bunch of constants in the form of definitions
// 1 = output debug to serial port, 0 = no debug
#define debug 1 
// define the buffer size... 
#define serialbufferSize 50 
// End of Constants


// Now the real varibles
// char inputBuffer[serialbufferSize]; 
// int serialIndex = 0; // keep track of where we are in the buffer
// End of real variables

void setup() 
{ 
  // initialize serial:
  // Serial.begin(9600);
  // do other setup here as needed
}

void loop() 
{
  // Notice how the main loop is very simple and the functions 
  // seperate the logic into easily manageable parts
  //  if (CheckSerial()) DoCommand(inputBuffer); 

}

//boolean DoCommand(char * commandBuffer)
//{
//  
//#if debug
//  Serial.println(commandBuffer);
//  Serial.print("Free Ram = "); Serial.println(freeRam(), DEC);
//#endif  
//return true;
//}
//
///*
//Checks the serial input for a string, returns true once a '\n' is seen
//users can always look at the global variable "serialIndex" to see if characters have been received already
//*/
//boolean CheckSerial()
//{
//  boolean lineFound = false;
//  // if there's any serial available, read it:
//  while (Serial.available() > 0) {
//    //Read a character as it comes in:
//    //currently this will throw away anything after the buffer is full or the \n is detected
//    char charBuffer = Serial.read(); 
//      if (charBuffer == '\n') {
//           inputBuffer[serialIndex] = 0; // terminate the string
//           lineFound = (serialIndex > 0); // only good if we sent more than an empty line
//           serialIndex=0; // reset for next line of data
//         }
//         else if(serialIndex < serialbufferSize && lineFound == false) {
//           /*Place the character in the string buffer:*/
//           inputBuffer[serialIndex++] = charBuffer; // auto increment index
//         }
//  }// End of While
//  return lineFound;
//}// End of CheckSerial()
//
//#if debug
//// check free ram and return as an integer
//int freeRam() 
//{
//  extern int __heap_start, *__brkval; 
//  int v; 
//  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
//}
//#endif
