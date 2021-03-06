// Sim900.h

#ifndef _SIM900_h
#define _SIM900_h
#include "GPRS_Shield_Arduino.h"
#include "ArduinoJson.h"
  
#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
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
	String AT();
	String moduleID();
	String revision();
	String imei();

	String celluarOperator();
	String mobileNumber();
	String moduleStatus();
	String signalStrength();
	String getCurrentTime();
	String setTime(char* time);
	String voltage();
	String ADCvalue();

	String callTo(char* cellNumber);
	String getBalance();
	String getTraffic();
	bool sendSMS(char* number, char* text);

	void setConnection();
	void sendHttpRequest(String url, String data);
	String readHttpRequest();

	
};
