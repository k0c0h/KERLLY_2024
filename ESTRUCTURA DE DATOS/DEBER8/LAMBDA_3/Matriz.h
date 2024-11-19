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

    static T sumaRecursivaMatrices(const Matriz<T>& m1, const Matriz<T>& m2, int f, int c);
};

#endif
