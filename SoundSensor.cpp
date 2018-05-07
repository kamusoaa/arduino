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

void SoundSensor::doInThread(GlobalState& globalState, ThreadController controller)
{
	_soundValue = analogRead(_pin);
	if (_soundValue < 700)
	{
		digitalWrite(13, HIGH);
		_state++;
		if (_soundValue > 15)
		{
			globalState.setGlobalState(2);
			globalState.setAlarm(true);
			globalState.setName(SoundSensor::_name);

			Serial.print(_name);
			Serial.print("  ");
			Serial.println(SoundSensor::getValue());
			_state = _state -15;

			//controller.enabled = false;
			return;
		}
	}
	digitalWrite(13, LOW);
}
