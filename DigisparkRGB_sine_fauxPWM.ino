#include <DigisparkRGB.h>
#include <math.h>
#include "RGBLED.h"

#define PI 3.14159265
#define greenShift 2*PI/3   // green LED phase shift -- red is assumed to be at 0
#define blueShift 4*PI/3    // blue LED phase shift 

#define redPeriod 1
#define greenPeriod 1
#define bluePeriod 1

RGBLED RED(0,0);
RGBLED GREEN(1,0);
RGBLED BLUE(2,0);

// setup routine runs once on reset:
void setup(){ 
  DigisparkRGBBegin();

	// LED fade ins before going into cycle

  int greenStartInt = 255.0 * sin((0/180.0) * PI + greenShift);
  int blueStartInt = 255.0 * sin((0/180.0) * PI + blueShift);

  if(greenStartInt > blueStartInt){
    for(int j = 0; j < greenStartInt; j++){
      DigisparkRGB(GREEN.getPin(), j);

      if(j > blueStartInt)
        DigisparkRGB(BLUE.getPin(), blueStartInt);
      else 
        DigisparkRGB(BLUE.getPin(), j);

      delay(2000);
    }
  }
  else if(blueStartInt > greenStartInt){
    for(int j = 0; j < blueStartInt; j++){
      DigisparkRGB(BLUE.getPin(), j);

      if(j > greenStartInt)
        DigisparkRGB(GREEN.getPin(), greenStartInt);
      else 
        DigisparkRGB(GREEN.getPin(), j);
      
      delay(2000);
    }
  }
  else {
    for(int j = 0; j < greenStartInt; j++){
      DigisparkRGB(GREEN.getPin(), j);
      DigisparkRGB(BLUE.getPin(), j);
      delay(2000);
    }
  }

} 

void loop(){
  for(int i = 0; i < 360; i++){

    double x = sin(redPeriod * (i/180.0) * PI);
    double y = sin(greenPeriod * (i/180.0) * PI + greenShift);
    double z = sin(bluePeriod * (i/180.0) * PI + blueShift);

    RED.setLevel(int(255.0 * x));
    GREEN.setLevel(int(255.0 * y));
    BLUE.setLevel(int(255.0 * z));

    if(RED.getLevel() <= 0)
      DigisparkRGB(RED.getPin(), 0);  
    else 
      DigisparkRGB(RED.getPin(), RED.getLevel());

    if(GREEN.getLevel() <= 0)
      DigisparkRGB(GREEN.getPin(), 0); 
    else 
      DigisparkRGB(GREEN.getPin(), GREEN.getLevel());

    if(BLUE.getLevel() <= 0)
      DigisparkRGB(BLUE.getPin(), 0);
    else 
      DigisparkRGB(BLUE.getPin(), BLUE.getLevel());

    delay(5000);
  }    
}
