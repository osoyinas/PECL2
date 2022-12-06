#ifndef NODOBINARIO_H
#define NODOBINARIO_H
#include <iostream>
#include <Central.hpp>
struct NodoBinario {
    Central elemento;
    NodoBinario* hijoIzquierdo;
    NodoBinario* hijoDerecho;
};

#endif // NODOBINARIO_H
