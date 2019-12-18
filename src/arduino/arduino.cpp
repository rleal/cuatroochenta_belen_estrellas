#include "arduino.h"
#include "handler/handler.h"
#include "logger/logger.h"

static Logger l = Logger("ARDUINO");

const char *HELLO_WORLD_TOPIC = "HELLO_WORLD";

void onHelloWorld(__UINT8_TYPE__ *payload, unsigned int length)
{
    l << "Handle for " << (char *)payload;

    if ((char)payload[0] == '1')
    {
        //digitalWrite(BUILTIN_LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
        // but actually the LED is on; this is because
        // it is active low on the ESP-01)
    }
    else
    {
        //digitalWrite(BUILTIN_LED, HIGH);  // Turn the LED off by making the voltage HIGH
    }
}

void setUpArduino()
{
    Serial.begin(115200);

    pinMode(A0, INPUT);
    pinMode(D0, OUTPUT);
    pinMode(D1, INPUT);

    addHandler(HELLO_WORLD_TOPIC, onHelloWorld);
    l << "Arduino ready";
}
