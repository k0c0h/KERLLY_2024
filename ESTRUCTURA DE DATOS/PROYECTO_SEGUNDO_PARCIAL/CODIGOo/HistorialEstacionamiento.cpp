/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Proyecto Primer Parcial                             *
 * Autor:                          Kerlly Chiriboga,Heidy Mera                         *
 * Fecha de creacion:              06/12/2024                                          *
 * Fecha de modificacion:          06/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#include "HistorialEstacionamiento.h"
#include <algorithm> // Para std::copy_if
#include <vector>
#include <string>
#include <iostream>


// Constructor: carga el historial desde el archivo
HistorialEstacionamiento::HistorialEstacionamiento() {
    cargarDesdeArchivo();
}

// Obtener la fecha y hora actual como string
string HistorialEstacionamiento::obtenerFechaHoraActual() const {
    time_t now = time(nullptr);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buffer);
}

// Cargar historial desde el archivo
void HistorialEstacionamiento::cargarDesdeArchivo() {
    ifstream archivoEntrada(archivoHistorial);
    if (!archivoEntrada.is_open()) {
        cerr << "No se pudo abrir el archivo " << archivoHistorial << ". Creando uno nuevo." << endl;
        return;
    }

    string linea;
    while (getline(archivoEntrada, linea)) {
        stringstream ss(linea);
        string placa, espacioId, fechaHoraIngreso, fechaHoraSalida;

        getline(ss, placa, ',');
        getline(ss, espacioId, ',');
        getline(ss, fechaHoraIngreso, ',');
        getline(ss, fechaHoraSalida, ',');

        historial.emplace_back(placa, espacioId, fechaHoraIngreso, fechaHoraSalida);
    }
    archivoEntrada.close();
}

// Guardar historial en el archivo
void HistorialEstacionamiento::guardarEnArchivo() {
    ofstream archivoSalida(archivoHistorial, ios::trunc);
    if (!archivoSalida.is_open()) {
        cerr << "Error al abrir el archivo " << archivoHistorial << " para guardar." << endl;
        return;
    }

    for (const auto& registro : historial) {
        archivoSalida << registro.placa << ","
                      << registro.espacioId << ","
                      << registro.fechaHoraIngreso << ","
                      << registro.fechaHoraSalida << "\n";
    }
    archivoSalida.close();
}

// Registrar la entrada de un auto
void HistorialEstacionamiento::registrarEntrada(const string& placa, const string& espacioId) {
    string fechaHora = obtenerFechaHoraActual();
    historial.emplace_back(placa, espacioId, fechaHora);
    guardarEnArchivo();
    cout << "Entrada registrada: Placa " << placa << ", Espacio " << espacioId 
         << ", Fecha/Hora: " << fechaHora << endl;
}

// Registrar la salida de un auto
void HistorialEstacionamiento::registrarSalida(const string& placa) {
    for (auto& registro : historial) {
        if (registro.placa == placa && registro.fechaHoraSalida.empty()) {
            registro.fechaHoraSalida = obtenerFechaHoraActual();
            guardarEnArchivo();
            cout << "Salida registrada: Placa " << placa 
                 << ", Fecha/Hora Salida: " << registro.fechaHoraSalida << endl;
            return;
        }
    }
    cout << "No se encontro una entrada activa para la placa " << placa << "." << endl;
}

// Mostrar todo el historial
void HistorialEstacionamiento::mostrarHistorial() const {
    if (historial.empty()) {
        cout << "No hay registros en el historial." << endl;
        return;
    }

    cout << "Historial de Estacionamiento:\n";
    for (const auto& registro : historial) {
        cout << "Placa: " << registro.placa 
             << ", Espacio: " << registro.espacioId 
             << ", Ingreso: " << registro.fechaHoraIngreso 
             << ", Salida: " << (registro.fechaHoraSalida.empty() ? "Aun en el parqueadero" : registro.fechaHoraSalida)
             << endl;
    }
}

