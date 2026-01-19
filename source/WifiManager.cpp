#include "WifiManager.h"

WifiManager::WifiManager(char* ssid, char* pass) {
  _ssid = ssid;
  _pass = pass;
  _status = WL_IDLE_STATUS;
}

void WifiManager::connect() {
  while (_status != WL_CONNECTED) {
    _status = WiFi.begin(_ssid, _pass);
    delay(5000);
  }
}

void WifiManager::printInfo() {
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  Serial.print("RSSI: ");
  Serial.println(WiFi.RSSI());
}
