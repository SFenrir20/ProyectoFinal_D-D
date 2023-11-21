#pragma once

#include "Bolsillo.cpp"
#include <iostream>

using namespace std;

template <typename T>
class Mochila
{
private:
    Bolsillo<T> *raiz;

public:
    // Constructores y destructor
    Mochila();
    Mochila(Bolsillo<T> *);
    ~Mochila();

    // Métodos generales
    void setRaiz(Bolsillo<T> *);
    Bolsillo<T> *getRaiz();
    Bolsillo<T> raizArbol();
    bool esVacio();
    Bolsillo<T> *hijoIzdo();
    Bolsillo<T> *hijoDcho();
    Bolsillo<T> *nuevaMochila(Bolsillo<T> *, Item, T, Bolsillo<T> *);
    void destruirArbol(Bolsillo<T> *);

    // Método de recorrido Inorden
    void listarItemsMenor(Bolsillo<T> *, bool);
    void listarItemsMayor(Bolsillo<T> *, bool);
    void listarItemsArma(Bolsillo<T> *, bool);
    void listarItemsProteccion(Bolsillo<T> *, bool);
    void listarItemsArmadura(Bolsillo<T> *, bool);
    void listarItemsConsumible(Bolsillo<T> *, bool);

    // Métodos de rotacion
    Bolsillo<T> *rotacionII(Bolsillo<T> *, Bolsillo<T> *);
    Bolsillo<T> *rotacionDD(Bolsillo<T> *, Bolsillo<T> *);
    Bolsillo<T> *rotacionDI(Bolsillo<T> *, Bolsillo<T> *);
    Bolsillo<T> *rotacionID(Bolsillo<T> *, Bolsillo<T> *);

    // Método de inserción
    Bolsillo<T> *insertarItem(Bolsillo<T> *, Item, T, bool &);

    // Método de busqueda
    Bolsillo<T> *buscarItem(Bolsillo<T> *, T);

    // Método de eliminación
    void eliminarItem(T, bool&);
    Bolsillo<T> *eliminarItem(Bolsillo<T> *, Item, T, bool &);
    Bolsillo<T> *reemplazar(Bolsillo<T> *);

    // Método de balance
    Bolsillo<T> *balancearMochila(Bolsillo<T> *);
    int altura(Bolsillo<T> *);
};
