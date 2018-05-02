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

String GSMModem::AT()
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

String GSMModem::moduleID()
{
	String response;
	Serial1.print("AT+GMM");
	Serial1.println();
	unsigned long startTime = millis();

	while (millis() - startTime < 2000)
	{
		if (Serial1.available())
		{
			char input = Serial1.read();
			response += input;
		}
	}
	response = response.substring(6);
	response = response.substring(0,17);
	response.trim();
	return response;
}

String GSMModem::revision()
{
	String response;
	Serial1.print("AT+GMR");
	Serial1.println();
	unsigned long startTime = millis();

	while (millis() - startTime < 1000)
	{
		if (Serial1.available())
		{
			char input = Serial1.read();
			response += input;
		}
	}
	response = response.substring(19,42);
	response.trim();
	return response;
}

String GSMModem::imei()
{
	String response;
	Serial1.print("AT+GSN");
	Serial1.println();
	unsigned long startTime = millis();

	while (millis() - startTime < 1000)
	{
		if (Serial1.available())
		{
			char input = Serial1.read();
			response += input;
		}
	}
	response = response.substring(10,25);
	response.trim();
	return response;
}

String GSMModem::celluarOperator()
{
	String response;
	Serial1.print("AT+COPS?");
	Serial1.println();
	unsigned long startTime = millis();

	while (millis() - startTime < 1000)
	{
		if (Serial1.available())
		{
			char input = Serial1.read();
			response += input;
		}
	}
	response = response.substring(24, 33);
	response.trim();
	return response;
}

String GSMModem::moduleStatus()
{
	String response;
	String a = "0";
	String a1 = "2";

	Serial1.print("AT+CPAS");
	Serial1.println();
	unsigned long startTime = millis();

	while (millis() - startTime < 1000)
	{
		if (Serial1.available())
		{
			char input = Serial1.read();
			response += input;
		}
	}
	response = response.substring(18, 19);
	response.trim();
	if (response == "0")
		return "Ready to work";
	if (response == "2")
		return "Unknown";
	return response;
}

String GSMModem::signalStrength()
{
	String response;

	Serial1.print("AT+CSQ");
	Serial1.println();
	unsigned long startTime = millis();

	while (millis() - startTime < 1000)
	{
		if (Serial1.available())
		{
			char input = Serial1.read();
			response += input;
		}
	}
	response = response.substring(16, 20);
	response.trim();

	switch (response.toInt())
	{
	case 0:
		return "-115dBl";
		break;
	case  1:
		return "-112dBl";
		break;
	case 31:
		return "-52dBl";
		break;
	case 99:
		return "No signal";
		break;
	default:
		break;
	}

	if (response.toInt() >= 2 && response.toInt() <= 30)
		return "-110dBl";
	return response;
}

String GSMModem::currentTime()
{
	String response;

	Serial1.print("AT+CCLK?");
	Serial1.println();
	unsigned long startTime = millis();

	while (millis() - startTime < 1000)
	{
		if (Serial1.available())
		{
			char input = Serial1.read();
			response += input;
		}
	}
	response = response.substring(20, 40);
	response.trim();
	return response;
}

String GSMModem::voltage()
{
	String response;

	Serial1.print("AT+CBC");
	Serial1.println();
	unsigned long startTime = millis();

	while (millis() - startTime < 1000)
	{
		if (Serial1.available())
		{
			char input = Serial1.read();
			response += input;
		}
	}
	response = response.substring(16, 28);
	response.trim();
	return response;
}

String GSMModem::ADCvalue()
{
	String response;

	Serial1.print("AT+CADC?");
	Serial1.println();
	unsigned long startTime = millis();

	while (millis() - startTime < 1000)
	{
		if (Serial1.available())
		{
			char input = Serial1.read();
			response += input;
		}
	}
	response = response.substring(19, 22);
	response.trim();


	/*Serial.println(response.length());
	Serial.println(response);
	response = response.substring(19, 22);
	response.trim();
	Serial.println("====");
	Serial.println(response);
	Serial.println(response.length());
	Serial.println(response.toInt());*/
	return response;
}
