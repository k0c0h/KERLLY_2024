#ifndef MATRIZ_H
#define MATRIZ_H

template <typename T>
class Matriz {
private:
    T** matriz;
    int filas;
    int columnas;

public:
    Matriz(int f, int c);
    ~Matriz();

    void llenarMatriz();
    void mostrarMatriz() const;
    T getElemento(int f, int c) const;
    void setElemento(int f, int c, T valor);

    static T sumaRecursivaMatrices(const Matriz& m1, const Matriz& m2, int f, int c);
};

#endif