void HistorialEstacionamiento::mostrarHistorialPorFecha(const string& fecha) const {
    bool encontrado = false;
    cout << "Historial de estacionamiento para la fecha: " << fecha << "\n";
    cout << "------------------------------------------------------\n";

    for (const auto& registro : historial) {
        if (registro.fechaHoraIngreso.substr(0, 10) == fecha) { // Compara la parte de la fecha (YYYY-MM-DD)
            cout << "Placa: " << registro.placa 
                 << ", Espacio: " << registro.espacioId 
                 << ", Ingreso: " << registro.fechaHoraIngreso 
                 << ", Salida: " << (registro.fechaHoraSalida.empty() ? "Aun en el parqueadero" : registro.fechaHoraSalida) 
                 << "\n";
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron registros para la fecha: " << fecha << ".\n";
    }
}
void HistorialEstacionamiento::mostrarHistorialPorFechaYPlaca(const string& fecha, const string& placa) const {
    bool encontrado = false;
    cout << "Historial de estacionamiento para la placa: " << placa 
         << " y fecha: " << fecha << "\n";
    cout << "------------------------------------------------------\n";

    for (const auto& registro : historial) {
        if (registro.placa == placa && registro.fechaHoraIngreso.substr(0, 10) == fecha) {
            cout << "Placa: " << registro.placa 
                 << ", Espacio: " << registro.espacioId 
                 << ", Ingreso: " << registro.fechaHoraIngreso 
                 << ", Salida: " << (registro.fechaHoraSalida.empty() ? "Aun en el parqueadero" : registro.fechaHoraSalida) 
                 << "\n";
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron registros para la placa: " << placa 
             << " en la fecha: " << fecha << ".\n";
    }
}

// Buscar historial por placa
string HistorialEstacionamiento::buscarHistorial(const string& placa) const {
    string resultado;
    cout << "Buscando historial para la placa: " << placa << endl;
    for (const auto& registro : historial) {
        if (registro.placa == placa) {
            resultado += "Placa: " + registro.placa 
                       + ", Espacio: " + registro.espacioId 
                       + ", Ingreso: " + registro.fechaHoraIngreso 
                       + ", Salida: " + (registro.fechaHoraSalida.empty() ? "Aun en el parqueadero" : registro.fechaHoraSalida) 
                       + "\n";
        }
    }
    return resultado.empty() ? "No se encontro historial para la placa " + placa : resultado;
}

void HistorialEstacionamiento::mostrarHistorialPorRangoHoras(const string& horaInicio, const string& horaFin) const {
    vector<RegistroHistorial> resultados;

    // Filtrar registros por rango de hora
    copy_if(historial.begin(), historial.end(), back_inserter(resultados), [&](const RegistroHistorial& registro) {
        // Extraer la hora de ingreso y salida
        string horaIngreso = registro.fechaHoraIngreso.substr(11, 8); // Extraer solo la hora
        string horaSalida = registro.fechaHoraSalida.empty() ? "" : registro.fechaHoraSalida.substr(11, 8);   // Extraer solo la hora, con control de vacío

        // Compara las horas de ingreso y salida con el rango
        return (horaIngreso >= horaInicio && horaIngreso <= horaFin) ||
               (!horaSalida.empty() && horaSalida >= horaInicio && horaSalida <= horaFin); // Evitar comparar horaSalida vacía
    });

    if (resultados.empty()) {
        cout << "No se encontraron registros en el rango de tiempo especificado." << endl;
        return;
    }

    for (const auto& registro : resultados) {
        cout << "Placa: " << registro.placa
             << ", Espacio: " << registro.espacioId
             << ", Ingreso: " << registro.fechaHoraIngreso
             << ", Salida: " << (registro.fechaHoraSalida.empty() ? "Aun en el parqueadero" : registro.fechaHoraSalida)
             << endl;
    }
}

void HistorialEstacionamiento::mostrarPrimerIngresoPorFecha(const string& fecha) const {
    vector<RegistroHistorial> resultados;

    // Filtrar los registros por fecha de ingreso
    copy_if(historial.begin(), historial.end(), back_inserter(resultados), [&](const RegistroHistorial& historialItem) {
        // Extraer solo la fecha de ingreso (formato: YYYY-MM-DD)
        string fechaIngreso = historialItem.fechaHoraIngreso.substr(0, 10); // Extraer solo la fecha (primeros 10 caracteres)

        // Comparar si la fecha de ingreso es igual a la fecha solicitada
        return fechaIngreso == fecha;
    });

    if (resultados.empty()) {
        cout << "No se encontraron registros para la fecha " << fecha << "." << endl;
        return;
    }

    // Asumiendo que los registros ya están ordenados por fecha y hora de ingreso
    cout << "Primer ingreso del dia " << fecha << ":\n";
    const auto& primerIngreso = resultados.front();  // Obtener el primer ingreso

    // Extraer la fecha y hora de salida, si está disponible
    string salida = primerIngreso.fechaHoraSalida.empty() ? "Aun en el parqueadero" : primerIngreso.fechaHoraSalida;

    // Mostrar detalles del primer ingreso y salida
    cout << "Placa: " << primerIngreso.placa
         << ", Espacio: " << primerIngreso.espacioId
         << ", Ingreso: " << primerIngreso.fechaHoraIngreso
         << ", Salida: " << salida << endl;
}

void HistorialEstacionamiento::mostrarAutosPorRangoFechas(const string& fechaInicio, const string& fechaFin) const {
    vector<RegistroHistorial> resultados;

    // Filtrar los registros por rango de fecha de ingreso
    copy_if(historial.begin(), historial.end(), back_inserter(resultados), [&](const RegistroHistorial& historialItem) {
        // Extraer solo la fecha de ingreso (formato: YYYY-MM-DD)
        string fechaIngreso = historialItem.fechaHoraIngreso.substr(0, 10); // Extraer solo la fecha (primeros 10 caracteres)

        // Comparar si la fecha de ingreso está dentro del rango solicitado
        return fechaIngreso >= fechaInicio && fechaIngreso <= fechaFin;
    });

    if (resultados.empty()) {
        cout << "No se encontraron registros entre las fechas " << fechaInicio << " y " << fechaFin << "." << endl;
        return;
    }

    // Asumimos que los registros ya están ordenados por fecha y hora de ingreso
    cout << "Autos ingresados entre el " << fechaInicio << " y el " << fechaFin << ":\n";
    for (const auto& registro : resultados) {
        // Extraer la fecha y hora de salida, si está disponible
        string salida = registro.fechaHoraSalida.empty() ? "Aun en el parqueadero" : registro.fechaHoraSalida;

        // Mostrar los detalles de cada auto en el rango de fechas
        cout << "Placa: " << registro.placa
             << ", Espacio: " << registro.espacioId
             << ", Ingreso: " << registro.fechaHoraIngreso
             << ", Salida: " << salida << endl;
    }
}






