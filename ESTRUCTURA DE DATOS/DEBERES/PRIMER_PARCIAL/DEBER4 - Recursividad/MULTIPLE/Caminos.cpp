#include "Caminos.h"

int Caminos::calcularCaminos(int n) {
    return contarCaminos(0, 0, n);  // Inicia la recursividad múltiple desde la posición (0,0)
}

int Caminos::contarCaminos(int x, int y, int n) {
    if (x == n - 1 && y == n - 1) return 1;  // Caso base: si estamos en la esquina inferior derecha
    if (x >= n || y >= n) return 0;  // Si se sale del límite de la malla, no hay camino

    // Recursividad múltiple: cuenta los caminos de dos direcciones posibles
    return contarCaminos(x + 1, y, n) + contarCaminos(x, y + 1, n);  // Se mueven tanto a la derecha como hacia abajo
}
