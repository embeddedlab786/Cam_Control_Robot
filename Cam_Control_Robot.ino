#include "AFMotor.h"

const int MOTOR_1 = 1; 
const int MOTOR_2 = 2; 
const int MOTOR_3 = 3; 
const int MOTOR_4 = 4; 

AF_DCMotor motor1(MOTOR_1, MOTOR12_64KHZ); // create motor object, 64KHz pwm
AF_DCMotor motor2(MOTOR_2, MOTOR12_64KHZ); // create motor object, 64KHz pwm
AF_DCMotor motor3(MOTOR_3, MOTOR12_64KHZ); // create motor object, 64KHz pwm
AF_DCMotor motor4(MOTOR_4, MOTOR12_64KHZ); // create motor object, 64KHz pwm

int state;
int Speed = 130; 

void setup() {
motor1.setSpeed(Speed);   // set the motor speed to 0-255
motor2.setSpeed(Speed);
motor3.setSpeed(Speed);
motor4.setSpeed(Speed);  
Serial.begin(9600);
delay(500); 
}

void loop(){   
if(Serial.available() > 0){  //if some date is sent, reads it and saves in state     
state = Serial.read();      
if(state > 10){Speed = state;}      
}
           
motor1.setSpeed(Speed);          // set the motor speed to 0-255
motor2.setSpeed(Speed);
motor3.setSpeed(Speed);
motor4.setSpeed(Speed);
   
//===============================================================================
//                          Key Control Command
//===============================================================================
   
     if(state == 1){forword(); }  // if the state is '1' the DC motor will go forward
else if(state == 2){backword();}  // if the state is '2' the motor will Reverse
else if(state == 3){turnLeft();}  // if the state is '3' the motor will turn left
else if(state == 4){turnRight();} // if the state is '4' the motor will turn right
else if(state == 5){Stop(); }     // if the state is '5' the motor will Stop
/////////////////////////////////////END\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

delay(80);    
}

void forword(){
motor1.run(FORWARD); // turn it on going forward
motor2.run(FORWARD); 
motor3.run(FORWARD); 
motor4.run(FORWARD);
}

void backword(){
motor1.run(BACKWARD); // the other way
motor2.run(BACKWARD);
motor3.run(BACKWARD); 
motor4.run(BACKWARD); 
}

void turnRight(){
motor1.run(FORWARD); // the other right
motor2.run(FORWARD); 
motor3.run(BACKWARD); 
motor4.run(BACKWARD);
}

void turnLeft(){
motor1.run(BACKWARD); // turn it on going left
motor2.run(BACKWARD);
motor3.run(FORWARD); 
motor4.run(FORWARD); 
}

void Stop(){
 motor1.run(RELEASE); // stopped
 motor2.run(RELEASE);
 motor3.run(RELEASE);
 motor4.run(RELEASE);
}

