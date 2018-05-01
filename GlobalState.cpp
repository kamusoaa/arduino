// 
// 
// 

#include "GlobalState.h"

GlobalState::GlobalState()
{
}

void GlobalState::setGlobalState(uint8_t value)
{
	if (value != 0)
	{
		if (_globalState >= 2)
			return;
		else _globalState += value;
	}
}

uint8_t GlobalState::reserGlobalState()
{
	return _globalState = 0;
}

bool GlobalState::getState()
{
	if (_globalState == 1)
		return true;
	else return false;
}

bool GlobalState::getCriticalState()
{
	if (_globalState == 2)
		return true;
	else return false;
}

uint8_t GlobalState::getGlobalValue()
{
	return _globalState;
}
