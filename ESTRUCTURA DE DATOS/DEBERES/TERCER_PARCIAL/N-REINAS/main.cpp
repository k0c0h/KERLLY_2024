#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>
#include <filesystem> // Para manejar directorios

using namespace std;
namespace fs = filesystem; // Alias para filesystem

int procesoCount = 0;
string carpetaCapturas; // Variable para la carpeta donde se guardarán las imágenes

bool esSeguro(const vector<vector<int>>& tablero, int fila, int columna, int n) {
    for (int i = 0; i < fila; i++) {
        if (tablero[i][columna] == 1 || 
            (columna - (fila - i)) >= 0 && tablero[i][columna - (fila - i)] == 1 ||
            (columna + (fila - i)) < n && tablero[i][columna + (fila - i)] == 1)
            return false;
    }
    return true;
}

// Función para guardar la imagen en la carpeta
void guardarImagen(const sf::RenderWindow& ventana) {
    sf::Image imagen = ventana.capture();
    string nombreArchivo = carpetaCapturas + "/paso_" + to_string(procesoCount) + ".png";
    imagen.saveToFile(nombreArchivo);
}

sf::Texture procesarReina(const sf::Texture& reinaTextura, sf::Color colorFondo) {
    sf::Image imagen = reinaTextura.copyToImage();

    // Recorrer cada píxel y ajustar el color
    for (unsigned int x = 0; x < imagen.getSize().x; x++) {
        for (unsigned int y = 0; y < imagen.getSize().y; y++) {
            sf::Color pixel = imagen.getPixel(x, y);
            if (pixel.a < 200 || (pixel.r > 200 && pixel.g > 200 && pixel.b > 200)) { 
                imagen.setPixel(x, y, colorFondo); 
            }            
        }
    }

    // Crear nueva textura con la imagen modificada
    sf::Texture nuevaTextura;
    nuevaTextura.loadFromImage(imagen);
    return nuevaTextura;
}

// Función para dibujar el tablero y las reinas
void dibujarTablero(sf::RenderWindow& ventana, const vector<vector<int>>& tablero, int n, const sf::Texture& reinaTextura) {
    ventana.clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sf::RectangleShape cuadrado(sf::Vector2f(50, 50));
            cuadrado.setPosition(j * 50, i * 50);
            sf::Color colorCasilla = (i + j) % 2 == 0 ? sf::Color::White : sf::Color::Black;
            cuadrado.setFillColor(colorCasilla);
            ventana.draw(cuadrado);

            if (tablero[i][j] == 1) {
                sf::Texture reinaModificada = procesarReina(reinaTextura, colorCasilla);
                sf::Sprite reinaSprite(reinaModificada);
                reinaSprite.setScale(50.f / reinaTextura.getSize().x, 50.f / reinaTextura.getSize().y);
                reinaSprite.setPosition(j * 50, i * 50);
                ventana.draw(reinaSprite);
            }
        }
    }
    ventana.display();
}

// Algoritmo para resolver el problema de las N-Reinas
bool resolverReinas(vector<vector<int>>& tablero, int fila, int n, sf::RenderWindow& ventana, const sf::Texture& reinaTextura) {
    if (fila == n) return true;
    for (int columna = 0; columna < n; columna++) {
        procesoCount++;
        if (esSeguro(tablero, fila, columna, n)) {
            tablero[fila][columna] = 1;
            dibujarTablero(ventana, tablero, n, reinaTextura);
            guardarImagen(ventana);
            if (resolverReinas(tablero, fila + 1, n, ventana, reinaTextura)) return true;
            tablero[fila][columna] = 0;
            dibujarTablero(ventana, tablero, n, reinaTextura);
        }
    }
    return false;
}

sf::Sprite crearReinaConFondo(const sf::Texture& reinaTextura, sf::Color colorFondo) {
    sf::RenderTexture renderTexture;
    renderTexture.create(50, 50); // Tamaño de la casilla

    // Dibujar el fondo
    sf::RectangleShape fondo(sf::Vector2f(50, 50));
    fondo.setFillColor(colorFondo);
    renderTexture.draw(fondo);

    // Dibujar la reina sobre el fondo
    sf::Sprite reinaSprite(reinaTextura);
    reinaSprite.setScale(50.f / reinaTextura.getSize().x, 50.f / reinaTextura.getSize().y);
    renderTexture.draw(reinaSprite);

    // Guardar la textura con el fondo
    renderTexture.display();
    
    // Devolver el sprite con la nueva textura
    sf::Sprite resultado(renderTexture.getTexture());
    return resultado;
}


int main() {
    int n;
    cout << "Ingrese el tamaño del tablero (N): ";
    cin >> n;

    // Definir la carpeta de almacenamiento
    carpetaCapturas = "Capturas_" + to_string(n) + "_Reinas";
    fs::create_directory(carpetaCapturas); // Crear la carpeta si no existe

    vector<vector<int>> tablero(n, vector<int>(n, 0));
    sf::Texture reinaTextura;
    if (!reinaTextura.loadFromFile("reina.png")) {
        cout << "Error al cargar la imagen de la reina." << endl;
        return -1;
    }

    sf::RenderWindow ventana(sf::VideoMode(n * 50, n * 50), "Problema de las N-Reinas");

    clock_t inicio = clock();
    if (resolverReinas(tablero, 0, n, ventana, reinaTextura)) {
        cout << "Solución encontrada. Procesos realizados: " << procesoCount << endl;
    } else {
        cout << "No hay solución para el problema de las N-Reinas." << endl;
    }
    clock_t fin = clock();
    cout << "Tiempo total de ejecución: " << double(fin - inicio) / CLOCKS_PER_SEC << " segundos." << endl;

    // Mantener la ventana abierta hasta que el usuario la cierre
    while (ventana.isOpen()) {
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                ventana.close();
            }
        }
    }

    return 0;
}
