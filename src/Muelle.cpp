#include "Muelle.hpp"

Muelle::Muelle()
{
    furgonetaActual = 0;
    addFurgoneta();
}
/**
Devuelve True si la etiqueta contiene coordenadas que estan dentro de la region del muelle.
*/
bool Muelle::recibe(Etiqueta etiqueta){

    Semicoord latitudEtiqueta = etiqueta.coords.latitud;
    Semicoord longitudEtiqueta = etiqueta.coords.longitud;

    bool latitudDentro = !latitudEtiqueta.esMenor(minCoords.latitud) && latitudEtiqueta.esMenor(maxCoords.latitud);
    bool longitudDentro = !longitudEtiqueta.esMenor(minCoords.longitud) && longitudEtiqueta.esMenor(maxCoords.longitud);

    return latitudDentro && longitudDentro;
}

/**
Introduce la etiqueta en la cola y segun la capacidad de N3 de furgonetas,
comprueba si una furgoneta ya esta llena y en consecuencia inserte la etiqueta en una nueva furgoneta
*/
void Muelle::insertar(Etiqueta etiqueta, int N3){
    cola.insertar(etiqueta);
    if(int(furgonetas[furgonetaActual].getArray().size()) < N3){
        furgonetas[furgonetaActual].apilar(etiqueta);
    }
    else{
        furgonetaActual++;
        addFurgoneta();
        furgonetas[furgonetaActual].apilar(etiqueta);
    }

}

/**
Crea un muelle a partir de las coordenadas limite.
*/
Muelle crearMuelle(Coord minCoords,Coord maxCoords){
    Muelle muelle;
    muelle.minCoords = minCoords;
    muelle.maxCoords = maxCoords;
    return muelle;
}
/**
Inserta una furgoneta vacia en la lista de las furgonetas.
*/
void Muelle::addFurgoneta(){
    Pila furgoneta;
    furgonetas.push_back(furgoneta);
}
