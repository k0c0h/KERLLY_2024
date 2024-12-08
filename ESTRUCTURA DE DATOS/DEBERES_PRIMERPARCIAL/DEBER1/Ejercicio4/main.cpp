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
#include "CuentaBancaria.h"

double leerSaldoInicial(const char* prompt) {
    double valor;
    int resultado;
    do {
        printf("%s", prompt);
        resultado = scanf("%lf", &valor);
        if (resultado != 1 || valor < 0) {
            printf("Entrada invalida. Ingrese solo numeros y asegurese de que no sea negativo.\n");
            while (getchar() != '\n'); 
        }
    } while (resultado != 1 || valor < 0); 

    return valor;
}

int main() {
    double saldoInicial = leerSaldoInicial("Ingrese el saldo inicial: ");

    CuentaBancaria cuenta(saldoInicial);

    printf("Saldo actual: %.2lf\n", cuenta.getSaldo());
    cuenta.depositar(500);
    printf("Saldo despues de depositar: %.2lf\n", cuenta.getSaldo());
    cuenta.retirar(200);
    printf("Saldo despues de retirar: %.2lf\n", cuenta.getSaldo());

    return 0;
}
