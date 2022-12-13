#ifndef CENTRAL_H
#define CENTRAL_H

#include <string>
#include "Random.hpp"
#include "Paquete.hpp"
#include "Lista.hpp"
using namespace std;
struct Central {
    Central();
    int ID;
    string localidad;
    Lista listaPaquetes;

    void addPaquete(Paquete paquete);
};
Central crearCentral(string localidad, int ID);
int generarID();
string getID(int cp);
#endif // CENTRAL_H
