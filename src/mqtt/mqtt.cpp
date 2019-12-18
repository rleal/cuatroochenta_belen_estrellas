/*
 * Implementación del módulo MQTT. 
 * sobre la dependencia `PubSubClient`.
 */

#include "mqtt.h"
#include "logger/logger.h"
#include "handler/handler.h"
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

static bool reconnecting = false;

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
    reconnecting = false;
    l << "Client connected";
    eachKey(subscribe);
}

/**
 * Bucle de reconexión. 
 * Ahora mismo es bloqueante hacia el bucle principal.
 */
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
            flushLog();
            delay(5000);
        }
    }
}

/**
 * Método declarados en el header.
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
    if (client.loop() || reconnecting)
    {
        return;
    }

    reconnecting = true;
    reconnectingLoop();
}
