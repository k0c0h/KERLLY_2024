#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Nodo
{
private:
    T dato;
    Nodo<T> *siguiente;  // Cambiar Nodo a Nodo<T>
    Nodo<T> *anterior;   // Cambiar Nodo a Nodo<T>

public:
    Nodo(T dato);

    T& getDato(); 
    void setDato(T dato);

    void setSiguiente(Nodo<T> *siguiente);
    Nodo<T> *getSiguiente();

    void setAnterior(Nodo<T> *anterior);
    Nodo<T> *getAnterior();
};

#include "Nodo.cpp"
