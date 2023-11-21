#pragma once

#include "Clase.h"

// Implementación de los métodos de Clase

Clase::Clase()
{
}
Clase::Clase(string _nombre, string _descripcion)
{
    nombre      = _nombre;
    descripcion = _descripcion;
}
Clase::Clase(string _nombre, string _descripcion, double _fuerza, double _inteligencia, double _voluntad, double _armadura, double _sabiduria, double _frenesi, double _carisma, double _animalHandling, double _agilidad, double _velocidadAtaque1, double _velocidadAtaque2, double _destreza1, double _destreza2, double _arcano)
{
    nombre      = _nombre;
    descripcion = _descripcion;
    fuerza      = _fuerza;
    inteligencia = _inteligencia;
    agilidad    = _agilidad;
    frenesi     = _frenesi;
    sabiduria   = _sabiduria;
    armadura    = _armadura;
    voluntad    = _voluntad;
    carisma     = _carisma;
    animalHandling = _animalHandling;
    velocidadAtaque1 = _velocidadAtaque1;
    velocidadAtaque2 = _velocidadAtaque2;
    destreza1    = _destreza1;
    destreza2    = _destreza2;
    arcano      = _arcano;
}
Clase::~Clase()
{
}

string Clase::getNombre()
{
    return nombre;
}
string Clase::getDescripcion()
{
    return descripcion;
}
double Clase::getFuerza()
{
    return fuerza;
}
double Clase::getInteligencia()
{
    return inteligencia;
}
double Clase::getAgilidad()
{
    return agilidad;
}
double Clase::getFrenesi()
{
    return frenesi;
}
double Clase::getSabiduria()
{
    return sabiduria;
}
double Clase::getArmadura()
{
    return armadura;
}
double Clase::getVoluntad()
{
    return voluntad;
}
double Clase::getCarisma()
{
    return carisma;
}
double Clase::getAnimalHandling()
{
    return animalHandling;
}
double Clase::getVelocidadAtaque1()
{
    return velocidadAtaque1;
}
double Clase::getVelocidadAtaque2()
{
    return velocidadAtaque2;
}
double Clase::getDestreza1()
{
    return destreza1;
}
double Clase::getDestreza2()
{
    return destreza2;
}
double Clase::getArcano()
{
    return arcano;
}
void Clase::setNombre(string _nombre)
{
    nombre = _nombre;
}
void Clase::setDescripcion(string _descripcion)
{
    descripcion = _descripcion;
}