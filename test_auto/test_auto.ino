#include "Arduino.h"
#include "./src/Auto/Auto.hpp"

void probarMotores(uint16_t tiempo_ms, bool vaParaAdelante);
void probarLuz(LuzTestigo* luz, uint16_t tiempo_ms);
void probarParlante(Parlante* parlante, uint16_t tiempo_ms);

Motor* motorDerecho = new Motor(Config::ENA, Config::IN1, Config::IN2);
Motor* motorIzquierdo = new Motor(Config::ENB, Config::IN3, Config::IN4);
LuzTestigo* luzAdelante = new LuzTestigo(Config::LED_ADELANTE);
LuzTestigo* luzAtras = new LuzTestigo(Config::LED_ATRAS);
Parlante* parlante = new Parlante(Config::PIN_PARLANTE, 50);
Display *display = new Display();

uint16_t MAX_POTENCIA = 255;

void setup(){
  Serial.begin(115200);
  Serial.println("Iniciado puerto serie");

  for (int i=10;i>0;i--){
    Serial.print("Comienzan las pruebas en: ");
    Serial.println(i);
    delay(1000);
  }

  Serial.println("---------------------------------------------");
  Serial.println("|    DIAGNOSTICO FUNCIONAL BASICO RUMRUM    |");
  Serial.println("---------------------------------------------");

  Serial.println("Moviendo motores hacia adelante por 10 segundos...");
  probarMotores(10000, true);
  Serial.println("Moviendo motores hacia atras por 10 segundos...");
  probarMotores(10000, false);

  Serial.println("Luz delantera encendida por 5 segundos...");
  probarLuz(luzAdelante, 5000);

  Serial.println("Luz trasera encendida por 5 segundos...");
  probarLuz(luzAtras, 5000);

  Serial.println("Haciendo sonar parlante por 3 segundos...");
  probarParlante(parlante, 3000);

  probarDisplay(display);

  Serial.println("Prueba finalizada! Reiniciar para ejecutar nuevamente");
}

void loop(){

}

void probarMotores(uint16_t tiempo_ms, bool vaParaAdelante){
  for (uint16_t i=25;i<=MAX_POTENCIA;i+=25){
        motorDerecho->potencia = vaParaAdelante ? i : i*(-1);
        motorIzquierdo->potencia = vaParaAdelante ? i : i*(-1);
        motorDerecho->aplicarPotencia();
        motorIzquierdo->aplicarPotencia();
        Serial.print("Potencia: ");
        Serial.println(i);
        delay(tiempo_ms/(MAX_POTENCIA/25));
    }
    motorDerecho->potencia = 0;
    motorIzquierdo->potencia = 0;
    motorDerecho->aplicarPotencia();
    motorIzquierdo->aplicarPotencia();
}

void probarLuz(LuzTestigo* luz, uint16_t tiempo_ms){
  luz->establecerEncendido(Modos::ENCENDIDO);luz->aplicarEstado();
  delay(tiempo_ms);
  luz->establecerEncendido(Modos::APAGADO);
  luz->aplicarEstado();
}

void probarParlante(Parlante* parlante, uint16_t tiempo_ms){
  parlante->establecerEncendido(Modos::ENCENDIDO);
  parlante->aplicarEstado();
  delay(tiempo_ms);
  parlante->establecerEncendido(Modos::APAGADO);
  parlante->aplicarEstado();
}

void probarDisplay(Display* display){
  display->Encender();
  Serial.println("Mostrando la palabra HOLA por 5 segundos...");
  display->MostrarPalabra(new String("HOLA"));
  delay(5000);
  Serial.println("Mostrando la palabra CHAU por 5 segundos...");
  display->MostrarPalabra(new String("CHAU"));
  delay(5000);
  display->Apagar();
}
