// 
// 
// 

#include "Piezo.h"

Piezo::Piezo(uint8_t pin[], int freq[], int time)
{
	for (int i = 0; i < sizeof(pin); i++)
		_pin[i] = pin[i];
	for (int i = 0; i < sizeof(freq); i++)
		_frequency[i] = freq[i];
	_time = time;
	_toneValue = _frequency[0];
}

void Piezo::configure()
{
	Serial.println("Configure Piezo");
	for (int i = 0; i < sizeof(_pin); i++)
		pinMode(_pin[i], OUTPUT);
}

void Piezo::loudlyBeeping()
{
	unsigned long currentTime = millis();
	if (currentTime - _previousMillis >= _time)
	{
		_previousMillis = millis();
		if (_toneValue == _frequency[0])
			_toneValue = _frequency[1];
		else  _toneValue = _frequency[0];

		tone(_pin[0], _toneValue);
		tone(_pin[1], _toneValue);

	}
}

void Piezo::waitCommand()
{

}
