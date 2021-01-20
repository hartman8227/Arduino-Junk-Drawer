#include <Arduino.h>
#include <L293.h>
#include <NewPing.h>
/* **************************
  *  Robot Command Software Version - Fucked Up Alpha
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
 int randomtime;
 int randomnum;
 bool stop = true;
 unsigned long  last_time;
 long delay_time;
 unsigned long pingTimer;
 int range;
 bool stop_check;
 const int range_stop = 10;

 
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
 NewPing sonar(trig, echo, 200);
 unsigned int pingSpeed = 50;
 unsigned long pingTimer;

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

void full_stop(){
  motor_1.stop();
  motor_2.stop();
  motor_3.stop();
  motor_4.stop();
}

// Borrowed from Edgar Bonnet - https://arduino.stackexchange.com/questions/12915/timer-function-without-the-use-of-a-library
 bool timer(unsigned long &last_time, unsigned long period)
{
  unsigned long now = millis();
  if (now - last_time >= period) {
    last_time = now;
    return true;
  }
  return false;


}

// Borrowed from the New Ping Library
bool echoCheck() { // Timer2 interrupt calls this function every 24uS where you can check the ping status.
  // Don't do anything here!
  if (sonar.check_timer()) { // This is how you check to see if the ping was received.
    // Here's where you can add code.
    range = (sonar.ping_result / US_ROUNDTRIP_CM); // Ping returned, uS result in ping_result, convert to cm with US_ROUNDTRIP_CM.
        if (range <= range_stop){
            return (true);
        }
        else {
            return (false);
        }
        
  }
  // Don't do anything here!
}
 

void setup(){
    randomSeed(analogRead(A0));
    
}

void loop(){
    delay_time = random(500, 1500);
    randomnum = random (1, 5); // Random does not count the highest number in a range. This says make randomnum equal to a random
                               // number between 1 and 4.

    if (millis() >= pingTimer) {   // pingSpeed milliseconds since last ping, do another ping.
    pingTimer += pingSpeed;      // Set the next ping time.
    sonar.ping_timer(echoCheck); // Send out the ping, calls "echoCheck" function every 24uS where you can check the ping status.
  }
    
    switch (randomnum){
    case 1:
      forward();
      
      break;
    case 2:
      while (timer(last_time, delay_time) == false){
        reverse();  
      }
      
      
      break;
    case 3:
        while (timer(last_time, delay_time) == false){
            turn_left;
        }
      break;
    case 4:
        while (timer(last_time, delay_time) == false){
            turn_right;
        }

 
      
      break; 
  }

}