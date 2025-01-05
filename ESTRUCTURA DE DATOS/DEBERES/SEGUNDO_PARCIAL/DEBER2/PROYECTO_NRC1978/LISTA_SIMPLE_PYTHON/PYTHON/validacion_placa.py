import re

class Placa:
    def ingresar_placa(self, aux):
        placa = ""
        provincias_validas = {"A", "B", "C", "E", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"}

        while True:
            placa = input("Ingrese la placa: ").strip()  # Usamos strip() para eliminar los espacios en blanco

            if len(placa) != 7:
                print("\nLa placa debe tener exactamente 7 caracteres. Intente de nuevo.")
                continue

            if placa[0].upper() not in provincias_validas:
                print("\nInicial de provincia no válida. Intente de nuevo.")
                continue

            if not re.match("^[A-Z]{1,3}[0-9]{4}$", placa):  # Expresión regular para validar el formato
                print("\nFormato de placa incorrecto. Intente de nuevo.")
                continue

            break  # Si pasa todas las validaciones, salimos del bucle

        return placa
