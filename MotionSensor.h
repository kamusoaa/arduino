#pragma once
class MotionSensor
{
public:
	//MotionSensor();
	MotionSensor(String name, uint8_t pin);
	String getName();
	int getValue();
	void setAlarm(bool value);
	bool getAlarm();
	void doInThread();
	//~MotionSensor();

private:
	String _name;
	uint8_t _pin;
	uint8_t _value;
	bool _alarm;
};

