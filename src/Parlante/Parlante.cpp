#include "Parlante.hpp"

Parlante::Parlante(uint8_t PIN, uint16_t frecuencia, Modos estado = Modos::APAGADO)
{
    this->PIN = PIN;
    this->frecuencia = frecuencia;
    this->estado = estado;
    pinMode(this->PIN, OUTPUT);
}

void Parlante::establecerEncendido(Modos estado)
{
    this->estado = estado;
}

bool Parlante::estaEncendido()
{
    return this->estado;
}

void Parlante::aplicarEstado()
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
        this->titilar(500);
    }
}

void Parlante::titilar(uint16_t tiempo_ms)
{
    static unsigned long time = 0;
    static bool sonando = false;
    if (millis() >= time + tiempo_ms)
    {
        time += tiempo_ms;
        sonando = !sonando;
        if (sonando && this->estaEncendido())
        {
            analogWrite(this->PIN, this->frecuencia);
        }
        else
        {
            analogWrite(this->PIN, 0);
        }
    }
    else if (!this->estaEncendido())
    {
        analogWrite(this->PIN, 0);
    }
}