#pragma once
#include "Mochila.h"

// Implementación de los métodos de Mochila

template <typename T>
Mochila<T>::Mochila()
{
    raiz = NULL;
}
template <typename T>
Mochila<T>::Mochila(Bolsillo<T> *r)
{
    raiz = r;
}
template <typename T>
Mochila<T>::~Mochila()
{
    destruirArbol(raiz);
}

template <typename T>
void Mochila<T>::setRaiz(Bolsillo<T> *r)
{
    raiz = r;
}
template <typename T>
Bolsillo<T> *Mochila<T>::getRaiz()
{
    return raiz;
}
template <typename T>
Bolsillo<T> Mochila<T>::raizArbol()
{
    if (raiz)
    {
        return *raiz;
    }
    else
    {
        cout << "Arbol vacio";
        throw " arbol vacio";
    }
}
template <typename T>
bool Mochila<T>::esVacio()
{
    return raiz == NULL;
}
template <typename T>
Bolsillo<T> *Mochila<T>::hijoIzdo()
{
    if (raiz)
    {
        return raiz->getSubArbolIzdo();
    }
    else
    {
        cout << "Arbol vacio";
        throw " arbol vacio";
    }
}
template <typename T>
Bolsillo<T> *Mochila<T>::hijoDcho()
{
    if (raiz)
    {
        return raiz->getSubArbolDcho();
    }
    else
    {
        cout << "Arbol vacio";
        throw " arbol vacio";
    }
}
template <typename T>
Bolsillo<T> *Mochila<T>::nuevaMochila(Bolsillo<T> *_izdo, Item _item, T _caracteristica, Bolsillo<T> *_dcho)
{
    return new Bolsillo(_izdo, _item, _caracteristica, _dcho);
}
template <typename T>
void Mochila<T>::destruirArbol(Bolsillo<T> *nodo)
{
    if (nodo != nullptr)
    {
        destruirArbol(nodo->getSubArbolIzdo());
        destruirArbol(nodo->getSubArbolDcho());
        delete nodo;
    }
}

