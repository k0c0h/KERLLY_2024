/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include <stdio.h>
#include <limits>
#include "Calculadora.h"

bool esNumeroValido(double& numero) {
    if (scanf("%lf", &numero) != 1) {
        while (getchar() != '\n'); 
        return false;
    }
    return true;
}

int main() {
    double n1, n2;

    printf("Ingrese el primer numero: ");
    while (!esNumeroValido(n1)) {
        printf("Entrada invalida. Ingrese un numero valido: ");
    }

    printf("Ingrese el segundo numero: ");
    while (!esNumeroValido(n2)) {
        printf("Entrada invalida. Ingrese un numero valido: ");
    }

    Calculadora calc(n1, n2);

    printf("Suma: %.2lf\n", calc.sumar());
    printf("Resta: %.2lf\n", calc.restar());
    printf("Multiplicacion: %.2lf\n", calc.multiplicar());

    if (n2 != 0) {
        printf("Division: %.2lf\n", calc.dividir());
    } else {
        printf("Error: Division por cero no es permitida.\n");
    }

    return 0;
}
