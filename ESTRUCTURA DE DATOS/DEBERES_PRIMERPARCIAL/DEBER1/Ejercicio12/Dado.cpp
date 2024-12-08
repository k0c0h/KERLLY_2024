/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include "Dado.h"
#include <cstdlib>
#include <ctime>

Dado::Dado() {
    srand(static_cast<unsigned int>(time(0)));
    lanzar();
}

int Dado::getValor() const {
    return valor;
}

void Dado::lanzar() {
    valor = rand() % 6 + 1;
}
