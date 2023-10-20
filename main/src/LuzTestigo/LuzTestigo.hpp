#ifndef LUZ_TESTIGO
#define LUZ_TESTIGO

#include <stdint.h>
#include "Arduino.h"
#include "../config/Modos.hpp"
#include <HardwareSerial.h>

class LuzTestigo{
    private:
        uint8_t PIN;
        Modos estado;
    public:
        LuzTestigo(uint8_t PIN, Modos estado = Modos::APAGADO){
            this->PIN = PIN;
            this->estado = estado;
            pinMode (this->PIN, OUTPUT);
        }
        void establecerEncendido(Modos estado){
            this->estado = estado;
        }
        bool estaEncendido(){
            return this->estado;
        }
        void aplicarEstado(){
            switch (this->estado){
                case Modos::APAGADO:
                    digitalWrite(this->PIN, LOW);
                    break;
                case Modos::ENCENDIDO:
                    Serial.println("ENCENDIDOOO");
                    digitalWrite(this->PIN, HIGH);
                    break;
                case Modos::TITILANDO:
                    this->titilar(1000);
            }
        }
        void titilar(uint16_t tiempo_ms){
            static unsigned long time = 0;
            static bool encendido = false;
            if(millis() >= time+tiempo_ms){
                time += tiempo_ms;
                encendido = !encendido;
                if (encendido && this->estaEncendido()){
                    digitalWrite(this->PIN, HIGH);
                } else {
                    digitalWrite(this->PIN, LOW);
                }
            } else if (!this->estaEncendido()){
                digitalWrite(this->PIN, LOW);
            }  
        }
};

#endif