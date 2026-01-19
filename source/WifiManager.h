#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <WiFiNINA.h>

class WifiManager {
  public:
    WifiManager(char* ssid, char* pass);
    void connect();
    void printInfo();

  private:
    char* _ssid;
    char* _pass;
    int _status;
};

#endif
