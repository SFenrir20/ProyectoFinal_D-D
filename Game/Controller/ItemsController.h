#pragma once

#include <iostream>
#include <fstream>
#include "../Model/Lista.cpp"
#include "../Model/Item.cpp"

using namespace std;

class ItemsController
{
private:
    Lista<Item> lstItems;
    Lista<Item> lstComunes;
    Lista<Item> lstRaros;
    Lista<Item> lstEpicos;
    Lista<Item> lstLegendarios;
    Lista<Item> lstInmortales;
    Lista<Item> lstDios;
public:
    ItemsController();
    ~ItemsController();
    Item getDataAtIndex(int);
    Item getRandomComun();
    Item getRandomRaro();
    Item getRandomEpico();
    Item getRandomLegendario();
    Item getRandomInmortal();
    Item getRandomDios();
    Lista<Item>* readLstItems();
    Lista<Item>* readLstComun();
    Lista<Item>* readLstRaro();
    Lista<Item>* readLstEpico();
    Lista<Item>* readLstLegendario();
    Lista<Item>* readLstInmortal();
    Lista<Item>* readLstDios();
    void copyFile();
    void fillLsts();
};

ItemsController::ItemsController()
{
    copyFile();
    fillLsts();
}

ItemsController::~ItemsController()
{
    lstItems.~Lista();
    lstComunes.~Lista();
    lstRaros.~Lista();
    lstEpicos.~Lista();
    lstLegendarios.~Lista();
    lstInmortales.~Lista();
    lstDios.~Lista();
}

Item ItemsController::getDataAtIndex(int _indice)
{
    return lstItems.getDataAtPosition(_indice);
}

Item ItemsController::getRandomComun()
{
    return lstComunes.getRandomData();
}

Item ItemsController::getRandomRaro()
{
    return lstRaros.getRandomData();
}

Item ItemsController::getRandomEpico()
{
    return lstEpicos.getRandomData();
}

Item ItemsController::getRandomLegendario()
{
    return lstLegendarios.getRandomData();
}

Item ItemsController::getRandomInmortal()
{
    return lstInmortales.getRandomData();
}

Item ItemsController::getRandomDios()
{
    return lstDios.getRandomData();
}

Lista<Item>* ItemsController::readLstItems()
{
    return lstItems.getFront();
}
Lista<Item>* ItemsController::readLstComun()
{
    return lstComunes.getFront();
}
Lista<Item>* ItemsController::readLstRaro()
{
    return lstRaros.getFront();
}
Lista<Item>* ItemsController::readLstEpico()
{
    return lstEpicos.getFront();
}
Lista<Item>* ItemsController::readLstLegendario()
{
    return lstLegendarios.getFront();
}
Lista<Item>* ItemsController::readLstInmortal()
{
    return lstInmortales.getFront();
}
Lista<Item>* ItemsController::readLstDios()
{
    return lstDios.getFront();
}

void ItemsController::fillLsts()
{
    int i = 0;
    Lista<Item> *lstTemp = readLstItems();

    while (lstTemp)
    {
        for(Rareza x:getDataAtIndex(i).getRarezas())
        {
            Item temp = getDataAtIndex(i);

            temp.setRareza(x);

            if(temp.getRareza().tipo == "Comun")
            {
                lstComunes.pushBack(temp);
            }
            else if(temp.getRareza().tipo == "Raro")
            {
                lstRaros.pushBack(temp);
            }
            else if(temp.getRareza().tipo == "Epico")
            {
                lstEpicos.pushBack(temp);
            }
            else if(temp.getRareza().tipo == "Legendario")
            {
                lstLegendarios.pushBack(temp);
            }
            else if(temp.getRareza().tipo == "Inmortal")
            {
                lstInmortales.pushBack(temp);
            }
            else if(temp.getRareza().tipo == "Dios")
            {
                lstDios.pushBack(temp);
            }
        }
        lstTemp = lstTemp->getBack();
        i++;
    }
}

// Funcion para leer datos de un csv
void ItemsController::copyFile()
{
    try
    {
        int i;
        size_t posi;
        string linea;
        fstream archivo;
        archivo.open("../Data/Items.csv", ios::in);
        if (archivo.is_open())
        {
            while (!archivo.eof() && getline(archivo, linea))
            {
                string temp[14];
                i = 0;
                while ((posi = linea.find(";")) != string::npos)
                {
                    temp[i] = linea.substr(0, posi);
                    linea.erase(0, posi + 1);
                    i++;
                }
                Item item = Item(
                    temp[0],
                    temp[1],
                    temp[2],
                    temp[3],
                    stoi(temp[4]),
                    stoi(temp[5]),
                    stoi(temp[6]),
                    stoi(temp[7]),
                    stoi(temp[8]),
                    stoi(temp[9]),
                    stoi(temp[10]),
                    stoi(temp[11]),
                    stoi(temp[12]),
                    stoi(temp[13])
                );
                lstItems.pushBack(item);
            }
            archivo.close();
        }
    }
    catch(exception e)
    {
        cout << "Ocurrio un error al leer el archivo" << e.what();
    }
}