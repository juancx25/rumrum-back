#ifndef MOTOR
#define MOTOR

#include "Arduino.h"
#include <stdint.h>

/**
 * @file Motor.hpp
 * @brief Definición de la clase Motor.
 */

/**
 * @class Motor
 * @brief Clase que representa un motor con control de potencia y
 * dirección.
 */
class Motor
{
private:
    uint8_t PIN_POTENCIA; ///< Pin de control de potencia del motor.
    uint8_t PIN_ADELANTE; ///< Pin de dirección "adelante" del motor.
    uint8_t PIN_ATRAS;    ///< Pin de dirección "atrás" del motor.

public:
    /**
     * @brief Constructor de la clase Motor.
     * @param PIN_POTENCIA Pin de control de potencia del motor.
     * @param PIN_ADELANTE Pin de dirección "adelante" del motor.
     * @param PIN_ATRAS Pin de dirección "atrás" del motor.
     */
    Motor(uint8_t PIN_POTENCIA, uint8_t PIN_ADELANTE, uint8_t PIN_ATRAS);

    int16_t potencia; ///< Valor de la potencia del motor.

    /**
     * @brief Aplica la potencia actual al motor.
     */
    void aplicarPotencia();
};

#endif
