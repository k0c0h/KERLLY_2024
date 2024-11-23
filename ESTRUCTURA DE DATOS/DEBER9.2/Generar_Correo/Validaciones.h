#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <cctype>  // Para isdigit, isalpha

template <typename T>
class Validaciones {
public:
    Validaciones() {}
    T ingresar(const char* msj, const char* tipo);
};

// Definición de la función plantilla en el mismo archivo .h
template <typename T>
T Validaciones<T>::ingresar(const char* msj, const char* tipo)
{
    char cad[100];  // Aumentamos el tamaño del buffer para la entrada
    char c;
    int i = 0;
    T valor;
    printf("%s", msj);

    while ((c = getch()) != 13)  // Leemos hasta Enter (13 es el código ASCII de Enter)
    {
        if (tipo == "entero")
        {
            if (isdigit(c))  // Validamos si es un número
            {
                printf("%c", c);
                cad[i++] = c;
            }
            else if (c == 8)  // Si presionamos Backspace, eliminamos el último carácter
            {
                if (i > 0)
                {
                    printf("\b \b");
                    i--;
                }
            }
        }
        else if (tipo == "flotante" || tipo == "double")
        {
            if (isdigit(c) || c == '.')  // Permitir dígitos y el punto decimal
            {
                printf("%c", c);
                cad[i++] = c;
            }
            else if (c == 8)
            {
                if (i > 0)
                {
                    printf("\b \b");
                    i--;
                }
            }
        }
        else if (tipo == "string")
        {
            if (isalpha(c) || isspace(c))  // Permitir letras y espacios
            {
                printf("%c", c);
                cad[i++] = c;
            }
            else if (c == 8)
            {
                if (i > 0)
                {
                    printf("\b \b");
                    i--;
                }
            }
        }
        else if (tipo == "char")
        {
            if (isalpha(c))  // Solo permitir caracteres alfabéticos
            {
                printf("%c", c);
                valor = c;
                break;
            }
            else if (c == 8)
            {
                if (i > 0)
                {
                    printf("\b \b");
                    i--;
                }
            }
        }
    }
    cad[i] = '\0';  // Aseguramos que la cadena termine correctamente

    // Convertimos la cadena a su tipo correspondiente
    if (tipo == "entero")
    {
        valor = atoi(cad);  // Convertir a entero
    }
    else if (tipo == "flotante" || tipo == "double")
    {
        valor = atof(cad);  // Convertir a flotante o double
    }
    else if (tipo == "string")
    {
        valor = cad;  // Directamente la cadena
    }
    else if (tipo == "char")
    {
        valor = cad[0];  // Solo el primer carácter
    }

    return valor;
}

#endif // VALIDACIONES_H
