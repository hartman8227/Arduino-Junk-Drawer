#include <Arduino.h>
#include <L293D.h>

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

 // Motor 2
 const int m2_en = 3;
 const int m2_fw = 24;
 const int m2_rw = 25;

 // Right side Motors

 // Motor 3
 const int m3_en = 4;
 const int m3_fw =26;
 const int m3_rw = 27;

 // Motor 4
 const int m4_en = 5;
 const int m4_fw = 28;
 const int m4_rw = 29;

 // Range Sensor 
 // HC-SR04

 const int trig = 6;
 const int echo = 30;

 // Setup Timer
 

void setup() {
  // Initilize Random Number Generator

}

void loop() {
  // put your main code here, to run repeatedly:
}

void ranging(){

}
