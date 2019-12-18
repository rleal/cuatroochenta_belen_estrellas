#include "mqtt.h"
#include "logger/logger.h"
#include <PubSubClient.h>
#include <ESP8266WiFi.h>

static WiFiClient espClient;
static PubSubClient client(espClient);
static Logger l = Logger("MQTT");

const char *MQTT_SERVER_IP = "34.226.229.35";
const int MQTT_SERVER_PORT = 1883;

static bool reconnecting = false;

void callback(char *topic, byte *payload, unsigned int length)
{
    l << "Message from topic " << topic << " with message " << (char *)payload;

    // TODO handler
    // Switch on the LED if an 1 was received as first character
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

void setUpMQTTClient()
{
    client.setServer(MQTT_SERVER_IP, MQTT_SERVER_PORT);
    client.setCallback(callback);
    l << "Client connected to " << MQTT_SERVER_IP << ":" << MQTT_SERVER_PORT;
}

void reconnect()
{
    while (!client.connected())
    {
        l << "Attempting MQTT connection...";

        String clientId = "ESP8266agdflkjadsy";
        clientId += String(random(0xffff), HEX);

        if (client.connect(clientId.c_str()))
        {
            reconnecting = false;
            l << "Client connected";

            // TODO mock
            // Once connected, publish an announcement...
            client.publish("outTopic", "hello world");
            // ... and resubscribe
            client.subscribe("inTopic");
        }
        else
        {
            l << "Connection failed with status " << client.state() << ". Try again in 5 seconds";
            delay(5000);
        }
    }
}

void reconnectMQTTClientIfRequired()
{
    if (!client.connected() && !reconnecting)
    {
        reconnecting = true;
        reconnect();
    }
}