template <typename T>
void Mochila<T>::listarItemsMenor(Bolsillo<T> *r, bool condicion)
{
    if (r != NULL)
    {
        listarItemsMenor(r->getSubArbolIzdo(), condicion);
        Item temp = r->getItem();
        if (condicion)
        {
            cout << " [" << temp.getNumOrden() << "]";
        }
        cout << " " << temp.getNombre() << endl;
        cout << "\tDescripcion: " << temp.getDescripcion() << endl;
        cout << "\tTipo: " << temp.getTipo() << endl;
        cout << "\tRareza: " << temp.getRareza().tipo << endl;
        listarItemsMenor(r->getSubArbolDcho(), condicion);
    }
}
template <typename T>
void Mochila<T>::listarItemsMayor(Bolsillo<T> *r, bool condicion)
{
    if (r != NULL)
    {
        listarItemsMayor(r->getSubArbolDcho(), condicion);
        Item temp = r->getItem();
        if (condicion)
        {
            cout << " [" << temp.getNumOrden() << "]";
        }
        cout << " " << temp.getNombre() << endl;
        cout << "\tDescripcion: " << temp.getDescripcion() << endl;
        cout << "\tTipo: " << temp.getTipo() << endl;
        cout << "\tRareza: " << temp.getRareza().tipo << endl;
        listarItemsMayor(r->getSubArbolIzdo(), condicion);
    }
}
template <typename T>
void Mochila<T>::listarItemsArma(Bolsillo<T> *r, bool condicion)
{
    if (r != NULL)
    {
        listarItemsArma(r->getSubArbolIzdo(), condicion);
        Item temp = r->getItem();
        if (temp.getTipo() == "Arma")
        {
            if (condicion)
            {
                cout << " [" << temp.getNumOrden() << "]";
            }
            cout << " " << temp.getNombre() << endl;
            cout << "\tDescripcion: " << temp.getDescripcion() << endl;
            cout << "\tRareza: " << temp.getRareza().tipo << endl;
        }
        listarItemsArma(r->getSubArbolDcho(), condicion);
    }
}
template <typename T>
void Mochila<T>::listarItemsProteccion(Bolsillo<T> *r, bool condicion)
{
    if (r != NULL)
    {
        listarItemsProteccion(r->getSubArbolIzdo(), condicion);
        Item temp = r->getItem();
        if (temp.getTipo() == "Proteccion")
        {
            if (condicion)
            {
                cout << " [" << temp.getNumOrden() << "]";
            }
            cout << " " << temp.getNombre() << endl;
            cout << "\tDescripcion: " << temp.getDescripcion() << endl;
            cout << "\tRareza: " << temp.getRareza().tipo << endl;
        }
        listarItemsProteccion(r->getSubArbolDcho(), condicion);
    }
}
template <typename T>
void Mochila<T>::listarItemsArmadura(Bolsillo<T> *r, bool condicion)
{
    if (r != NULL)
    {
        listarItemsArmadura(r->getSubArbolIzdo(), condicion);
        Item temp = r->getItem();
        if (temp.getTipo() == "Armadura")
        {
            if (condicion)
            {
                cout << " [" << temp.getNumOrden() << "]";
            }
            cout << " " << temp.getNombre() << endl;
            cout << "\tDescripcion: " << temp.getDescripcion() << endl;
            cout << "\tRareza: " << temp.getRareza().tipo << endl;
        }
        listarItemsArmadura(r->getSubArbolDcho(), condicion);
    }
}
template <typename T>
void Mochila<T>::listarItemsConsumible(Bolsillo<T> *r, bool condicion)
{
    if (r != NULL)
    {
        listarItemsConsumible(r->getSubArbolIzdo(), condicion);
        Item temp = r->getItem();
        if (temp.getTipo() == "Consumible")
        {
            if (condicion)
            {
                cout << " [" << temp.getNumOrden() << "]";
            }
            cout << " " << temp.getNombre() << endl;
            cout << "\tDescripcion: " << temp.getDescripcion() << endl;
            cout << "\tRareza: " << temp.getRareza().tipo << endl;
        }
        listarItemsConsumible(r->getSubArbolDcho(), condicion);
    }
}

template <typename T>
Bolsillo<T> *Mochila<T>::rotacionII(Bolsillo<T> *n, Bolsillo<T> *n1)
{
    n->setRamaIzdo(n1->getSubArbolDcho());
    n1->setRamaDcho(n);

    if (n1->getFe() == -1)
    {
        n->setFe(0);
        n1->setFe(0);
    }
    else
    {
        n->setFe(-1);
        n1->setFe(1);
    }

    return n1;
}
template <typename T>
Bolsillo<T> *Mochila<T>::rotacionDD(Bolsillo<T> *n, Bolsillo<T> *n1)
{
    n->setRamaDcho(n1->getSubArbolIzdo());
    n1->setRamaIzdo(n);

    if (n1->getFe() == -1)
    {
        n->setFe(0);
        n1->setFe(0);
    }
    else
    {
        n->setFe(1);
        n1->setFe(-1);
    }

    return n1;
}
template <typename T>
Bolsillo<T> *Mochila<T>::rotacionDI(Bolsillo<T> *n, Bolsillo<T> *n1)
{
    Bolsillo<T> *n2;

    n2 = n1->getSubArbolIzdo();
    n->setRamaDcho(n2->getSubArbolIzdo());
    n2->setRamaIzdo(n);
    n1->setRamaIzdo(n2->getSubArbolDcho());
    n2->setRamaDcho(n1);

    if (n2->getFe() == 1)
    {
        n->setFe(-1);
    }
    else
    {
        n->setFe(0);
    }

    if (n2->getFe() == -1)
    {
        n1->setFe(1);
    }
    else
    {
        n1->setFe(0);
    }

    n2->setFe(0);

    return n2;
}
template <typename T>
Bolsillo<T> *Mochila<T>::rotacionID(Bolsillo<T> *n, Bolsillo<T> *n1)
{
    Bolsillo<T> *n2;

    n2 = n1->getSubArbolDcho();
    n->setRamaIzdo(n2->getSubArbolDcho());
    n2->setRamaDcho(n);
    n1->setRamaDcho(n2->getSubArbolIzdo());
    n2->setRamaIzdo(n1);

    if (n2->getFe() == 1)
    {
        n->setFe(-1);
    }
    else
    {
        n->setFe(0);
    }

    if (n2->getFe() == -1)
    {
        n1->setFe(1);
    }
    else
    {
        n1->setFe(0);
    }

    n2->setFe(0);

    return n2;
}

