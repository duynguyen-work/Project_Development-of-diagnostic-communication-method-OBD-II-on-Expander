#include "OBDManager.h"

void OBDManager::begin() {
  Serial1.begin(9600);
  Serial1.print("ATZ\r");
  delay(2000);
}

void OBDManager::read() {
  char inChar;
  while (Serial1.available() > 0) {
    if (Serial1.peek() == '\r') {
      inChar = Serial1.read();
      rxData[rxIndex] = '\0';
      rxIndex = 0;
    } else {
      inChar = Serial1.read();
      if (inChar != '\n')
        rxData[rxIndex++] = inChar;
    }
  }
}

void OBDManager::clearBuffer() {
  memset(rxData, 0, sizeof(rxData));
  memset(text, 0, sizeof(text));
}

void OBDManager::parse() {
  int len = strlen(rxData);
  if (rxData[0] == '>') {
    for (i = 4; i < (len / 2 + 2); i++) text[j++] = rxData[i];
  } else {
    for (i = 0; i < (len / 2 - 2); i++) text[j++] = rxData[i];
  }
  text[j] = '\0';
  j = 0;
}

void OBDManager::getRPM() {
  Serial1.print("010C\r");
  read(); parse();
  vRPM = ((strtol(&text[6], 0, 16) * 256) + strtol(&text[9], 0, 16)) / 4;
  clearBuffer();
}

void OBDManager::getSpeed() {
  Serial1.print("010D\r");
  read(); parse();
  vSpeed = strtol(&text[6], 0, 16);
  clearBuffer();
}

void OBDManager::getVoltage() {
  Serial1.print("0142\r");
  read(); parse();
  vVoltage = (strtol(&text[6], 0, 16) * 256 + strtol(&text[9], 0, 16)) / 1000;
  clearBuffer();
}

void OBDManager::getThrottle() {
  Serial1.print("0111\r");
  read(); parse();
  vThrottle_Position = (strtol(&text[6], 0, 16) * 100) / 255;
  clearBuffer();
}

void OBDManager::getPedal() {
  Serial1.print("0149\r");
  read(); parse();
  vPedal_Position = (strtol(&text[6], 0, 16) * 100) / 255;
  clearBuffer();
}

void OBDManager::getOxygen() {
  Serial1.print("0115\r");
  read(); parse();
  vOxygen_Sensor = strtol(&text[6], 0, 16) / 200.0;
  clearBuffer();
}

void OBDManager::getIntakeTemp() {
  Serial1.print("010F\r");
  read(); parse();
  vIntake_Air_Temp = strtol(&text[6], 0, 16) - 40;
  clearBuffer();
}

void OBDManager::updateAll() {
  getRPM();
  getSpeed();
  getVoltage();
  getIntakeTemp();
  getThrottle();
  getOxygen();
  getPedal();
}
