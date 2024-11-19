#ifndef IMPRIMIR_H
#define IMPRIMIR_H

#include "Lista.h"
#include <iostream>

template <typename T>
class Imprimir {
public:
    void realizarOperacion(Lista<T>& lista) {
        lista.imprimir();
    }
};

#endif
