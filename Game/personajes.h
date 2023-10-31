#include <iostream>

using namespace std;

struct Personaje {
 string nombre;
 string raza;
 string clase;
 int nivel;
 float puntos_vida;
 float puntos_exp;
 float puntos_def;
 float puntos_mag;

};
inline Personaje crearPersonaje(){
    Personaje nuevoPersonaje;
    cout << "!Creemos tu Personaje" << endl;
    cout << "ingresa el  nombre de tu personaje" << endl;
    cin >> nuevoPersonaje.nombre;

    cout << "Seleciona una clase para tu personaje" << endl;
    cin >> nuevoPersonaje.clase; 

    //esto se debe hacer de manera automartica para cada clase o hacerlo con dados 
    //crear una funcion que se use dados para la genracion de los puntos del pj  
    nuevoPersonaje.nivel = 1;
    nuevoPersonaje.puntos_vida = 10;  

    return nuevoPersonaje;
}