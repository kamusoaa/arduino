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

void ProximitySensor::doInThread(GlobalState& state)
{
	_value = digitalRead(_pin);
	if (_value == LOW)
	{
		_state++;
		if (_state > 2)
		{
			state.setGlobalState(1);
			Serial.print(_name);
			Serial.print("  ");
			Serial.println(_value);
			_state--;
		}
	}
}

void ProximitySensor::configure()
{
	Serial.print("Configure ");
	Serial.println(_name);

	pinMode(_pin, INPUT);
}
