#ifndef PARLANTE
#define PARLANTE

#include "../config/Modos.hpp"
#include <HardwareSerial.h>

/**
 * @file Parlante.hpp
 * @brief Definición de la clase Parlante.
 */

/**
 * @class Parlante
 * @brief Clase que representa un parlante con diferentes modos de
 * funcionamiento.
 */
class Parlante
{
private:
    uint8_t PIN;         ///< Pin al que está conectado el parlante.
    uint16_t frecuencia; ///< Frecuencia de sonido del parlante.
    Modos estado;        ///< Estado actual del parlante.

public:
    /**
     * @brief Constructor de la clase Parlante.
     * @param PIN Pin al que está conectado el parlante.
     * @param frecuencia Frecuencia de sonido del parlante.
     * @param estado Estado inicial del parlante (por defecto, Modos::APAGADO).
     */
    Parlante(uint8_t PIN, uint16_t frecuencia, Modos estado = Modos::APAGADO);

    /**
     * @brief Establece el estado de encendido para el parlante.
     * @param estado Nuevo estado del parlante.
     */
    void establecerEncendido(Modos estado);

    /**
     * @brief Verifica si el parlante está encendido.
     * @return true si el parlante está encendido, false de lo contrario.
     */
    bool estaEncendido();

    /**
     * @brief Aplica el estado actual del parlante.
     */
    void aplicarEstado();

    /**
     * @brief Hace titilar el parlante durante un tiempo especificado.
     * @param tiempo_ms Tiempo en milisegundos durante el cual el parlante titilará.
     */
    void titilar(uint16_t tiempo_ms);
};

#endif
