#pragma once
#include "Bolsillo.h"

// Implementación de los métodos de Bolsillo

template <typename C>
Bolsillo<C>::Bolsillo(Item _item, C _caracteristica)
{
    item = _item;
    caracteristica = _caracteristica;
    izdo = dcho = NULL;
    fe = 0;
}
template <typename C>
Bolsillo<C>::Bolsillo(Item _item, C _caracteristica, int _fe)
{
    item = _item;
    caracteristica = _caracteristica;
    izdo = dcho = NULL;
    fe = _fe;
}
template <typename C>
Bolsillo<C>::Bolsillo(Bolsillo<C>* _izdo, Item _item, C _caracteristica, Bolsillo<C>* _dcho)
{
    item = _item;
    caracteristica = _caracteristica;
    izdo = _izdo;
    dcho = _dcho;
    fe = 0;
}
template <typename C>
Bolsillo<C>::Bolsillo(Bolsillo<C>* _izdo, int _fe, Item _item, C _caracteristica, Bolsillo<C>* _dcho)
{
    item = _item;
    caracteristica = _caracteristica;
    izdo = _izdo;
    dcho = _dcho;
    fe = _fe;
}
template <typename C>
Bolsillo<C>::~Bolsillo()
{
    delete izdo;
    delete dcho;
}

template <typename C>
Item Bolsillo<C>::getItem()
{
    return item;
}
template <typename C>
C Bolsillo<C>::getCaracteristica()
{
    return caracteristica;
}
template <typename C>
int Bolsillo<C>::getFe()
{
    return fe;
}
template <typename C>
Bolsillo<C>* Bolsillo<C>::getSubArbolIzdo()
{
    return izdo;
}
template <typename C>
Bolsillo<C>* Bolsillo<C>::getSubArbolDcho()
{
    return dcho;
}
template <typename C>
void Bolsillo<C>::setNuevoItem(Item _item)
{
    item = _item;
}
template <typename C>
void Bolsillo<C>::setCaracteristica(C _caracteristica)
{
    caracteristica = _caracteristica;
}
template <typename C>
void Bolsillo<C>::setFe(int _fe)
{
    fe = _fe;
}
template <typename C>
void Bolsillo<C>::setRamaIzdo(Bolsillo<C>* _izdo)
{
    izdo = _izdo;
}
template <typename C>
void Bolsillo<C>::setRamaDcho(Bolsillo<C>* _dcho)
{
    dcho = _dcho;
}