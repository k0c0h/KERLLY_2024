#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <iostream>
#include <string>
#include <functional>
#include <conio.h>
#include <cctype>
#include <stdexcept>

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

using namespace std;

class EXPORT InputValidator {
public:
    static int ingresarEntero(const string& mensaje);
    static float ingresarFlotante(const string& mensaje);
    static char ingresarLetra(const string& mensaje);
    static string ingresarString(const string& mensaje);
    static double ingresarDouble(const string& mensaje);

private:
    template <typename T>
    static T ingresar(const string& mensaje, function<T(const string&)> convert);
};

#endif // INPUTVALIDATOR_H
