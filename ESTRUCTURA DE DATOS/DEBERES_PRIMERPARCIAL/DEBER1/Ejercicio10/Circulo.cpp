/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include "Circulo.h"
#include <cmath>

Circulo::Circulo(double r) : radio(r) {}

double Circulo::getRadio() const {
    return radio;
}

void Circulo::setRadio(double r) {
    radio = r;
}

double Circulo::area() const {
    return M_PI * radio * radio;
}

double Circulo::perimetro() const {
    return 2 * M_PI * radio;
}
