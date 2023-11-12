#ifndef MOV_AUTO
#define MOV_AUTO

/**
 * @file Acciones.hpp
 * @brief Definición del conjunto de acciones para el control del
 * automóvil.
 */

/**
 * @enum Acciones
 * @brief Enumeración que define las posibles acciones para el control
 * del automóvil.
 */
enum Acciones
{
    Adelante,         ///< Mover el automóvil hacia adelante.
    Atras,            ///< Mover el automóvil hacia atrás.
    Izquierda,        ///< Girar el automóvil hacia la izquierda.
    Derecha,          ///< Girar el automóvil hacia la derecha.
    Frenar,           ///< Detener el movimiento del automóvil.
    Manual,           ///< Modo de control manual del automóvil.
    EncenderDisplay,  ///< Encender el display del automóvil.
    ApagarDisplay,    ///< Apagar el display del automóvil.
    PalabraManual,    ///< Mostrar una palabra en el display.
    PalabraAutomatica ///< Activar la palabra automática en el display.
};

#endif
