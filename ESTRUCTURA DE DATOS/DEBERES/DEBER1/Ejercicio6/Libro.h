#ifndef LIBRO_H
#define LIBRO_H

#include <string>

class Libro {
private:
    std::string titulo;
    std::string autor;

public:
    Libro(const std::string& t, const std::string& a);

    std::string getTitulo() const;
    std::string getAutor() const;

    void setTitulo(const std::string& t);
    void setAutor(const std::string& a);

    void mostrar() const;
};

#endif
