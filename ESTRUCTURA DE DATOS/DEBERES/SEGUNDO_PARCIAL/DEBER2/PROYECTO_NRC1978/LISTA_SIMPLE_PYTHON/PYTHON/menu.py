import os
from time import sleep
from ordenamiento import Ordenamiento
from propietario import Propietario
from lista_propietarios import *
from validaciones import *
from lista import ListaSimple
from coche import Coche
import os

def menu_interactivo(opciones, titulo):
    seleccion = 0
    num_opciones = len(opciones)
    
    while True:
        os.system('cls' if os.name == 'nt' else 'clear')  # Limpiar la pantalla en Windows o Unix

        print("========================================")
        print("========================================")
        print(f"        {titulo}")
        print("========================================")
        print("========================================")

        for i in range(num_opciones):
            if i == seleccion:
                print(f" > {opciones[i]} < ")
            else:
                print(f"   {opciones[i]}")

        print("========================================")

        tecla = input("Usa 'w' para arriba, 's' para abajo, y Enter para seleccionar: ").lower()

        if tecla == 'w':  # Subir en el menú
            seleccion = (seleccion - 1 + num_opciones) % num_opciones
        elif tecla == 's':  # Bajar en el menú
            seleccion = (seleccion + 1) % num_opciones
        elif tecla == '':  # Enter para seleccionar
            return seleccion

# Función para gestionar el menú de propietarios
def menu_gestion_propietarios(lista_propietarios):
    salir_submenu = False

    while not salir_submenu:
        os.system('cls' if os.name == 'nt' else 'clear')  # Limpiar pantalla

        print("========================================")
        print("========================================")
        print("      Menú de Gestión de Propietarios   ")
        print("========================================")
        print("========================================")

        opciones_propietarios = [
            "Agregar Propietario",
            "Mostrar Propietarios",
            "Buscar Propietario por Cédula",
            "Eliminar Placa de Propietario",
            "Volver al Menú Principal"
        ]

        seleccion_propietarios = menu_interactivo(opciones_propietarios, "Menú de Gestión de Propietarios")

        if seleccion_propietarios == 0:
            ListaPropietarios.agregar_propietario(lista_propietarios)
            ListaPropietarios.guardar_archivo("propietarios.txt")

        elif seleccion_propietarios == 1:
            ListaPropietarios.mostrar_propietarios()
            input("Presione Enter para continuar...")

        elif seleccion_propietarios == 2:
            os.system('cls' if os.name == 'nt' else 'clear')
            print("========================================")
            print("   BÚSQUEDA DE PROPIETARIO POR CÉDULA   ")
            print("========================================")
            cedula = input("Ingrese la cédula a buscar: ")
            propietario = ListaPropietarios.buscar_propietario_por_cedula(cedula)
            if propietario:
                print("Propietario encontrado:", Propietario.to_string())
            else:
                print("Propietario no encontrado.")
            input("Presione Enter para continuar...")

        elif seleccion_propietarios == 3:
            Propietario.eliminar_placa_propietario(ListaPropietarios)
            ListaPropietarios.guardar_archivo("propietarios.txt")

        elif seleccion_propietarios == 4:
            salir_submenu = True

        else:
            print("Opción no válida. Intente de nuevo.")
            sleep(1)

