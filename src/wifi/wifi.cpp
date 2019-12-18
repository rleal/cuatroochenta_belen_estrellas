#include "wifi.h"
#include "logger/logger.h"
#include <WiFiManager.h>

static WiFiManager wifiManager;
static Logger l = Logger("WiFi");

void setUpWifi()
{
    wifiManager.autoConnect("EquipoLuces");
    l << "Connected";
}

void resetWifi()
{
    wifiManager.resetSettings();
    l << "Reset";
}
