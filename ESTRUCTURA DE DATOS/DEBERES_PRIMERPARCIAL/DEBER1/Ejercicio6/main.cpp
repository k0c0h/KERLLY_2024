/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include <iostream>
#include <string>
#include "Libro.h"

std::string leerString(const std::string& prompt) {
    std::string entrada;
    do {
        std::cout << prompt;
        std::getline(std::cin, entrada);
        
        if (entrada.empty()) {
            std::cout << "Entrada invalida. No puede estar vacia.\n";
        }
    } while (entrada.empty()); 

    return entrada;
}

int main() {
    std::string titulo = leerString("Ingrese el titulo del libro: ");
    std::string autor = leerString("Ingrese el autor del libro: ");

    Libro libro(titulo, autor);
    libro.mostrar();

    return 0;
}
