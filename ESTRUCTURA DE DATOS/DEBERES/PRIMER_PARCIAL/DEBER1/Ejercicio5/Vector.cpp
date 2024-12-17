#include "Vector.h"
#include <stdio.h>

Vector::Vector(double x, double y) : x(x), y(y) {}

double Vector::getX() const {
    return x;
}

void Vector::setX(double x) {
    this->x = x;
}

double Vector::getY() const {
    return y;
}

void Vector::setY(double y) {
    this->y = y;
}

void Vector::mostrar() const {
    printf(" (%.2f, %.2f)\n", x, y);
}
