#ifndef PARLANTE
#define PARLANTE

#include <HardwareSerial.h>

class Parlante{
    private:
        uint8_t PIN;
        bool estado;
        uint16_t frecuencia;
    public:
        Parlante(uint8_t PIN, uint16_t frecuencia, bool estado = false){
            this->PIN = PIN;
            this->frecuencia = frecuencia;
            this->estado = estado;
            pinMode(this->PIN, OUTPUT);
        }
        void establecerEncendido(bool estado){
            this->estado = estado;
        }
        bool estaEncendido(){
            return this->estado;
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