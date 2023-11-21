#pragma once

#include "Lista.h"

// Implementación de los métodos de Lista

template <typename D>
Lista<D>::Lista()
{
}
template <typename D>
Lista<D>::Lista(D _data)
{
    data = _data;
    front = back = NULL;
}
template <typename D>
Lista<D>::~Lista()
{
    Lista<D> *current = front;
    while (current)
    {
        Lista<D> *next = current->getBack();
        delete current;
        current = next;
    }
}

template <typename D>
D Lista<D>::getData()
{
    return data;
}
template <typename D>
Lista<D> *Lista<D>::getFront()
{
    return front;
}
template <typename D>
Lista<D> *Lista<D>::getBack()
{
    return back;
}
template <typename D>
void Lista<D>::setFront(Lista<D> *_front)
{
    front = _front;
}
template <typename D>
void Lista<D>::setBack(Lista<D> *_back)
{
    back = _back;
}

template <typename D>
void Lista<D>::pushFront(D _data)
{
    Lista<D> *temp = new Lista(_data);

    if (!front)
    {
        front = temp;
        back = temp;
    }
    else
    {
        temp->setBack(front);
        front->setFront(temp);
        front = temp;
    }
}
template <typename D>
void Lista<D>::pushBack(D _data)
{
    Lista<D> *temp = new Lista(_data);

    if (!back)
    {
        front = temp;
        back = temp;
    }
    else
    {
        temp->setFront(back);
        back->setBack(temp);
        back = temp;
    }
}

template <typename D>
void Lista<D>::modifyData(D _data, int position)
{
    Lista<D> *current = front;
    int currentPosition = 0;

    while (current && currentPosition < position)
    {
        current = current->getBack();
        currentPosition++;
    }

    if (current && currentPosition == position)
    {
        current->data = _data;
    }
    else
    {
        cout << "Error: La posición especificada no existe en la lista." << endl;
    }
}

template <typename D>
D Lista<D>::getDataAtPosition(int position)
{
    Lista<D> *current = front;
    int currentPosition = 0;

    while (current && currentPosition < position)
    {
        current = current->getBack();
        currentPosition++;
    }

    if (current && currentPosition == position)
    {
        return current->data;
    }
    else
    {
        cout << "Error: La posición especificada no existe en la lista." << endl;
        return D();
    }
}

template <typename D>
void Lista<D>::removeAt(int position)
{
    Lista<D> *current = front;
    Lista<D> *previous = nullptr;
    int currentPosition = 0;

    while (current && currentPosition < position)
    {
        previous = current;
        current = current->getBack();
        currentPosition++;
    }

    if (current)
    {
        if (current == front)
        {
            front = current->getBack();
            if (front)
            {
                front->setFront(nullptr);
            }
        }
        else
        {
            previous->setBack(current->getBack());
            if (current->getBack())
            {
                current->getBack()->setFront(previous);
            }
        }

        delete current;
    }
    else
    {
        cout << "Error: La posición especificada no existe en la lista." << endl;
    }
}
template <typename D>
D Lista<D>::getRandomData()
{
    if (!front)
    {
        cerr << "La lista está vacía. No se puede obtener un dato aleatorio." << endl;
    }

    int size = 0;
    Lista<D> *current = front;
    while (current)
    {
        size++;
        current = current->getBack();
    }

    srand(static_cast<unsigned>(time(0)));
    int randomIndex = rand() % size;

    current = front;
    for (int i = 0; i < randomIndex; ++i)
    {
        current = current->getBack();
    }

    return current->getData();
}