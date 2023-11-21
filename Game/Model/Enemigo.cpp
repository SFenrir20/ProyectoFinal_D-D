#pragma once

#include "Enemigo.h"

Enemigo::Enemigo()
{
}
Enemigo::Enemigo(string _tipo, string _nombre, int _nivel, double _vida)
{
    tipo = _tipo;
    nombre = _nombre;
    nivel = _nivel;
    vida = _vida;
}
Enemigo::~Enemigo()
{
}

string Enemigo::getTipo()
{
    return tipo;
}
string Enemigo::getNombre()
{
    return nombre;
}
int Enemigo::getNivel()
{
    return nivel;
}
double Enemigo::getVida()
{
    return vida;
}
void Enemigo::setTipo(string _tipo)
{
    tipo = _tipo;
}
void Enemigo::setNombre(string _nombre)
{
    nombre = _nombre;
}
void Enemigo::setNivel(int _nivel)
{
    nivel = _nivel;
}
void Enemigo::setVida(double _vida)
{
    vida = _vida;
}