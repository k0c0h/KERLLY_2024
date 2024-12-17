/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Validacion de datos                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#ifndef MATRIZ_H
#define MATRIZ_H

class Matriz {
private:
    int** matriz;
    int filas;
    int columnas;

public:
    Matriz(int f, int c);
    ~Matriz();

    int getElemento(int f, int c) const;
    void setElemento(int f, int c, int valor);

    void llenarMatriz();

    void mostrarMatriz() const;

    static int sumaRecursivaMatrices(const Matriz& m1, const Matriz& m2, int f, int c);
};

#endif
