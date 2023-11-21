#pragma once
#include "Item.h"
#include <sstream>

// Implementación de los métodos de Item

Item::Item()
{
}
Item::Item(string _nombre, string _tipo, string _descripcion, string _rarezas, int _usos, int _precio, int _nivelMin, int _fuerzaMin, int _inteligenciaMin, int _carismaMin, int _animalHandlingMin, int _agilidadMin, int _destrezaMin, int _arcanoMin)
{
    nombre = _nombre;
    tipo = _tipo;
    rarezas = obtenerRarezas(_rarezas);
    descripcion = _descripcion;
    usos = _usos;
    numOrden = 0;
    precio = _precio;
    nivelMin = _nivelMin;
    fuerzaMin = _fuerzaMin;
    inteligenciaMin = _inteligenciaMin;
    carismaMin = _carismaMin;
    animalHandlingMin = _animalHandlingMin;
    agilidadMin = _agilidadMin;
    destrezaMin = _destrezaMin;
    arcanoMin = _arcanoMin;
}
Item::~Item()
{
}

vector<Rareza> Item::obtenerRarezas(string &entrada)
{
    vector<Rareza> datos;

    istringstream ss(entrada);
    string token;

    while (getline(ss, token, ','))
    {
        size_t inicio = token.find('(');
        size_t fin = token.find(')');

        if (inicio != string::npos && fin != string::npos)
        {
            Rareza dato;
            dato.tipo = token.substr(0, inicio);
            dato.valor = stoi(token.substr(inicio + 1, fin - inicio - 1));
            datos.push_back(dato);
        }
        else
        {
            cerr << "Error al procesar el token: " << token << endl;
        }
    }

    return datos;
}

string Item::getNombre()
{
    return nombre;
}
Rareza Item::getRareza()
{
    return rareza;
}
vector<Rareza> Item::getRarezas()
{
    return rarezas;
}
string Item::getTipo()
{
    return tipo;
}
string Item::getDescripcion()
{
    return descripcion;
}
int Item::getUsos()
{
    return usos;
}
int Item::getNumOrden()
{
    return numOrden;
}
int Item::getPrecio()
{
    return precio;
}
int Item::getNivelMin()
{
    return nivelMin;
}
int Item::getFuerzaMin()
{
    return fuerzaMin;
}
int Item::getInteligenciaMin()
{
    return inteligenciaMin;
}
int Item::getCarismaMin()
{
    return carismaMin;
}
int Item::getAnimalHandlingMin()
{
    return animalHandlingMin;
}
int Item::getAgilidadMin()
{
    return agilidadMin;
}
int Item::getDestrezaMin()
{
    return destrezaMin;
}
int Item::getArcanoMin()
{
    return arcanoMin;
}

void Item::setNombre(string _nombre)
{
    nombre = _nombre;
}
void Item::setRareza(Rareza _rareza)
{
    rareza = _rareza;
}
void Item::setTipo(string _tipo)
{
    tipo = _tipo;
}
void Item::setDescripcion(string _descripcion)
{
    descripcion = _descripcion;
}
void Item::setUsos(int _usos)
{
    usos = _usos;
}
void Item::setNumOrden(int _numOrden)
{
    numOrden = _numOrden;
}
void Item::setPrecio(int _precio)
{
    precio = _precio;
}
void Item::setNivelMin(int _nivelMin)
{
    nivelMin = _nivelMin;
}
void Item::setFuerzaMin(int _fuerzaMin)
{
    fuerzaMin = _fuerzaMin;
}
void Item::setInteligenciaMin(int _inteligenciaMin)
{
    inteligenciaMin = _inteligenciaMin;
}
void Item::setCarismaMin(int _carismaMin)
{
    carismaMin = _carismaMin;
}
void Item::setAnimalHandlingMin(int _animalHandlingMin)
{
    animalHandlingMin = _animalHandlingMin;
}
void Item::setAgilidadMin(int _agilidadMin)
{
    agilidadMin = _agilidadMin;
}
void Item::setDestrezaMin(int _destrezaMin)
{
    destrezaMin = _destrezaMin;
}
void Item::setArcanoMin(int _arcanoMin)
{
    arcanoMin = _arcanoMin;
}