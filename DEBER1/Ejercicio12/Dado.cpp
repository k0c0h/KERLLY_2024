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
