#pragma once
#include "Personaje.h"
#include <cmath>

// Implementación de los métodos de Personaje

Personaje::Personaje()
{
}
Personaje::Personaje(string _nombre, Raza _raza, Clase _clase, double _puntosVida, double _puntosMana, double _puntosVelocidad, double _puntosGracia, double _puntosDefMagica, double _puntosDefFisica, double _puntosDanMagico, double _puntosDanFisico)
{
    nombre = _nombre;
    raza = _raza;
    clase = _clase;
    nivel = 0;
    estado = true;
    puntosExp = 0.0;
    puntosVida = _puntosVida;
    puntosVidaPerdidos = 0.0;
    puntosMana = _puntosMana;
    puntosVelocidad = _puntosVelocidad;
    puntosGracia = _puntosGracia;
    puntosDefMagica = _puntosDefMagica;
    puntosDefFisica = _puntosDefFisica;
    puntosDanMagico = _puntosDanMagico;
    puntosDanFisico = _puntosDanFisico;
}
Personaje::Personaje(string _nombre, Raza _raza, Clase _clase, double _puntosVida)
{
    nombre = _nombre;
    raza = _raza;
    clase = _clase;
    nivel = 0;
    puntosExp = 0.0;
    puntosVida = _puntosVida;
    estado = true;
}
Personaje::~Personaje()
{
}

void Personaje::updateStats()
{
    puntosVida = (fuerza * clase.getFuerza()) + (destreza * clase.getDestreza1());
    puntosMana = inteligencia * clase.getInteligencia();
    puntosVelocidad = (agilidad * clase.getAgilidad()) + (velocidadAtaque * clase.getVelocidadAtaque1()) + (destreza * clase.getDestreza2());
    puntosGracia = (carisma * clase.getCarisma()) + (animalHandling * clase.getAnimalHandling()) + (arcano * clase.getArcano());
    puntosDefFisica = armadura * clase.getArmadura();
    puntosDefMagica = voluntad * clase.getVoluntad();
    puntosDanFisico = (frenesi * clase.getFrenesi()) + (velocidadAtaque * clase.getVelocidadAtaque2());
    puntosDanMagico = sabiduria * clase.getSabiduria();
}
void Personaje::setSkills()
{
    fuerza = static_cast<int>(round(puntosVida / clase.getFuerza()));
    inteligencia = static_cast<int>(round(puntosMana / clase.getInteligencia()));
    agilidad = static_cast<int>(round(puntosVelocidad / clase.getAgilidad()));
    frenesi = static_cast<int>(round(puntosDanFisico / clase.getFrenesi()));
    sabiduria = static_cast<int>(round(puntosDanMagico / clase.getSabiduria()));
    armadura = static_cast<int>(round(puntosDefFisica / clase.getArmadura()));
    voluntad = static_cast<int>(round(puntosDefMagica / clase.getVoluntad()));
    carisma = static_cast<int>(round(puntosGracia / clase.getCarisma()));
    animalHandling = static_cast<int>(round(puntosGracia / clase.getCarisma()));
    velocidadAtaque = static_cast<int>(round((puntosVelocidad / clase.getVelocidadAtaque1()) + (puntosDanFisico / clase.getVelocidadAtaque2())));
    destreza = static_cast<int>(round((puntosVida / clase.getDestreza1()) + (puntosVelocidad / clase.getDestreza2())));
    arcano = static_cast<int>(round(puntosGracia / clase.getArcano()));
}
void Personaje::lvlUp()
{
    setPuntosExp(getPuntosExp() - 20);
    nivel++;
    fuerza++;
    inteligencia++;
    agilidad++;
    frenesi++;
    sabiduria++;
    armadura++;
    voluntad++;
    carisma++;
    animalHandling++;
    velocidadAtaque++;
    destreza++;
    arcano++;
}

