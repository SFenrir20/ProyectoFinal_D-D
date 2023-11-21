#pragma once

#include <iostream>
#include <string>

using namespace std;

class Raza
{
private:
    string nombre;
    string descripcion;
    int vida;
    int mana;
    int velocidad;
    int gracia;
    int danFisico;
    int danMagico;
    int defFisica;
    int defMagica;
public:
    Raza();
    Raza(string, string);
    Raza(string, string, int, int, int, int, int, int, int, int);
    ~Raza();

    string getNombre();
    string getDescripcion();
    int getVida();
    int getMana();
    int getVelocidad();
    int getGracia();
    int getDefFisica();
    int getDefMagica();
    int getDanFisico();
    int getDanMagico();
    void setNombre(string);
    void setDescripcion(string);
};