#include "Central.hpp"

Central::Central()
{
    //ctor
}
void Central::addPaquete (Paquete paquete){
    this->listaPaquetes.insertarNodo(paquete,'f');
}

Central crearCentral(string localidad, int ID){
    Central central;
    central.ID = ID;
    central.localidad = localidad;
    return central;
}

int generarID(){
    int random;
    random = generarRandom(1,9999);
    return random;
}
