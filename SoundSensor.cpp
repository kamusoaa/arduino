// 
// 
// 

#include "SoundSensor.h"

SoundSensor::SoundSensor(String name, uint8_t pin)
{
	_name = name;
	_pin = pin;
}

int SoundSensor::getValue()
{
	return _soundValue;
}

void SoundSensor::configure()
{
	Serial.print("Configure ");
	Serial.println(_name);
	pinMode(_pin, INPUT);
}

void SoundSensor::doInThread(GlobalState& globalState)
{
	_soundValue = analogRead(_pin);
	if (_soundValue < 700)
	{
		digitalWrite(13, HIGH);
		_state++;
		if (_soundValue > 15)
		{
			globalState.setGlobalState(1);
			_state =-15;

			/*
				send to the server
			*/
			return;
		}
	}
	digitalWrite(13, LOW);
}
