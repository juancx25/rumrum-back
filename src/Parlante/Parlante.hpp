#ifndef PARLANTE
#define PARLANTE

#include <HardwareSerial.h>
#include "../config/Modos.hpp"

class Parlante{
    private:
        uint8_t PIN;
        uint16_t frecuencia;
        Modos estado;
    public:
        Parlante(uint8_t PIN, uint16_t frecuencia, Modos estado = Modos::APAGADO){
            this->PIN = PIN;
            this->frecuencia = frecuencia;
            this->estado = estado;
            pinMode(this->PIN, OUTPUT);
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
                    digitalWrite(this->PIN, HIGH);
                    break;
                case Modos::TITILANDO:
                    this->titilar(1000);
            }
        }
        void titilar(uint16_t tiempo_ms){
            static unsigned long time = 0;
            static bool sonando = false;
            if(millis() >= time+tiempo_ms){
                time += tiempo_ms;
                sonando = !sonando;
                if (sonando && this->estaEncendido()){
                    analogWrite(this->PIN, this->frecuencia);
                } else {
                    analogWrite(this->PIN, 0);
                }
            } else if (!this->estaEncendido()){
                analogWrite(this->PIN, 0);
            }  
        }
};

#endif