/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Validacion de datos                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              08/11/2024                          *
 * Fecha de modificacion:          09/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <string>
#include <functional>

class InputValidator {
public:
    static int ingresarEntero(const std::string& mensaje);
    static float ingresarFlotante(const std::string& mensaje);
    static char ingresarLetra(const std::string& mensaje);
    static std::string ingresarString(const std::string& mensaje);
    static double ingresarDouble(const std::string& mensaje);

private:
    template <typename T>
    static T ingresar(const std::string& mensaje, std::function<T(const std::string&)> convert);
};

#endif
