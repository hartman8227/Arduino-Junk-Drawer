#include <Arduino.h>
#include <L293.h>

/* **************************
  *  Robot Command Software Version 0.0.01
  *  Copyright 2021
  *  Paul Hartman
  *************************** 
  */

/*
  * Software will be running on an Arduino Mega 2560 with an HC-SR04 range
  * finder and 4 x 12v DC motors providing motion. Will Probably 
  * use a Ryobi 18 volt battery to provide power and use a DC-DC 
  * Buck Converter to drop voltage down to a reasonable 12 volts DC.
  * /
  */

 // Initilize Variables
 
 // Left Side Motors
 
 // Motor 1
 const int m1_en = 2;
 const int m1_fw = 22;
 const int m1_rw = 23;
 L293 motor_1 (m1_en, m1_fw, m1_rw);

 // Motor 2
 const int m2_en = 3;
 const int m2_fw = 24;
 const int m2_rw = 25;
L293 motor_2 (m2_en, m2_fw, m2_rw);

 // Right side Motors

 // Motor 3
 const int m3_en = 4;
 const int m3_fw =26;
 const int m3_rw = 27;
 L293 motor_3 (m3_en, m3_fw, m3_rw);

 // Motor 4
 const int m4_en = 5;
 const int m4_fw = 28;
 const int m4_rw = 29;
 L293 motor_4 (m4_en, m4_fw, m4_rw);

 // Range Sensor 
 // HC-SR04

 const int trig = 6;
 const int echo = 30;

 // Setup Timer

 // Random Number Generator

 long randomtime;
 int randomnum;
 
 // Program Functions

 //Need to check out the New Ping library

int ranging(){
 float duration;
 float distance;
 digitalWrite(trig, LOW);
 delayMicroseconds(2);
 digitalWrite(trig, HIGH);
 delayMicroseconds(10);
 digitalWrite(trig, LOW);

 duration = pulseIn(echo, HIGH);
 distance = (duration /2) * 0.0343;
 return distance;
 
}

// Thank you Edgar Bonnet - https://arduino.stackexchange.com/questions/12915/timer-function-without-the-use-of-a-library
//Call This timer function like this.
/* void loop() {
    static unsigned long previousMillis1;
    static unsigned long previousMillis2;
    static unsigned long previousMillis3;

    if (timer(previousMillis1, 1000)) Serial.println(1);
    if (timer(previousMillis2, 2000)) Serial.println(2);
    if (timer(previousMillis3, 3000)) Serial.println(3);
} */
bool timer(unsigned long &last_time, unsigned long period)
{
  unsigned long now = millis();
  if (now - last_time >= period) {
    last_time = now;
    return true;
  }
  return false;


}

// Motor Strapping

void forward(){
  motor_1.forward(255);
  motor_2.forward(255);
  motor_3.forward(255);
  motor_4.forward(255); 

}

void reverse(){
  motor_1.back(255);
  motor_2.back(255);
  motor_3.back(255);
  motor_4.back(255);

}
// Question - Is there a way to bind these motors together  by which side they are on?

void turn_left(){
  motor_1.back(125);
  motor_2.back(125);
  motor_3.forward(255);
  motor_4.forward(255);

}

void turn_right(){
  motor_1.forward(255);
  motor_2.forward(255);
  motor_3.back(125);
  motor_4.back(125);

}

void action_select(long delay_time){
  switch (randomnum){
    case 1:
      forward();
      
      break;
    case 2:
      reverse();
      
      break;
    case 3:
      turn_left();
      
      break;
    case 4: 
      turn_right();
      
      break; 
  }
}

// SYSTEM FUNCTIONS

void setup() {
  // Initilize Random Number Generator
 randomSeed(analogRead(A0));
 pinMode(trig, OUTPUT);
 pinMode(echo, INPUT);

}

void loop() {
  randomtime = random(500, 1500);
  randomnum = random (1, 5);
  
  
}

