#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Rareza
{
    string tipo;
    int valor;
};

class Item
{
private:
    string nombre;
    Rareza rareza;
    vector<Rareza> rarezas;
    string tipo;
    string descripcion;
    int usos;
    int numOrden;
    int precio;
    int nivelMin;
    int fuerzaMin;
    int inteligenciaMin;
    int agilidadMin;
    int destrezaMin;
    int carismaMin;
    int animalHandlingMin;
    int arcanoMin;

public:
    // Constructores y destructor
    Item();
    Item(string, string, string, string, int, int, int, int, int, int, int, int, int, int);
    ~Item();

    // Función para dividir el string y almacenar los datos en un vector
    vector<Rareza> obtenerRarezas(string &);

    // Métodos de acceso
    string getNombre();
    string getTipo();
    Rareza getRareza();
    vector<Rareza> getRarezas();
    string getDescripcion();
    int getUsos();
    int getNumOrden();
    int getPrecio();
    int getNivelMin();
    int getFuerzaMin();
    int getInteligenciaMin();
    int getCarismaMin();
    int getAnimalHandlingMin();
    int getAgilidadMin();
    int getDestrezaMin();
    int getArcanoMin();

    // Métodos de modificación
    void setNombre(string);
    void setRareza(Rareza);
    void setTipo(string);
    void setDescripcion(string);
    void setUsos(int);
    void setNumOrden(int);
    void setPrecio(int);
    void setNivelMin(int);
    void setFuerzaMin(int);
    void setInteligenciaMin(int);
    void setCarismaMin(int);
    void setAnimalHandlingMin(int);
    void setAgilidadMin(int);
    void setDestrezaMin(int);
    void setArcanoMin(int);
};