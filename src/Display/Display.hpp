#ifndef LIBDISPLAY
#define LIBDISPLAY

#include <Arduino.h>
#include <TM1637TinyDisplay.h>

#include "../config/config.hpp"

class Display {
    private:
        TM1637TinyDisplay *display;
        bool encendido;
        const uint8_t default_brightness = 2;

    public:
        Display(bool encendido = true);
        void Encender();
        void Apagar();
        void MostrarPalabra(const String* palabra);
        bool estaEncendido();
};

#endif