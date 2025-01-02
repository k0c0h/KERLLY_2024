#include "Lista.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include "Coche.h"
#include <algorithm>
#include <cctype>
#include <regex>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Propietario.h"

using namespace std;

template <typename T>
ListaDoble<T>::ListaDoble()
{
    primero = nullptr;
    ultimo = nullptr;
}

template <typename T>
void ListaDoble<T>::insertar(T dato, const std::string &nombreArchivo)
{
    Nodo<T> *nuevoCarro = new Nodo<T>(dato);

    if (primero == nullptr)
    {
        primero = nuevoCarro;
        ultimo = nuevoCarro;
    }
    else
    {
        ultimo->setSiguiente(nuevoCarro);
        nuevoCarro->setAnterior(ultimo);
        ultimo = nuevoCarro;
    }

    GuardarArchivo(nombreArchivo);
}

template <typename T>
void ListaDoble<T>::buscarPorPlaca(string placa)
{
    if (primero == nullptr)
    {
        cout << "La lista está vacía." << endl;
        return;
    }

    Nodo<T> *aux = primero;
    while (aux != nullptr)
    {
        if (aux->getDato().getPlaca() == placa)
        {
            cout << "========================================" << endl;
            cout << "   AUTOMOVIL REGISTRADO" << endl;
            cout << "========================================" << endl;
            cout << aux->getDato() << endl;
            return;
        }
        aux = aux->getSiguiente();
    }

    cout << "El coche con la placa " << placa << " no está en el parqueadero." << endl;
}

