#ifndef ELIMINAR_H
#define ELIMINAR_H

#include "Lista.h"
#include <iostream>

template <typename T>
class Eliminar {
public:
    void realizarOperacion(Lista<T>& lista, bool desdeFrente) {
        if (desdeFrente) {
            std::cout << "Eliminando desde el frente." << std::endl;
            lista.eliminarFrente();
        } else {
            std::cout << "Eliminando desde atrás." << std::endl;
            lista.eliminarAtras();
        }
    }
};

#endif
