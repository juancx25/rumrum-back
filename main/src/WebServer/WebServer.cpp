#include "WebServer.hpp"

WebServer::WebServer(uint32_t port, AwsEventHandler enEvento){
    this->server = new AsyncWebServer(port);
    this->webSocket = new AsyncWebSocket("/ws");
    this->webSocket->onEvent(enEvento);
    this->server->addHandler(this->webSocket);
    this->server->begin();
}  

void WebServer::limpiarClientes(){
    this->webSocket->cleanupClients(MAX_USUARIOS);
}