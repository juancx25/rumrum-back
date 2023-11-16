#ifndef AUTO
#define AUTO

#include "../Display/Display.hpp"
#include "../LuzTestigo/LuzTestigo.hpp"
#include "../Motor/Motor.hpp"
#include "../Parlante/Parlante.hpp"
#include "../config/Acciones.hpp"
#include "../config/config.hpp"
#include <cmath>
#include <string>

/**
 * @file Auto.hpp
 * @brief Definición de la clase Auto.
 */

/**
 * @class Auto
 * @brief Clase que representa un automóvil con funciones específicas.
 */
class Auto
{
private:
    static const uint8_t MAX_LONGITUD_PALABRA = 4; ///< Longitud máxima de la palabra a mostrar en el display.
    static const uint8_t MAX_POTENCIA = 100;       ///< Valor máximo de la potencia de los motores.
    Motor *motorDerecho;                           ///< Puntero al motor derecho del automóvil.
    Motor *motorIzquierdo;                         ///< Puntero al motor izquierdo del automóvil.
    char palabraDisplay[4];                        ///< Almacena la palabra actual a mostrar en el display.
    LuzTestigo *luzAdelante;                       ///< Puntero a la luz delantera del automóvil.
    LuzTestigo *luzAtras;                          ///< Puntero a la luz trasera del automóvil.
    Parlante *parlante;                            ///< Puntero al parlante del automóvil.
    int16_t limitarRango(int16_t number);          ///< Limita el rango de un número entre -MAX_POTENCIA y MAX_POTENCIA.
    Display *display;                              ///< Puntero al display del automóvil.
    const String *palabraAdelante;                 ///< Puntero a la palabra asociada al movimiento "Adelante".
    const String *palabraAtras;                    ///< Puntero a la palabra asociada al movimiento "Atras".
    bool mostrandoPalabraAutomatica;               ///< Indica si se está mostrando una palabra automáticamente.
    const String *palabraUsuario;                  ///< Puntero a la palabra ingresada por el usuario.

public:
    /**
     * @brief Constructor de la clase Auto.
     */
    Auto();

    /**
     * @brief Actualiza los estados del automóvil.
     */
    void actualizarEstados();

    /**
     * @brief Desplaza el auto en la dirección especificada.
     * @param posX Posición en el eje X.
     * @param posY Posición en el eje Y.
     */
    void desplazar(int16_t posX, int16_t posY);

    /**
     * @brief Frena el auto.
     */
    void frenar();

    /**
     * @brief Realiza un movimiento automático según la acción
     * proporcionada.
     * @param movimiento Acción a realizar (Adelante, Atras, Izquierda,
     * Derecha).
     */
    void automatico(Acciones movimiento);

    /**
     * @brief Muestra una palabra en el display.
     * @param palabra Puntero a la cadena de caracteres que representa la palabra a mostrar.
     */
    void mostrarPalabra(const String *palabra);

    /**
     * @brief Enciende el display del automóvil.
     */
    void encenderDisplay();

    /**
     * @brief Apaga el display del automóvil.
     */
    void apagarDisplay();

    /**
     * @brief Activa la función de mostrar palabra automáticamente.
     */
    void activarPalabraAutomatica();
};

#endif
