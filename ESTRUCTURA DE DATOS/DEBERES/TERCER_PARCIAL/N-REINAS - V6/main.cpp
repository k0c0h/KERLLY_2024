#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <ctime>
#include <filesystem>
#include "Validaciones.h"

using namespace std;
namespace fs = filesystem;

int procesoCount = 0;
string carpetaCapturas;

int** crearTablero(int n) {
    int** tablero = new int*[n];
    for (int i = 0; i < n; i++) {
        tablero[i] = new int[n]();
    }
    return tablero;
}

void liberarTablero(int** tablero, int n) {
    for (int i = 0; i < n; i++) {
        delete[] tablero[i];
    }
    delete[] tablero;
}

bool esSeguro(int** tablero, int fila, int columna, int n) {
    for (int i = 0; i < fila; i++) {
        if (*(*(tablero + i) + columna) == 1 || 
            (columna - (fila - i)) >= 0 && *(*(tablero + i) + (columna - (fila - i))) == 1 || 
            (columna + (fila - i)) < n && *(*(tablero + i) + (columna + (fila - i))) == 1) 
            return false;
    }
    return true;
}

void guardarImagen(sf::RenderWindow& ventana) {
    sf::Texture textura;
    textura.create(ventana.getSize().x, ventana.getSize().y);
    textura.update(ventana);
    
    sf::Image imagen = textura.copyToImage();
    string nombreArchivo = carpetaCapturas + "/paso_" + to_string(procesoCount) + ".png";
    
    if (imagen.saveToFile(nombreArchivo)) {
        cout << "Imagen guardada: " << nombreArchivo << endl;
    } else {
        cout << "Error al guardar la imagen." << endl;
    }
}

sf::Texture procesarReina(const sf::Texture& reinaTextura, sf::Color colorFondo) {
    sf::Image imagen = reinaTextura.copyToImage();
    for (unsigned int x = 0; x < imagen.getSize().x; x++) {
        for (unsigned int y = 0; y < imagen.getSize().y; y++) {
            sf::Color pixel = imagen.getPixel(x, y);
            if (pixel.a < 200 || (pixel.r > 200 && pixel.g > 200 && pixel.b > 200)) { 
                imagen.setPixel(x, y, colorFondo); 
            }            
        }
    }

    sf::Texture nuevaTextura;
    nuevaTextura.loadFromImage(imagen);
    return nuevaTextura;
}

// Mantener un vector de posiciones para las reinas
vector<sf::Vector2i> posicionesReinas;

void dibujarTablero(sf::RenderWindow& ventana, int** tablero, int n, const sf::Texture& reinaTextura, const vector<sf::Vector2i>& posicionesReinas) {
    ventana.clear();
    sf::Color colorClaro(222, 184, 135);
    sf::Color colorOscuro(139, 69, 19); 

    // Dibujar las casillas del tablero
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sf::RectangleShape cuadrado(sf::Vector2f(80, 80));
            cuadrado.setPosition(j * 80, i * 80);
            sf::Color colorCasilla = (i + j) % 2 == 0 ? colorClaro : colorOscuro;
            cuadrado.setFillColor(colorCasilla);
            ventana.draw(cuadrado);
        }
    }

    // Dibujar las reinas en las posiciones almacenadas
    for (auto& posicion : posicionesReinas) {
        int x = posicion.x;
        int y = posicion.y;
        sf::Texture reinaModificada = procesarReina(reinaTextura, (x + y) % 2 == 0 ? colorClaro : colorOscuro);
        sf::Sprite reinaSprite(reinaModificada);
        reinaSprite.setScale(80.f / reinaTextura.getSize().x, 80.f / reinaTextura.getSize().y);
        reinaSprite.setPosition(x * 80, y * 80);
        ventana.draw(reinaSprite);

        // Dibujar los puntos en las casillas atacadas por la reina
        sf::CircleShape punto(5); // Radio de 5 para hacer un pequeño punto
        punto.setFillColor(sf::Color::Red); // Color del punto
        // Atacar casillas en la fila y columna de la reina
        for (int i = 0; i < n; i++) {
            if (i != x) {
                punto.setPosition(i * 80 + 35, y * 80 + 35); // Posicionar punto en la casilla
                ventana.draw(punto);
            }
            if (i != y) {
                punto.setPosition(x * 80 + 35, i * 80 + 35); // Posicionar punto en la casilla
                ventana.draw(punto);
            }
        }

        // Atacar casillas en las diagonales
        for (int i = -n; i < n; i++) {
            if (x + i >= 0 && x + i < n && y + i >= 0 && y + i < n && i != 0) {
                punto.setPosition((x + i) * 80 + 35, (y + i) * 80 + 35); // Posicionar punto en la casilla
                ventana.draw(punto);
            }
        }
    }

    ventana.display();
}


int main() {
    Validaciones<int> validador;
    int tamanio;
    do { 
        tamanio = validador.ingresar("Ingrese el tamanio del tablero (N): ", "entero");
        cout << endl;
        if (tamanio < 1 || tamanio > 8) {
            cout << "Por favor, ingrese un valor entre 1 y 8." << endl;
        }
    } while (tamanio < 1 || tamanio > 8);

    carpetaCapturas = "Capturas_" + to_string(tamanio) + "_Reinas";
    fs::create_directory(carpetaCapturas); 

    int** tablero = crearTablero(tamanio);

    sf::Texture reinaTextura;
    if (!reinaTextura.loadFromFile("reina.png")) {
        cout << "Error al cargar la imagen de la reina." << endl;
        return -1;
    }

    sf::RenderWindow ventana(sf::VideoMode(tamanio * 80, tamanio* 80), "Problema de las N-Reinas");

    vector<sf::Vector2i> posicionesReinas; // Mantener las posiciones de las reinas

    while (ventana.isOpen()) {
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                ventana.close();
            }

            if (evento.type == sf::Event::MouseButtonPressed) {
                int x = evento.mouseButton.x / 80;
                int y = evento.mouseButton.y / 80;

                // Borrar la reina de la posición anterior
                if (!posicionesReinas.empty()) {
                    sf::Vector2i ultimaPosicion = posicionesReinas.back();
                    tablero[ultimaPosicion.y][ultimaPosicion.x] = 0; // Limpiar la casilla
                    posicionesReinas.pop_back(); // Eliminar la última reina
                }

                // Colocar la reina en la nueva posición
                posicionesReinas.push_back(sf::Vector2i(x, y)); 
                tablero[y][x] = 1; // Colocar la reina en la casilla
            }
        }

        dibujarTablero(ventana, tablero, tamanio, reinaTextura, posicionesReinas);
    }

    liberarTablero(tablero, tamanio);
    return 0;
}
