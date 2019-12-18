/*
 * Módulo de logging.
 *
 * Centralización de los logs del sistema. 
 * 
 * Se utilizan streams para eficiencia y comodidad.
 * Hay que añadir sobrecargas del operador de stream
 * si se necesite que funcione com más tipos.
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>
#include <sstream>
using namespace std;

/**
 * Método que se ha de llamar de vez en cuando para
 * hacer efectivos los logs.
 */
void flushLog();

/**
 * Clase para instanciar un logger de un asunto concreto
 * y ofrecer operaciones de stream.
 */
class Logger
{
public:
    const char *subject;

    Logger(const char *s)
    {
        subject = s;
    }

    Logger(char *s)
    {
        subject = s;
    }

    friend ostream &operator<<(ostream &os, const Logger &l);

    friend ostream &operator<<(const Logger &l, const void *p);

    friend ostream &operator<<(const Logger &l, const char *p);

    friend ostream &operator<<(const Logger &l, char *p);

    friend ostream &operator<<(const Logger &l, int p);
};

#endif
