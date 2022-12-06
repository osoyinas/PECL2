#ifndef NODOBINARIO_H
#define NODOBINARIO_H
#include <iostream>
#include <Central.hpp>
struct NodoBinario {
    Central elemento;
    NodoBinario* izquierdo;
    NodoBinario* derecho;
};

#endif // NODOBINARIO_H
