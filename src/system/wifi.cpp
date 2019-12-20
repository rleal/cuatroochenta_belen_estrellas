/*
 * Implementación del módulo de WiFi 
 * sobre la dependencia `WifiManager`.
 */

#include "wifi.h"
#include "system/logger.h"
#include <WiFiManager.h>

static WiFiManager wifiManager;
static Logger l = Logger("WiFi");

/**
 * Método declarado en el header.
 */
void setUpWifi()
{
    wifiManager.autoConnect("EquipoLuces");
    l << "Connected";
}

/**
 * Método declarado en el header.
 */
void resetWifi()
{
    wifiManager.resetSettings();
    l << "Reset";
}
