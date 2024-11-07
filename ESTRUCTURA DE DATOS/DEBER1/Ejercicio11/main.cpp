#include <stdio.h>
#include "Fecha.h"
#include <stdexcept>

int leerEntero(const char* prompt) {
    int valor;
    int resultado;
    do {
        printf("%s", prompt);
        resultado = scanf("%d", &valor);

        if (resultado != 1) {
            printf("Entrada invalida. Ingrese solo numeros.\n");
            while (getchar() != '\n');
        }
    } while (resultado != 1);

    return valor;
}

int main() {
    int dia = leerEntero("Ingrese el dia: ");
    int mes = leerEntero("Ingrese el mes: ");
    int anio = leerEntero("Ingrese el anio: ");

    try {
        Fecha fecha(dia, mes, anio);
        printf("La fecha ingresada es: ");
        fecha.mostrar();
    } catch (std::invalid_argument& e) {
        printf("Error: %s\n", e.what());
    }

    return 0;
}
