//Librerías requeridas
#include <ESP8266WiFi.h>
#include <FS.h>

//Clases personalizadas
#include "./src/Auto/Auto.hpp"
#include "./src/WebServer/WebServer.hpp"
#include "./src/WifiConfig/WifiConfig.hpp"

void enEvento(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);
void manejarMensajeRecibido(void *argumento, uint8_t *datos, size_t longitud);

WifiConfig* wifiConfig = new WifiConfig("RUMRUM_AccessPoint", "rumrum");
WebServer* webServer = new WebServer(80, enEvento);
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
      char* payload = (char*) datos;

      

      /* if (strcmp(payload, "Adelante") == 0){
          Serial.println("Adelante");
          autito->automatico(Adelante);
      } else if (strcmp(payload, "Frenar") == 0){
          Serial.println("Frenar");
          autito->frenar();
      } else if (strcmp(payload, "Izquierda") == 0){
          Serial.println("Izquierda");
          autito->automatico(Izquierda);
      } else if (strcmp(payload, "Derecha") == 0){
          Serial.println("Derecha");
          autito->automatico(Derecha);
      } else if (strcmp(payload, "Atras") == 0){
          Serial.println("Atras");
          autito->automatico(Atras);
      } */
      //notifyClients();
      Serial.println("DONE");
  }
}

bool ledState = 0;

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  
  Serial.println();
  Serial.print("Configurando punto de acceso...");
  WiFi.softAP(wifiConfig->SSID, wifiConfig->contrasena);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("Mi dirección IP: ");
  Serial.println(myIP);
  Serial.println("Servidor iniciado");

  if(!SPIFFS.begin()){
    Serial.println("Ha ocurrido un error al intentar montar SPIFFS");
    return;
  }

  // Route for root / web page
  webServer->server->on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html");
  });
  webServer->server->on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/style.css");
  });
  webServer->server->on("/code-min.js", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/code-min.js");
  });
}

void loop() {
  autito->actualizarEstados();
  webServer->limpiarClientes();
}
