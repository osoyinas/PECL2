#include "Central.hpp"

Central::Central()
{
    //ctor
}
void Central::addPaquete (Paquete paquete){
    this->listaPaquetes.insertarNodo(paquete,'f');
}
string generarCP(){

    string CP;
    for(int i = 1; i <= 4; i++ ){
        char digito = generarRandom(48,57);
        CP += digito;
    }
    return CP;
}

Central crearCentral(string localidad){
    Central central;
    central.CP = generarCP();
    central.localidad = localidad;
    return central;
}


