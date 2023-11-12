#ifndef CONFIG
#define CONFIG

/**
 * @file Config.hpp
 * @brief Configuración de pines y valores por defecto para el sistema.
 */

/**
 * @class Config
 * @brief Clase que contiene configuraciones de pines y valores por
 * defecto.
 */
class Config
{
public:
    /*

              --------
     A0 - A0 |        | 16 - D0
    RSU -  X |        |  5 - D1
    PSU -  X |        |  4 - D2
    SD3 - 10 |        |  0 - D3
    SD2 -  9 |        |  2 - D4
    SD1 -  X |        |  X - 3V3
    CMD -  X |        |  X - GND
    SD0 -  X |        | 14 - D5
    CLK -  X |        | 12 - D6
    GND -  X |        | 13 - D7
    3V3 -  X |        | 15 - D8
     EN -  X |        |  3 - RX
    RST -  X |        |  1 - TX
    GND -  X |        |  X - GND
    Vin -  x |        |  x - 3V3
              --------
                 v
                USB

    */

    static const uint8_t LED_PLACA = 2; ///< Pin del LED de la placa.

    static const uint8_t ENA = 14; ///< Pin de habilitación del motor derecho.
    static const uint8_t IN1 = 12; ///< Pin de entrada 1 del motor derecho.
    static const uint8_t IN2 = 13; ///< Pin de entrada 2 del motor derecho.

    static const uint8_t ENB = 4;  ///< Pin de habilitación del motor izquierdo.
    static const uint8_t IN3 = 5;  ///< Pin de entrada 3 del motor izquierdo.
    static const uint8_t IN4 = 16; ///< Pin de entrada 4 del motor izquierdo.

    static const uint8_t LED_ADELANTE = 0; ///< Pin de los LED delanteros.
    static const uint8_t LED_ATRAS = 10;   ///< Pin de los LED traseros.

    static const uint8_t PIN_PARLANTE = 15; ///< Pin del buzzer.

    static const uint8_t PIN_CLK_DISPLAY = 1;                       ///< Pin del reloj para el display.
    static const uint8_t PIN_DIO_DISPLAY = 3;                       ///< Pin de datos para el display.
    static constexpr const char *PALABRA_ADELANTE_DEFAULT = "HOLA"; ///< Palabra por defecto para el movimiento hacia adelante.
    static constexpr const char *PALABRA_ATRAS_DEFAULT = "CHAU";    ///< Palabra por defecto para el movimiento hacia atrás.
};

#endif
