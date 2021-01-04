/* *****************************
 * Playing with Random Numbers
 * Paul Hartman
 * January 2021
 * *****************************
 * 
 * Experimentation script playing with random numbers as to use as a timer.
 * The idea is to use the random number generator to decide to do something 
 * and then how long to do that something for.
 * 
 * I have no fucking idea what I am doing.
 * 
 * for this file I am planning on using the ArduinoIDE as my compliler
 * 
 */
 
//#include <arduino.h> // Won't need this

//Random number Variables
long randNum = 0;
long randLED = 0;

unsigned long previousMillis = 0;

 

void setup(){
	// if analog input pin 0 is unconnected, random analog
	// noise will cause the call to randomSeed() to generate
	// different seed numbers each time the sketch runs.
    // randomSeed() will then shuffle the random function.
	
	randomSeed(analogRead(A0));	
	
	// Setup the LEDS
	
}

void loop(){
	
}

 

