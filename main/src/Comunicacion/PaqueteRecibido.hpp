#ifndef PAQ_RECIBIDO
#define PAQ_RECIBIDO

#include <vector>
#include <sstream>
#include <HardwareSerial.h>

#include "../config/Acciones.hpp"

class PaqueteRecibido{
    public:
        Acciones accion;
        std::vector<int16_t> parametros;
        
        PaqueteRecibido(char* payload);
};

#endif