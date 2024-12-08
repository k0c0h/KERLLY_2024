/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include "Rectangulo.h"

Rectangulo::Rectangulo(double a, double al) : ancho(a), alto(al) {}

double Rectangulo::getAncho() const {
    return ancho;
}

double Rectangulo::getAlto() const {
    return alto;
}

void Rectangulo::setAncho(double a) {
    ancho = a;
}

void Rectangulo::setAlto(double al) {
    alto = al;
}

double Rectangulo::area() const {
    return ancho * alto;
}

double Rectangulo::perimetro() const {
    return 2 * (ancho + alto);
}
