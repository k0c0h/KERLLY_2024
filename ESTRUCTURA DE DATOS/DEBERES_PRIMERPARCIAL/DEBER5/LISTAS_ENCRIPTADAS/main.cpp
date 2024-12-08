/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Listas Encriptadas(Metodo de Cesar)                 *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              25/11/2024                                          *
 * Fecha de modificacion:          27/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#include <iostream>
#include <string>
#include "ListaSimple.h"
#include "ListaDoble.h"
#include "ListaCircular.h"
#include "Menu.h"

using namespace std;

string cesarCipher(const string &text, int shift) {
    string result;
    for (char c : text) {
        if (isalpha(c)) { 
            char offset = isupper(c) ? 'A' : 'a';
            result += (c - offset + shift) % 26 + offset;
        }
        else if (isdigit(c)) { 
            result += (c - '0' + shift) % 10 + '0'; 
        }
        else { 
            result += c;
        }
    }
    return result;
}


int main()
{
    ListaSimple<string> *listaSimple = new ListaSimple<string>();
    ListaDoble<string> *listaDoble = new ListaDoble<string>();
    ListaCircular<string> *listaCircular = new ListaCircular<string>();
    Menu menu;

    string dato;
    int opcion;

    while (true)
    {
        vector<string> opciones = {
            " Insertar en lista simple ",
            " Insertar en lista doble  ",
            "Insertar en lista circular",
            "     Mostrar listas       ",
            "    Encriptar listas      ",
            "         Salir            "};
        opcion = menu.mostrarMenu("========== Encriptar Listas =========", opciones);
        system("cls");
        switch (opcion + 1)
        {
        case 1:
            cout << "Ingrese un dato a la lista Simple: ";
            cin >> dato;
            listaSimple->insertar(dato);
            break;
        case 2:
            cout << "Ingrese un dato a la lista Doble: ";
            cin >> dato;
            listaDoble->insertar(dato);
            break;
        case 3:
            cout << "Ingrese un dato a la lista Circular: ";
            cin >> dato;
            listaCircular->insertar(dato);
            break;
        case 4:
            cout << "Lista simple: ";
            listaSimple->mostrar();
            cout << "Lista doble: ";
            listaDoble->mostrar();
            cout << "Lista circular: ";
            listaCircular->mostrar();
            break;
        case 5:
            listaSimple->encriptar([](const string &d)
                                   { return cesarCipher(d, 3); });
            listaDoble->encriptar([](const string &d)
                                  { return cesarCipher(d, 3); });
            listaCircular->encriptar([](const string &d)
                                     { return cesarCipher(d, 3); });
            cout << "Listas encriptadas.\n";
            break;
        case 6:
            cout << "\nSaliendo del programa.\n";
            return 0;
        }

        cout << "\nPresione Enter para continuar...";
        cin.ignore();
        cin.get();
    }

    delete listaSimple;
    delete listaDoble;
    delete listaCircular;

    return 0;
}
// g++ main.cpp Menu.cpp -o main.exe