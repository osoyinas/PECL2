#ifndef CENTRAL_H
#define CENTRAL_H

#include <string>
#include <vector>
#include "Etiqueta.hpp"
using namespace std;
struct Central
{
    Central();
    string CP;
    string localidad;
    vector<Etiqueta> listaPaquetes;
};
Central crearCentral(string localidad, vector<Etiqueta> listaPaquetes);
#endif // CENTRAL_H
