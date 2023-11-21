#pragma once

#include "Item.cpp"
template <typename C>
class Bolsillo
{
private:
    Item item;
    C caracteristica;
    Bolsillo *izdo;
    Bolsillo *dcho;
    int fe;
public:
    // Constructores y destructor
    Bolsillo(Item, C);
    Bolsillo(Item, C, int);
    Bolsillo(Bolsillo<C>*, Item, C, Bolsillo<C>*);
    Bolsillo(Bolsillo<C>*, int, Item, C, Bolsillo<C>*);
    ~Bolsillo();

    // Métodos de acceso
    Item getItem();
    C getCaracteristica();
    int getFe();
    Bolsillo<C>* getSubArbolIzdo();
    Bolsillo<C>* getSubArbolDcho();
    void setNuevoItem(Item);
    void setCaracteristica(C);
    void setFe(int);
    void setRamaIzdo(Bolsillo<C>*);
    void setRamaDcho(Bolsillo<C>*);
};