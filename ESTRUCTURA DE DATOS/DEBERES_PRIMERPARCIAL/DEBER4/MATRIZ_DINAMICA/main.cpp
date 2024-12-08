/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Matriz con Memoria Dinamica                         *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              18/11/2024                                          *
 * Fecha de modificacion:          21/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#include <iostream>
#include "Matriz.h"
#include "Operaciones.h"
#include "Validaciones.h"

void iniciar(int dim) {
    int **matriz;
    Matriz m(matriz, dim);
    Operaciones operaciones(m);
    Validaciones<int> ingresar_int;
    
    operaciones.segmentar();
    operaciones.encerar();
    
    operaciones.generar();
    printf("\nMatriz generada:\n");
    operaciones.imprimir();
    
    int pot = ingresar_int.ingresar("Ingrese la potencia de la matriz: ", "entero");
    operaciones.procesarPot(pot);
    printf("\nMatriz elevada a la potencia:\n");
    operaciones.imprimir();
    
    operaciones.procesarMulti();
    printf("\nResultado de la multiplicacion de la matriz por si misma:\n");
    operaciones.imprimir();
}

int main(){
    Validaciones<int> ingresar_entero;
    int dim =  ingresar_entero.ingresar("Ingrese la dimension de la matriz: ","entero");
    iniciar(dim);
}
 // g++ main.cpp Matriz.cpp Operaciones.cpp -o main.exe