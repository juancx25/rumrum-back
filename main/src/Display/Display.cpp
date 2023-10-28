#include "Display.hpp"

Display::Display()
{
    this->display = new TM1637TinyDisplay(Config::PIN_CLK_DISPLAY,
                                      Config::PIN_DIO_DISPLAY);
    this->display->setBrightness(default_brightness, true);
    this->display->setScrolldelay(800U);
}

void Display::Encender() {
    this->display->setBrightness(default_brightness, false);
}

void Display::Apagar() {
    this->display->setBrightness(default_brightness, true);
}

void Display::MostrarPalabra(const String *palabra) {
    this->display->showString(palabra->c_str());
}

