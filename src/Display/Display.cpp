#include "Display.hpp"

Display::Display(bool encendido)
{
    this->display = new TM1637TinyDisplay(Config::PIN_CLK_DISPLAY,
                                          Config::PIN_DIO_DISPLAY);
    this->display->setBrightness(default_brightness, true);
    this->display->setScrolldelay(800U);
    this->display->flipDisplay();
    this->encendido = encendido;
}

void Display::Encender()
{
    this->encendido = true;
    this->display->setBrightness(default_brightness, true);
}

void Display::Apagar()
{
    this->encendido = false;
    this->display->setBrightness(default_brightness, false);
}

bool Display::estaEncendido()
{
    return this->encendido;
}

void Display::MostrarPalabra(const String *palabra)
{
    (palabra->isEmpty() || !this->estaEncendido()) ? this->display->clear() : this->display->showString(palabra->c_str());
}
