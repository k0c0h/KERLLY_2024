#include <stdio.h>
#include "Vector.h"

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
    double x = leerDouble("Ingrese la componente x del vector: ");
    double y = leerDouble("Ingrese la componente y del vector: ");

    Vector v(x, y);

    printf("El vector ingresado es: ");
    v.mostrar();

    return 0;
}

//g++ main.cpp Vector.cpp -o main.exe
