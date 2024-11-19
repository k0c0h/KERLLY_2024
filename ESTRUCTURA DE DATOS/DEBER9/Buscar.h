#ifndef BUSCAR_H
#define BUSCAR_H

#include "Lista.h"
#include <iostream>

template <typename T>
class Buscar {
public:
    void realizarOperacion(Lista<T>& lista, T valor) {
        if (lista.buscar(valor)) {
            std::cout << "Elemento " << valor << " encontrado en la lista." << std::endl;
        } else {
            std::cout << "Elemento " << valor << " no encontrado en la lista." << std::endl;
        }
    }
};

#endif
