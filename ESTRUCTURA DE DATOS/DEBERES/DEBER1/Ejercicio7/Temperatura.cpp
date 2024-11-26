#include "Temperatura.h"

Temperatura::Temperatura(double c) : celsius(c) {}

double Temperatura::getCelsius() const {
    return celsius;
}

void Temperatura::setCelsius(double c) {
    celsius = c;
}

double Temperatura::aFahrenheit() const {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double Temperatura::aCelsius() const {
    return (celsius - 32.0) * 5.0 / 9.0;
}
