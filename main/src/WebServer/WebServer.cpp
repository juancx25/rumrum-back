#include "WebServer.hpp"

WebServer::WebServer(uint32_t puerto){
    this->server = new AsyncWebServer(puerto);
    this->webSocket = new AsyncWebSocket("/ws");
    this->luzPlaca = new LuzTestigo(Config::LED_PLACA);
    this->server->addHandler(this->webSocket);
    this->server->begin();
}  

void WebServer::actualizarEstados(){
    if (this->webSocket->count() > 0){
        this->luzPlaca->establecerEncendido(Modos::ENCENDIDO);
    } else {
        this->luzPlaca->establecerEncendido(Modos::TITILANDO);
    }
    this->luzPlaca->aplicarEstado();
    this->limpiarClientes();
}

void WebServer::limpiarClientes(){
    this->webSocket->cleanupClients(MAX_USUARIOS);
}