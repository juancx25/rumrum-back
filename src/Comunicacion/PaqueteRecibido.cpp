#include "PaqueteRecibido.hpp"

PaqueteRecibido::PaqueteRecibido(char* payload){
    std::stringstream ss(payload);
    std::vector<int16_t> result;
    char ch;
    int tmp;
    while(ss >> tmp) {
        result.push_back(tmp);
        ss >> ch;
    }
    this->accion = static_cast<Acciones>(result.at(0));
    result.erase(result.begin());
    this->parametros = result;
}