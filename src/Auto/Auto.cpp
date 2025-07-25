#include "Auto.hpp"
#include "../config/Modos.hpp"
#include "../config/config.hpp"

Auto::Auto()
{
    this->motorIzquierdo = new Motor(Config::ENA, Config::IN1, Config::IN2);
    this->motorDerecho = new Motor(Config::ENB, Config::IN3, Config::IN4);
    this->luzAdelante = new LuzTestigo(Config::LED_ADELANTE);
    this->luzAtras = new LuzTestigo(Config::LED_ATRAS);
    this->parlante = new Parlante(Config::PIN_PARLANTE, 50);
    this->motorDerecho->potencia = 0;
    this->motorIzquierdo->potencia = 0;
    this->display = new Display();
    this->palabraAdelante = new String(Config::PALABRA_ADELANTE_DEFAULT);
    this->palabraAtras = new String(Config::PALABRA_ATRAS_DEFAULT);
    this->display->MostrarPalabra(this->palabraAdelante);
    this->mostrandoPalabraAutomatica = true;
}

void Auto::actualizarEstados()
{
    this->motorDerecho->aplicarPotencia();
    this->motorIzquierdo->aplicarPotencia();
    this->luzAdelante->aplicarEstado();
    this->luzAtras->aplicarEstado();
    this->parlante->aplicarEstado();
}

void Auto::desplazar(int16_t posX, int16_t posY)
{
    this->motorDerecho->potencia = limitarRango(posX + posY);
    this->motorIzquierdo->potencia = limitarRango(posY - posX);
    if (posY > 0)
    {
        this->luzAdelante->establecerEncendido(Modos::ENCENDIDO);
        this->luzAtras->establecerEncendido(Modos::APAGADO);
        this->parlante->establecerEncendido(Modos::APAGADO);

        if (this->mostrandoPalabraAutomatica)
            this->display->MostrarPalabra(this->palabraAdelante);
    }
    else if (posY < 0)
    {
        this->luzAdelante->establecerEncendido(Modos::APAGADO);
        this->luzAtras->establecerEncendido(Modos::ENCENDIDO);
        this->parlante->establecerEncendido(Modos::TITILANDO);

        if (this->mostrandoPalabraAutomatica)
            this->display->MostrarPalabra(this->palabraAtras);
    }
    else
    {
        this->luzAdelante->establecerEncendido(Modos::APAGADO);
        this->luzAtras->establecerEncendido(Modos::APAGADO);
        this->parlante->establecerEncendido(Modos::APAGADO);
    }
}

void Auto::frenar()
{
    this->desplazar(0, 0);
    if (this->mostrandoPalabraAutomatica)
        this->display->MostrarPalabra(this->palabraAdelante);
}

void Auto::automatico(Acciones movimiento)
{
    switch (movimiento)
    {
    case Adelante:
        this->desplazar(0, MAX_POTENCIA);
        break;
    case Atras:
        this->desplazar(0, -MAX_POTENCIA);
        break;
    case Derecha:
        this->desplazar(MAX_POTENCIA, 0);
        break;
    case Izquierda:
        this->desplazar(-MAX_POTENCIA, 0);
        break;
    }
}

void Auto::mostrarPalabra(const String *palabra)
{
    this->palabraUsuario = palabra;
    this->mostrandoPalabraAutomatica = false;
    this->display->MostrarPalabra(this->palabraUsuario);
}

int16_t Auto::limitarRango(int16_t number)
{
    if (number > MAX_POTENCIA)
    {
        return MAX_POTENCIA;
    }
    else if (number < -MAX_POTENCIA)
    {
        return -MAX_POTENCIA;
    }
    else
    {
        return number;
    }
}

void Auto::encenderDisplay()
{
    this->display->Encender();

    if (this->mostrandoPalabraAutomatica)
    {
        this->display->MostrarPalabra(this->palabraAdelante);
    }
    else
    {
        this->display->MostrarPalabra(this->palabraUsuario);
    }
}

void Auto::apagarDisplay()
{
    this->display->Apagar();
}

void Auto::activarPalabraAutomatica()
{
    this->mostrandoPalabraAutomatica = true;
    this->display->MostrarPalabra(this->palabraAdelante);
}