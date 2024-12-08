/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Listas Encriptadas(Metodo de Cesar)                 *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              25/11/2024                                          *
 * Fecha de modificacion:          27/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include "Lista.h"
#include <vector>
#include <iostream>
#include <functional>
#include "Nodo.h"

using namespace std;

template <typename T>
class ListaSimple : public Lista<T> {
private:
    std::vector<T> datos;

public:
    void insertar(const T& dato) override {
        datos.push_back(dato);
    }

    void mostrar() const override {
        for (const auto& dato : datos) {
            std::cout << dato << " -> ";
        }
        std::cout << std::endl;
    }

    void encriptar(std::function<T(const T&)> func) override {
        for (auto& dato : datos) {
            dato = func(dato);
        }
    }
};

#endif
