#include "Motor.hpp"

Motor::Motor(uint8_t PIN_POTENCIA, uint8_t PIN_ADELANTE, uint8_t PIN_ATRAS) {
    this->PIN_POTENCIA = PIN_POTENCIA;
    this->PIN_ADELANTE = PIN_ADELANTE;
    this->PIN_ATRAS = PIN_ATRAS;
    pinMode(PIN_POTENCIA, OUTPUT);
    pinMode(PIN_ADELANTE, OUTPUT);
    pinMode(PIN_ATRAS, OUTPUT);
}

void Motor::aplicarPotencia(){
    
    if (this->potencia > 0){
        digitalWrite(this->PIN_ADELANTE, HIGH);
        digitalWrite(this->PIN_ATRAS, LOW);
    } else{
        digitalWrite(this->PIN_ADELANTE, LOW);
        digitalWrite(this->PIN_ATRAS, HIGH);
    }
    analogWrite(this->PIN_POTENCIA, abs(this->potencia));
}