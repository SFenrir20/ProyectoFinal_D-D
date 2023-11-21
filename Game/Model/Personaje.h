#pragma once

#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include "Clase.cpp"
#include "Raza.cpp"

using namespace std;

class Personaje
{
private:
    string nombre;
    Raza raza;
    Clase clase;
    int nivel;
    int oro;
    bool estado;
    double puntosExp;
    double puntosVida;
    double puntosVidaPerdidos;
    double puntosMana;
    double puntosVelocidad;
    double puntosGracia;
    double puntosDefFisica;
    double puntosDefMagica;
    double puntosDanFisico;
    double puntosDanMagico;
    int fuerza;
    int inteligencia;
    int agilidad;
    int frenesi;
    int sabiduria;
    int armadura;
    int voluntad;
    int carisma;
    int animalHandling;
    int velocidadAtaque;
    int destreza;
    int arcano;

public:
    // Constructores y destructor
    Personaje();
    Personaje(string, Raza, Clase, double, double, double, double, double, double, double, double);
    Personaje(string, Raza, Clase, double);
    ~Personaje();

    // Métodos adicionales
    void updateStats();
    void setSkills();
    void lvlUp();

    // Métodos de acceso
    string getNombre();
    Raza getRaza();
    Clase getClase();
    int getNivel();
    int getOro();
    bool getEstado();
    double getPuntosExp();
    double getPuntosVida();
    double getPuntosVidaPerdidos();
    double getPuntosMana();
    double getPuntosVelocidad();
    double getPuntosGracia();
    double getPuntosDefMagica();
    double getPuntosDefFisica();
    double getPuntosDanMagico();
    double getPuntosDanFisico();
    int getFuerza();
    int getInteligencia();
    int getAgilidad();
    int getVoluntad();
    int getArmadura();
    int getSabiduria();
    int getFrenesi();
    int getCarisma();
    int getAnimalHandling();
    int getVelocidadAtaque();
    int getDestreza();
    int getArcano();

    // Métodos de modificación
    void setNombre(string);
    void setRaza(Raza);
    void setClase(Clase);
    void setNivel(int);
    void setOro(int);
    void setEstado(bool);
    void setPuntosExp(double);
    void setPuntosVida(double);
    void setPuntosVidaPerdidos(double);
    void setPuntosMana(double);
    void setPuntosVelocidad(double);
    void setPuntosGracia(double);
    void setPuntosDefMagica(double);
    void setPuntosDefFisica(double);
    void setPuntosDanMagico(double);
    void setPuntosDanFisico(double);
    void setFuerza(int);
    void setInteligencia(int);
    void setVoluntad(int);
    void setArmadura(int);
    void setSabiduria(int);
    void setFrenesi(int);
    void setCarisma(int);
    void setAnimalHandling(int);
    void setAgilidad(int);
    void setVelocidadAtaque(int);
    void setDestreza(int);
    void setArcano(int);
};