#include "Nodo.h"

template <typename T>
Nodo<T>::Nodo(T dato)
{
    this->dato = dato;
    this->siguiente = nullptr;
}

template <typename T>
T& Nodo<T>::getDato()  // Devolver una referencia en lugar de una copia
{
    return dato;
}

template <typename T>
void Nodo<T>::setDato(T dato)
{
    this->dato = dato;
}

template <typename T>
void Nodo<T>::setSiguiente(Nodo<T> *siguiente)
{
    this->siguiente = siguiente;
}

template <typename T>
Nodo<T> *Nodo<T>::getSiguiente()
{
    return this->siguiente;
}
