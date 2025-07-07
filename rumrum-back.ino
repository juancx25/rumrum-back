/**
 * @file main.cpp
 * @brief Programa principal para el control de un auto mediante WebSocket y un servidor web.
 */

// Librerías requeridas
#include <ESP8266WiFi.h>
#include <FS.h>
#include <WiFiClient.h>

// Clases personalizadas
#include "./src/Auto/Auto.hpp"
#include "./src/Comunicacion/PaqueteRecibido.hpp"
#include "./src/WebServer/WebServer.hpp"
#include "./src/WifiConfig/WifiConfig.hpp"

// Instanciación de objetos
WifiConfig *wifiConfig = new WifiConfig("RUMRUM", "123456789");
WebServer *webServer = new WebServer(80);
Auto *autito = new Auto();

/**
 * @brief Maneja los eventos de la conexión WebSocket.
 *
 * @param server Puntero al servidor WebSocket.
 * @param client Puntero al cliente WebSocket.
 * @param type Tipo de evento.
 * @param arg Argumento del evento.
 * @param data Datos recibidos.
 * @param len Longitud de los datos.
 */
void enEvento(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);

/**
 * @brief Maneja los mensajes recibidos a través de WebSocket.
 *
 * @param argumento Argumento del evento.
 * @param datos Datos recibidos.
 * @param longitud Longitud de los datos.
 */
void manejarMensajeRecibido(void *argumento, uint8_t *datos, size_t longitud);

void enEvento(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
              void *arg, uint8_t *data, size_t len)
{
  Serial.println("EVENT"); // Debug
  switch (type)
  {
  case WS_EVT_CONNECT:
    Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
    break;
  case WS_EVT_DISCONNECT:
    Serial.printf("WebSocket client #%u disconnected\n", client->id());
    autito->frenar();
    break;
  case WS_EVT_DATA:
    manejarMensajeRecibido(arg, data, len);
    break;
  case WS_EVT_PONG:
  case WS_EVT_ERROR:
    break;
  }
}

void manejarMensajeRecibido(void *argumento, uint8_t *datos, size_t longitud)
{
  AwsFrameInfo *info = (AwsFrameInfo *)argumento;
  if (info->final && info->index == 0 && info->len == longitud && info->opcode == WS_TEXT)
  {
    datos[longitud] = 0;
    PaqueteRecibido *paquete = new PaqueteRecibido((char *)datos);

    switch (paquete->accion)
    {
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
    case EncenderDisplay:
      autito->encenderDisplay();
      break;
    case ApagarDisplay:
      autito->apagarDisplay();
      break;
    case PalabraManual:
      autito->mostrarPalabra(paquete->palabra);
      break;
    case PalabraAutomatica:
      autito->activarPalabraAutomatica();
      break;
    }
  }
}

// Variable de estado del LED
bool ledState = 0;

/**
 * @brief Configuración inicial del programa.
 */
void setup()
{
  // Inicialización del puerto serie para debug
  Serial.begin(115200);

  Serial.println();
  Serial.print("Configurando punto de acceso...");
  WiFi.softAP(wifiConfig->SSID, wifiConfig->contrasena);
  WiFi.printDiag(Serial);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("Mi dirección IP: ");
  Serial.println(myIP);
  Serial.println("Servidor iniciado");

  if (!SPIFFS.begin())
  {
    Serial.println("Ha ocurrido un error al intentar montar SPIFFS");
    return;
  }

  // Configuración de manejadores de eventos para el servidor web
  webServer->webSocket->onEvent(enEvento);
  webServer->server->on("/", HTTP_GET, [](AsyncWebServerRequest *request)
                        { request->send(SPIFFS, "/index.html"); });
  webServer->server->on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request)
                        { request->send(SPIFFS, "/style.css"); });
  webServer->server->on("/code-min.js", HTTP_GET, [](AsyncWebServerRequest *request)
                        { request->send(SPIFFS, "/code-min.js"); });
  webServer->server->serveStatic("/img/", SPIFFS, "/img/");
}

/**
 * @brief Bucle principal del programa.
 */
void loop()
{
  autito->actualizarEstados();
  webServer->actualizarEstados();
}