template <typename T>
Bolsillo<T> *Mochila<T>::insertarItem(Bolsillo<T> *raiz, Item _item, T _caracteristica, bool &hc)
{
    Bolsillo<T> *n1;

    if (raiz == NULL)
    {
        raiz = new Bolsillo(_item, _caracteristica);
    }
    else if (_caracteristica < raiz->getCaracteristica())
    {
        Bolsillo<T> *iz;
        iz = insertarItem(raiz->getSubArbolIzdo(), _item, _caracteristica, hc);
        raiz->setRamaIzdo(iz);

        if (hc)
        {
            switch (raiz->getFe())
            {
            case 1:
                raiz->setFe(0);
                hc = false;
                break;
            case 0:
                raiz->setFe(-1);
                break;
            case -1:
                n1 = raiz->getSubArbolIzdo();
                if (n1->getFe() == -1)
                {
                    raiz = rotacionII(raiz, n1);
                }
                else
                {
                    raiz = rotacionID(raiz, n1);
                }
                hc = false;
                break;
            }
        }
    }
    else if (_caracteristica > raiz->getCaracteristica())
    {
        Bolsillo<T> *dr;
        dr = insertarItem(raiz->getSubArbolDcho(), _item, _caracteristica, hc);
        raiz->setRamaDcho(dr);

        if (hc)
        {
            switch (raiz->getFe())
            {
            case 1:
                n1 = raiz->getSubArbolDcho();
                if (n1->getFe() == +1)
                {
                    raiz = rotacionDD(raiz, n1);
                }
                else
                {
                    raiz = rotacionDI(raiz, n1);
                }
                hc = false;
                break;
            case 0:
                raiz->setFe(+1);
                break;
            case -1:
                raiz->setFe(0);
                hc = false;
            }
        }
    }
    else
    {
        cout << "No puede haber claves repetidas";
        throw "No puede haber claves repetidas";
    }

    return raiz;
}

template <typename T>
Bolsillo<T> *Mochila<T>::buscarItem(Bolsillo<T> *raiz, T caracteristica)
{
    if (raiz == nullptr || raiz->getCaracteristica() == caracteristica)
    {
        return raiz;
    }

    if (caracteristica < raiz->getCaracteristica())
    {
        return buscarItem(raiz->getSubArbolIzdo(), caracteristica);
    }
    else
    {
        return buscarItem(raiz->getSubArbolDcho(), caracteristica);
    }
}

