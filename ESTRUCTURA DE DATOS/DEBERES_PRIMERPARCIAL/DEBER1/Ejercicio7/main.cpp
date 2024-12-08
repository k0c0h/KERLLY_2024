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
#include <stdlib.h>
#include "Temperatura.h"

int main() {
    double celsius;

    printf("Ingrese la temperatura en Celsius: ");
    while (scanf("%lf", &celsius) != 1) {
        printf("Entrada invalida.\nIngrese un valor numerico: ");
        while(getchar() != '\n');
    }

    Temperatura t(celsius);
    printf("En Fahrenheit: %.2lf\n", t.aFahrenheit());

    return 0;
}
