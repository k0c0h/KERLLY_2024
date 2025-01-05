from datetime import datetime
import time
from nodo import Nodo


class ListaSimple:
    def __init__(self):
        self.primero = None
    
    def get_primero(self):
        return self.primero
    
    def insertar(self, dato, nombre_archivo):
        nuevo_nodo = Nodo(dato)
        if not self.primero:
            self.primero = nuevo_nodo
        else:
            aux = self.primero
            while aux.siguiente:
                aux = aux.siguiente
            aux.siguiente = nuevo_nodo

        self.guardar_archivo(nombre_archivo)

    def buscar_por_placa(self, placa):
        if not self.primero:
            print("La lista está vacía.")
            return

        aux = self.primero
        while aux:
            if aux.dato.placa == placa:
                print("========================================")
                print("   AUTOMÓVIL REGISTRADO")
                print("========================================")
                print(aux.dato)
                return
            aux = aux.siguiente

        print(f"El coche con la placa {placa} no está en el parqueadero.")

    def busqueda_avanzada(self, criterio, valor_inicio, valor_fin=None):
        if not self.primero:
            print("La lista está vacía.")
            return

        aux = self.primero
        encontrado = False

        while aux:
            dato = aux.dato
            if criterio == "marca" and dato.marca.lower() == valor_inicio.lower():
                encontrado = True
            elif criterio == "modelo" and dato.modelo.lower() == valor_inicio.lower():
                encontrado = True
            elif criterio == "color" and dato.color.lower() == valor_inicio.lower():
                encontrado = True
            elif criterio == "hora" and valor_inicio <= dato.hora.strftime("%H:%M:%S") <= valor_fin:
                encontrado = True

            if encontrado:
                print("========================================")
                print(f"   AUTOMÓVIL REGISTRADO POR {criterio.upper()}")
                print("========================================")
                print(dato)
            aux = aux.siguiente

        if not encontrado:
            print(f"No se encontró ningún automóvil con el criterio de búsqueda: {criterio}")

    def mostrar(self):
        if not self.primero:
            print("La lista está vacía.")
            return

        aux = self.primero
        print("AUTOMÓVILES REGISTRADOS")
        print("========================================")
        while aux:
            print(aux.dato)
            aux = aux.siguiente

    def eliminar_por_placa(self, placa):
        if not self.primero:
            print("La lista está vacía.")
            return

        aux = self.primero
        anterior = None

        while aux:
            if aux.dato.placa == placa:
                if anterior:
                    anterior.siguiente = aux.siguiente
                else:
                    self.primero = aux.siguiente

                print(f"El coche con la placa {placa} ha sido eliminado.")
                self.guardar_archivo("autos.txt")
                return

            anterior = aux
            aux = aux.siguiente

        print(f"El coche con la placa {placa} no se encontró en el parqueadero.")

    def guardar_archivo(self, nombre_archivo):
        from coche import Coche
        try:
            with open(nombre_archivo, 'w') as archivo:
                aux = self.primero
                while aux:
                    coche = aux.dato
                    placa_cifrada = self.cifrar_texto(coche.placa)
                    hora_ingreso = coche.get_hora_ingreso().strftime("%a %b %d %H:%M:%S %Y")
                    hora_salida = (
                        coche.hora_salida.strftime("%a %b %d %H:%M:%S %Y")
                        if coche.hora_salida else "N/A"
                    )

                    archivo.write(
                        f"{placa_cifrada},{coche.modelo},{coche.color},{coche.marca},"
                        f"{hora_ingreso},{hora_salida}\n"
                    )
                    aux = aux.siguiente
        except IOError as e:
            print(f"Error al guardar el archivo: {e}")

    def cargar_archivo(self, nombre_archivo):
        from coche import Coche
        try:
            with open(nombre_archivo, 'r') as archivo:
                for linea in archivo:
                    datos = linea.strip().split(',')
                    if len(datos) == 6:
                        placa = self.descifrar_texto(datos[0])
                        modelo = datos[1]
                        color = datos[2]
                        marca = datos[3]
                        hora_ingreso = datetime.strptime(datos[4], "%a %b %d %H:%M:%S %Y")
                        hora_salida = (
                            datetime.strptime(datos[5], "%a %b %d %H:%M:%S %Y")
                            if datos[5] != "N/A" else None
                        )

                        coche = Coche(placa, modelo, color, marca, hora_ingreso, hora_salida)
                        self.insertar(coche, nombre_archivo)
        except IOError as e:
            print(f"Error al cargar el archivo: {e}")

    def cifrar_texto(self, texto):
        texto_cifrado = ''
        for c in texto:
            if c.isdigit():
                texto_cifrado += chr((ord(c) - ord('0') + 2) % 10 + ord('0'))
            elif c.isalpha():
                base = ord('A') if c.isupper() else ord('a')
                texto_cifrado += chr((ord(c) - base + 2) % 26 + base)
            else:
                texto_cifrado += c
        return texto_cifrado

    def descifrar_texto(self, texto):
        texto_descifrado = ''
        for c in texto:
            if c.isdigit():
                texto_descifrado += chr((ord(c) - ord('0') - 2 + 10) % 10 + ord('0'))
            elif c.isalpha():
                base = ord('A') if c.isupper() else ord('a')
                texto_descifrado += chr((ord(c) - base - 2 + 26) % 26 + base)
            else:
                texto_descifrado += c
        return texto_descifrado

    def salir_del_parqueadero(self, placa):
        aux = self.primero
        encontrado = False

        while aux:
            if aux.dato.placa == placa:
                aux.dato.hora_salida = datetime.now()
                print(f"El coche con placa {placa} ha salido del parqueadero.")
                encontrado = True
                break
            aux = aux.siguiente

        if encontrado:
            self.guardar_archivo("autos_historial.txt")
        else:
            print(f"Coche con placa {placa} no encontrado en el parqueadero.")
