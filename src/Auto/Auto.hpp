#ifndef AUTO
#define AUTO

#include <cmath>
#include <string>
#include "../Motor/Motor.hpp"
#include "../LuzTestigo/LuzTestigo.hpp"
#include "../Parlante/Parlante.hpp"
#include "../config/config.hpp"
#include "../config/Acciones.hpp"
#include "../Display/Display.hpp"

class Auto {
    private:
        static const uint8_t MAX_LONGITUD_PALABRA = 4;
        Motor* motorDerecho;
        Motor* motorIzquierdo;
        char palabraDisplay[4];
        LuzTestigo* luzAdelante;
        LuzTestigo* luzAtras;
        Parlante* parlante;
        int16_t limitarRango(int16_t number);
        Display* display;
        const String* palabraAdelante;
        const String* palabraAtras;

    public:
        Auto();
        void actualizarEstados();
        void desplazar(int16_t posX, int16_t posY);
        void frenar();
        void automatico(Acciones movimiento);
        const char* getPalabra();
        void mostrarPalabra(const String* palabra);
        void encenderDisplay();
        void apagarDisplay();
        void setPalabraAdelante(const String* palabra);
        void setPalabraAtras(const String* palabra);
};

#endif