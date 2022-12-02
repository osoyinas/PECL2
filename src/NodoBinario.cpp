#include "NodoBinario.hpp"
#include <iostream>

NodoBinario::NodoBinario(int dat, NodoBinario *izq, NodoBinario *der){
    dato = dat;
    izquierda = izq;
    derecha = der;
}
