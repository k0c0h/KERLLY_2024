#ifndef TEMPERATURA_H
#define TEMPERATURA_H

class Temperatura {
private:
    double celsius;

public:
    Temperatura(double c);

    double getCelsius() const;
    void setCelsius(double c);

    double aFahrenheit() const;
    double aCelsius() const;
};

#endif
