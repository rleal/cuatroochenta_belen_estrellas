#include "wifi.h"
#include <WiFiManager.h>

WiFiManager wifiManager;

void setUpWifi()
{
    wifiManager.autoConnect("EquipoLuces");
    Serial.println("WiFi connected");
}

void resetWifi()
{
    wifiManager.resetSettings();
}
