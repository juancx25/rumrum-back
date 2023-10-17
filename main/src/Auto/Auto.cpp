#include "Auto.hpp"

Auto::Auto(){
    this->motorIzquierdo = new Motor(Config::ENA, Config::IN1, Config::IN2);
    this->motorDerecho = new Motor(Config::ENB, Config::IN3, Config::IN4);
    this->motorDerecho->potencia = 0;
    this->motorIzquierdo->potencia = 0;
    //TODO: Set palabra
}

void Auto::actualizarEstados(){
    this->motorDerecho->aplicarPotencia();
    this->motorIzquierdo->aplicarPotencia();
}

void Auto::desplazar(int16_t posX, int16_t posY){
    this->motorDerecho->potencia = limitarRango(posX+posY);
    this->motorIzquierdo->potencia = limitarRango(posY-posX);
}

void Auto::frenar(){
    this->motorDerecho->potencia = 0;
    this->motorIzquierdo->potencia = 0;
}

void Auto::automatico(MovimientosAutomaticos movimiento){
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

void Auto::mostrarPalabra(char* palabra){
    //TODO
}

int16_t Auto::limitarRango(int16_t number){
    if (number > 255){
        return 255;
    } else if (number < -255){
        return -255;
    } else {
        Serial.println(number);
        return number;
    }
}