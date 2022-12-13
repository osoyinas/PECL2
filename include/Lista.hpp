#ifndef LISTA_HPP
#define LISTA_HPP

#include <iomanip>
#include "NodoLista.hpp"

using namespace std;
class Lista {
    private:
        pnodo cabeza, actual, final;
    public:
        Lista();
        void insertarNodo(Paquete v, char c);
        void borrarNodo(char c);
        bool listaVacia();
        void recorrerLista(int);
        void esSiguiente();
        void esAnterior();
        void esPrimero();
        void esUltimo();
        bool esActual();
        int getLength();
        void borrarPaquete(string ID);
        Paquete buscarPaquete(string ID);
        pnodo buscarNodo(string ID);
        Paquete getUlt();
        void mostrar();
        Paquete valorActual();
};

#endif // LISTA_HPP
