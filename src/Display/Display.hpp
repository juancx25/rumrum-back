#ifndef LIBDISPLAY
#define LIBDISPLAY

#include <Arduino.h>
#include <TM1637TinyDisplay.h>

#include "../config/config.hpp"

/**
 * @file Display.hpp
 * @brief Declaración de la clase Display.
 */

/**
 * @class Display
 * @brief Clase que representa y controla un display TM1637.
 */
class Display
{
private:
    TM1637TinyDisplay *display;           ///< Puntero al objeto TM1637TinyDisplay.
    bool encendido;                       ///< Indica si el display está encendido.
    const uint8_t default_brightness = 2; ///< Brillo predeterminado del display. Valor entre 0 y 7 inclusive.

public:
    /**
     * @brief Constructor de la clase Display.
     * @param encendido Indica si el display debe iniciarse encendido o
     * apagado.
     */
    Display(bool encendido = true);

    /**
     * @brief Enciende el display.
     */
    void Encender();

    /**
     * @brief Apaga el display.
     */
    void Apagar();

    /**
     * @brief Muestra una palabra en el display.
     * @param palabra Puntero a la cadena de caracteres que representa
     * la palabra a mostrar.
     */
    void MostrarPalabra(const String *palabra);

    /**
     * @brief Verifica si el display está encendido.
     * @return true si el display está encendido, false de lo contrario.
     */
    bool estaEncendido();
};

#endif
