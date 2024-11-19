#ifndef ELIMINAR_H
#define ELIMINAR_H

#include "Lista.h"
#include <iostream>

template <typename T>
class Eliminar {
public:
    void realizarOperacion(Lista<T>& lista, bool desdeFrente) {
        if (desdeFrente) {
            std::cout << "\nEliminando desde el frente." << std::endl;
            lista.eliminarFrente();
        } else {
            std::cout << "\nEliminando desde atras." << std::endl;
            lista.eliminarAtras();
        }
    }
};

#endif
