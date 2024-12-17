#include "RegistroHistorial.h"
#include <fstream>
#include <iostream>
#include <ctime>

RegistroHistorial::RegistroHistorial(const std::string& rutaArchivo)
    : rutaArchivo(rutaArchivo) {}

// Método para obtener la fecha y hora actual
std::string RegistroHistorial::obtenerFechaHoraActual() const {
    time_t now = time(0);
    tm* tiempoLocal = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tiempoLocal);
    return std::string(buffer);
}

// Registrar un evento en el archivo
void RegistroHistorial::registrarEvento(const std::string& placa, const std::string& accion) {
    std::ofstream archivo(rutaArchivo, std::ios::app);
    if (!archivo.is_open()) {
        std::cerr << "\nError al abrir el archivo de historial: " << rutaArchivo << std::endl;
        return;
    }
    archivo << obtenerFechaHoraActual() << " - " << accion << " - Placa: " << placa << '\n';
    archivo.close();
}

// Mostrar el historial completo
void RegistroHistorial::mostrarHistorial() const {
    std::ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        std::cerr << "\nNo se pudo abrir el archivo de historial: " << rutaArchivo << std::endl;
        return;
    }
    std::string linea;
    while (getline(archivo, linea)) {
        std::cout << linea << '\n';
    }
    archivo.close();
}

void RegistroHistorial::mostrarHistorialPorFecha(const std::string& fecha) const {
    std::ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        std::cerr << "\nNo se pudo abrir el archivo de historial: " << rutaArchivo << std::endl;
        return;
    }
    std::string linea;
    bool encontrado = false;
    while (getline(archivo, linea)) {
        if (linea.find(fecha) != std::string::npos) {
            std::cout << linea << '\n';
            encontrado = true;
        }
    }
    if (!encontrado) {
        std::cout << "No se encontraron registros para la fecha " << fecha << ".\n";
    }
    archivo.close();
}

void RegistroHistorial::mostrarHistorialPorPlacaYFecha(const std::string& placa, const std::string& fecha) const {
    std::ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        std::cerr << "\nNo se pudo abrir el archivo de historial: " << rutaArchivo << std::endl;
        return;
    }
    std::string linea;
    bool encontrado = false;
    while (getline(archivo, linea)) {
        if (linea.find(fecha) != std::string::npos && linea.find("Placa: " + placa) != std::string::npos) {
            std::cout << linea << '\n';
            encontrado = true;
        }
    }
    if (!encontrado) {
        std::cout << "No se encontraron registros para la placa " << placa << " en la fecha " << fecha << ".\n";
    }
    archivo.close();
}

