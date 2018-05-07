// 
// 
// 

#include "MoitionSensor.h"
#include"GlobalState.h"


MotionSensor::MotionSensor()
{
}

MotionSensor::MotionSensor(String name, uint8_t pin)
{
	_name = name;
	_pin = pin;
}

void MotionSensor::configure()
{
	Serial.print("Configure ");
	Serial.println(_name);
	pinMode(_pin, INPUT);

}

String MotionSensor::getName()
{
	return _name;
}

int MotionSensor::getValue()
{
	return _value;
}

void MotionSensor::setAlarm(bool value)
{
	_alarm = value;
}

bool MotionSensor::getAlarm()
{
	return _alarm;
}

void MotionSensor::doInThread(GlobalState& globalState, ThreadController controller)
{
	_value = digitalRead(_pin);
	if (_value == HIGH)
	{
		_state++;
		if (_state > 2)
		{
			globalState.setGlobalState(2);
			globalState.setAlarm(true);
			globalState.setName(MotionSensor::getName());

			Serial.print(_name);
			Serial.print("  ");
			Serial.println(_value);
			_state--;

			//controller.enabled = false;
		}
	}
}