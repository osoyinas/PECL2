#include "Central.hpp"

Central::Central()
{
    //ctor
}

string generarCP(){

    string CP;
    for(int i = 1; i <= 4; i++ ){
        char digito = generarRandom(48,57);
        CP += digito;
    }
    return CP;
}

Central crearCentral(string localidad, vector<Etiqueta> listaPaquetes){
    Central central;
    central.CP = generarCP();
    central.localidad = localidad;
    central.listaPaquetes = listaPaquetes;
}
