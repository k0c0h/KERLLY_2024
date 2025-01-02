#ifndef AUTO_H
#define AUTO_H

#include <string>

using namespace std;

class Auto
{
private:
    string placa;
    string marca;
    string color;
    string estado;


public:
    // Constructor por defecto
    Auto();

    // Constructor parametrizado
    Auto(const string &placa, const string &marca, const string &color, const string &estado);

    // Sobrecargar el operador == para comparar Autos por placa
    bool operator==(const string &otherPlaca) const
    {
        return placa == otherPlaca;
    }

    // Métodos getters
    string getPlaca() const;
    string getMarca() const;
    string getColor() const;
    string getEstado() const;

    // Métodos setters
    void setPlaca(const string &placa);
    void setMarca(const string &marca);
    void setColor(const string &color);
    void setEstado(const std::string &nuevoEstado);
    // Destructor
    ~Auto();
};

#endif