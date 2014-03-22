#include <DigisparkRGB.h>
#include <math.h>
#include "RGBLED.h"

RGBLED RED(0,0);
RGBLED GREEN(1,0);
RGBLED BLUE(2,0);

RGBLED COLORS[] = {RED, GREEN, BLUE};

// the setup routine runs once when you press reset:
void setup()  { 
  DigisparkRGBBegin();
} 

void loop ()
{
  //direction: up = true, down = false
  //boolean dir = true;
 
		//fade(COLORS[i%3], dir);
		//i++;
		//dir = !dir;
		for(int i = 0; i < 127; i++){
				
			double x = (i/127.0) * PI;
			
			RED.setLevel(256*(1.0 + sin(x)));
			//GREEN.setLevel(256*(1.0 + sin(x + 2*PI/3)));
			//BLUE.setLevel(256*(1.0 + sin(x + 4*PI/3)));

			DigisparkRGB(RED.getPin(), RED.getLevel());
			
// 			for (int j = 0; j < 4; j++) {
// 			  DigisparkRGB(COLORS[j].getPin(), COLORS[j].getLevel());
// 			  DigisparkRGBDelay(25);
// 			}
			
			delay(2000);
  		}    
}

void fade(byte Led, boolean dir)
{
  int i;

  //if fading up
  if (dir)
  {
    for (i = 0; i < 256; i++) 
    {
      DigisparkRGB(Led, i);
      DigisparkRGBDelay(25);//1);
    }
  }
  else
  {
    for (i = 255; i >= 0; i--) 
    {
      DigisparkRGB(Led, i);
      DigisparkRGBDelay(25);//1);
    }
  }
}






