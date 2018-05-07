// HallSensor.h

#ifndef _HALLSENSOR_h
#define _HALLSENSOR_h
#include "GlobalState.h"
#include "ThreadController.h"
#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

class HallSensor
{
private :
	uint8_t _pin;
	uint8_t _state;
	int _value;
	String _name;

public:
	HallSensor(String name, uint8_t pin);
	int getValue();
	void doInThread(GlobalState& global, ThreadController controller);
	void configure();
};