#include <stdio.h>
#include "Dado.h"

int main() {
    Dado dado;

    printf("Lanzando el dado...\n");
    dado.lanzar();
    printf("El valor obtenido es: %d\n", dado.getValor());

    return 0;
}
