#ifndef CLOUD_CLIENT_H
#define CLOUD_CLIENT_H

#include <WiFiNINA.h>
#include "OBDManager.h"

class CloudClient {
  public:
    CloudClient(char* server);
    void send(OBDManager& obd);

  private:
    WiFiClient client;
    char* _server;
};

#endif
