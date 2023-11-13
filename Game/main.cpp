#include <iostream>
#include "personajes.h"

using namespace std;

int main(){
  string rutaArchivo = "C:/Users/santi/OneDrive/Documents/Repositorios/Estructuras y Programacion de Algoritmos/ProyectoFinal_D-D/Data";


   int options;
   cout << " Bienvenido a un Nueva Aventura" << endl;
   cout << " 1. Ser Game Master" << endl;
   cout << " 2. Ser Jugador" << endl;  
   cin >> options;

   switch(options)  {
    case 1:{
      cout << "Has seleccionado ser Game Master" << endl;
      break;}
    case 2:{
      cout << "Has selecccionado ser Jugador" << endl;
       Personaje jugador = crearPersonaje(rutaArchivo); // Llamada a la función crearPersonaje
       cout << "¡Personaje creado! Nombre: " << jugador.nombre 
            << ", Raza: " << jugador.raza 
            << ", Clase: " << jugador.clase << endl;
      break;}
    default:
      cout << "Opción no valida. Por favor elija ser GM o Jugador" << endl;
      break;
   }

   return 0;

}
