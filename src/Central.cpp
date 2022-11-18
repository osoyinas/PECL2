#include "Central.hpp"


/**
Constructor:
Establece una central con N1 paquetes en la cola inicial.
N2 es la cantidad de paquetes que se van a clasificar por cada intro que demos.
N3 es el limite de capacidad de las furgonetas.
Las minCoords son el punto limite inferior derecho del mapa (SE), y las maxCoords son el punto limite superior izquierdo (NO).
Establece los 4 muelles principales. Se puede aumentar el numero de muelles diviendo el mapa entre mas puntos.
*/
Central::Central(int N1,int N2, int N3, Coord minCoords, Coord maxCoords)
{
    this->N1 = N1;
    this->N2 = N2;
    this->N3 = N3;
    //Generacion de N1 paquetes en la cola.
    for(int i = 0; i < N1; i++){
        Etiqueta etiqueta = generarEtiqueta(i,minCoords.latitud, maxCoords.latitud,minCoords.longitud, maxCoords.longitud);
        colaInicial.insertar(etiqueta);
    }
    Semicoord latitudMin = minCoords.latitud;
    Semicoord latitudMax = maxCoords.latitud;

    Semicoord longitudMin = minCoords.longitud;
    Semicoord longitudMax = maxCoords.longitud;

    Semicoord pMedioLatitud = puntoMedio(latitudMin, latitudMax);
    Semicoord pMedioLongitud = puntoMedio(longitudMin, longitudMax);
    //Establecer coordenadas globales del mapa.
    Coord NORTE = crearCoordenada(latitudMax, pMedioLongitud);
    Coord SUR = crearCoordenada(latitudMin, pMedioLongitud);
    Coord ESTE = crearCoordenada(pMedioLatitud, longitudMin);
    Coord OESTE = crearCoordenada(pMedioLatitud, longitudMax);
    Coord NO = crearCoordenada(latitudMax,longitudMax);
    //Coord NE = crearCoordenada(latitudMax, longitudMin);
    //Coord SO = crearCoordenada(latitudMin, longitudMax);
    Coord SE = crearCoordenada(latitudMin, longitudMin);
    Coord centro = crearCoordenada(pMedioLatitud, pMedioLongitud);
    //Muelles
    muelleNO = crearMuelle(centro, NO);
    muelleNE = crearMuelle(ESTE, NORTE);
    muelleSO = crearMuelle(SUR, OESTE);
    muelleSE = crearMuelle(SE, centro);

}

/**
Devuelve un array con los elementos de la cola inicial.
*/
vector<Etiqueta> Central::getColaArray(){
    return colaInicial.getArray();
}

/**
Devuelve la cola inicial.
*/
Cola Central::getCola(){
    return colaInicial;
}
/**
Introduce en el muelle correspondiente el primer elemento de la cola inicial. Esto lo hace N2 veces.
*/
void Central::clasificar(){
    int n = N2;
    if (colaInicial.vacia()){
        return;
    }
    if(int(colaInicial.getArray().size()) < N2){
        n= N2-colaInicial.getArray().size();
    }
    for(int i = 0; i<n; i++){
        Etiqueta etiqueta = colaInicial.verPrimero();

        if(muelleNO.recibe(etiqueta)){
            muelleNO.insertar(etiqueta, N3);
        }

        else if(muelleNE.recibe(etiqueta)){
            muelleNE.insertar(etiqueta, N3);
        }

        else if(muelleSO.recibe(etiqueta)){
            muelleSO.insertar(etiqueta, N3);
        }

        else if(muelleSE.recibe(etiqueta)){
            muelleSE.insertar(etiqueta, N3);
        }
        else{
            muelleSE.insertar(etiqueta, N3);
        }

        colaInicial.eliminar();
    }
}
/**
Devuelve un true si la Cola inicial esta vacia.
*/
bool Central::estaVacia(){

    return colaInicial.getArray().size() == 0;
}
