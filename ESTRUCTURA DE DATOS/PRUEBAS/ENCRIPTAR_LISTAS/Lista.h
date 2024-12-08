#ifndef LISTA_H
#define LISTA_H

#include <functional>
using namespace std;

template <typename T>
class Lista {
public:
    virtual void insertar(const T& dato) = 0;
    virtual void mostrar() const = 0;
    virtual void encriptar(function<T(const T&)> func) = 0;
    virtual ~Lista() = default;
};

#endif // LISTA_H
