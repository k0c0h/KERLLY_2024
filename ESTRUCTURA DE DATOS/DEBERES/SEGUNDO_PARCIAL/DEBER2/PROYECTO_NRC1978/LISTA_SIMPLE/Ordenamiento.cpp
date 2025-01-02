#include <iostream>
#include <vector>
#include <algorithm>
#include "Coche.h"
#include <functional>

template <typename T, typename Comparator>
int partition(std::vector<T>& lista, int low, int high, Comparator comp) {
    T pivot = lista[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (comp(lista[j], pivot)) {
            i++;
            std::swap(lista[i], lista[j]);
        }
    }
    std::swap(lista[i + 1], lista[high]);
    return i + 1;
}

template <typename T, typename Comparator>
void quickSort(std::vector<T>& lista, int low, int high, Comparator comp) {
    if (low < high) {
        int pi = partition(lista, low, high, comp);
        quickSort(lista, low, pi - 1, comp);
        quickSort(lista, pi + 1, high, comp);
    }
}

template <typename T, typename Comparator>
void bubbleSortPass(std::vector<T>& lista, Comparator comp, int n) {
    // Función auxiliar que realiza una pasada completa de intercambios
    if (n <= 1) return;

    for (int j = 0; j < n - 1; j++) {
        if (!comp(lista[j], lista[j + 1])) {
            std::swap(lista[j], lista[j + 1]);
        }
    }
}

template <typename T, typename Comparator>
void bubbleSortRecursive(std::vector<T>& lista, Comparator comp, int n) {
    // Función recursiva principal
    if (n <= 1) return;
    // Realizar una pasada completa de intercambios
    bubbleSortPass(lista, comp, n);
    // Llamada recursiva con un rango reducido
    bubbleSortRecursive(lista, comp, n - 1);
}

// Función wrapper para iniciar el ordenamiento
template <typename T, typename Comparator>
void bubbleSort(std::vector<T>& lista, Comparator comp) {
    bubbleSortRecursive(lista, comp, lista.size());
}

template <typename T, typename Comparator>
void ordenarLista(ListaSimple<T>& lista, Comparator comp) {
    std::vector<T> elementos;

    // Extraer los elementos de la lista simplemente enlazada
    Nodo<T>* aux = lista.getPrimero();
    while (aux != nullptr) {
        elementos.push_back(aux->getDato());
        aux = aux->getSiguiente();
    }

    // Ordenar los elementos usando QuickSort
    quickSort(elementos, 0, elementos.size() - 1, comp);

    // Volver a insertar los elementos ordenados en la lista
    aux = lista.getPrimero();
    int index = 0;
    while (aux != nullptr) {
        aux->setDato(elementos[index++]);
        aux = aux->getSiguiente();
    }

    // Mostrar la lista ordenada
    lista.mostrar(lista.getPrimero());
}

template <typename T, typename Comparator>
void ordenarListaBubbleSort(ListaSimple<T>& lista, Comparator comp) {
    std::vector<T> elementos;

    // Extraer los elementos de la lista
    Nodo<T>* aux = lista.getPrimero();
    while (aux != nullptr) {
        elementos.push_back(aux->getDato());
        aux = aux->getSiguiente();
    }

    // Ordenar usando Bubble Sort
    bubbleSort(elementos, comp);

    // Volver a insertar los elementos ordenados en la lista
    aux = lista.getPrimero();
    int index = 0;
    while (aux != nullptr) {
        aux->setDato(elementos[index++]);
        aux = aux->getSiguiente();
    }

    lista.mostrar(lista.getPrimero());
}

template <typename T>
void ordenarListaBucket(ListaSimple<T>& lista, std::function<std::string(const T&)> getKey) {
    std::vector<T> elementos;

    // Extraer los elementos de la lista simplemente enlazada
    Nodo<T>* aux = lista.getPrimero();
    while (aux != nullptr) {
        elementos.push_back(aux->getDato());
        aux = aux->getSiguiente();
    }

    // Determinar el número de buckets (256 para cubrir caracteres ASCII)
    const int bucketCount = 256;
    std::vector<std::vector<T>> buckets(bucketCount);

    // Distribuir los elementos en los buckets
    for (const auto& item : elementos) {
        std::string key = getKey(item);
        if (!key.empty()) {
            char firstChar = tolower(key[0]); // Usar el primer carácter de la clave
            int bucketIndex = static_cast<int>(firstChar);
            buckets[bucketIndex].push_back(item);
        }
    }

    // Limpiar el vector de elementos
    elementos.clear();

    // Ordenar cada bucket y volver a insertar en el vector de elementos
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end(), [&getKey](const T& a, const T& b) {
            return getKey(a) < getKey(b); // Usar la clave para ordenar
        });
        elementos.insert(elementos.end(), bucket.begin(), bucket.end());
    }

    // Volver a insertar los elementos ordenados en la lista simplemente enlazada
    aux = lista.getPrimero();
    int index = 0;
    while (aux != nullptr) {
        aux->setDato(elementos[index++]);
        aux = aux->getSiguiente();
    }

    // Mostrar la lista ordenada
    lista.mostrar(lista.getPrimero());
}

