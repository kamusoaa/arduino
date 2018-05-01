
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
