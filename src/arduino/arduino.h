/*
 * Módulo para declarar la lógica 
 * relacionada con la placa.
 */

#ifndef ARDUINO_H
#define ARDUINO_H

#include <Arduino.h>

/**
 * Configuración inicial
 */
void setUpArduino();

/**
 * Método que ha de ser llamado de vez en cuando para
 * permitir acciones de la placa.
 */
void arduinoLoop();

#endif
