import re
import msvcrt  # Usado para simular _getch() en Windows
import sys

class Validaciones:
    def ingresar_string(self, msj):
        input_str = ""
        print(msj, end="", flush=True)

        while True:
            c = msvcrt.getch().decode("utf-8")  # Lee un solo carácter

            if c.isalpha():  # Si el carácter es alfabético
                input_str += c
                print(c, end="", flush=True)
            elif c == '\b' and input_str:  # Si es una retroceso y hay caracteres
                input_str = input_str[:-1]
                print("\b \b", end="", flush=True)
            elif c == '\r':  # Enter (retorno de carro)
                if input_str:
                    break
                else:
                    print("\a", end="", flush=True)  # Beep si no hay entrada
            else:
                print("\a", end="", flush=True)  # Beep para otros caracteres

        print()
        return input_str

    def ingresar_cedula(self, msj):
        cedula = ""
        print(msj, end="", flush=True)

        while True:
            c = msvcrt.getch().decode("utf-8")  # Lee un solo carácter

            if c.isdigit():  # Si el carácter es numérico
                cedula += c
                print(c, end="", flush=True)
            elif c == '\b' and cedula:  # Si es una retroceso y hay caracteres
                cedula = cedula[:-1]
                print("\b \b", end="", flush=True)
            elif c == '\r':  # Enter (retorno de carro)
                if cedula:
                    break
                else:
                    print("\a", end="", flush=True)  # Beep si no hay entrada
            else:
                print("\a", end="", flush=True)  # Beep para otros caracteres

        print()
        return cedula

    def ingresar_correo(self, msj):
        correo = input(msj)
        return correo

    def validar_cedula(self, cedula):
        if len(cedula) != 10:
            return False

        suma = 0
        for i in range(9):
            digito = int(cedula[i])
            if i % 2 == 0:
                digito *= 2
                if digito > 9:
                    digito -= 9
            suma += digito

        ultimo_digito = int(cedula[9])
        digito_verificador = (10 - (suma % 10)) % 10

        return ultimo_digito == digito_verificador

    def validar_correo(self, correo):
        pattern = r"(\w+)(\.{1}\w+)*@(\w+)(\.{1}\w+)+"
        return re.match(pattern, correo) is not None


