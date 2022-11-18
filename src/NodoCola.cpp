#include "NodoCola.hpp"
/**
Constructor
*/
NodoCola::NodoCola(Etiqueta v, NodoCola* sig)
{
    valor = v;
    siguiente = sig;
}
/**
Destructor
*/
NodoCola::~NodoCola()
{


}
