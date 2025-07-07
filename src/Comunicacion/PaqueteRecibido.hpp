#ifndef PAQ_RECIBIDO
#define PAQ_RECIBIDO

#include <HardwareSerial.h>
#include <sstream>
#include <string>
#include <vector>

#include "../config/Acciones.hpp"

/**
 * @file PaqueteRecibido.hpp
 * @brief Declaración de la clase PaqueteRecibido.
 */

/**
 * @class PaqueteRecibido
 * @brief Clase que representa un paquete recibido con información
 * específica para el control del auto.
 */
class PaqueteRecibido
{
public:
    Acciones accion;                 ///< Acción asociada al paquete.
    std::vector<int16_t> parametros; /**< Vector de parámetros asociados
                                          al paquete.*/
    String *palabra;                 /**< Puntero a la cadena de
                                          caracteres que representa la
                                          palabra asociada al paquete.*/

    /**
     * @brief Constructor de la clase PaqueteRecibido.
     * @param payload Puntero al arreglo de caracteres que contiene la
     * información del paquete.
     */
    PaqueteRecibido(char *payload);
};

#endif
