#include <stdio.h>
#include <wiringPi.h>

typedef enum {false = 0, true = 1} boolean;

// Configuration
const int led_Blue = 0;
const int led_Red = 1;
const int led_Yellow = 2;
const int led_Green = 3;
const int led_White = 4;


const int timeoutMsPrimo = 30;
const int timeoutMsSecondo = 100;


const boolean ON = true;
const boolean OFF = false;

int pins[] = {led_Blue, led_Red, led_Yellow, led_Green, led_White};
int numberPins = sizeof(pins)/sizeof(pins[0]);


void setLed(int ledNumber, boolean action) {
		
	digitalWrite(ledNumber, action);
}

// Turn off all the leds

void resetLeds() {
	
	static int indexPins;
	for(indexPins = 0; indexPins < numberPins; indexPins ++) {
		
		setLed(pins[indexPins], OFF);
	}
}

void init() {
	
	wiringPiSetup();
	
	static int indexPins;
	for(indexPins = 0; indexPins < numberPins; indexPins ++) {
		
		pinMode(pins[indexPins], OUTPUT);
	}
	
	resetLeds();
}

// Turn on all the leds
void setLeds() {
	
	static int indexPins;
	for(indexPins = 0; indexPins < numberPins; indexPins ++) {
		
		setLed(pins[indexPins], ON);
	}
}

// Turn on the led once by once
void onceByOnce(){
	
	static int indexPins;
	
	for(int i = 0; i < 50; i++){
	
		for(indexPins = 0; indexPins < numberPins; indexPins ++) {
			
			setLed(pins[indexPins], ON);
			delay(timeoutMsPrimo);
			setLed(pins[indexPins], OFF);

		}
	}
}

void blink(){
	
	for(int i = 0; i < 10; i++){
		resetLeds();
		delay(timeoutMsSecondo);
		setLeds();
		delay(timeoutMsSecondo);
	}
}

int main() {

    init();
	
	while(true) {
				
		onceByOnce();
				
		delay(timeoutMsSecondo);
		
		blink();
	}
	
    return 0;
}
