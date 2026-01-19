#ifndef OBD_MANAGER_H
#define OBD_MANAGER_H

#include <Arduino.h>

class OBDManager {
  public:
    int vSpeed;
    int vRPM;
    int vPedal_Position;
    float vOxygen_Sensor;
    int vIntake_Air_Temp;
    int vVoltage;
    int vThrottle_Position;

    void begin();
    void updateAll();

  private:
    char rxData[40];
    char text[20];
    char rxIndex = 0;
    int i = 0, j = 0;

    void read();
    void parse();
    void clearBuffer();

    void getRPM();
    void getSpeed();
    void getVoltage();
    void getThrottle();
    void getPedal();
    void getOxygen();
    void getIntakeTemp();
};

#endif
