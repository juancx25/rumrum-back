#include "Display.hpp"

Display::Display()
{
    this->display = new TM1637TinyDisplay(Config::PIN_CLK_DISPLAY,
                                      Config::PIN_DIO_DISPLAY);
    this->display->setBrightness(default_brightness, true);
    this->display->setScrolldelay(800U);
    this->display->flipDisplay();
}

void Display::Encender() {
    this->display->setBrightness(default_brightness, false);
}

void Display::Apagar() {
    this->display->setBrightness(default_brightness, true);
}

void Display::MostrarPalabra(const String *palabra) {
    palabra->isEmpty() ? this->display->clear() : this->display->showString(palabra->c_str());
}

