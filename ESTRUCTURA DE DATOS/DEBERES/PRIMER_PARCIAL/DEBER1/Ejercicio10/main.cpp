#include <stdio.h>
#include <limits>
#include "Circulo.h"

bool esNumeroValido(double& numero) {
    if (scanf("%lf", &numero) != 1) {
        while (getchar() != '\n'); 
        return false;
    }
    while (getchar() != '\n');
    return true;
}

int main() {
    double radio;

    printf("Ingrese el radio del circulo: ");
    while (!esNumeroValido(radio) || radio <= 0) {
        if (radio <= 0) {
            printf("El radio debe ser un numero mayor que cero. Intente de nuevo: ");
        } else {
            printf("Entrada invalida. Ingrese un valor numerico para el radio: ");
        }
    }

    Circulo circ(radio);
    printf("Area: %.2lf\n", circ.area());
    printf("Perimetro: %.2lf\n", circ.perimetro());

    return 0;
}