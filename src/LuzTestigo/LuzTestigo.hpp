#ifndef LUZ_TESTIGO
#define LUZ_TESTIGO

#include "../config/Modos.hpp"
#include <Arduino.h>
#include <stdint.h>

/**
 * @file LuzTestigo.hpp
 * @brief Declaración de la clase LuzTestigo.
 */

/**
 * @class LuzTestigo
 * @brief Clase que representa una luz de testigo con diferentes modos
 * de funcionamiento.
 */
class LuzTestigo
{
private:
    uint8_t PIN;  ///< Pin al que está conectada la luz de testigo.
    Modos estado; ///< Estado actual de la luz de testigo.

public:
    /**
     * @brief Constructor de la clase LuzTestigo.
     * @param PIN Pin al que está conectada la luz de testigo.
     * @param estado Estado inicial de la luz de testigo (por defecto,
     * Modos::APAGADO).
     */
    LuzTestigo(uint8_t PIN, Modos estado = Modos::APAGADO);

    /**
     * @brief Establece el estado de encendido para la luz de testigo.
     * @param estado Nuevo estado de la luz de testigo.
     */
    void establecerEncendido(Modos estado);

    /**
     * @brief Verifica si la luz de testigo está encendida.
     * @return true si la luz de testigo está encendida, false de lo contrario.
     */
    bool estaEncendido();

    /**
     * @brief Aplica el estado actual de la luz de testigo.
     */
    void aplicarEstado();

    /**
     * @brief Hace titilar la luz de testigo durante un tiempo especificado.
     * @param tiempo_ms Tiempo en milisegundos durante el cual la luz titilará.
     */
    void titilar(uint16_t tiempo_ms);
};

#endif
