#ifndef CENTRAL_H
#define CENTRAL_H

#include <string>
#include <vector>
#include "Paquete.hpp"
using namespace std;
struct Central
{
    Central();
    string CP;
    string localidad;
    vector<Paquete> listaPaquetes;
};
Central crearCentral(string localidad, vector<Paquete> listaPaquetes);
#endif // CENTRAL_H
