// ProximitySensor.h

#ifndef _PROXIMITYSENSOR_h
#define _PROXIMITYSENSOR_h
#include "GlobalState.h"
#include "ThreadController.h"
#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

class ProximitySensor
{
private:
	uint8_t _pin;
	uint8_t _state;
	int _value;
	String _name;
public:
	ProximitySensor(String name, uint8_t pin);
	int getValue();
	void doInThread(GlobalState& state, ThreadController controller);
	void configure();
};
