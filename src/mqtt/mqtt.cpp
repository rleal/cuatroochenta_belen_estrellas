#include "mqtt.h"
#include <PubSubClient.h>
#include <ESP8266WiFi.h>

WiFiClient espClient;
PubSubClient client(espClient);

const char *MQTT_SERVER_IP = "34.226.229.35";
const int MQTT_SERVER_PORT = 1883;

bool reconnecting = false;

void callback(char *topic, byte *payload, unsigned int length)
{
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    for (int i = 0; i < length; i++)
    {
        Serial.print((char)payload[i]);
    }
    Serial.println();

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
}

void reconnect()
{
    while (!client.connected())
    {
        Serial.print("Attempting MQTT connection...");
        String clientId = "ESP8266agdflkjadsy";
        clientId += String(random(0xffff), HEX);

        if (client.connect(clientId.c_str()))
        {
            reconnecting = false;
            Serial.println("MQTT client connected");
            // Once connected, publish an announcement...
            client.publish("outTopic", "hello world");
            // ... and resubscribe
            client.subscribe("inTopic");
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            // Wait 5 seconds before retrying
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
