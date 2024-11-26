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
