#include "arduino.h"
#include "logger/logger.h"

static Logger l = Logger("ARDUINO");

void setUpArduino()
{
    Serial.begin(115200);

    pinMode(A0, INPUT);
    pinMode(D0, OUTPUT);
    pinMode(D1, INPUT);
    l << "Arduino ready";
}