# Función para gestionar el menú principal
def menu(lista: ListaSimple, lista_historial: ListaSimple, lista_propietarios: ListaPropietarios):
    validador = Validaciones()

    opciones = [
        "Insertar Coche",
        "Mostrar Lista de Coches",
        "Busqueda de Coche Por Placa",
        "Busqueda Avanzada",
        "Menu de Gestion de Propietarios",
        "Liberar el parqueadero",
        "Ordenar lista de coches",
        "Ayuda",
        "Salir"
    ]

    archivo = "autos.txt"
    archivo_historial = "autos_historial.txt"

    while True:
        seleccion = menu_interactivo(opciones, "Menú de Parqueadero")

        if seleccion == 0:
            if ListaPropietarios.esta_vacia():
                print("No hay propietarios registrados. Por favor, registre un propietario antes de continuar.")
            else:
                nuevo_coche = Coche.insertar_datos(lista, lista_historial, lista_propietarios)
                ListaSimple.insertar(nuevo_coche, archivo)
                lista_historial.insertar(nuevo_coche, archivo_historial)

        elif seleccion == 1:
            salir_submenu = False
            while not salir_submenu:
                os.system('cls' if os.name == 'nt' else 'clear')
                print("========================================")
                print("========================================")
                print("         Menú de Lista de Coches        ")
                print("========================================")
                print("========================================")

                opciones_lista = [
                    "Mostrar Coches en Parqueadero",
                    "Mostrar Historial Completo de Coches",
                    "Volver al Menú Principal"
                ]

                seleccion_lista = menu_interactivo(opciones_lista, "Menú de Lista de Coches")

                if seleccion_lista == 0:
                    os.system('cls' if os.name == 'nt' else 'clear')
                    print("========================================")
                    print("   LISTA DE COCHES EN EL PARQUEADERO    ")
                    print("========================================")
                    lista.mostrar()
                    input("Presione Enter para continuar...")

                elif seleccion_lista == 1:
                    os.system('cls' if os.name == 'nt' else 'clear')
                    print("========================================")
                    print("   HISTORIAL COMPLETO DE COCHES         ")
                    print("========================================")
                    lista_historial.mostrar()
                    input("Presione Enter para continuar...")

                elif seleccion_lista == 2:
                    print("Regresando al menú principal...")
                    salir_submenu = True

                else:
                    print("Opción inválida. Inténtelo de nuevo.")
                    sleep(1)

        elif seleccion == 2:
            salir_submenu = False
            while not salir_submenu:
                os.system('cls' if os.name == 'nt' else 'clear')
                print("========================================")
                print("========================================")
                print("        Menú de Búsqueda por Placa      ")
                print("========================================")
                print("========================================")

                opciones_busqueda = [
                    "Buscar en Parqueadero",
                    "Buscar en Historial",
                    "Volver al Menú Principal"
                ]

                seleccion_busqueda = menu_interactivo(opciones_busqueda, "Menú de Búsqueda por Placa")

                if seleccion_busqueda == 0:
                    os.system('cls' if os.name == 'nt' else 'clear')
                    print("========================================")
                    print("   BÚSQUEDA DE PLACA EN PARQUEADERO     ")
                    print("========================================")
                    placa = input("Ingrese la placa a buscar (Utilice mayúsculas para validar su placa): ")
                    ListaSimple.buscar_por_placa(placa)
                    input("Presione Enter para continuar...")

                elif seleccion_busqueda == 1:
                    os.system('cls' if os.name == 'nt' else 'clear')
                    print("========================================")
                    print("   BÚSQUEDA DE PLACA EN HISTORIAL       ")
                    print("========================================")
                    placa = input("Ingrese la placa a buscar (Utilice mayúsculas para validar su placa): ")
                    lista_historial.buscar_por_placa(placa)
                    input("Presione Enter para continuar...")

                elif seleccion_busqueda == 2:
                    print("Regresando al menú principal...")
                    salir_submenu = True

                else:
                    print("Opción inválida. Inténtelo de nuevo.")
                    sleep(1)

        elif seleccion == 3:
            os.system('cls' if os.name == 'nt' else 'clear')
            print("========================================")
            print("========================================")
            print("   BIENVENIDOS A LA BÚSQUEDA AVANZADA   ")
            print("========================================")
            print("========================================")
            menu_busqueda_avanzada(lista, lista_historial)

        elif seleccion == 4:
            menu_gestion_propietarios(lista_propietarios)

        elif seleccion == 5:
            os.system('cls' if os.name == 'nt' else 'clear')
            print("=============================================")
            print("=============================================")
            print(" BIENVENIDOS A LA GESTIÓN DE ESTACIONAMIENTO ")
            print("=============================================")
            print("=============================================")
            placa = input("Ingrese la placa del coche que va a dejar el estacionamiento: ")
            lista_historial.salir_del_parqueadero(placa)
            ListaSimple.eliminar_por_placa(placa)

        elif seleccion == 6:
            menu_ordenar(lista, lista_historial)

        elif seleccion == 7:
            os.system('cls' if os.name == 'nt' else 'clear')
            print("========================================")
            print("========================================")
            print("               (i)AYUDA                 ")
            print("========================================")
            print("========================================")
            archivo = "ayuda.html"
            comando = f"start {archivo}" if os.name == 'nt' else f"open {archivo}"
            os.system(comando)

        elif seleccion == 8:
            print("Saliendo...")
            return

        else:
            print("Opción inválida. Inténtelo de nuevo.")
            sleep(1)

        input("Presione Enter para continuar...")

