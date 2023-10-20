#ifndef WEB_SERVER
#define WEB_SERVER

#include <stdint.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "../LuzTestigo/LuzTestigo.hpp"
#include "../config/config.hpp"
#include "../config/Modos.hpp"

class WebServer {
    private:
        static const uint8_t MAX_USUARIOS = 1;
        uint32_t puerto;
        LuzTestigo* luzPlaca;
    public:
        AsyncWebServer* server;
        AsyncWebSocket* webSocket;
        WebServer(uint32_t puerto);
        void actualizarEstados();
        void limpiarClientes();

};

#endif