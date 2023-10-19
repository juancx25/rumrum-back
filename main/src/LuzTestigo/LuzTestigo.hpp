#ifndef LUZ_TESTIGO
#define LUZ_TESTIGO

#include <stdint.h>
#include "Arduino.h"

class LuzTestigo{
    private:
        uint8_t PIN;
        bool estado;
    public:
        LuzTestigo(uint8_t PIN, bool estado = false){
            this->PIN = PIN;
            this->estado = estado;
            pinMode (this->PIN, OUTPUT);
        }
        void establecerEncendido(bool estado){
            this->estado = estado;
        }
        bool estaEncendido(){
            return this->estado;
        }
        void aplicarEstado(){
            digitalWrite(this->PIN, this->estaEncendido());
        }
};

#endif