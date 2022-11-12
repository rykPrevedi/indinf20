#include <stdio.h>
#include <wiringPi.h>

typedef enum {false = 0, true = 1} boolean;

// Configuration
const int led_Blue = 0;
const int timeoutMs = 1000;


void init() {
	
	wiringPiSetup();
	pinMode(led_Blue, OUTPUT);
}

void setLed(int ledNumber, boolean action) {
	
	digitalWrite(ledNumber, action);
	
}

int main() {

    init();
	
	boolean onoff = true;
	
	unsigned int count = 0;
	
	while(true) {
		
		printf("current value is: %d\n", count);

		setLed(led_Blue, onoff);
		onoff = !onoff;
		
		count ++;
		delay(timeoutMs);
	}
	
    return 0;
}
