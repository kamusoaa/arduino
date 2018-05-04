
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
	modem.sendHttpRequest("off", motionSensor1.getValue(), motionSensor2.getValue(),
		hallSensor.getValue(), proximity.getValue(), soundSensor.getValue());
	modem.readHttpRequest();

}