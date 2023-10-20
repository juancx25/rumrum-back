#include "Auto.hpp"
#include "../config/Modos.hpp"

Auto::Auto(){
    this->motorIzquierdo = new Motor(Config::ENA, Config::IN1, Config::IN2);
    this->motorDerecho = new Motor(Config::ENB, Config::IN3, Config::IN4);
    this->luzAdelante = new LuzTestigo(Config::LED_ADELANTE);
    this->luzAtras = new LuzTestigo(Config::LED_ATRAS);
    this->parlante = new Parlante(Config::PIN_PARLANTE, 50);
    this->motorDerecho->potencia = 0;
    this->motorIzquierdo->potencia = 0;
    //TODO: Set palabra
}

void Auto::actualizarEstados(){
    this->motorDerecho->aplicarPotencia();
    this->motorIzquierdo->aplicarPotencia();
    this->luzAdelante->aplicarEstado();
    this->luzAtras->aplicarEstado();
    this->parlante->aplicarEstado();
}

void Auto::desplazar(int16_t posX, int16_t posY){
    this->motorDerecho->potencia = limitarRango(posX+posY);
    this->motorIzquierdo->potencia = limitarRango(posY-posX);
    if (posY > 0){
        this->luzAdelante->establecerEncendido(Modos::ENCENDIDO);
        this->luzAtras->establecerEncendido(Modos::APAGADO);
        this->parlante->establecerEncendido(Modos::APAGADO);
    } else if (posY < 0){
        this->luzAdelante->establecerEncendido(Modos::APAGADO);
        this->luzAtras->establecerEncendido(Modos::ENCENDIDO);
        this->parlante->establecerEncendido(Modos::TITILANDO);
    } else {
        this->luzAdelante->establecerEncendido(Modos::APAGADO);
        this->luzAtras->establecerEncendido(Modos::APAGADO);
        this->parlante->establecerEncendido(Modos::APAGADO);
    }
}

void Auto::frenar(){
    this->desplazar(0, 0);
}

void Auto::automatico(Acciones movimiento){
    switch(movimiento){
        case Adelante:
            this->desplazar(0, 255);
            break;
        case Atras:
            this->desplazar(0, -255);
            break;
        case Derecha:
            this->desplazar(255, 0);
            break;
        case Izquierda:
            this->desplazar(-255, 0);
            break;
    }
}

void Auto::establecerPalabra(char* palabra){
    //TODO
}

void Auto::mostrarPalabra(){
    //TODO
}

const char* Auto::getPalabra(){
    //TODO
    return "";
}

int16_t Auto::limitarRango(int16_t number){
    if (number > 255){
        return 255;
    } else if (number < -255){
        return -255;
    } else {
        return number;
    }
}