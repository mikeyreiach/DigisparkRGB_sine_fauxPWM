#include "RGBLED.h" //include the declaration for this class

//<<constructor>> setup the LED, make pin 13 an OUTPUT
RGBLED::RGBLED(int pinAllocation, int startingIntensity){
	_ledPin = pinAllocation;
	_ledIntensity = startingIntensity; 
	
	pinMode(_ledPin, OUTPUT);   
}

//<<destructor>>
RGBLED::~RGBLED(){/*nothing to destruct*/}

int RGBLED::getPin(){
	return _ledPin;
}

void RGBLED::setLevel(int level){
	_ledIntensity = level;
}

int RGBLED::level(int level){
	_ledIntensity = level;
	return _ledIntensity;
}

int RGBLED::getLevel(){
	return _ledIntensity;
}
