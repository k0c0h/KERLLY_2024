#pragma once
#include "Nodo.h"
#include <iostream>
using namespace std;

template <typename T>
class ListaSimple {
private:
    Nodo<T>* cabeza;

public:
    ListaSimple() : cabeza(nullptr) {}
    void Insertar_cabeza(T _dato);
    void Mostrar() const;
    ~ListaSimple();  // Destructor para liberar memoria
};
