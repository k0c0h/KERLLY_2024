#include "Punto.h"
#include <cmath>

Punto::Punto(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

double Punto::getX() const {
    return x;
}

double Punto::getY() const {
    return y;
}

void Punto::setX(double xCoord) {
    x = xCoord;
}

void Punto::setY(double yCoord) {
    y = yCoord;
}

double Punto::distancia(const Punto& otro) const {
    return sqrt(pow(x - otro.x, 2) + pow(y - otro.y, 2));
}
