/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Validacion de datos                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include <iostream>
#include "Matriz.h"

using namespace std;

int main() {
    Matriz mat1(3, 3);
    Matriz mat2(3, 3);

    mat1.llenarMatriz();
    mat2.llenarMatriz();

    cout << "Matriz 1:" << endl;
    mat1.mostrarMatriz();
    cout << endl;

    cout << "Matriz 2:" << endl;
    mat2.mostrarMatriz();
    cout << endl;

    int resultado = Matriz::sumaRecursivaMatrices(mat1, mat2, 2, 2);
    cout << "Suma de matrices es: " << resultado << endl;

    return 0;
}