# Función para gestionar el menú de búsqueda avanzada
def menu_busqueda_avanzada(lista: ListaSimple, lista_historial: ListaSimple):
    validaciones = Validaciones()

    opciones = [
        "Buscar en Parqueadero",
        "Buscar en Historial de Coches",
        "Volver al Menú Principal"
    ]

    while True:
        seleccion = menu_interactivo(opciones, "Menú de Búsqueda Avanzada")

        if seleccion == 0:
            opciones_busqueda = [
                "Buscar por Modelo",
                "Buscar por Color",
                "Buscar por Año/Fecha",
                "Buscar por Marca",
                "Buscar por Hora",
                "Volver al Menú Principal"
            ]

            seleccion_busqueda = menu_interactivo(opciones_busqueda, "Menú de Búsqueda en Parqueadero")

            if seleccion_busqueda == 0:
                os.system('cls' if os.name == 'nt' else 'clear')
                print("========================================")
                print("  Buscar por Modelo")
                print("========================================")
                modelo = validaciones.ingresar_string("Ingrese el modelo: ")
                lista.busqueda_avanzada("modelo", modelo, "")

            elif seleccion_busqueda == 1:
                os.system('cls' if os.name == 'nt' else 'clear')
                print("========================================")
                print("  Buscar por Color")
                print("========================================")
                color = validaciones.ingresar_string("Ingrese el color: ")
                lista.busqueda_avanzada("color", color, "")

            elif seleccion_busqueda == 2:
                os.system('cls' if os.name == 'nt' else 'clear')
                print("========================================")
                print("  Buscar por Año/Fecha")
                print("========================================")
                fecha = input("Ingrese la fecha (DD-MM-AAAA): ")
                lista.busqueda_avanzada("fecha", fecha, "")

            elif seleccion_busqueda == 3:
                os.system('cls' if os.name == 'nt' else 'clear')
                print("========================================")
                print("  Buscar por Marca")
                print("========================================")
                marca = validaciones.ingresar_string("Ingrese la marca: ")
                lista.busqueda_avanzada("marca", marca, "")

            elif seleccion_busqueda == 4:
                os.system('cls' if os.name == 'nt' else 'clear')
                print("========================================")
                print("  Buscar por Hora")
                print("========================================")
                hora_entrada1 = input("Ingrese la hora de entrada 1: ")
                hora_entrada2 = input("Ingrese la hora de entrada 2: ")
                lista.busqueda_avanzada("hora", hora_entrada1, hora_entrada2)

            elif seleccion_busqueda == 5:
                print("Saliendo...")
                return

            else:
                print("Opción inválida. Inténtelo de nuevo.")
                sleep(1)

        elif seleccion == 1:
            opciones_busqueda = [
                "Buscar por Modelo",
                "Buscar por Color",
                "Buscar por Año/Fecha",
                "Buscar por Marca",
                "Buscar por Hora",
                "Volver al Menú Principal"
            ]

            seleccion_busqueda = menu_interactivo(opciones_busqueda, "Menú de Búsqueda en Historial")

            if seleccion_busqueda == 0:
                os.system('cls' if os.name == 'nt' else 'clear')
                print("========================================")
                print("  Buscar por Modelo")
                print("========================================")
                modelo = validaciones.ingresar_string("Ingrese el modelo: ")
                lista_historial.busqueda_avanzada("modelo", modelo, "")

            elif seleccion_busqueda == 1:
                os.system('cls' if os.name == 'nt' else 'clear')
                print("========================================")
                print("  Buscar por Color")
                print("========================================")
                color = validaciones.ingresar_string("Ingrese el color: ")
                lista_historial.busqueda_avanzada("color", color, "")

            elif seleccion_busqueda == 2:
                os.system('cls' if os.name == 'nt' else 'clear')
                print("========================================")
                print("  Buscar por Año/Fecha")
                print("========================================")
                fecha = input("Ingrese la fecha (DD-MM-AAAA): ")
                lista_historial.busqueda_avanzada("fecha", fecha, "")

            elif seleccion_busqueda == 3:
                os.system('cls' if os.name == 'nt' else 'clear')
                print("========================================")
                print("  Buscar por Marca")
                print("========================================")
                marca = validaciones.ingresar_string("Ingrese la marca: ")
                lista_historial.busqueda_avanzada("marca", marca, "")

            elif seleccion_busqueda == 4:
                os.system('cls' if os.name == 'nt' else 'clear')
                print("========================================")
                print("  Buscar por Hora")
                print("========================================")
                hora_entrada1 = input("Ingrese la hora de entrada 1: ")
                hora_entrada2 = input("Ingrese la hora de entrada 2: ")
                lista_historial.busqueda_avanzada("hora", hora_entrada1, hora_entrada2)

            elif seleccion_busqueda == 5:
                print("Saliendo...")
                return

            else:
                print("Opción inválida. Inténtelo de nuevo.")
                sleep(1)

        elif seleccion == 2:
            print("Saliendo...")
            return

        else:
            print("Opción inválida. Inténtelo de nuevo.")
            sleep(1)

        input("Presione Enter para continuar...")


