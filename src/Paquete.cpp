#include "Paquete.hpp"

Paquete::Paquete(){}
/**
Crea una etiqueta a partir de un ID, NIF y Coordenadas introducidas como parametros.
*/
Paquete crearPaquete(CodigoId id, Nif nif, Coord coords, int CP){
    Paquete paquete;
    paquete.id = id;
    paquete.nif = nif;
    paquete.coords = coords;
    paquete.CP = CP;
    return paquete;
}
/**
Devuelve una etiqueta generada aleatoriamente con coordenadas localizadas entre las latitudes y longitudes introducidas.
*/
Paquete generarPaquete(int i,Semicoord latitudMin,Semicoord latitudMax,Semicoord longitudMin,Semicoord longitudMax, int CP){
    Paquete paquete;
    paquete.id = generarCodigoId(i);
    paquete.nif = generarNif();
    paquete.coords = generarCoordenada(latitudMin,latitudMax,longitudMin,longitudMax);
    paquete.CP = CP;
    return paquete;
}
