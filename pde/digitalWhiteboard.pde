// digitalWhiteBoard.pde

// http://samsneatprojectblogcode.blogspot.com/

 ProLine:

import processing.serial.*;

Serial myPort;

boolean firstContact = false;
int[] serialInArray = new int[2]; // Where we'll put what we receive
int serialCount = 0;                 // A count of how many bytes we receive
int x;                               //the x coordinate
int y;             //the y coordinate

int mx = 250;
int my = 250;
int px = mx;
int py = my;
int ppy = mx;
int ppx = my;
int fx;
int fy;
int gx;
int gy;
int mpx;
int mpy;
int xs = 10;
int xy = 10;
int count = 2;
int counter = 0;
void setup()
{
  size(500, 500);
  background(0);
  String portName = Serial.list()[4];
  myPort = new Serial(this, portName, 9600);
  strokeWeight(1);
  stroke(255);
  serialEvent(myPort);

  mx = int(map(x, 0, 110, 0, 500));
  my = int(map(y, 0, 110, 0, 500));
}


void draw()
{
  if (keyPressed && key == 'b' && (count%2 == 0))
  {
    serialEvent(myPort);
    fx = int(map(x, 0, 200, 0, 500));
    fy = int(map(y, 0, 200, 0, 500));
    if(count == 2)
    {
      gx = fx;
      gy = fy;
    }
   count++;
   line(gx, gy, fx, fy);
  }

  if (keyPressed && key == 'b' && (count % 2 != 0))
  {
    serialEvent(myPort);
    gx = int(map(x, 0, 200, 0, 500));
    gy = int(map(y, 0, 200, 0, 500));
    line(fx, fy, gx, gy);
    count++;
  }

  //delay(0);
  //fill(0, 0, 0, 10);
  //rect(0, 0, 500, 500);



  //  checkValid();

  //line(mx, my, px, py);
  //print("px" + px + "   ");
  //print("py" + py + "     ");
  //print("mx" + mx + "   ");
  //print("my" + my + "   ");
  //println(" ");
 
  if ( mx > 500 ||  my > 500)
  {
    mx = px;
    my = py;
    fill(random(10, 255));
    rect(250, 250, 50, 50);
  }
  if (counter > 5)
  {
    //line(mx, my, ppx, ppy);
  }
  counter++;
  serialEvent(myPort);
}


void serialEvent(Serial myPort) { //communication setup from arduino
  // read a byte from the serial port:
  int inByte = myPort.read();
  // if this is the first byte received, and it's an A,
  // clear the serial buffer and note that you've
  // had first contact from the microcontroller.
  // Otherwise, add the incoming byte to the array:
  if (firstContact == false) {
    if (inByte == 'A') {
      myPort.clear();          // clear the serial port buffer
      firstContact = true;     // you've had first contact from the microcontroller
      myPort.write('A');       // ask for more
    }
  } else {
    // Add the latest byte from the serial port to array:
    if (serialCount < 2)
    {
      serialInArray[serialCount] = inByte;
      serialCount++;
    }

    if (serialCount > 1) {  

      if (serialInArray[0] == -1 || serialInArray[1] == -1)
      {
        // myPort.clear();
        myPort.write("A");
        serialCount = 0;
        //   println("x" + x + "   " + "y" + y);
      } else {
        x = serialInArray[0];
        y = serialInArray[1];
        println("x" + x + "   " + "y" + y);
        //if(x || y =

        myPort.write('A');

        serialCount = 0;
      }
    }
  }
}


void checkValid()
{
  if (mx <= 0)
  {
    mx = px;
  }
  if (my <= 0)
  {
    my = py;
  }

  if (mx == py)
  {
    int tmx = mx;
    int tmy = my;
    int tpx = px;
    int tpy = py;
    mx = tmy;
    my = tmx;
    px = tpy;
    py = tpx;
  }


  if (abs(mx-px) >= 50 || abs(my-py) >= 50)
  {
    mx = px;
    my = py;
  }
}






Pro first:

import processing.serial.*;

Serial myPort;

boolean firstContact = false;
int[] serialInArray = new int[2]; // Where we'll put what we receive
int serialCount = 0;                 // A count of how many bytes we receive
int x;                               //the x coordinate
int y;             //the y coordinate

int mx = 250;
int my = 250;
int px = mx;
int py = my;
int ppy = mx;
int ppx = my;
int mpx;
int mpy;
int xs = 10;
int xy = 10;
int counter = 0;
void setup()
{
  size(500, 500);
  background(0);
  String portName = Serial.list()[4];
  myPort = new Serial(this, portName, 9600);
   strokeWeight(1);
  stroke(255);
   serialEvent(myPort);
  
 mx = int(map(x, 0, 110, 0, 500));
 my = int(map(y, 0, 110, 0, 500));
}


