#include "LuzTestigo.hpp"

LuzTestigo::LuzTestigo(uint8_t PIN, Modos estado = Modos::APAGADO)
{
    this->PIN = PIN;
    this->estado = estado;
    pinMode(this->PIN, OUTPUT);
}

void LuzTestigo::establecerEncendido(Modos estado)
{
    this->estado = estado;
}

bool LuzTestigo::estaEncendido()
{
    return this->estado;
}

void LuzTestigo::aplicarEstado()
{
    switch (this->estado)
    {
    case Modos::APAGADO:
        digitalWrite(this->PIN, LOW);
        break;
    case Modos::ENCENDIDO:
        digitalWrite(this->PIN, HIGH);
        break;
    case Modos::TITILANDO:
        this->titilar(1000);
    }
}

void LuzTestigo::titilar(uint16_t tiempo_ms)
{
    static unsigned long time = 0;
    static bool encendido = false;
    if (millis() >= time + tiempo_ms)
    {
        time += tiempo_ms;
        encendido = !encendido;
        if (encendido && this->estaEncendido())
        {
            digitalWrite(this->PIN, HIGH);
        }
        else
        {
            digitalWrite(this->PIN, LOW);
        }
    }
    else if (!this->estaEncendido())
    {
        digitalWrite(this->PIN, LOW);
    }
}