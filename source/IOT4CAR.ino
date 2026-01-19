#include "OBDManager.h"
#include "WifiManager.h"
#include "CloudClient.h"

char ssid[] = "YOUR_WIFI";
char pass[] = "YOUR_PASS";
char server[] = "dweet.io";

OBDManager obd;
WifiManager wifi(ssid, pass);
CloudClient cloud(server);

void setup() {
  Serial.begin(9600);
  obd.begin();
  wifi.connect();
}

void loop() {
  obd.updateAll();
  cloud.send(obd);
  wifi.printInfo();
  delay(5000);
}
