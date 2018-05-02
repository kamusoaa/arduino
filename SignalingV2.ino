
/*
Name:		SignalingV2.ino
Created:	01.05.2018 12:35:33
Author:	kozjava
*/


#include "Sim900.h"
#include "HallSensor.h"
#include "ProximitySensor.h"
#include "Piezo.h"
#include "SoundSensor.h"
#include "GlobalState.h"
#include "MoitionSensor.h"
#include<Thread.h>

uint8_t piezoPins[2] = { 4,3};
int freq[2] = { 700,900 };
int piezoTime = 1000;


GlobalState state = GlobalState();
Piezo piezo = Piezo(piezoPins, freq, piezoTime);

Thread motionThread1 = Thread();
Thread motionThread2 = Thread();
Thread soundThread = Thread();
Thread proximityThread = Thread();
Thread hallThread = Thread();
GSMModem modem;

MotionSensor motionSensor1("Motion1", 12);
MotionSensor motionSensor2("Motion2", 11);
SoundSensor soundSensor("Sound", A0);
ProximitySensor proximity("Proximity", 7);
HallSensor hallSensor("HallSensor", A1);


void setup()
{
  /* add setup code here */

	Serial.begin(9600);
	Serial1.begin(2400);

	motionSensor1.configure();
	motionThread1.enabled = true;
	motionThread1.onRun(doInMotionSensorThread1);
	motionThread1.setInterval(1000);

	motionSensor2.configure();
	motionThread2.enabled = true;
	motionThread2.onRun(doInMotionSensorThread2);
	motionThread2.setInterval(1000);

	soundSensor.configure();
	soundThread.enabled = true;
	soundThread.onRun(doInSoundSensorThread);
	soundThread.setInterval(0);

	proximity.configure();
	proximityThread.enabled = true;
	proximityThread.onRun(doInProximitySensorThread);
	proximityThread.setInterval(1000);

	hallSensor.configure();
	hallThread.enabled = true;
	hallThread.onRun(doInHallThread);
	hallThread.setInterval(0);

	piezo.configure();

	modem.config();
	//modem.cATcheck(); work!




	
}

void loop()
{
  /* add main program code here */
	if (motionThread1.shouldRun())
		motionThread1.run();
	if (motionThread2.shouldRun())
		motionThread2.run();
	if (soundThread.shouldRun())
		soundThread.run();
	if (proximityThread.shouldRun())
		proximityThread.run();
	if (hallThread.shouldRun())
		hallThread.run();


	if (state.getCriticalState())
		piezo.loudlyBeeping();

}



