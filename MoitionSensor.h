// MoitionSensor.h
#ifndef _MOITIONSENSOR_h
#define _MOITIONSENSOR_h

#include"GlobalState.h"
#include "ThreadController.h"
#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif



class MotionSensor
{

private:
	String _name;
	uint8_t _pin;
	uint8_t _value;
	bool _alarm;
	uint8_t _state;
public:
	MotionSensor();
	MotionSensor(String name, uint8_t pin);
	void configure();
	String getName();
	int getValue();
	void setAlarm(bool value);
	bool getAlarm();
	void doInThread(GlobalState& globalState, ThreadController controller);

};