/*
 * Módulo para declarar la lógica del Belen
 * relacionada con la placa.
 */

#ifndef BELEN_H
#define BELEN_H

#include <Arduino.h>

/**
 * Configuración inicial
 */
void setUpBelen();

/**
 * Método que ha de ser llamado de vez en cuando para
 * permitir acciones de la placa.
 */
void belenLoop();

#endif
