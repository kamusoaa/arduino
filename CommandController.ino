bool _run = false;
String _JSON;
String commandResponse;

constexpr unsigned int str2int(const char* str, int h = 0)
{
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}


void parseCommand()
{
  Serial.println("Parser");
  if (_run)
  {
    JsonObject& root = buffer.parseObject(_JSON);
    String command = root["text"];
    const char *cCommand = command.c_str();
    switch (str2int(cCommand))
    {
      case str2int("ON"):
        turnOnTheSiren();
        break;
      case str2int("OFF"):
        turnOffTheSiren();
        break;
      case str2int("CNOFF"):
        alwaysTurnOfTheSiren();
        break;
      case str2int("STMOI"):
        stopMotion1();
        break;
      case str2int("STMOII"):
        stopMotion2();
        break;
      case str2int("STSND"):
        stopSound();
        break;
      case str2int("STPRX"):
        stopProximity();
        break;
      case str2int("STHLL"):
        stopHall();
        break;
      case str2int("STALL"):
        stopAllSensors();
        break;
      case str2int("MODID"):
        getMoudleID();
        break;
      case str2int("MREVN"):
        getMoudleRevision();
        break;
      case str2int("MIMEI"):
        getModuleIMEI();
        break;
      case str2int("MCELL"):
        getMobileCelluar();
        break;
      case str2int("MSTAT"):
        getMobileStatus();
        break;
      case str2int("MNUMR"):
        getMobileNumber();
        break;
      case str2int("MSIGN"):
        getMobileSignalStrength();
        break;
      case str2int("MVOLT"):
        getMobileVoltage();
        break;
      case str2int("MADCV"):
        getADCvalue();
        break;
      case str2int("MBALL"):
        getBalance();
        break;
      case str2int("MTRAF"):
        getTraffic();
        break;
      default:
        break;
    }

    memset(&root, 0, sizeof(root));
    _run = false;
  }
}



void turnOnTheSiren()
{
  piezo.loudlyBeeping();
}
void turnOffTheSiren()
{
  if (state.getCriticalState())
  {
    state.reserGlobalState();
    noTone(4);
    return;
  }
  else
  {
    noTone(4);
  }
}


void alwaysTurnOfTheSiren()
{
  piezo.isShouldAlarm(false);

}

void stopMotion1()
{
  motionThread1.enabled = !motionThread1.enabled;
}

void stopMotion2()
{
  motionThread2.enabled = !motionThread2.enabled;
}

void stopSound()
{
  soundThread.enabled = !soundThread;
}
void stopProximity()
{
  proximityThread.enabled = !proximityThread.enabled;
}
void stopHall()
{
  hallThread.enabled = !hallThread.enabled;
}
void stopAllSensors()
{
  motionThread1.enabled = false;
  motionThread2.enabled = false;
  soundThread.enabled = false;
  proximityThread.enabled = false;
  hallThread.enabled = false;

}
void getMoudleID()
{
  commandResponse = modem.moduleID();
}
void getMoudleRevision()
{
  commandResponse = modem.revision();
}
void getModuleIMEI()
{
  commandResponse = modem.imei();
}
void getMobileCelluar()
{
  commandResponse = modem.celluarOperator();
}
void getMobileStatus()
{
  commandResponse = modem.moduleStatus();
}
void getMobileNumber()
{
  commandResponse = modem.mobileNumber();
}
void getMobileSignalStrength()
{
  commandResponse = modem.signalStrength();
}
void getMobileVoltage()
{
  commandResponse = modem.voltage();
}
void getADCvalue()
{
  commandResponse = modem.ADCvalue();
}
void getBalance()
{
  commandResponse = modem.getBalance();
}
void getTraffic()
{
  commandResponse = modem.getTraffic();
}
