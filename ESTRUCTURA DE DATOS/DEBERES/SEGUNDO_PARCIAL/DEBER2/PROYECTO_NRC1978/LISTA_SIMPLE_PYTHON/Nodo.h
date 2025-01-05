#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Nodo
{
private:
    T dato;
    Nodo<T> *siguiente;  // Puntero al siguiente nodo

public:
    Nodo(T dato);

    T& getDato(); 
    void setDato(T dato);

    void setSiguiente(Nodo<T> *siguiente);
    Nodo<T> *getSiguiente();
};

#include "Nodo.cpp"
