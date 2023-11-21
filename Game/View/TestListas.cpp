#include <iostream>
#include "../Model/Lista.cpp"

int main()
{
    Lista<int> lista;

    lista.pushFront(2);
    lista.pushFront(3);
    lista.pushFront(5);

    lista.pushBack(7);
    lista.pushBack(6);

    Lista<int> *currentBefore = lista.getFront();
    cout << "Lista:";
    while (currentBefore)
    {
        cout << currentBefore->getData() << " ";
        currentBefore = currentBefore->getBack();
    }
    cout << endl;

    return 0;
}