template <typename T, typename Comparator>
void ordenarListaShellSort(ListaSimple<T>& lista, Comparator comp) {
    std::vector<T> elementos;

    // Extraer los elementos de la lista
    Nodo<T>* aux = lista.getPrimero();
    while (aux != nullptr) {
        elementos.push_back(aux->getDato());
        aux = aux->getSiguiente();
    }

    // Ordenar usando Shell Sort
    auto shellSort = [&](std::vector<T>& elementos) {
        int n = elementos.size();
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                T temp = elementos[i];
                int j = i;
                while (j >= gap && comp(temp, elementos[j - gap])) {
                    elementos[j] = elementos[j - gap];
                    j -= gap;
                }
                elementos[j] = temp;
            }
        }
    };

    shellSort(elementos);

    // Volver a insertar los elementos ordenados
    aux = lista.getPrimero();
    int index = 0;
    while (aux != nullptr) {
        aux->setDato(elementos[index++]);
        aux = aux->getSiguiente();
    }

    lista.mostrar(lista.getPrimero());
}

template <typename T, typename KeyExtractor>
void radixSortByString(std::vector<T>& elementos, KeyExtractor getKey) {
    int maxLength = 0;
    for (const auto& item : elementos) {
        int length = static_cast<int>(getKey(item).length());
        maxLength = std::max(maxLength, length);
    }

    for (int i = maxLength - 1; i >= 0; i--) {
        std::vector<std::vector<T>> buckets(256);
        for (const auto& item : elementos) {
            std::string key = getKey(item);
            int charIndex = static_cast<int>(key.length()) - 1 - i;
            int charValue = (charIndex >= 0) ? static_cast<int>(key[charIndex]) : 0;
            buckets[charValue].push_back(item);
        }

        elementos.clear();
        for (auto& bucket : buckets) {
            for (const auto& item : bucket) {
                elementos.push_back(item);
            }
        }
    }
}

template <typename T, typename KeyExtractor>
void radixSortByInt(std::vector<T>& elementos, KeyExtractor getKey) {
    int maxValue = 0;
    for (const auto& item : elementos) {
        int value = getKey(item);
        maxValue = std::max(maxValue, value);
    }

    for (int exp = 1; maxValue / exp > 0; exp *= 10) {
        std::vector<std::vector<T>> buckets(10);
        for (const auto& item : elementos) {
            int digit = (getKey(item) / exp) % 10;
            buckets[digit].push_back(item);
        }

        elementos.clear();
        for (auto& bucket : buckets) {
            for (const auto& item : bucket) {
                elementos.push_back(item);
            }
        }
    }
}


template <typename T, typename KeyExtractor>
void ordenarListaPorRadix(ListaSimple<T>& lista, KeyExtractor getKey) {
    std::vector<T> elementos;

    // Extraer los elementos de la lista
    Nodo<T>* aux = lista.getPrimero();
    while (aux != nullptr) {
        elementos.push_back(aux->getDato());
        aux = aux->getSiguiente();
    }

    // Determinar si se ordena por cadena o entero
    using KeyType = typename std::invoke_result<KeyExtractor, T>::type;
    if constexpr (std::is_same<KeyType, std::string>::value) {
        radixSortByString(elementos, getKey);
    } else if constexpr (std::is_integral<KeyType>::value) {
        radixSortByInt(elementos, getKey);
    } else {
        static_assert(false, "El tipo de clave no es compatible con Radix Sort");
    }

    // Volver a insertar los elementos ordenados
    aux = lista.getPrimero();
    int index = 0;
    while (aux != nullptr) {
        aux->setDato(elementos[index++]);
        aux = aux->getSiguiente();
    }

    lista.mostrar(lista.getPrimero());
}
