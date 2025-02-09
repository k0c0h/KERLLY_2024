/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Lista simple                                        *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              18/11/2024                                          *
 * Fecha de modificacion:          24/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#include "Lista_Simple.cpp"
#include "Nodo.cpp"
#include "Validaciones.h"
#include "Menu.h"
#include <iostream>
#include "GeneradorCorreos.h"
#include "Persona.h"


using namespace std;

int main()
{
    Lista_Simple<int> *lista_enteros = new Lista_Simple<int>();
    Lista_Simple<float> *lista_flotantes = new Lista_Simple<float>();
    Lista_Simple<double> *lista_dobles = new Lista_Simple<double>();
    Lista_Simple<std::string> *lista_strings = new Lista_Simple<std::string>();
    Lista_Simple<char> *lista_letras = new Lista_Simple<char>();

    int opcion, dato_entero, dato, sub_opcion;
    float dato_flotante;
    double dato_doble;
    std::string dato_string;
    char dato_char;
    Menu menu;

    Validaciones<int> ingresar_entero;
    Validaciones<float> ingresar_flotante;
    Validaciones<double> ingresar_doble;
    Validaciones<std::string> ingresar_string;
    Validaciones<char> ingresar_letra;

    GeneradorCorreos<string> *generador = new GeneradorCorreos<string>();

    while (true)
    {
        vector<string> opciones = {
            "  Ingresar datos y generar correo   ",
            "    Mostrar datos ingresados        ",
            "       Correos Generados            ",
            "            Salir                   "
        };
        opcion = menu.mostrarMenu("=========== Lista Simple ===========", opciones);
        system("cls");
        switch (opcion + 1)
        {
        case 1:
            generador->ingresarDatos();
            break;
        case 2:
            generador->mostrarPersonas();
            break;
        case 3:
            generador->mostrarCorreos();
                break;
        case 4:
            cout << "\nSaliendo del programa.\n";
            return 0;
        }
            
            cout << "\nPresione Enter para continuar...";
            cin.get();
        }
        delete generador;
        return 0;
    }
// g++ Lista_Simple.cpp Menu.cpp main.cpp Nodo.cpp Persona.cpp -o main.exe