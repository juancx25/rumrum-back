#ifndef LIBDISPLAY
#define LIBDISPLAY

#include <Arduino.h>
#include <TM1637TinyDisplay.h>

#include "../config/config.hpp"

class Display {
    private:
        TM1637TinyDisplay *display;
        const uint8_t default_brightness = 2;

    public:
        Display();
        void Encender();
        void Apagar();
        void MostrarPalabra(const String *palabra);
};

#endif