template <typename T>
void Mochila<T>::eliminarItem(T _caracteristica, bool &hc)
{
    raiz = eliminarItem(raiz, raiz->getItem(), _caracteristica, hc);
}
template <typename T>
Bolsillo<T> *Mochila<T>::eliminarItem(Bolsillo<T> *raiz, Item _item, T _caracteristica, bool &hc)
{
    Bolsillo<T> *n1;

    if (raiz == NULL)
    {
        throw "No se ha encontrado el bolsillo con la clave";
    }
    else if (_caracteristica < raiz->getCaracteristica())
    {
        Bolsillo<T> *iz;
        iz = eliminarItem(raiz->getSubArbolIzdo(), _item, _caracteristica, hc);
        raiz->setRamaIzdo(iz);

        if (hc)
        {
            switch (raiz->getFe())
            {
            case 1:
                raiz->setFe(0);
                hc = false;
                break;
            case 0:
                raiz->setFe(-1);
                break;
            case -1:
                n1 = raiz->getSubArbolIzdo();
                if (n1->getFe() == -1)
                {
                    raiz = rotacionII(raiz, n1);
                }
                else
                {
                    raiz = rotacionID(raiz, n1);
                }
                hc = false;
                break;
            }
        }
    }
    else if (_caracteristica > raiz->getCaracteristica())
    {
        Bolsillo<T> *dr;
        dr = eliminarItem(raiz->getSubArbolIzdo(), _item, _caracteristica, hc);
        raiz->setRamaDcho(dr);

        if (hc)
        {
            switch (raiz->getFe())
            {
            case 1:
                n1 = raiz->getSubArbolDcho();
                if (n1->getFe() == +1)
                {
                    raiz = rotacionDD(raiz, n1);
                }
                else
                {
                    raiz = rotacionDI(raiz, n1);
                }
                hc = false;
                break;
            case 0:
                raiz->setFe(+1);
                break;
            case -1:
                raiz->setFe(0);
                hc = false;
            }
        }
    }
    else
    {
        Bolsillo<T> *q;
        q = raiz;
        if (q->getSubArbolIzdo() == NULL)
        {
            raiz = q->getSubArbolDcho();
        }
        else if (q->getSubArbolDcho() == NULL)
        {
            raiz = q->getSubArbolIzdo();
        }
        else
        {
            q = reemplazar(q);
        }
        q = NULL;
    }
    return raiz;
}
template <typename T>
Bolsillo<T> *Mochila<T>::reemplazar(Bolsillo<T> *act)
{
    Bolsillo<T> *a, *p;
    p = act;
    a = act->getSubArbolIzdo();
    while (a->getSubArbolDcho() != NULL)
    {
        p = a;
        a = a->getSubArbolDcho();
    }
    act->setNuevoItem(a->getItem());
    act->setCaracteristica(a->getCaracteristica());
    if (p == act)
    {
        p->setRamaIzdo(a->getSubArbolIzdo());
    }
    else
    {
        p->setRamaDcho(a->getSubArbolIzdo());
    }

    return a;
}

template <typename T>
Bolsillo<T> *Mochila<T>::balancearMochila(Bolsillo<T> *raiz)
{
    if (raiz == NULL)
    {
        return raiz;
    }

    int fe = altura(raiz->getSubArbolDcho()) - altura(raiz->getSubArbolIzdo());
    raiz->setFe(fe);

    if (fe > 1)
    {
        if (altura(raiz->getSubArbolDcho()->getSubArbolDcho()) >= altura(raiz->getSubArbolDcho()->getSubArbolIzdo()))
        {
            raiz = rotacionII(raiz, raiz->getSubArbolDcho());
        }
        else
        {
            raiz = rotacionID(raiz, raiz->getSubArbolDcho());
        }
    }
    else if (fe < -1)
    {
        if (altura(raiz->getSubArbolIzdo()->getSubArbolIzdo()) >= altura(raiz->getSubArbolIzdo()->getSubArbolDcho()))
        {
            raiz = rotacionDD(raiz, raiz->getSubArbolIzdo());
        }
        else
        {
            raiz = rotacionDI(raiz, raiz->getSubArbolIzdo());
        }
    }

    return raiz;
}

template <typename T>
int Mochila<T>::altura(Bolsillo<T> *nodo)
{
    if (nodo == NULL)
    {
        return 0;
    }
    return 1 + max(altura(nodo->getSubArbolIzdo()), altura(nodo->getSubArbolDcho()));
}