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
#include "Dado.h"

int main() {
    Dado dado;

    printf("Lanzando el dado...\n");
    dado.lanzar();
    printf("El valor obtenido es: %d\n", dado.getValor());

    return 0;
}