# Función para gestionar el menú de ordenamiento
def menu_ordenar(lista:ListaSimple, lista_historial:ListaSimple):
    salir_submenu = False

    while not salir_submenu:
        os.system('cls' if os.name == 'nt' else 'clear')
        print("========================================")
        print("           Menú de Ordenamiento         ")
        print("========================================")

        opciones_metodo = [
            "Quick Sort",
            "Bucket Sort",
            "Bubble Sort",
            "Shell Sort",
            "Radix Sort",
            "Volver al Menú Principal"
        ]

        seleccion_metodo = menu_interactivo(opciones_metodo, "Seleccione el método de ordenamiento:")

        if seleccion_metodo == 5:
            salir_submenu = True
            continue

        opciones_ordenar = [
            "Ordenar por Placa",
            "Ordenar por Apellido del Propietario",
            "Ordenar por Color",
            "Ordenar por Modelo",
            "Ordenar por Marca",
            "Volver al Menú Principal"
        ]

        seleccion_ordenar = menu_interactivo(opciones_ordenar, "Seleccione el criterio de ordenamiento:")

        if seleccion_ordenar == 5:
            continue

        os.system('cls' if os.name == 'nt' else 'clear')
        if seleccion_metodo == 0:  # Quick Sort
            if seleccion_ordenar == 0:
                Ordenamiento.ordenar_lista(lista, lambda a, b: a.get_placa() < b.get_placa())
                print("Lista ordenada por placa y guardada exitosamente.")
            elif seleccion_ordenar == 1:
                Ordenamiento.ordenar_lista(lista, lambda a, b: a.get_propietario().get_apellido() < b.get_propietario().get_apellido())
                print("Lista ordenada por apellido del propietario y guardada exitosamente.")
            elif seleccion_ordenar == 2:
                Ordenamiento.ordenar_lista(lista, lambda a, b: a.get_color() < b.get_color())
                print("Lista ordenada por color y guardada exitosamente.")
            elif seleccion_ordenar == 3:
                Ordenamiento.ordenar_lista(lista, lambda a, b: a.get_modelo() < b.get_modelo())
                print("Lista ordenada por modelo y guardada exitosamente.")
            elif seleccion_ordenar == 4:
                Ordenamiento.ordenar_lista(lista, lambda a, b: a.get_marca() < b.get_marca())
                print("Lista ordenada por marca y guardada exitosamente.")
            else:
                print("Opción inválida. Intente de nuevo.")

        elif seleccion_metodo == 1:  # Bucket Sort
            get_key = None

            if seleccion_ordenar == 0:
                get_key = lambda item: item.get_placa()
            elif seleccion_ordenar == 1:
                get_key = lambda item: item.get_propietario().get_apellido()
            elif seleccion_ordenar == 2:
                get_key = lambda item: item.get_color()
            elif seleccion_ordenar == 3:
                get_key = lambda item: item.get_modelo()
            elif seleccion_ordenar == 4:
                get_key = lambda item: item.get_marca()

            if get_key:
                Ordenamiento.ordenar_lista_bucket(lista, get_key)
                print("Lista ordenada por el criterio seleccionado y guardada exitosamente.")
            else:
                print("Opción inválida. Intente de nuevo.")
                continue

        elif seleccion_metodo == 2:  # Bubble Sort
            if seleccion_ordenar == 0:
                Ordenamiento.ordenar_lista_bubble_sort(lista, lambda a, b: a.get_placa() < b.get_placa())
                print("Lista ordenada por placa y guardada exitosamente.")
            elif seleccion_ordenar == 1:
                Ordenamiento.ordenar_lista_bubble_sort(lista, lambda a, b: a.get_propietario().get_apellido() < b.get_propietario().get_apellido())
                print("Lista ordenada por apellido del propietario y guardada exitosamente.")
            elif seleccion_ordenar == 2:
                Ordenamiento.ordenar_lista_bubble_sort(lista, lambda a, b: a.get_color() < b.get_color())
                print("Lista ordenada por color y guardada exitosamente.")
            elif seleccion_ordenar == 3:
                Ordenamiento.ordenar_lista_bubble_sort(lista, lambda a, b: a.get_modelo() < b.get_modelo())
                print("Lista ordenada por modelo y guardada exitosamente.")
            elif seleccion_ordenar == 4:
                Ordenamiento.ordenar_lista_bubble_sort(lista, lambda a, b: a.get_marca() < b.get_marca())
                print("Lista ordenada por marca y guardada exitosamente.")
            else:
                print("Opción inválida. Intente de nuevo.")

        elif seleccion_metodo == 3:  # Shell Sort
            if seleccion_ordenar == 0:
                Ordenamiento.ordenar_lista_shell_sort(lista, lambda a, b: a.get_placa() < b.get_placa())
                print("Lista ordenada por placa y guardada exitosamente.")
            elif seleccion_ordenar == 1:
                Ordenamiento.ordenar_lista_shell_sort(lista, lambda a, b: a.get_propietario().get_apellido() < b.get_propietario().get_apellido())
                print("Lista ordenada por apellido del propietario y guardada exitosamente.")
            elif seleccion_ordenar == 2:
                Ordenamiento.ordenar_lista_shell_sort(lista, lambda a, b: a.get_color() < b.get_color())
                print("Lista ordenada por color y guardada exitosamente.")
            elif seleccion_ordenar == 3:
                Ordenamiento.ordenar_lista_shell_sort(lista, lambda a, b: a.get_modelo() < b.get_modelo())
                print("Lista ordenada por modelo y guardada exitosamente.")
            elif seleccion_ordenar == 4:
                Ordenamiento.ordenar_lista_shell_sort(lista, lambda a, b: a.get_marca() < b.get_marca())
                print("Lista ordenada por marca y guardada exitosamente.")
            else:
                print("Opción inválida. Intente de nuevo.")

        elif seleccion_metodo == 4:  # Radix Sort
            if seleccion_ordenar == 0:
                Ordenamiento.ordenar_lista_por_radix(lista, lambda coche: coche.get_placa())
                lista.guardar_archivo("autos.txt")
                print("Lista ordenada por placa y guardada exitosamente.")
            elif seleccion_ordenar == 1:
                Ordenamiento.ordenar_lista_por_radix(lista, lambda coche: coche.get_propietario().get_apellido())
                lista.guardar_archivo("autos.txt")
                print("Lista ordenada por apellido del propietario y guardada exitosamente.")
            elif seleccion_ordenar == 2:
                Ordenamiento.ordenar_lista_por_radix(lista, lambda coche: coche.get_color())
                lista.guardar_archivo("autos.txt")
                print("Lista ordenada por color y guardada exitosamente.")
            elif seleccion_ordenar == 3:
                Ordenamiento.ordenar_lista_por_radix(lista, lambda coche: coche.get_modelo())
                lista.guardar_archivo("autos.txt")
                print("Lista ordenada por modelo y guardada exitosamente.")
            elif seleccion_ordenar == 4:
                Ordenamiento.ordenar_lista_por_radix(lista, lambda coche: coche.get_marca())
                lista.guardar_archivo("autos.txt")
                print("Lista ordenada por marca y guardada exitosamente.")
            else:
                print("Opción inválida. Intente de nuevo.")

        lista.guardar_archivo("autos.txt")
        input("Presione Enter para continuar...")
