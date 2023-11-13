// personajes.h
#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <fstream>
#include <vector>
#include <iostream>
#include <string>

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


// Función para leer las opciones desde un archivo de texto
inline vector<string> leerOpcionesDesdeArchivo(const string& rutaArchivo){
    vector<string> opciones;
    ifstream archivo(rutaArchivo);

    if (archivo.is_open()){
         string linea;
         while (getline(archivo, linea, ';')){
            opciones.push_back(linea);
         }
         archivo.close();
    }else {
        cerr << "No se pudo abrir el archivo: " << rutaArchivo << endl;
    }
    return opciones;
}
// Función para mostrar las opciones disponibles
inline void mostrarOpciones(const vector<string>& opciones) {
    cout << "Opciones disponibles:" << endl;
    for (size_t i = 0; i < opciones.size(); ++i) {
        cout << i + 1 << ". " << opciones[i] << endl;
    }
}

// Función para que el jugador elija una opción
inline string elegirOpcion(const vector<string>& opciones) {
    mostrarOpciones(opciones);

    int eleccion;
    cin >> eleccion;

    // Validar la elección
    if (eleccion < 1 || eleccion > static_cast<int>(opciones.size())) {
        cerr << "Elección no valida." << endl;
        // Puedes manejar esto de diferentes maneras, por ejemplo, volver a pedir la elección.
        return "";
    }

    return opciones[eleccion - 1];
}

// Función para que el jugador elija una raza
inline string elegirRaza(const string& rutaArchivo) {
    vector<string> razas = leerOpcionesDesdeArchivo( rutaArchivo + "\\Razas.txt");
    cout << "Elige una raza para tu personaje:" << endl;
    return elegirOpcion(razas);
}

// Función para que el jugador elija una clase
inline string elegirClase(const string& rutaArchivo) {
    vector<string> clases = leerOpcionesDesdeArchivo(rutaArchivo + "/Clases.txt");
    cout << "Elige una clase para tu personaje:" << endl;
    return elegirOpcion(clases);
}


// Función para crear un personaje con raza y clase elegidas
inline Personaje crearPersonaje(const string& rutaArchivo) {
    Personaje nuevoPersonaje;
    cout << "!Creemos tu Personaje" << endl;
    cout << "Ingresa el nombre de tu personaje" << endl;
    cin >> nuevoPersonaje.nombre;

    nuevoPersonaje.raza = elegirRaza(rutaArchivo);
    nuevoPersonaje.clase = elegirClase(rutaArchivo);

    // Esto se debe hacer de manera automática para cada clase o hacerlo con dados
    // Crear una función que use dados para la generación de los puntos del pj
    nuevoPersonaje.nivel = 1;
    nuevoPersonaje.puntos_vida = 10;

    return nuevoPersonaje;
}

#endif // PERSONAJE_H