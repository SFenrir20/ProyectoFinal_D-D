#include <iostream>
#include "personajes.h"

using namespace std;

int main(){

   int options;
   cout << " Bienvenido a un Nueva Aventura" << endl;
   cout << " 1. Ser Game Master" << endl;
   cout << " 2. Ser Jugador" << endl;  
   cin >> options;

   switch(options)  {
    case 1:
      cout << "Has seleccionado ser Game Master" << endl;
      break;
    case 2:
      cout << "Has selecccionado ser Juegador" << endl;
      break;
    default:
      cout << "Opción no valida. Por favor elija ser GM o Jugador" << endl;
      break;
   }

   return 0;

}
