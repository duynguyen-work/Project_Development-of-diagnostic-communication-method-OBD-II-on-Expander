#include "CloudClient.h"

CloudClient::CloudClient(char* server) {
  _server = server;
}

void CloudClient::send(OBDManager& obd) {
  if (client.connect(_server, 80)) {
    String req = "GET /dweet/for/arduinoMRK1000";
    req += "&RPM=" + String(obd.vRPM);
    req += "&Speed=" + String(obd.vSpeed);
    req += "&Pedal=" + String(obd.vPedal_Position);
    req += "&Oxygen=" + String(obd.vOxygen_Sensor);
    req += "&Voltage=" + String(obd.vVoltage);
    req += "&Intake=" + String(obd.vIntake_Air_Temp);
    req += "&Throttle=" + String(obd.vThrottle_Position);

    client.println(req);
    client.println("Host: dweet.io");
    client.println("Connection: close");
    client.println();
  }
  client.stop();
}
