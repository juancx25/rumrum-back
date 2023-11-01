#include "PaqueteRecibido.hpp"

PaqueteRecibido::PaqueteRecibido(char* payload){
    std::stringstream ss(payload);
    std::vector<int16_t> result;
    char ch;
    int tmp;
    ss >> ch;
    this->accion = static_cast<Acciones>(ch - '0');
    ss >> ch;
    switch (this->accion){
        case Manual:
            while(ss >> tmp) {
                result.push_back(tmp);
                ss >> ch;
            }
            break;
        case PalabraManual:
            Serial.println(payload+2);
            this->palabra = new String(payload+2);
        default:
            break;
    }
    
    this->parametros = result;
}