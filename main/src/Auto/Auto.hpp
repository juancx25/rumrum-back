#ifndef AUTO
#define AUTO

#include <cmath>
#include "../Motor/Motor.hpp"
#include "../config/config.hpp"
#include "../config/MovimientosAutomaticos.hpp"
#include <HardwareSerial.h>

class Auto {
    private:
        static const uint8_t MAX_LONGITUD_PALABRA = 4;
        Motor* motorDerecho;
        Motor* motorIzquierdo;
        char palabraDisplay[4];
        int16_t limitarRango(int16_t number);

    public:
        Auto();
        void actualizarEstados();
        void desplazar(int16_t posX, int16_t posY);
        void frenar();
        void automatico(MovimientosAutomaticos movimiento);
        void mostrarPalabra(char* palabra);
};

#endif