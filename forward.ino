// EE 302 Robot Car 
// Written by Matthew Prinz, with help from Rishi Talati
// Additional help from internet, sources cited at bottom

//Motor A
const int motorPin1  = 5;  // Pin 14 of L293
const int motorPin2  = 6;  // Pin 10 of L293
//Motor B
const int motorPin3  = 10; // Pin  7 of L293
const int motorPin4  = 9;  // Pin  2 of L293
//IR Sensor
const int obstaclePin = 7;  // IR Sensor pin
//Photoresistor
const int pResistor1 = A0; 
const int pResistor2 = A5;
//const int pResistor3 = A4;
int value1 = 0; //value from presistor1
int value2 = 0; //value from presistor2

void setup(){

    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(pResistor1, INPUT);
    pinMode(pResistor2, INPUT);
    //pinMode(pResistor3, INPUT);

}
void loop(){  
  value1 = analogRead(A0);
  value2 = analogRead(A5);
  stopcar();
  if ( (value2 - 60) <= value1 <= (value2+60)) {
    forward();
  }
  if ( value1 > (value2+60) ) {
    turnRight();
  }
  if (value1 < (value2 - 80)) {
    turnLeft();
  }
   
 }

void turnRight(){
    
    //This code  will turn Motor A clockwise
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
}
void turnLeft() {
    //This code  will turn Motor B clockwise
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
}
void forward(){
    //This code  will turn Motor A & B clockwise
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
}



void backward(){
    //This code will turn Motor A & B counter-clockwise.
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH );
}

void stopcar(){
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
}


//Sources: 

//https://www.codeproject.com/Articles/1109511/IR-obstacle-sensor-with-Arduino for IR sensor
//http://www.instructables.com/id/How-to-use-the-L293D-Motor-Driver-Arduino-Tutorial/ L293D H-bridge
//http://www.instructables.com/id/How-to-use-a-photoresistor-or-photocell-Arduino-Tu/ Photoresistor


