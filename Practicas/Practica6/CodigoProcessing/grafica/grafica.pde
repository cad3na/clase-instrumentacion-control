import processing.serial.*;
 
Serial myPort;        // The serial port
int xPos = 1;         // horizontal position of the graph
 
void setup () {
  // set the window size:
  size(1000, 640);        
  // List all the available serial ports
  println(Serial.list());
  myPort = new Serial(this, Serial.list()[2], 9600);
  // don't generate a serialEvent() unless you get a newline character:
  myPort.bufferUntil('\n');
  // set inital background:
  background(0);
}

void draw () {
// everything happens in the serialEvent()
}

void serialEvent (Serial myPort) {
  String inString = myPort.readStringUntil('\n');

  if (inString != null) {
    inString = trim(inString);
    float inByte = float(inString); 
    inByte = map(inByte, 0, 1280.0, 0, height);

    stroke(200,200,200);
    strokeWeight(5);
    point(xPos, height - inByte);
    
    if (xPos >= width) {
      xPos = 0;
      background(0);
    } 
    else {
    xPos += 5;
    }
    
  }
}
