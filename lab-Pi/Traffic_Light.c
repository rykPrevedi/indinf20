#include <stdio.h>
#include <wiringPi.h>

typedef enum {false = 0, true = 1} boolean;

// Configuration pins
const int led_Red = 1;
const int led_Yellow = 2;
const int led_Green = 3;

const int timeoutMs = 1000;	// 1 sec

const boolean ON = true;
const boolean OFF = false;

int pins[] = {led_Red, led_Yellow, led_Green};
int numberPins = sizeof(pins)/sizeof(pins[0]);


void init() {
	wiringPiSetup();
	static int indexPins;
	
	for (indexPins = 0; indexPins < numberPins; indexPins++) {
		pinMode(pins[indexPins], OUTPUT);
	}
}

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

void setOnOff(int time, int led) {
	setLed(led, ON);
	delay(time*1000);
	setLed(led, OFF);
}

void blinkingYellow(){
	boolean onoff = true;
	int count = 0;
	
	while(count < 5) {
		setLed(led_Yellow, onoff);
		onoff = !onoff;
		delay(timeoutMs);
		count++;
	}
}

void normalCycle() {
	
	int currentState = 0;
	int errorCounter = 0;
	int time1 = 10;
	int time2 = 15;
	int time3 = 5;
	
	while (true) {
		
		printf("insert current state:\n");
		scanf("%d", &currentState);
		
		if(errorCounter == 10) {
			blinkingYellow();
			break;
		}
		
		if(currentState == 0){
			setOnOff(time1, led_Red);
			currentState = 2;
			errorCounter++;
		} else if(currentState == 2){
			setOnOff(time2, led_Green);
			currentState = 1;
			errorCounter++;
		} else {
			setOnOff(time3, led_Yellow);
			currentState = 0;
		}
	}
}

int main() {

    init();
	resetLeds();
	normalCycle();
	
    return 0;
}
