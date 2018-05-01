// GlobalState.h

#ifndef _GLOBALSTATE_h
#define _GLOBALSTATE_h

	#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"

	#else
	#include "WProgram.h"
#endif

class GlobalState
{
private:
	uint8_t _globalState;

public:
	GlobalState();
	void setGlobalState(uint8_t value);
	uint8_t reserGlobalState();
	bool getState();
	bool getCriticalState();
	uint8_t getGlobalValue();

};



#endif