void draw()
{
  if(keyPressed)
  {
    background(0);
  }

   //delay(0);
  //fill(0, 0, 0, 10);
  //rect(0, 0, 500, 500);

 mx = int(map(x, 0, 200, 0, 500));
 my = int(map(y, 0, 200, 0, 500));

//  checkValid();
  
  //line(mx, my, px, py);
  //print("px" + px + "   ");
  //print("py" + py + "     ");
  //print("mx" + mx + "   ");
  //print("my" + my + "   ");
  //println(" ");
   ppx = px;
   ppy = py;
   px = mx;
   py = my;
   if( mx > 500 ||  my > 500)
   {
     mx = px;
     my = py;
     fill(random(10, 255));
     rect(250, 250, 50, 50);
   }
   if(counter > 5)
   {
   line(mx, my, ppx, ppy);
   }
  counter++;
  serialEvent(myPort);
}


void serialEvent(Serial myPort) { //communication setup from arduino
  // read a byte from the serial port:
  int inByte = myPort.read();
  // if this is the first byte received, and it's an A,
  // clear the serial buffer and note that you've
  // had first contact from the microcontroller.
  // Otherwise, add the incoming byte to the array:
  if (firstContact == false) {
    if (inByte == 'A') {
      myPort.clear();          // clear the serial port buffer
      firstContact = true;     // you've had first contact from the microcontroller
      myPort.write('A');       // ask for more
    }
  }
  else {
    // Add the latest byte from the serial port to array:
    if(serialCount < 2)
    {
    serialInArray[serialCount] = inByte;
    serialCount++;
    }
    
    if (serialCount > 1) {  
    
      if(serialInArray[0] == -1 || serialInArray[1] == -1)
      {
       // myPort.clear();
        myPort.write("A");
        serialCount = 0;
          //   println("x" + x + "   " + "y" + y);

      }
      else{
      x = serialInArray[0];
      y = serialInArray[1];
     println("x" + x + "   " + "y" + y);
     //if(x || y =
   
    myPort.write('A');
  
      serialCount = 0;
    }
    }
  }
}


void checkValid()
{
    if (mx <= 0)
  {
    mx = px;
  }
  if (my <= 0)
  {
    my = py;
  }
  
  if(mx == py)
  {
    int tmx = mx;
    int tmy = my;
    int tpx = px;
    int tpy = py;
    mx = tmy;
    my = tmx;
    px = tpy;
    py = tpx;
  }
  
  
  if(abs(mx-px) >= 50 || abs(my-py) >= 50)
  {
    mx = px;
    my = py;
  }
  
}




Arduino:

int trig1 = 9;
int echo1 = 10;

int trig2 = 5;
int echo2 = 6;

long duration1;
long distance1;

long duration2;
long distance2;

int board = 118;
int x;
int y;
double a;
double b;
double c;
int px = x;
int py = y;
int inByte = 0;
double theta;
void setup() {
  pinMode(echo1, INPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(trig2, OUTPUT);
  Serial.begin(9600);
  establishContact();
  // put your setup code here, to run once:

}

void loop() {
if(Serial.available()>0)
{
inByte = Serial.read();

  
  a = getDistance1()+(c/2);
  delay(10);
  b = getDistance2()+(c/2);
  c = board;
  
//  Serial.print("a");
//  Serial.println(a);
//  Serial.print("b");
//  Serial.println(b);
//  Serial.println(" ");

  theta = acos( ( (pow(a, 2))+(pow(c,2))-(pow(b,2)))/(2*a*c));
      
  //Serial.println(theta);
  y = a * sin(theta);
  x = a * cos(theta);
  if (x == 0)
  {
    x = px;
  }
  if (y == 0)
  {
    y = py;
  }
  //
//     Serial.write(x);
//     Serial.write(y);
     delay(20);
//   
////  //
//  Serial.print("x ");
//  Serial.print(x);
//  Serial.print( "    y ");
//  Serial.print(y);
//  Serial.println(" ");


  Serial.write(px);
  Serial.write(py);
  px = x;
  py = y;

  delay(100);
}


}


int getDistance1()
{
  digitalWrite(trig1, LOW); //triggers on/off and then reads data
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  duration1 = pulseIn(echo1, HIGH);
  distance1 = (duration1 / 2) * .0344;    //344 m/s = speed of sound. We're converting into cm
  return distance1;
}

int getDistance2()
{
  digitalWrite(trig2, LOW); //triggers on/off and then reads data
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  duration2 = pulseIn(echo2, HIGH);
  distance2 = (duration2 / 2) * .0344;    //344 m/s = speed of sound. We're converting into cm
  return distance2;
}

void establishContact() {   //prints A until contact is established.
  while (Serial.available() <= 0) {
    Serial.print('A');   // send a capital A
    delay(300);
  }
}
