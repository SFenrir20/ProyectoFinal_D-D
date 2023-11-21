#pragma once

#include <iostream>

using namespace std;

template <typename D>
class Lista
{
private:
    D data;
    Lista<D> *front;
    Lista<D> *back;

public:
    // Constructores y destructor
    Lista();
    Lista(D);
    ~Lista();

    // Métodos generales
    D getData();
    Lista<D> *getFront();
    Lista<D> *getBack();
    void setFront(Lista<D> *);
    void setBack(Lista<D> *);

    // Métodos de inserción
    void pushFront(D);
    void pushBack(D);

    // Método de modificación
    void modifyData(D, int);

    // Método de obtención
    D getDataAtPosition(int);

    // Método de eliminación
    void removeAt(int);

    // Método para obtener un dato aleatorio de la lista
    D getRandomData();
};