// Sim900.h

#ifndef _SIM900_h
#define _SIM900_h
#include "GPRS_Shield_Arduino.h"
#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

class GSMModem
{
private:
	int _previousMillis;
public:
	GSMModem();
	void config();
	String cATcheck();
};