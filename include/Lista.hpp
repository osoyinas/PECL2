#ifndef LISTA_HPP
#define LISTA_HPP

#include <iomanip>
#include "NodoLista.hpp"

using namespace std;
class Lista
{
    private:
        pnodo cabeza, actual, final;
    public:
        Lista();
        ~Lista();
        void insertarNodo(Paquete v, char c);
        void borrarNodo(char c);
        bool listaVacia();
        void recorrerLista(int);
        void esSiguiente();
        void esAnterior();
        void esPrimero();
        void esUltimo();
        bool esActual();
        Paquete getUlt();
        void mostrar();
        Paquete valorActual();
        int len = 0;
};

#endif // LISTA_HPP
