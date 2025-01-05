from lista_propietarios import ListaPropietarios
from lista import ListaSimple
from coche import Coche
from menu import menu

def main():
    lista_propietarios = ListaPropietarios()
    lista_propietarios.cargar_archivo("propietarios.txt")
    
    lista_coches_historial = ListaSimple()
    lista_coches_historial.cargar_archivo("autos_historial.txt")
    
    lista_coches = ListaSimple()
    lista_coches.cargar_archivo("autos.txt")
    
    menu(lista_coches, lista_coches_historial, lista_propietarios)


if __name__ == "__main__":
    main()
