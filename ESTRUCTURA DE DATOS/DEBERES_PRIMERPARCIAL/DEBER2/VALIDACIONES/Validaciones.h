/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                     Validaciones                         *
 * Autor:                         Kerlly Chiriboga                     *
 * Fecha de creacion:              10/10/2024                          *
 * Fecha de modificacion:          11/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <string>
using namespace std;

class Validaciones {
public:
    int ingresar(const char *msj);
    float ingresarFloat(const char *msj);
    char ingresarLetra(const char *msj);
    string ingresarString(const char *msj);
    double ingresarDouble(const char *msj);

private:
};

#endif
