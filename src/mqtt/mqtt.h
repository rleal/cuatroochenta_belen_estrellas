/*
 * Módulo de WiFi.
 *
 * Interfaz con controles simples 
 * para gersionar el cliente MQTT.
 */

#ifndef MQTT_H
#define MQTT_H

/**
 * Configuración inicial.
 */
void setUpMQTTClient();

/**
 * Método que debe ser llamado frecuentemente
 * para procesar el estado (mensajes, conexión...)
 */
void MQTTClientLoop();

#endif
