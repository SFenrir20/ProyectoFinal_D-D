#pragma once

#include <iostream>
#include <string>

using namespace std;

class Clase
{
private:
    string nombre;
    string descripcion;
    double fuerza;
    double inteligencia;
    double agilidad;
    double frenesi;
    double sabiduria;
    double armadura;
    double voluntad;
    double carisma;
    double animalHandling;
    double velocidadAtaque1;
    double velocidadAtaque2;
    double destreza1;
    double destreza2;
    double arcano;
public:
    Clase();
    Clase(string, string);
    Clase(string, string, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
    ~Clase();

    string getNombre();
    string getDescripcion();
    double getFuerza();
    double getInteligencia();
    double getAgilidad();
    double getFrenesi();
    double getSabiduria();
    double getArmadura();
    double getVoluntad();
    double getCarisma();
    double getAnimalHandling();
    double getVelocidadAtaque1();
    double getVelocidadAtaque2();
    double getDestreza1();
    double getDestreza2();
    double getArcano();
    void setNombre(string);
    void setDescripcion(string);
};
