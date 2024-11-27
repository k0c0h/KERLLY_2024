// Nodo.h
#ifndef NODO_H
#define NODO_H

template <typename T>
class ListaDoble;

template <typename T>
class ListaCircular;

template <typename T>
class Nodo {
private:
    T dato;
    Nodo<T>* siguiente;
    Nodo<T>* anterior;

public:
    Nodo(const T& dato) : dato(dato), siguiente(nullptr), anterior(nullptr) {}

    friend class ListaDoble<T>;
    friend class ListaCircular<T>;
};

#endif 
