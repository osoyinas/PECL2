#include "Coord.hpp"
#include "Semicoord.hpp"

Coord::Coord(){}
/**
Crea una coordenada a partir de dos semicoordenadas.
*/
Coord crearCoordenada(Semicoord latitud, Semicoord longitud){
    Coord coordenada;
    coordenada.latitud = latitud;
    coordenada.longitud = longitud;
    return coordenada;
}
/**
Crea una coordenada a partir de integers, l es Latitud, lo es Longitud.
*/
Coord crearCoordenada(int lGrados, int lMinutos, int lSegundos, int loGrados, int loMinutos, int loSegundos){
    Coord coordenada;
    coordenada.latitud.grados = lGrados;
    coordenada.latitud.minutos = lMinutos;
    coordenada.latitud.segundos = lSegundos;

    coordenada.longitud.grados = loGrados;
    coordenada.longitud.minutos = loMinutos;
    coordenada.longitud.segundos = loSegundos;
    return coordenada;
}
/**
Genera una coordenada aleatoria entre 4 puntos.
*/
Coord generarCoordenada(Semicoord latitudMin, Semicoord latitudMax, Semicoord longitudMin, Semicoord longitudMax){

    Coord coordenada;
    coordenada.latitud = generarSemicoord(latitudMin, latitudMax);
    coordenada.longitud = generarSemicoord(longitudMin, longitudMax);
    return coordenada;
}
/**
Devuelve la coordenada en formato String.
*/
string getCoordenadaStr(Coord coord){
    string coordStr = to_string(coord.latitud.grados) + " " + to_string(coord.latitud.minutos) + " " + to_string(coord.latitud.segundos) + "," + " " + to_string(coord.longitud.grados)
    + " " + to_string(coord.longitud.minutos) + " " + to_string(coord.longitud.segundos);
    return coordStr;
}
