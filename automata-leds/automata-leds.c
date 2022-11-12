#include <stdio.h>
#include <wiringPi.h>

typedef enum {false = 0, true = 1} boolean;

// Configuration
const int led_Blue = 0;
const int led_Red = 1;
const int led_Yellow = 2;
const int led_Green = 3;

const int timeoutMs = 5000;

const boolean ON = true;
const boolean OFF = false;

int pins[] = {led_Blue, led_Red, led_Yellow, led_Green};
int numberPins = sizeof(pins)/sizeof(pins[0]);


void setLed(int ledNumber, boolean action) {
		
	digitalWrite(ledNumber, action);

}

// Turns off all leds

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

const int table[][4] =
        {
                {2,  1,  3,  -1}, // State 0
                {-1, 1,  3,  -1}, // State 1
                {0,  -1, -1, -1}, // State 2
                {-1, -1, -1, -1}  // State 3
        };
//Input Symbols: 'a' 'b' 'c' 'x'

const char *outmfn[] = {"You are in state: 0", "You are in state: 1", "You are in state: 2", "You are in state: 3"};

int sfn(int currentState, int in) {
    return table[currentState][in];
}

void mfn(int currentState) {
	
	resetLeds();
	
	if (currentState < 0) {
		setLed(led_Red, ON);
		printf("Input not legal!\n");
		delay(timeoutMs);
		//Turn OFF the Led
		setLed(led_Red, OFF);
	} else if (currentState == 0) {
		setLed(led_Blue, ON);
		printf("%s\n", outmfn[currentState]);
	} else if (currentState == 1 || currentState == 2) {
		setLed(led_Yellow, ON);
		printf("%s\n", outmfn[currentState]);
	} else if (currentState == 3) {
		setLed(led_Green, ON);
		printf("Input is legal :)\n");
		delay(timeoutMs);
		//Turn OFF the Led
		setLed(led_Green, OFF);
	}
}



int main() {

    init();
	
	static int state = 0;
    static char letter = ' ';

	setLed(led_Blue, ON);
	
	while (true) {
		printf("Insert a symbol\n");
		scanf("%s", &letter);
		int numLetter = (int) letter - 'a';
		
		//Check if it's a legal symbol
		if(numLetter < 0 || numLetter > 2) {
			
			resetLeds();
			setLed(led_Red, ON);
			printf("Symbol not legal\n");
			delay(timeoutMs);
			//Turn OFF the Led
			setLed(led_Red, OFF);
			break;
			return -1;
		}
		
		state = sfn(state, numLetter);
		mfn(state);
		
		if (state < 0) {
			break;
			return -1;
		} else if (state == 3) {
			break;
			return 0;
		}
	}
    
    return 0;
}
