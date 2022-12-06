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
    void setID(int id);
    string getID();
};
Central crearCentral(string localidad, int ID);
int generarID();
#endif // CENTRAL_H
