// https://www.hackster.io/hardikrathod/create-gui-to-visualize-temp-and-humidity-for-arduino-85a7aa


// Lets create a simple meter

// Import Meter library
import meter.*;

// Import serial library
import processing.serial.*;

Serial port; // Define a port

Meter m, m2;

void setup(){
  // First we need to create a empty window
  size(950, 400); // Size of the window (width, height)
  background(0, 0, 0); // Background color of window (R,G,B)
  
  // Create new port
  port = new Serial(this, "COM3", 9600); //name of the port would be different for linux
  
  // Lets add a default meter to empty window
  // TEMPERATURE METER
  m = new Meter(this, 25, 80);  // here 25, 10 are x and y coordinates of meter's upper left corner
  
  m.setTitleFontSize(20);
  m.setTitleFontName("Arial bold");
  m.setTitle("Temperature (C)");
  
  // Change meter scale values
  String[] scaleLabels = {"0", "10", "20", "30", "40", "50", "60", "70", "80"};
  m.setScaleLabels(scaleLabels);
  m.setScaleFontSize(18);
  m.setScaleFontName("Times new roman bold");
  m.setScaleFontColor(color(200, 30, 70));
  
  // We can also display the value of meter
  m.setDisplayDigitalMeterValue(true);
  
  // Lets do some more modifications so our meter looks nice
  m.setArcColor(color(141, 113, 178));
  m.setArcThickness(15);
  
  m.setMaxScaleValue(80);
  
  m.setMinInputSignal(0);
  m.setMaxInputSignal(80);
  
  m.setNeedleThickness(3);
  
  // HUMIDITY METER
  // lets take some refference from first meter
  int mx = m.getMeterX(); // x coordinate of m
  int my = m.getMeterY(); // y coordinate of m
  int mw = m.getMeterWidth();
  
  m2 = new Meter(this, mx + mw + 20, my);
  
  m2.setTitleFontSize(20);
  m2.setTitleFontName("Arial bold");
  m2.setTitle("Humidity (%)");
  
  // Change meter scale values
  String[] scaleLabels2 = {"0", "10", "20", "30", "40", "50", "60", "70", "80", "90", "100"};
  m2.setScaleLabels(scaleLabels2);
  m2.setScaleFontSize(18);
  m2.setScaleFontName("Times new roman bold");
  m2.setScaleFontColor(color(200, 30, 70));
  
  // We can also display the value of meter
  m2.setDisplayDigitalMeterValue(true);
  
  // Lets do some more modifications so our meter looks nice
  m2.setArcColor(color(141, 113, 178));
  m2.setArcThickness(15);
  
  m2.setMaxScaleValue(100);
  
  m2.setMinInputSignal(0);
  m2.setMaxInputSignal(100);
  
  m2.setNeedleThickness(3);
}

void draw(){
  // Lets give title to our window
  textSize(30);
  fill(0, 255, 0); // Font color , (r,g,b)
  text("Temperature and Humidity", 250, 40); // ("text", x, y)
  
  if (port.available() > 0){
    String val = port.readString(); // read incoming string on serial port
    // First we need to separate temperature and humidity values
    String[] list = split(val, ','); // splits value separated by ','
    float temp = float(list[0]); // first value is Temperature
    float hum = float(list[1]);  // second value is Humidity
    
    m.updateMeter(int(temp)); // int is used due to updateMeter accepts only int values
    m2.updateMeter(int(hum));
    
    println("Temperature: " + temp + " C  " + "Humidity: " + hum+ "%");
  }
}
