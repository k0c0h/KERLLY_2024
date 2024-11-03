#include "Complejo.h"
#include <stdio.h>

Complejo::Complejo(double r, double i) : real(r), imaginario(i) {}

double Complejo::getReal() const {
    return real;
}

void Complejo::setReal(double r) {
    real = r;
}

double Complejo::getImaginario() const {
    return imaginario;
}

void Complejo::setImaginario(double i) {
    imaginario = i;
}

Complejo Complejo::sumar(const Complejo& c) const {
    return Complejo(real + c.real, imaginario + c.imaginario);
}

void Complejo::mostrar() const {
    printf("%.2f + %.2fi\n", real, imaginario);
}
