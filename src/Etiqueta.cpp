#include "Etiqueta.hpp"

Etiqueta::Etiqueta(){}
/**
Crea una etiqueta a partir de un ID, NIF y Coordenadas introducidas como parametros.
*/
Etiqueta crearEtiqueta(CodigoId id, Nif nif, Coord coords){
    Etiqueta etiqueta;
    etiqueta.id = id;
    etiqueta.nif = nif;
    etiqueta.coords = coords;
    return etiqueta;
}
/**
Devuelve una etiqueta generada aleatoriamente con coordenadas localizadas entre las latitudes y longitudes introducidas.
*/
Etiqueta generarEtiqueta(int i,Semicoord latitudMin,Semicoord latitudMax,Semicoord longitudMin,Semicoord longitudMax){
    Etiqueta etiqueta;
    etiqueta.id = generarCodigoId(i);
    etiqueta.nif = generarNif();
    etiqueta.coords = generarCoordenada(latitudMin,latitudMax,longitudMin,longitudMax);
    return etiqueta;
}
