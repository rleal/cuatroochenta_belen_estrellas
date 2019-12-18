#include "mqtt.h"
#include "logger/logger.h"
#include "handler/handler.h"
#include <PubSubClient.h>
#include <ESP8266WiFi.h>

static WiFiClient espClient;
static PubSubClient client(espClient);
static Logger l = Logger("MQTT");

const char *MQTT_SERVER_IP = "34.226.229.35";
const int MQTT_SERVER_PORT = 1883;

static bool reconnecting = false;

void callback(char *topic, uint8_t *payload, unsigned int length)
{
    l << "Message from topic " << topic << " with message " << (char *)payload;
    handle(topic, payload, length);
}

void setUpMQTTClient()
{
    client.setServer(MQTT_SERVER_IP, MQTT_SERVER_PORT);
    client.setCallback(callback);
    l << "Client connected to " << MQTT_SERVER_IP << ":" << MQTT_SERVER_PORT;
}

boolean tryToConnect()
{
    l << "Attempting MQTT connection...";
    String clientId = "ESP8266agdflkjadsy";
    clientId += String(random(0xffff), HEX);
    return client.connect(clientId.c_str());
}

void subscribe(const char *topic)
{
    if (client.subscribe(topic))
    {
        l << "Subscribed for " << topic;
    }
    else
    {
        l << "Subscription failed for " << topic;
    }
}

void onConnect()
{
    reconnecting = false;
    l << "Client connected";
    eachKey(subscribe);
}

void reconnectingLoop()
{
    while (!client.connected())
    {
        if (tryToConnect())
        {
            onConnect();
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
        reconnectingLoop();
    }
}
