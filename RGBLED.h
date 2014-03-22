#ifndef RGBLED_H
#define RGBLED_H

#include <WProgram.h> //It is very important to remember this! note that if you are using Arduino 1.0 IDE, change "WProgram.h" to "Arduino.h" 
//#include <Arduino.h>

class RGBLED {

public:
	RGBLED(int pinAllocation, int startingIntensity);
	~RGBLED();
	
	int getPin();
	void setLevel(int level);
	int level(int level);
	int getLevel();
	
private:

	int _ledPin;		// default pin to 0
	int _ledIntensity;	// starting intensity of LED is 0

};

#endif