template <typename T>
void ListaDoble<T>::mostrar(Nodo<T>* aux)
{
    if (primero == nullptr)
    {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    aux = primero;
    cout << "AUTOMOVIL REGISTRADO" << endl;
    cout << "========================================" << endl;
    while (aux != nullptr)
    {
        cout << aux->getDato() << endl;
        aux = aux->getSiguiente();
    }
}

template <typename T>
void ListaDoble<T>::eliminarPorPlaca(string placa)
{
    if (primero == nullptr)
    {
        cout << "La lista está vacía." << endl;
        return;
    }

    Nodo<T> *aux = primero;
    while (aux != nullptr)
    {
        if (aux->getDato().getPlaca() == placa)
        {
            if (aux == primero)
            {
                primero = primero->getSiguiente();
                if (primero != nullptr)
                {
                    primero->setAnterior(nullptr);
                }
                else
                {
                    ultimo = nullptr;
                }
            }
            else if (aux == ultimo)
            {
                ultimo = ultimo->getAnterior();
                if (ultimo != nullptr)
                {
                    ultimo->setSiguiente(nullptr);
                }
                else
                {
                    primero = nullptr;
                }
            }
            else
            {
                Nodo<T> *anterior = aux->getAnterior();
                Nodo<T> *siguiente = aux->getSiguiente();
                anterior->setSiguiente(siguiente);
                siguiente->setAnterior(anterior);
            }

            delete aux;
            cout << "El coche con la placa " << placa << " ha sido eliminado." << endl;
            GuardarArchivo("autos.txt");
            return;
        }

        aux = aux->getSiguiente();
    }

    cout << "El coche con la placa " << placa << " no se encontró en el parqueadero." << endl;
}

template <typename T>
void ListaDoble<T>::BusquedaAvanzada(string criterio, string valorInicio, string valorFin)
{
    if (primero == nullptr)
    {
        cout << "La lista está vacía." << endl;
        return;
    }

    if (criterio != "hora")
    {
        transform(valorInicio.begin(), valorInicio.end(), valorInicio.begin(), ::tolower);
    }

    Nodo<T> *aux = primero;
    bool encontrado = false;

    while (aux != nullptr)
    {
        if (criterio == "marca")
        {
            string marca = aux->getDato().getMarca();
            transform(marca.begin(), marca.end(), marca.begin(), ::tolower);
            if (marca == valorInicio)
            {
                cout << "========================================" << endl;
                cout << "   AUTOMOVIL REGISTRADO POR MARCA" << endl;
                cout << "========================================" << endl;
                cout << aux->getDato() << endl;
                encontrado = true;
            }
        }
        else if (criterio == "modelo")
        {
            string modelo = aux->getDato().getModelo();
            transform(modelo.begin(), modelo.end(), modelo.begin(), ::tolower);
            if (modelo == valorInicio)
            {
                cout << "========================================" << endl;
                cout << "   AUTOMOVIL REGISTRADO POR MODELO" << endl;
                cout << "========================================" << endl;
                cout << aux->getDato() << endl;
                encontrado = true;
            }
        }
        else if (criterio == "color")
        {
            string color = aux->getDato().getColor();
            transform(color.begin(), color.end(), color.begin(), ::tolower);
            if (color == valorInicio)
            {
                cout << "========================================" << endl;
                cout << "   AUTOMOVIL REGISTRADO POR COLOR" << endl;
                cout << "========================================" << endl;
                cout << aux->getDato() << endl;
                encontrado = true;
            }
        }
        else if (criterio == "hora")
        {
            chrono::system_clock::time_point horaIngreso = aux->getDato().getHora();
            time_t tiempo = chrono::system_clock::to_time_t(horaIngreso);
            tm *tm = localtime(&tiempo);

            char horaActual[9];
            strftime(horaActual, sizeof(horaActual), "%H:%M:%S", tm);

            auto estaEnIntervalo = [&valorInicio, &valorFin, &horaActual]()
            {
                return valorInicio <= horaActual && horaActual <= valorFin;
            };

            if (estaEnIntervalo())
            {
                cout << "========================================" << endl;
                cout << "   AUTOMOVIL REGISTRADO POR HORA" << endl;
                cout << "========================================" << endl;
                cout << aux->getDato() << endl;
                encontrado = true;
            }
        }

        aux = aux->getSiguiente();
    }

    if (!encontrado)
    {
        cout << "No se encontró ningún automóvil con el criterio de búsqueda: " << criterio << endl;
    }
}

template <typename T>
void ListaDoble<T>::GuardarArchivo(std::string nombreArchivo) {
    std::ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << ". Creando archivo nuevo..." << std::endl;
        std::ofstream nuevoArchivo(nombreArchivo);
        if (!nuevoArchivo.is_open()) {
            std::cerr << "Error: No se pudo crear el archivo " << nombreArchivo << std::endl;
            return;
        }
        nuevoArchivo.close();
        return;
    }

    Nodo<T> *actual = primero;
    while (actual != nullptr) {
        T coche = actual->getDato();

        std::string placaCifrada = cifrarTexto(coche.getPlaca());
        auto horaIngreso = coche.getHora();
        std::time_t horaIngresoTime = std::chrono::system_clock::to_time_t(horaIngreso);
        std::tm tmHoraIngreso = *std::localtime(&horaIngresoTime);

        auto horaSalida = coche.getHoraSalida();
        std::ostringstream horaSalidaStream;

        if (horaSalida != std::chrono::system_clock::time_point()) {
            std::time_t horaSalidaTime = std::chrono::system_clock::to_time_t(horaSalida);
            std::tm tmHoraSalida = *std::localtime(&horaSalidaTime);
            horaSalidaStream << std::put_time(&tmHoraSalida, "%a %b %d %H:%M:%S %Y");
        } else {
            horaSalidaStream << "N/A";
        }

        archivo << placaCifrada << ","
                << coche.getModelo() << ","
                << coche.getColor() << ","
                << coche.getMarca() << ","
                << std::put_time(&tmHoraIngreso, "%a %b %d %H:%M:%S %Y") << ","
                << horaSalidaStream.str() << std::endl;

        actual = actual->getSiguiente();
    }

    archivo.close();
}

