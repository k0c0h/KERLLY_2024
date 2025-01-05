from typing import List, Callable
from nodo import Nodo  # Para la clase Nodo
from lista import ListaSimple  # Para la clase ListaSimple

class Ordenamiento:
    # QuickSort
    @staticmethod
    def partition(lista: List, low: int, high: int, comp: Callable):
        pivot = lista[high]
        i = low - 1
        for j in range(low, high):
            if comp(lista[j], pivot):
                i += 1
                lista[i], lista[j] = lista[j], lista[i]
        lista[i + 1], lista[high] = lista[high], lista[i + 1]
        return i + 1

    @staticmethod
    def quick_sort(lista: List, low: int, high: int, comp: Callable):
        if low < high:
            pi = Ordenamiento.partition(lista, low, high, comp)
            Ordenamiento.quick_sort(lista, low, pi - 1, comp)
            Ordenamiento.quick_sort(lista, pi + 1, high, comp)

    # BubbleSort
    @staticmethod
    def bubble_sort_pass(lista: List, comp: Callable, n: int):
        if n <= 1:
            return
        for j in range(n - 1):
            if not comp(lista[j], lista[j + 1]):
                lista[j], lista[j + 1] = lista[j + 1], lista[j]

    @staticmethod
    def bubble_sort_recursive(lista: List, comp: Callable, n: int):
        if n <= 1:
            return
        Ordenamiento.bubble_sort_pass(lista, comp, n)
        Ordenamiento.bubble_sort_recursive(lista, comp, n - 1)

    @staticmethod
    def bubble_sort(lista: List, comp: Callable):
        Ordenamiento.bubble_sort_recursive(lista, comp, len(lista))

    # ShellSort
    @staticmethod
    def ordenar_lista_shell_sort(lista: ListaSimple, comp: Callable):
        elementos = []
        aux = lista.get_primero()
        while aux:
            elementos.append(aux.get_dato())
            aux = aux.get_siguiente()

        def shell_sort(elementos: List):
            n = len(elementos)
            gap = n // 2
            while gap > 0:
                for i in range(gap, n):
                    temp = elementos[i]
                    j = i
                    while j >= gap and comp(temp, elementos[j - gap]):
                        elementos[j] = elementos[j - gap]
                        j -= gap
                    elementos[j] = temp
                gap //= 2

        shell_sort(elementos)

        aux = lista.get_primero()
        index = 0
        while aux:
            aux.set_dato(elementos[index])
            aux = aux.get_siguiente()
            index += 1

        lista.mostrar(lista.get_primero())

    # RadixSort
    @staticmethod
    def radix_sort_by_string(elementos: List, get_key: Callable):
        max_length = max(len(get_key(item)) for item in elementos)
        for i in range(max_length - 1, -1, -1):
            buckets = [[] for _ in range(256)]
            for item in elementos:
                key = get_key(item)
                char_index = len(key) - 1 - i
                char_value = ord(key[char_index]) if char_index >= 0 else 0
                buckets[char_value].append(item)

            elementos.clear()
            for bucket in buckets:
                for item in bucket:
                    elementos.append(item)

    @staticmethod
    def radix_sort_by_int(elementos: List, get_key: Callable):
        max_value = max(get_key(item) for item in elementos)
        exp = 1
        while max_value // exp > 0:
            buckets = [[] for _ in range(10)]
            for item in elementos:
                digit = (get_key(item) // exp) % 10
                buckets[digit].append(item)

            elementos.clear()
            for bucket in buckets:
                for item in bucket:
                    elementos.append(item)
            exp *= 10

    @staticmethod
    def ordenar_lista_por_radix(lista: ListaSimple, get_key: Callable):
        elementos = []
        aux = lista.get_primero()
        while aux:
            elementos.append(aux.get_dato())
            aux = aux.get_siguiente()

        key_type = type(get_key(elementos[0]))
        if isinstance(get_key(elementos[0]), str):
            Ordenamiento.radix_sort_by_string(elementos, get_key)
        elif isinstance(get_key(elementos[0]), int):
            Ordenamiento.radix_sort_by_int(elementos, get_key)
        else:
            raise TypeError("El tipo de clave no es compatible con Radix Sort")

        aux = lista.get_primero()
        index = 0
        while aux:
            aux.set_dato(elementos[index])
            aux = aux.get_siguiente()
            index += 1

        lista.mostrar(lista.get_primero())

    # Ordenar usando QuickSort
    @staticmethod
    def ordenar_lista(lista: ListaSimple, comp: Callable):
        elementos = []
        aux = lista.get_primero()
        while aux:
            elementos.append(aux.get_dato())
            aux = aux.get_siguiente()

        Ordenamiento.quick_sort(elementos, 0, len(elementos) - 1, comp)

        aux = lista.get_primero()
        index = 0
        while aux:
            aux.set_dato(elementos[index])
            aux = aux.get_siguiente()
            index += 1

        lista.mostrar(lista.get_primero())

    # Ordenar usando BubbleSort
    @staticmethod
    def ordenar_lista_bubble_sort(lista: ListaSimple, comp: Callable):
        elementos = []
        aux = lista.get_primero()
        while aux:
            elementos.append(aux.get_dato())
            aux = aux.get_siguiente()

        Ordenamiento.bubble_sort(elementos, comp)

        aux = lista.get_primero()
        index = 0
        while aux:
            aux.set_dato(elementos[index])
            aux = aux.get_siguiente()
            index += 1

        lista.mostrar(lista.get_primero())

    # Ordenar usando Bucket Sort
    @staticmethod
    def ordenar_lista_bucket(lista: ListaSimple, get_key: Callable):
        elementos = []
        aux = lista.get_primero()
        while aux:
            elementos.append(aux.get_dato())
            aux = aux.get_siguiente()

        bucket_count = 256
        buckets = [[] for _ in range(bucket_count)]

        for item in elementos:
            key = get_key(item)
            if key:
                first_char = key[0].lower()
                bucket_index = ord(first_char)
                buckets[bucket_index].append(item)

        elementos.clear()

        for bucket in buckets:
            bucket.sort(key=get_key)
            elementos.extend(bucket)

        aux = lista.get_primero()
        index = 0
        while aux:
            aux.set_dato(elementos[index])
            aux = aux.get_siguiente()
            index += 1

        lista.mostrar(lista.get_primero())
