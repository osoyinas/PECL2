#include "Paquete.hpp"

Paquete::Paquete(){}
/**
Crea una etiqueta a partir de un ID, NIF y Coordenadas introducidas como parametros.
*/
Paquete crearPaquete(CodigoId id, Nif nif, Coord coords){
    Paquete etiqueta;
    etiqueta.id = id;
    etiqueta.nif = nif;
    etiqueta.coords = coords;
    return etiqueta;
}
/**
Devuelve una etiqueta generada aleatoriamente con coordenadas localizadas entre las latitudes y longitudes introducidas.
*/
Paquete generarPaquete(int i,Semicoord latitudMin,Semicoord latitudMax,Semicoord longitudMin,Semicoord longitudMax){
    Paquete etiqueta;
    etiqueta.id = generarCodigoId(i);
    etiqueta.nif = generarNif();
    etiqueta.coords = generarCoordenada(latitudMin,latitudMax,longitudMin,longitudMax);
    return etiqueta;
}
