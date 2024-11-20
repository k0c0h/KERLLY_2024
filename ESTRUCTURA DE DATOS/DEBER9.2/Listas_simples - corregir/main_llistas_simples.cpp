/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Programa sobre lista simple                         *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              18/11/2024                                          *
 * Fecha de modificacion:          20/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
#include "Lista_Simple.cpp"
#include "Nodo.cpp"
#include <iostream>
#include <stdlib.h>
#include "Validaciones.cpp"
// #include <windows.h>
using namespace std;

bool esEntero(string);

int main()
{
    Lista_Simple<int> *lista_entero = new Lista_Simple<int>();
    Lista_Simple<float> *lista_flotante = new Lista_Simple<float>();
    Lista_Simple<double> *lista_doble = new Lista_Simple<double>();
    Lista_Simple<std::string> *lista_string = new Lista_Simple<std::string>();
    Lista_Simple<char> *lista_letras = new Lista_Simple<char>();

    int opcion, dato_entero;
    float dato_flotante;
    double dato_doble;
    std::string dato_string;
    char dato_char;

    Validaciones<int> ingresar_entero;
    Validaciones<float> ingresar_flotante;
    Validaciones<double> ingresar_doble;
    Validaciones<std::string> ingresar_string;
    Validaciones<char> ingresar_letra;

    /*HINSTANCE hDLL = LoadLibrary("ValidDll.dll");
    if (!hDLL) {
        std::cerr << "No se pudo cargar la DLL.\n";
        return 1;
    }*/

    do
    {
        system("cls");
        cout << "***********Listas Simples***********" << endl;
        cout << "1. Lista de enteros" << endl;
        cout << "2. lista de flotantes" << endl;
        cout << "3. lista de dobles" << endl;
        cout << "4. lista de strings" << endl;
        cout << "5. lista de letras" << endl;
        cout << "6. salir" << endl;
        opcion = ingresar_entero.ingresar("Opcion: ", "entero");
        cout << endl;
        switch (opcion)
        {
        case 1:
            do
            {
                system("cls");
                cout << "***********Listas Simples***********" << endl;
                cout << "1. Insertar" << endl;
                cout << "2. Buscar" << endl;
                cout << "3. Eliminar" << endl;
                cout << "4. Mostrar" << endl;
                cout << "5. Salir" << endl;
                opcion = ingresar_entero.ingresar("Opcion: ", "entero");
                cout << endl;
                switch (opcion)
                {
                case 1:
                    int opcionInsertar = ingresar_entero.ingresar("1. Insertar al inicio\n2. Insertar al final\nOpcion: ", "entero");
                    dato_entero = ingresar_entero.ingresar("Ingrese el dato a insertar: ", "entero");
                    if (opcionInsertar == 1)
                    {
                        lista_entero->Insertar_cabeza(dato_entero);
                        cout << "Dato insertado al inicio correctamente." << endl;
                    }
                    else if (opcionInsertar == 2)
                    {
                        lista_entero->Insertar_cola(dato_entero);
                        cout << "Dato insertado al final correctamente." << endl;
                    }
                    else
                    {
                        cout << "Opcion no valida." << endl;
                    }
                    system("pause");
                    break;
                case 2:
                    dato_entero = ingresar_entero.ingresar("ingrese el dato a buscar: ", "entero");
                    cout << endl;
                    lista_entero->Buscar(dato_entero);
                    system("pause");
                    break;
                case 3:
                    int opcionEliminar = ingresar_entero.ingresar("1. Eliminar al inicio\n2. Eliminar al final\nOpcion: ", "entero");
                    if (opcionEliminar == 1)
                    {
                        lista_entero->Eliminar_cabeza();
                        cout << "Elemento eliminado del inicio." << endl;
                    }
                    else if (opcionEliminar == 2)
                    {
                        lista_entero->Eliminar_cola();
                        cout << "Elemento eliminado del final." << endl;
                    }
                    else
                    {
                        cout << "Opcion no valida." << endl;
                    }
                    system("pause");
                    break;
                case 4:
                    lista_entero->Mostrar();
                    cout << endl;
                    system("pause");
                    break;
                case 5:
                    break;
                default:
                    cout << "Opcion no valida, intente de nuevo" << endl;
                    system("pause");
                    break;
                }
            } while (opcion != 5);
            break;
        case 2:
            do
            {
                system("cls");
                cout << "***********Listas Simples***********" << endl;
                cout << "1. Insertar" << endl;
                cout << "2. Buscar" << endl;
                cout << "3. Eliminar" << endl;
                cout << "4. Mostrar" << endl;
                cout << "5. Salir" << endl;
                opcion = ingresar_entero.ingresar("Opcion: ", "entero");
                cout << endl;
                switch (opcion)
                {
                case 1:
                    int opcionInsertar = ingresar_entero.ingresar("1. Insertar al inicio\n2. Insertar al final\nOpcion: ", "entero");
                    dato_flotante = ingresar_flotante.ingresar("Ingrese el dato a insertar: ", "flotante");
                    if (opcionInsertar == 1)
                    {
                        lista_flotante->Insertar_cabeza(dato_flotante);
                        cout << "Dato insertado al inicio correctamente en la lista de flotantes." << endl;
                    }
                    else if (opcionInsertar == 2)
                    {
                        lista_flotante->Insertar_cola(dato_flotante);
                        cout << "Dato insertado al final correctamente en la lista de flotantes." << endl;
                    }
                    else
                    {
                        cout << "Opcion no valida." << endl;
                    }
                    system("pause");
                    break;
                case 2:
                    dato_flotante = ingresar_flotante.ingresar("ingrese el dato a buscar: ", "flotante");
                    cout << endl;
                    lista_flotante->Buscar(dato_flotante);
                    system("pause");
                    break;
                case 3:
                    int opcionEliminar = ingresar_entero.ingresar("1. Eliminar al inicio\n2. Eliminar al final\nOpcion: ", "entero");
                    if (opcionEliminar == 1)
                    {
                        lista_flotante->Eliminar_cabeza();
                        cout << "Elemento eliminado del inicio." << endl;
                    }
                    else if (opcionEliminar == 2)
                    {
                        lista_flotante->Eliminar_cola();
                        cout << "Elemento eliminado del final." << endl;
                    }
                    else
                    {
                        cout << "Opcion no valida." << endl;
                    }
                    system("pause");
                    break;
                case 4:
                    lista_flotante->Mostrar();
                    cout << endl;
                    system("pause");
                    break;
                case 5:
                    break;
                default:
                    cout << "Opcion no valida, intente de nuevo" << endl;
                    system("pause");
                    break;
                }
            } while (opcion != 5);
            break;
        case 3:
            do
            {
                system("cls");
                cout << "***********Listas Simples***********" << endl;
                cout << "1. Insertar" << endl;
                cout << "2. Buscar" << endl;
                cout << "3. Eliminar" << endl;
                cout << "4. Mostrar" << endl;
                cout << "5. Salir" << endl;
                opcion = ingresar_entero.ingresar("Opcion: ", "entero");
                cout << endl;
                switch (opcion)
                {
                case 1:
                    int opcionInsertar = ingresar_entero.ingresar("1. Insertar al inicio\n2. Insertar al final\nOpcion: ", "entero");
                    dato_doble = ingresar_doble.ingresar("Ingrese el dato a insertar: ", "double");
                    if (opcionInsertar == 1)
                    {
                        lista_doble->Insertar_cabeza(dato_doble);
                        cout << "Dato insertado al inicio correctamente en la lista de dobles." << endl;
                    }
                    else if (opcionInsertar == 2)
                    {
                        lista_doble->Insertar_cola(dato_doble);
                        cout << "Dato insertado al final correctamente en la lista de dobles." << endl;
                    }
                    else
                    {
                        cout << "Opcion no valida." << endl;
                    }
                    system("pause");
                    break;
                case 2:
                    dato_doble = ingresar_doble.ingresar("ingrese el dato a buscar: ", "double");
                    cout << endl;
                    lista_doble->Buscar(dato_doble);
                    system("pause");
                    break;
                case 3:
                    int opcionEliminar = ingresar_entero.ingresar("1. Eliminar al inicio\n2. Eliminar al final\nOpcion: ", "entero");
                    if (opcionEliminar == 1)
                    {
                        lista_doble->Eliminar_cabeza();
                        cout << "Elemento eliminado del inicio." << endl;
                    }
                    else if (opcionEliminar == 2)
                    {
                        lista_doble->Eliminar_cola();
                        cout << "Elemento eliminado del final." << endl;
                    }
                    else
                    {
                        cout << "Opcion no valida." << endl;
                    }
                    system("pause");
                    break;
                case 4:
                    lista_doble->Mostrar();
                    cout << endl;
                    system("pause");
                    break;
                case 5:
                    break;
                default:
                    cout << "Opcion no valida, intente de nuevo" << endl;
                    system("pause");
                    break;
                }
            } while (opcion != 5);
            break;
        case 4:
            do
            {
                system("cls");
                cout << "***********Listas Simples***********" << endl;
                cout << "1. Insertar" << endl;
                cout << "2. Buscar" << endl;
                cout << "3. Eliminar" << endl;
                cout << "4. Mostrar" << endl;
                cout << "5. Salir" << endl;
                opcion = ingresar_entero.ingresar("Opcion: ", "entero");
                cout << endl;
                switch (opcion)
                {
                case 1:
                    int opcionInsertar = ingresar_entero.ingresar("1. Insertar al inicio\n2. Insertar al final\nOpcion: ", "entero");
                    dato_string = ingresar_string.ingresar("Ingrese el dato a insertar: ", "string");
                    if (opcionInsertar == 1)
                    {
                        lista_string->Insertar_cabeza(dato_string);
                        cout << "Dato insertado al inicio correctamente en la lista de cadenas." << endl;
                    }
                    else if (opcionInsertar == 2)
                    {
                        lista_string->Insertar_cola(dato_string);
                        cout << "Dato insertado al final correctamente en la lista de cadenas." << endl;
                    }
                    else
                    {
                        cout << "Opcion no valida." << endl;
                    }
                    system("pause");
                    break;
                case 2:
                    dato_string = ingresar_string.ingresar("ingrese el dato a buscar: ", "string");
                    cout << endl;
                    lista_string->Buscar(dato_string);
                    system("pause");
                    break;
                case 3:
                    int opcionEliminar = ingresar_entero.ingresar("1. Eliminar al inicio\n2. Eliminar al final\nOpcion: ", "entero");
                    if (opcionEliminar == 1)
                    {
                        lista_string->Eliminar_cabeza();
                        cout << "Elemento eliminado del inicio." << endl;
                    }
                    else if (opcionEliminar == 2)
                    {
                        lista_string->Eliminar_cola();
                        cout << "Elemento eliminado del final." << endl;
                    }
                    else
                    {
                        cout << "Opcion no valida." << endl;
                    }
                    system("pause");
                    break;
                case 4:
                    lista_string->Mostrar();
                    cout << endl;
                    system("pause");
                    break;
                case 5:
                    break;
                default:
                    cout << "Opcion no valida, intente de nuevo" << endl;
                    system("pause");
                    break;
                }
            } while (opcion != 5);
            break;
        case 5:
            do
            {
                system("cls");
                cout << "***********Listas Simples***********" << endl;
                cout << "1. Insertar" << endl;
                cout << "2. Buscar" << endl;
                cout << "3. Eliminar" << endl;
                cout << "4. Mostrar" << endl;
                cout << "5. Salir" << endl;
                opcion = ingresar_entero.ingresar("Opcion: ", "entero");
                cout << endl;
                switch (opcion)
                {
                case 1:
                    int opcionInsertar = ingresar_entero.ingresar("1. Insertar al inicio\n2. Insertar al final\nOpcion: ", "entero");
                    dato_char = ingresar_letra.ingresar("Ingrese el dato a insertar: ", "char");
                    if (opcionInsertar == 1)
                    {
                        lista_letras->Insertar_cabeza(dato_char);
                        cout << "Dato insertado al inicio correctamente en la lista de caracteres." << endl;
                    }
                    else if (opcionInsertar == 2)
                    {
                        lista_letras->Insertar_cola(dato_char);
                        cout << "Dato insertado al final correctamente en la lista de caracteres." << endl;
                    }
                    else
                    {
                        cout << "Opcion no valida." << endl;
                    }
                    system("pause");
                    break;
                case 2:
                    dato_char = ingresar_letra.ingresar("ingrese el dato a buscar: ", "char");
                    cout << endl;
                    lista_letras->Buscar(dato_char);
                    system("pause");
                    break;
                case 3:
                    int opcionEliminar = ingresar_entero.ingresar("1. Eliminar al inicio\n2. Eliminar al final\nOpcion: ", "entero");
                    if (opcionEliminar == 1)
                    {
                        lista_letras->Eliminar_cabeza();
                        cout << "Elemento eliminado del inicio." << endl;
                    }
                    else if (opcionEliminar == 2)
                    {
                        lista_letras->Eliminar_cola();
                        cout << "Elemento eliminado del final." << endl;
                    }
                    else
                    {
                        cout << "Opcion no valida." << endl;
                    }
                    system("pause");
                    break;
                case 4:
                    lista_letras->Mostrar();
                    cout << endl;
                    system("pause");
                    break;
                case 5:
                    break;
                default:
                    cout << "Opcion no valida, intente de nuevo" << endl;
                    system("pause");
                    break;
                }
            } while (opcion != 5);
            break;
        case 6:
            cout << "Gracias por visitarnos" << endl;
            system("pause");
            break;
        default:
            cout << "Opcion no valida, intente de nuevo" << endl;
            system("pause");
            break;
        }
    } while (opcion != 6);

    return 0;
}
