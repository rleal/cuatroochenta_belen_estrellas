/*
 * Implementación del módulo MQTT. 
 * sobre la dependencia `PubSubClient`.
 */

#include "mqtt.h"
#include "system/logger.h"
#include "system/handler.h"
#include <PubSubClient.h>
#include <ESP8266WiFi.h>

static WiFiClient espClient;
static PubSubClient client(espClient);
static Logger l = Logger("MQTT");

/**
 * Editar estas constantes para configurar 
 * la conexión al servidor.
 */
const char *MQTT_SERVER_IP = "34.226.229.35";
const int MQTT_SERVER_PORT = 1883;

static long lastReconnectAttempt = 0;

/**
 * Método para procesar mensajes entrantes. 
 * Se apoya en el módulo de Handlers.
 */
void callback(char *topic, uint8_t *payload, unsigned int length)
{
    l << "Message from topic " << topic << " with message " << (char *)payload;
    handle(topic, payload, length);
}

/**
 * Método para intentar conectar con el servidor.
 */
boolean tryToConnect()
{
    l << "Attempting MQTT connection...";
    String clientId = "ESP8266agdflkjadsy";
    clientId += String(random(0xffff), HEX);
    return client.connect(clientId.c_str());
}

/**
 * Método para intentar suscribirse 
 * a un evento MQTT.
 */
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

/**
 * Método que se llama cuando el cliente
 * se conecta al servidor con éxito.
 * Se suscribe a los eventos registrados en
 * el módulo de Handlers.
 */
void onConnect()
{
    lastReconnectAttempt = 0;
    eachKey(subscribe);
    l << "Client connected";
}

/**
 * Bucle de reconexión. 
 * No bloqueante.
 */
void reconnectionLoop()
{
    if (!client.connected())
    {
        long now = millis();
        if (now - lastReconnectAttempt > 5000)
        {
            lastReconnectAttempt = now;
            l << "Trying to connect. Current state code is " << client.state();
            if (tryToConnect())
            {
                onConnect();
            }
        }
    }
}

/**
 * Método declarado en el header.
 */
void setUpMQTTClient()
{
    client.setServer(MQTT_SERVER_IP, MQTT_SERVER_PORT);
    client.setCallback(callback);
    l << "Client attached to " << MQTT_SERVER_IP << ":" << MQTT_SERVER_PORT;
}

/**
 * Método declarado en el header.
 */
void MQTTClientLoop()
{
    if (!client.loop())
    {
        reconnectionLoop();
    }
}
