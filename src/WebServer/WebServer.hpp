#ifndef WEB_SERVER
#define WEB_SERVER

#include "../LuzTestigo/LuzTestigo.hpp"
#include "../config/Modos.hpp"
#include "../config/config.hpp"
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <stdint.h>

/**
 * @file WebServer.hpp
 * @brief Declaración de la clase WebServer.
 */

/**
 * @class WebServer
 * @brief Clase que representa un servidor web con funcionalidades
 * específicas.
 */
class WebServer
{
private:
    static const uint8_t MAX_USUARIOS = 1; ///< Número máximo de usuarios permitidos.
    uint32_t puerto;                       ///< Puerto del servidor web.
    LuzTestigo *luzPlaca;                  ///< Puntero a la luz de la placa.

public:
    AsyncWebServer *server;    ///< Puntero al servidor web.
    AsyncWebSocket *webSocket; ///< Puntero al WebSocket del servidor web.

    /**
     * @brief Constructor de la clase WebServer.
     * @param puerto Puerto del servidor web.
     */
    WebServer(uint32_t puerto);

    /**
     * @brief Actualiza los estados del servidor web.
     */
    void actualizarEstados();

    /**
     * @brief Limpia los clientes del servidor web.
     */
    void limpiarClientes();
};

#endif
