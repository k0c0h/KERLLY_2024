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
