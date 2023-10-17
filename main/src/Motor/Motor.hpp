#ifndef MOTOR
#define MOTOR

#include <stdint.h>
#include "Arduino.h"

class Motor {
    private:
        uint8_t PIN_POTENCIA;
        uint8_t PIN_ADELANTE;
        uint8_t PIN_ATRAS;
    public:
        Motor(uint8_t PIN_POTENCIA, uint8_t PIN_ADELANTE, uint8_t PIN_ATRAS);
        int16_t potencia;
        void aplicarPotencia();
};

#endif