//Librerías requeridas
#include <ESP8266WiFi.h>
#include <FS.h>
#include <WiFiClient.h>

//Clases personalizadas
#include "./src/Comunicacion/PaqueteRecibido.hpp"
#include "./src/Auto/Auto.hpp"
#include "./src/WebServer/WebServer.hpp"
#include "./src/WifiConfig/WifiConfig.hpp"

void enEvento(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);
void manejarMensajeRecibido(void *argumento, uint8_t *datos, size_t longitud);

WifiConfig* wifiConfig = new WifiConfig("RUMRUM_AccessPoint", "rumrum");
WebServer* webServer = new WebServer(80);
Auto* autito = new Auto();

void enEvento(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
                    void *arg, uint8_t *data, size_t len) {
  Serial.println("EVENT");
  switch (type) {
      case WS_EVT_CONNECT:
          Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
          break;
      case WS_EVT_DISCONNECT:
          Serial.printf("WebSocket client #%u disconnected\n", client->id());
          break;
      case WS_EVT_DATA:
          manejarMensajeRecibido(arg, data, len);
          break;
      case WS_EVT_PONG:
      case WS_EVT_ERROR:
          break;
  }
}

void manejarMensajeRecibido(void *argumento, uint8_t *datos, size_t longitud){
  AwsFrameInfo *info = (AwsFrameInfo*)argumento;
  if (info->final && info->index == 0 && info->len == longitud && info->opcode == WS_TEXT) {
      datos[longitud] = 0;
      PaqueteRecibido* paquete = new PaqueteRecibido((char*) datos);
      
      switch (paquete->accion){
        case Adelante:
          autito->automatico(Adelante);
          break;
        case Atras:
          autito->automatico(Atras);
          break;
        case Izquierda:
          autito->automatico(Izquierda);
          break;
        case Derecha:
          autito->automatico(Derecha);
          break;
        case Frenar:
          autito->frenar();
          break;
        case Manual:
          autito->desplazar(paquete->parametros[0], paquete->parametros[1]);
          break;
      }
  }
}

bool ledState = 0;

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  
  Serial.println();
  Serial.print("Configurando punto de acceso...");
  WiFi.softAP(wifiConfig->SSID, wifiConfig->contrasena);
  WiFi.printDiag(Serial);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("Mi dirección IP: ");
  Serial.println(myIP);
  Serial.println("Servidor iniciado");

  if(!SPIFFS.begin()){
    Serial.println("Ha ocurrido un error al intentar montar SPIFFS");
    return;
  }

  webServer->webSocket->onEvent(enEvento);
  webServer->server->on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html");
  });
  webServer->server->on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/style.css");
  });
  webServer->server->on("/code-min.js", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/code-min.js");
  });
  webServer->server->serveStatic("/img/", SPIFFS, "/img/");
}

void loop() {
  autito->actualizarEstados();
  webServer->actualizarEstados();
}
