#ifndef DADO_H
#define DADO_H

class Dado {
private:
    int valor;

public:
    Dado();

    int getValor() const;
    void lanzar();
};

#endif
