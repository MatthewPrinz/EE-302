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

int value1; //value from presistor
int hasObstacle = HIGH;  // HIGH MEANS NO OBSTACLE

void setup(){

    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(obstaclePin, INPUT);
    pinMode(pResistor1, INPUT);
    Serial.begin(9600);

}
void loop(){
  hasObstacle = digitalRead(obstaclePin);
  value1 = analogRead(pResistor1);
  if (value1 > 300) { //
    //forward();
    delay(100); 
  }
   if (hasObstacle == LOW) //LOW means something is ahead
  {
    stopcar();
  }
  else
  {
    
  }
  stopcar();
 }


void forward(){
  
    //This code  will turn Motor A clockwise
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    //This code will turn Motor B clockwise 
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
}

void backward(){
    //This code will turn Motor A counter-clockwise for 2 sec.
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
  
    //This code will turn Motor B counter-clockwise for 2 sec.
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
  
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