string Personaje::getNombre()
{
    return nombre;
}
Raza Personaje::getRaza()
{
    return raza;
}
Clase Personaje::getClase()
{
    return clase;
}
int Personaje::getNivel()
{
    return nivel;
}
int Personaje::getOro()
{
    return oro;
}
bool Personaje::getEstado()
{
    return estado;
}
double Personaje::getPuntosExp()
{
    return puntosExp;
}
double Personaje::getPuntosVida()
{
    return puntosVida;
}
double Personaje::getPuntosVidaPerdidos()
{
    return puntosVidaPerdidos;
}
double Personaje::getPuntosMana()
{
    return puntosMana;
}
double Personaje::getPuntosVelocidad()
{
    return puntosVelocidad;
}
double Personaje::getPuntosGracia()
{
    return puntosGracia;
}
double Personaje::getPuntosDefMagica()
{
    return puntosDefMagica;
}
double Personaje::getPuntosDefFisica()
{
    return puntosDefFisica;
}
double Personaje::getPuntosDanMagico()
{
    return puntosDanMagico;
}
double Personaje::getPuntosDanFisico()
{
    return puntosDanFisico;
}
int Personaje::getFuerza()
{
    return fuerza;
}
int Personaje::getInteligencia()
{
    return inteligencia;
}
int Personaje::getVoluntad()
{
    return voluntad;
}
int Personaje::getArmadura()
{
    return armadura;
}
int Personaje::getSabiduria()
{
    return sabiduria;
}
int Personaje::getFrenesi()
{
    return frenesi;
}
int Personaje::getCarisma()
{
    return carisma;
}
int Personaje::getAnimalHandling()
{
    return animalHandling;
}
int Personaje::getAgilidad()
{
    return agilidad;
}
int Personaje::getVelocidadAtaque()
{
    return velocidadAtaque;
}
int Personaje::getDestreza()
{
    return destreza;
}
int Personaje::getArcano()
{
    return arcano;
}

void Personaje::setNombre(string _nombre)
{
    nombre = _nombre;
}
void Personaje::setRaza(Raza _raza)
{
    raza = _raza;
}
void Personaje::setClase(Clase _clase)
{
    clase = _clase;
}
void Personaje::setNivel(int _nivel)
{
    nivel = _nivel;
}
void Personaje::setOro(int _oro)
{
    oro = _oro;
}
void Personaje::setEstado(bool _estado)
{
    estado = _estado;
}
void Personaje::setPuntosExp(double _puntosExp)
{
    puntosExp = _puntosExp;
}
void Personaje::setPuntosVida(double _puntosVida)
{
    puntosVida = _puntosVida;
}
void Personaje::setPuntosVidaPerdidos(double _puntosVidaPerdidos)
{
    puntosVidaPerdidos = _puntosVidaPerdidos;
}
void Personaje::setPuntosMana(double _puntosMana)
{
    puntosMana = _puntosMana;
}
void Personaje::setPuntosVelocidad(double _puntosVelocidad)
{
    puntosVelocidad = _puntosVelocidad;
}
void Personaje::setPuntosGracia(double _puntosGracia)
{
    puntosGracia = _puntosGracia;
}
void Personaje::setPuntosDefMagica(double _puntosDefMagica)
{
    puntosDefMagica = _puntosDefMagica;
}
void Personaje::setPuntosDefFisica(double _puntosDefFisica)
{
    puntosDefFisica = _puntosDefFisica;
}
void Personaje::setPuntosDanMagico(double _puntosDanMagico)
{
    puntosDanMagico = _puntosDanMagico;
}
void Personaje::setPuntosDanFisico(double _puntosDanFisico)
{
    puntosDanFisico = _puntosDanFisico;
}
void Personaje::setFuerza(int _fuerza)
{
    fuerza = _fuerza;
}
void Personaje::setInteligencia(int _inteligencia)
{
    inteligencia = _inteligencia;
}
void Personaje::setVoluntad(int _voluntad)
{
    voluntad = _voluntad;
}
void Personaje::setArmadura(int _armadura)
{
    armadura = _armadura;
}
void Personaje::setSabiduria(int _sabiduria)
{
    sabiduria = _sabiduria;
}
void Personaje::setFrenesi(int _frenesi)
{
    frenesi = _frenesi;
}
void Personaje::setCarisma(int _carisma)
{
    carisma = _carisma;
}
void Personaje::setAnimalHandling(int _animalHandling)
{
    animalHandling = _animalHandling;
}
void Personaje::setAgilidad(int _agilidad)
{
    agilidad = _agilidad;
}
void Personaje::setVelocidadAtaque(int _velocidadAtaque)
{
    velocidadAtaque = _velocidadAtaque;
}
void Personaje::setDestreza(int _destreza)
{
    destreza = _destreza;
}
void Personaje::setArcano(int _arcano)
{
    arcano = _arcano;
}