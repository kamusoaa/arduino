// 
// 
// 

#include "ProximitySensor.h"

ProximitySensor::ProximitySensor(String name, uint8_t pin)
{
	_name = name;
	_pin = pin;
}

int ProximitySensor::getValue()
{
	return _value;
}

void ProximitySensor::doInThread(GlobalState& state, ThreadController controller)
{
	_value = digitalRead(_pin);
	if (_value == LOW)
	{
		_state++;
		if (_state > 2)
		{
			state.setGlobalState(2);
			state.setAlarm(true);
			state.setName(ProximitySensor::_name);


			Serial.print(_name);
			Serial.print("  ");
			Serial.println(_value);
			_state--;

			//controller.enabled = false;
		}
	}
}

void ProximitySensor::configure()
{
	Serial.print("Configure ");
	Serial.println(_name);

	pinMode(_pin, INPUT);
}