template <typename T>
void ListaDoble<T>::CargarArchivo(std::string nombreArchivo) {
    std::ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << ". Creando archivo vacío..." << std::endl;
        std::ofstream nuevoArchivo(nombreArchivo);
        if (!nuevoArchivo.is_open()) {
            std::cerr << "Error: No se pudo crear el archivo " << nombreArchivo << std::endl;
            return;
        }
        nuevoArchivo.close();
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream ss(linea);
        std::string placa, modelo, color, marca, fechaIngreso, horaSalida;

        if (std::getline(ss, placa, ',') &&
            std::getline(ss, modelo, ',') &&
            std::getline(ss, color, ',') &&
            std::getline(ss, marca, ',') &&
            std::getline(ss, fechaIngreso, ',') &&
            std::getline(ss, horaSalida, ',')) {
            placa = descifrarTexto(placa);

            std::tm tm = {};
            std::istringstream ssFecha(fechaIngreso);
            ssFecha >> std::get_time(&tm, "%a %b %d %H:%M:%S %Y");
            if (ssFecha.fail()) {
                std::cerr << "Error en el formato de la fecha de ingreso: " << fechaIngreso << std::endl;
                continue;
            }
            auto horaIngreso = std::chrono::system_clock::from_time_t(std::mktime(&tm));

            std::chrono::system_clock::time_point horaSalidaParsed;
            if (horaSalida == "N/A" || horaSalida.empty()) {
                horaSalidaParsed = std::chrono::system_clock::time_point();
            } else {
                std::tm tmSalida = {};
                std::istringstream ssHoraSalida(horaSalida);
                ssHoraSalida >> std::get_time(&tmSalida, "%a %b %d %H:%M:%S %Y");
                if (ssHoraSalida.fail()) {
                    std::cerr << "Error en el formato de la hora de salida: " << horaSalida << std::endl;
                    horaSalidaParsed = std::chrono::system_clock::time_point();
                } else {
                    horaSalidaParsed = std::chrono::system_clock::from_time_t(std::mktime(&tmSalida));
                }
            }

            Propietario propietario("Desconocido", "Desconocido", "0000000000", "desconocido@correo.com");
            T coche(placa, modelo, color, marca, horaIngreso, horaSalidaParsed, propietario);

            this->insertar(coche, nombreArchivo);
        } else {
            std::cerr << "Error: Formato de línea inválido: " << linea << std::endl;
        }
    }

    archivo.close();
}

template <typename T>
std::string ListaDoble<T>::cifrarTexto(const std::string &texto) {
    std::string textoCifrado = texto;

    for (char &c : textoCifrado) {
        if (isdigit(c)) {
            c = ((c - '0' + 2) % 10) + '0';
        } else if (isalpha(c)) {
            if (isupper(c)) {
                c = ((c - 'A' + 2) % 26) + 'A';
            } else {
                c = ((c - 'a' + 2) % 26) + 'a';
            }
        }
    }

    return textoCifrado;
}

template <typename T>
std::string ListaDoble<T>::descifrarTexto(const std::string &texto) {
    std::string textoDescifrado = texto;

    for (char &c : textoDescifrado) {
        if (isdigit(c)) {
            c = ((c - '0' - 2 + 10) % 10) + '0';
        } else if (isalpha(c)) {
            if (isupper(c)) {
                c = ((c - 'A' - 2 + 26) % 26) + 'A';
            } else {
                c = ((c - 'a' - 2 + 26) % 26) + 'a';
            }
        }
    }

    return textoDescifrado;
}

template <typename T>
void ListaDoble<T>::salirDelParqueadero(const std::string &placa) {
    Nodo<T> *actual = primero;
    bool encontrado = false;

    while (actual != nullptr) {
        T coche = actual->getDato();

        if (coche.getPlaca() == placa) {
            if (coche.getHoraSalida() != std::chrono::system_clock::time_point()) {
                actual = actual->getSiguiente();
                continue;
            }

            auto ahora = std::chrono::system_clock::now();
            coche.setHoraSalida(ahora);
            actual->setDato(coche);

            std::cout << "El coche con placa " << placa << " ha salido del parqueadero." << std::endl;
            encontrado = true;
        }

        actual = actual->getSiguiente();
    }

    if (encontrado) {
        GuardarArchivo("autos_historial.txt");
    } else {
        std::cerr << "Coche con placa " << placa << " no encontrado en el parqueadero." << std::endl;
    }
}
