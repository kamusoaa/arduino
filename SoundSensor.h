// SoundSensor.h

#ifndef _SOUNDSENSOR_h
#define _SOUNDSENSOR_h
#include "GlobalState.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif


class SoundSensor
{
private:
	uint8_t _pin;
	int _soundValue;
	uint8_t _state;
	String _name;

public:
	SoundSensor(String name, uint8_t pin);
	int getValue();
	void configure();
	void doInThread(GlobalState& globalState);

};
