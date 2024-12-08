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
#include <string>
#include <limits>
#include "Estudiante.h"
#include <iostream>
#include <cctype>  

bool esNombreValido(const std::string& nombre) {
    for (char c : nombre) {
        if (isdigit(c)) {
            return false;  
        }
    }
    return true; 
}

bool esNotaValida(double nota) {
    return (nota >= 0 && nota <= 20);  
}

int main() {
    std::string nombre;
    double n1, n2, n3;

    printf("Ingrese el nombre del estudiante: ");
    std::getline(std::cin, nombre);
    
    while (!esNombreValido(nombre)) {
        printf("El nombre no puede contener numeros. Ingrese el nombre del estudiante nuevamente: ");
        std::getline(std::cin, nombre);
    }

    printf("Ingrese la primera nota (0 - 20): ");
    while (true) {
        if (scanf("%lf", &n1) != 1 || !esNotaValida(n1)) {
            printf("Entrada invalida. Ingrese un valor numerico entre 0 y 20 para la primera nota: ");
            while (getchar() != '\n'); 
        } else {
            break; 
        }
    }

    printf("Ingrese la segunda nota (0 - 20): ");
    while (true) {
        if (scanf("%lf", &n2) != 1 || !esNotaValida(n2)) {
            printf("Entrada invalida. Ingrese un valor numerico entre 0 y 20 para la segunda nota: ");
            while (getchar() != '\n');
        } else {
            break; 
        }
    }
    printf("Ingrese la tercera nota (0 - 20): ");
    while (true) {
        if (scanf("%lf", &n3) != 1 || !esNotaValida(n3)) {
            printf("Entrada invalida. Ingrese un valor numerico entre 0 y 20 para la tercera nota: ");
            while (getchar() != '\n'); 
        } else {
            break;
        }
    }

    Estudiante est(nombre, n1, n2, n3);
    est.mostrar();

    return 0;
}
