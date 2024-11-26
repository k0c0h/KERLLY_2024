#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo {
public:
    T dato;
    Nodo* siguiente;

    Nodo(T val) : dato(val), siguiente(nullptr) {}
};

#endif
