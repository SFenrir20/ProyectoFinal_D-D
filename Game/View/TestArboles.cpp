#include <iostream>
#include "../Model/Item.cpp"
#include "../Model/Mochila.cpp"
#include <string>

using namespace std;

int main()
{
    Item item1 = Item("Pocion de vida", "Cura 5 de vida", "Consumible", 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    Item item2 = Item("Espada de madera", "Inflinje 3 de dano", "Espada", 10, 0, 3, 0, 1, 2, 3, 5, 6, 2, 0, 3, 0, 0);
    Item item3 = Item("Cota de malla", "Proporciona 3 de armadura fisica", "Armadura", -1, 1, 4, 0, 2, 0, 4, 0, 6, 0, 7, 0, 2, 0);

    Mochila<string> mochila;

    bool hc = false;
    mochila.setRaiz(mochila.insertarItem(mochila.getRaiz(), item1, item1.getNombre(), hc));
    mochila.setRaiz(mochila.insertarItem(mochila.getRaiz(), item2, item2.getNombre(), hc));
    mochila.setRaiz(mochila.insertarItem(mochila.getRaiz(), item3, item3.getNombre(), hc));

    mochila.listarItems(mochila.getRaiz());
}