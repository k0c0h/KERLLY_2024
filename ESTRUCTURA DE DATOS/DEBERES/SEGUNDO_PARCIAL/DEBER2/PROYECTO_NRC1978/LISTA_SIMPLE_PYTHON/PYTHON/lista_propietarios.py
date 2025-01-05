from nodo import Nodo
from propietario import Propietario

class ListaPropietarios:
    def __init__(self):
        self.__primero = None
        self.__ultimo = None

    def __del__(self):
        aux = self.__primero
        while aux is not None:
            siguiente = aux.get_siguiente()
            del aux
            aux = siguiente

    def agregar_propietario(self, propietario):
        nuevo_nodo = Nodo(propietario)
        if self.__primero is None:
            self.__primero = nuevo_nodo
            self.__ultimo = nuevo_nodo
        else:
            self.__ultimo.set_siguiente(nuevo_nodo)
            self.__ultimo = nuevo_nodo

    def buscar_propietario_por_cedula(self, cedula):
        aux = self.__primero
        while aux is not None:
            if aux.get_dato().get_cedula() == cedula:
                return aux.get_dato()
            aux = aux.get_siguiente()
        return None

    def mostrar_propietarios(self):
        aux = self.__primero
        if aux is None:
            print("La lista de propietarios está vacía.")
            return
        while aux is not None:
            print(aux.get_dato().to_string())
            aux = aux.get_siguiente()

    def esta_vacia(self):
        return self.__primero is None

    def cargar_archivo(self, archivo):
        try:
            with open(archivo, 'r') as file:
                for linea in file:
                    partes = linea.strip().split(',')
                    if len(partes) < 4:
                        continue
                    nombre, apellido, cedula, correo = partes[:4]
                    propietario = Propietario(nombre, apellido, cedula, correo)
                    for placa in partes[4:]:
                        propietario.agregar_placa(placa)
                    self.agregar_propietario(propietario)
        except FileNotFoundError:
            print("Error: No se pudo abrir el archivo para cargar propietarios.")
        except Exception as e:
            print(f"Error inesperado al cargar el archivo: {e}")

    def guardar_archivo(self, archivo):
        try:
            with open(archivo, 'w') as file:
                aux = self.__primero
                while aux is not None:
                    propietario = aux.get_dato()
                    line = f"{propietario.get_nombre()},{propietario.get_apellido()},{propietario.get_cedula()},{propietario.get_correo()}"
                    for placa in propietario.get_placas():
                        line += f",{placa}"
                    file.write(line + '\n')
                    aux = aux.get_siguiente()
        except Exception as e:
            print(f"Error al guardar el archivo: {e}")
