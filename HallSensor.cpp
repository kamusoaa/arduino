// 
// 
// 

#include "HallSensor.h"

HallSensor::HallSensor(String name, uint8_t pin)
{
	_name = name;
	_pin = pin;
}

int HallSensor::getValue()
{
	return _value;
}

void HallSensor::doInThread(GlobalState & global, ThreadController controller)
{
	_value = analogRead(_pin);
	if (_value > 450) // for - in magnet
	{
		_state++;
		if (_state > 50)
		{
			global.setGlobalState(2);
			global.setAlarm(true);
			global.setName(HallSensor::_name);
			_state = _state - 50;

			Serial.print(_name);
			Serial.print("  ");
			Serial.println(_value);

			//controller.enabled = false;

		}
	}
}

void HallSensor::configure()
{
	Serial.print("Configure ");
	Serial.println(_name);
	pinMode(_pin, INPUT);
}
