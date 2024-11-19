#ifndef INGRESAR_H
#define INGRESAR_H

#include "Lista.h"
#include <iostream>

template <typename T>
class Ingresar {
public:
    void realizarOperacion(Lista<T>& lista, T valor) {
        lista.insertarAtras(valor);
        std::cout << "\nElemento " << valor << " ingresado en la lista." << std::endl;
    }
};

#endif
