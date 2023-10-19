#ifndef WEB_SERVER
#define WEB_SERVER

#include <stdint.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

class WebServer {
    private:
        static const uint8_t MAX_USUARIOS = 1;
        AsyncWebSocket* webSocket;
        uint32_t port;
    public:
        AsyncWebServer* server; //should be private
        WebServer(uint32_t puerto, std::function<void(AsyncWebSocket*, AsyncWebSocketClient*, AwsEventType, void*, uint8_t*, size_t)> accion);
        void limpiarClientes();

};

#endif