
void doInMotionSensorThread1()
{
	motionSensor1.doInThread(state);
}

void doInMotionSensorThread2()
{
	motionSensor2.doInThread(state);
}

void doInSoundSensorThread()
{
	soundSensor.doInThread(state);
}

void doInProximitySensorThread()
{
	proximity.doInThread(state);
}
void doInHallThread()
{
	hallSensor.doInThread(state);
}

void sendData()
{

	/*String response;
	Serial1.println("AT+HTTPACTION=1");
	unsigned long startTime = millis();
	while (millis() - startTime < 8000)
	{
		if (Serial1.available())
		{
			char input = Serial1.read();
			response += input;
		}
	}
	Serial.println("===");
	Serial.println(response);*/


	modem.sendHttpRequest("off", motionSensor1.getValue(), motionSensor2.getValue(),
		hallSensor.getValue(), proximity.getValue(), soundSensor.getValue());
	modem.readHttpRequest();

}