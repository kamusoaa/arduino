// LoudSpeaker.h

#ifndef _LOUDSPEAKER_h
#define _LOUDSPEAKER_h
#include "GlobalState.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#endif

class Piezo
{
private:
	uint8_t _pin[2];
	int _frequency[2];
	int _time;
	bool _alarm = false; //false - off, true - on
	unsigned long _previousMillis = 0;
	int _toneValue;

public:
	Piezo(uint8_t pin[], int freq[], int time);
	void configure();
	void loudlyBeeping();
	void quietBeep();
};