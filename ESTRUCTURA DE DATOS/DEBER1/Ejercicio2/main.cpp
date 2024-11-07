#include <stdio.h>
#include "Punto.h"

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
    double x1 = leerDouble("Ingrese la coordenada x del primer punto: ");
    double y1 = leerDouble("Ingrese la coordenada y del primer punto: ");
    Punto p1(x1, y1);

    double x2 = leerDouble("Ingrese la coordenada x del segundo punto: ");
    double y2 = leerDouble("Ingrese la coordenada y del segundo punto: ");
    Punto p2(x2, y2);

    printf("La distancia entre los puntos es: %.2lf\n", p1.distancia(p2));

    return 0;
}
