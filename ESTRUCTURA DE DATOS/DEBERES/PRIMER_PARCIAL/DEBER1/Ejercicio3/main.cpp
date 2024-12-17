#include <stdio.h>
#include "Rectangulo.h"

double leerDouble(const char* prompt) {
    double valor;
    int resultado;
    do {
        printf("%s", prompt);
        resultado = scanf("%lf", &valor);
        if (resultado != 1) {
            printf("Entrada invalida. Ingrese solo numeros.\n");
            while (getchar() != '\n'); 
        }
    } while (resultado != 1); 

    return valor;
}

int main() {
    double ancho = leerDouble("Ingrese el ancho del rectangulo: ");
    double alto = leerDouble("Ingrese el alto del rectangulo: ");

    Rectangulo rect(ancho, alto);
    printf("Area: %.2lf\n", rect.area());
    printf("Perimetro: %.2lf\n", rect.perimetro());

    return 0;
}
