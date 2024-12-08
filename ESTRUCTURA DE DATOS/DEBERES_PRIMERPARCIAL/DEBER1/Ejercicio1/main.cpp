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
#include "Complejo.h"

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
    double real1 = leerDouble("Ingrese la parte real del primer numero complejo: ");
    double imag1 = leerDouble("Ingrese la parte imaginaria del primer numero complejo: ");

    Complejo c1(real1, imag1);

    double real2 = leerDouble("Ingrese la parte real del segundo numero complejo: ");
    double imag2 = leerDouble("Ingrese la parte imaginaria del segundo numero complejo: ");

    Complejo c2(real2, imag2);

    Complejo resultado = c1.sumar(c2);
    printf("La suma de los numeros complejos es: ");
    resultado.mostrar();

    return 0;
}
