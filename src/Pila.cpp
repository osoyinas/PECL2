#include "Pila.hpp"

Pila::Pila(){}


/**
Apila el elemento
*/
void Pila::apilar(Etiqueta etiqueta){
    this->lista.push_back(etiqueta);
}

/**
Desapila el elemento
*/
void Pila::desapilar(){
    this->lista.pop_back();
}

/**
Devuelve el elemento de la cima.
*/
Etiqueta Pila::cima(){
    return this->lista.back();
}
/**
Devuelve true si la pila esta vacia.
*/
bool Pila::vacia(){
    if(this->lista.size() == 0)
        return false;
    return true;
}

/**
Devuelve una lista (vector) con todos los elementos de la pila.
*/
vector<Etiqueta> Pila::getArray(){
    return this->lista;
}
