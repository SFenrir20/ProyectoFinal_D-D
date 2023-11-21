#pragma once

#include "Raza.h"

// Implementación de los métodos de Raza

Raza::Raza()
{
}
Raza::Raza(string _nombre, string _descripcion)
{
    nombre      = _nombre;
    descripcion = _descripcion;
}
Raza::Raza(string _nombre, string _descripcion, int _vida, int _mana, int _defMagica, int _defFisica, int _danMagico, int _danFisico, int _gracia, int _velocidad)
{
    nombre      = _nombre;
    descripcion = _descripcion;
    vida        = _vida;
    mana        = _mana;
    velocidad   = _velocidad;
    gracia      = _gracia;
    danFisico   = _danFisico;
    danMagico   = _danMagico;
    defFisica   = _defFisica;
    defMagica   = _defMagica;
}
Raza::~Raza()
{
}

string Raza::getNombre()
{
    return nombre;
}
string Raza::getDescripcion()
{
    return descripcion;
}
int Raza::getVida()
{
    return vida;
}
int Raza::getMana()
{
    return mana;
}
int Raza::getVelocidad()
{
    return velocidad;
}
int Raza::getGracia()
{
    return gracia;
}
int Raza::getDefFisica()
{
    return defFisica;
}
int Raza::getDefMagica()
{
    return defMagica;
}
int Raza::getDanFisico()
{
    return danFisico;
}
int Raza::getDanMagico()
{
    return danMagico;
}
void Raza::setNombre(string _nombre)
{
    nombre = _nombre;
}
void Raza::setDescripcion(string _descripcion)
{
    descripcion = _descripcion;
}