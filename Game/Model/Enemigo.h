#pragma once

#include <iostream>
#include <string>

using namespace std;

class Enemigo
{
private:
    string tipo;
    string nombre;
    int nivel;
    double vida;
public:
    Enemigo();
    Enemigo(string, string, int, double);
    ~Enemigo();

    string getTipo();
    string getNombre();
    int getNivel();
    double getVida();
    void setTipo(string);
    void setNombre(string);
    void setNivel(int);
    void setVida(double);
};