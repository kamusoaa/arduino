// GlobalState.h

#ifndef _GLOBALSTATE_h
#define _GLOBALSTATE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"

#else
#include "WProgram.h"
#endif

class GlobalState
{
  private:
    uint8_t _globalState;
    bool _alarm;
    bool _shouldAlarm = true;
    String _sensor;
  public:
    GlobalState();
    void setGlobalState(uint8_t value);
    uint8_t reserGlobalState();
    bool getState();
    bool getCriticalState();
    uint8_t getGlobalValue();

    void setAlarm(bool value);
    bool isAlarm();
    void setName(String name);
    String getName();
    bool isShouldAlarm();
    void setShouldAlarm(bool value);


};



#endif


