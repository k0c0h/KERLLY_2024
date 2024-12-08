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
#include "Fraccion.h"

int main() {
    int num1, den1, num2, den2;

    auto leerNumeroEntero = [](const char* mensaje) {
        int num;
        while (true) {
            printf("%s", mensaje);
            if (scanf("%d", &num) == 1) {
                return num;
            }
            printf("Entrada invalida. Intente de nuevo.\n");
            while (getchar() != '\n'); 
        }
    };

    num1 = leerNumeroEntero("Ingrese el numerador de la primera fraccion: ");
    do {
        den1 = leerNumeroEntero("Ingrese el denominador de la primera fraccion (distinto de 0): ");
    } while (den1 == 0);

    Fraccion f1(num1, den1);

    num2 = leerNumeroEntero("Ingrese el numerador de la segunda fraccion: ");
    do {
        den2 = leerNumeroEntero("Ingrese el denominador de la segunda fraccion (distinto de 0): ");
    } while (den2 == 0);

    Fraccion f2(num2, den2);

    Fraccion resultado = f1.sumar(f2);

    printf("La suma de las fracciones es: ");
    resultado.mostrar();

    return 0;
}
