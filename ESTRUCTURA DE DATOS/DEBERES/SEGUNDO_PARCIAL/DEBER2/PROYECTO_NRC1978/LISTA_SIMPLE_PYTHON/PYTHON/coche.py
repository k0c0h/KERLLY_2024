from datetime import datetime
from lista_propietarios import ListaPropietarios
from lista import ListaSimple

class Coche:
    def __init__(self, placa="", modelo="", color="", marca="", anio=0, propietario=None):
        self.placa = placa
        self.modelo = modelo
        self.color = color
        self.marca = marca
        self.anio = anio
        self.propietario = propietario
        self.hora_ingreso = datetime.now()
        self.hora_salida = None

    def set_hora_salida(self, hora):
        self.hora_salida = hora

    def set_placa(self, placa):
        self.placa = placa

    def set_modelo(self, modelo):
        self.modelo = modelo

    def set_marca(self, marca):
        self.marca = marca

    def set_color(self, color):
        self.color = color

    def get_hora_salida(self):
        return self.hora_salida

    def get_placa(self):
        return self.placa

    def get_marca(self):
        return self.marca

    def get_modelo(self):
        return self.modelo

    def get_color(self):
        return self.color

    def get_anio(self):
        return self.anio

    def get_hora_ingreso(self):
        return self.hora_ingreso

    def __str__(self):
        result = (f"Placa: {self.placa}\nMarca: {self.marca}\nModelo: {self.modelo}\n"
                  f"Color: {self.color}\n----------------------------------------\n")
        result += f"Hora de Ingreso: {self.hora_ingreso}\n"

        if self.hora_salida is None:
            result += "Hora de Salida: N/A\n"
        else:
            result += f"Hora de Salida: {self.hora_salida}\n"

        result += "----------------------------------------\n"
        return result

    @staticmethod
    def insertar_datos(lista:ListaSimple, lista_historial:ListaSimple, lista_propietarios:ListaPropietarios):
        from validaciones import Validaciones
        from validacion_placa import Placa

        validaciones = Validaciones()
        validador = Placa()

        placa = ""
        modelo = ""
        color = ""
        marca = ""
        anio = 0
        propietario = None

        while True:
            placa = validador.ingresar_placa(lista.get_primero())
            placa_duplicada = any(
                coche.get_placa() == placa and coche.get_hora_salida() is None
                for coche in lista
            )
            if not placa_duplicada:
                break
            print(f"El coche con la placa {placa} ya está en el parqueadero. Ingrese una placa nueva.")

        for coche_historial in lista_historial:
            if coche_historial.get_placa() == placa:
                print(f"La placa {placa} fue encontrada en el historial. Recuperando datos...")
                modelo = coche_historial.get_modelo()
                color = coche_historial.get_color()
                marca = coche_historial.get_marca()

                print(f"Marca: {marca}\nColor: {color}\nModelo: {modelo}")

                opciones = ["Si", "No"]
                seleccion = input("¿Desea sobreescribir los datos del historial? (Si/No): ")

                if seleccion.lower() == "si":
                    print("========================================")
                    print("        Datos Recuperados Exitosamente  ")
                    print("========================================")
                    print(f"Marca:    {marca}\nModelo:   {modelo}\nColor:    {color}\nPlaca:    {placa}")

                    while True:
                        cedula = validaciones.ingresar_cedula("Ingrese la cédula del propietario: ")
                        propietario = lista_propietarios.buscar_propietario_por_cedula(cedula)
                        if propietario:
                            propietario.agregar_placa(placa)
                            print("Placa asociada exitosamente al propietario.")
                            lista_propietarios.guardar_archivo("propietarios.txt")
                            break
                        else:
                            print("Propietario no encontrado. Intente de nuevo.")

                    return Coche(placa, modelo, color, marca, anio, propietario)

        return Coche(placa, modelo, color, marca, anio, propietario)

    def get_propietario(self):
        return self.propietario
