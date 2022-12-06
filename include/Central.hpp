#ifndef CENTRAL_H
#define CENTRAL_H

#include <string>
#include "Paquete.hpp"
#include "Lista.hpp"
using namespace std;
struct Central {
    Central();
    void addPaquete(Paquete paquete);
    string CP;
    string localidad;
    Lista listaPaquetes;
};
Central crearCentral(string localidad);
#endif // CENTRAL_H
