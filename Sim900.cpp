// 
// 
// 

#include "Sim900.h"

GSMModem::GSMModem()
{
	
}

void GSMModem::config()
{
	GPRS gprs(Serial1);
	while (!gprs.init())
		Serial.println("GSM : initialization error");
	Serial.println("GSM : initialization success");
}

String GSMModem::cATcheck()
{
	String response;

	Serial1.print("AT");
	Serial1.println();
	unsigned long startTime = millis();

	while (millis() - startTime < 500)
	{
		if (Serial1.available())
		{
			char input = Serial1.read();
			response += input;
		}
	}
	response = response.substring(6);
	response.trim();
	return response;
}
