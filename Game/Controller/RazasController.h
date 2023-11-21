#pragma once

#include <iostream>
#include <fstream>
#include "../Model/Lista.cpp"
#include "../Model/Raza.cpp"

using namespace std;

class RazasController
{
private:
    Lista<Raza> lstRazas;

public:
    RazasController();
    ~RazasController();
    Raza getDataAtIndex(int);
    Lista<Raza>* readLstRazas();
    void copyFile();
};

RazasController::RazasController()
{
    copyFile();
}

RazasController::~RazasController()
{
    lstRazas.~Lista();
}

Raza RazasController::getDataAtIndex(int _indice)
{
    return lstRazas.getDataAtPosition(_indice);
}

Lista<Raza>* RazasController::readLstRazas()
{
    return lstRazas.getFront();
}

// Funcion para leer datos de un csv
void RazasController::copyFile()
{
    try
    {
        int i;
        size_t posi;
        string linea;
        fstream archivo;
        archivo.open("../Data/Razas.csv", ios::in);
        if (archivo.is_open())
        {
            while (!archivo.eof() && getline(archivo, linea))
            {
                string temp[10];
                i = 0;
                while ((posi = linea.find(";")) != string::npos)
                {
                    temp[i] = linea.substr(0, posi);
                    linea.erase(0, posi + 1);
                    i++;
                }
                Raza raza = Raza(
                    temp[0],
                    temp[1],
                    stoi(temp[2]),
                    stoi(temp[3]),
                    stoi(temp[4]),
                    stoi(temp[5]),
                    stoi(temp[6]),
                    stoi(temp[7]),
                    stoi(temp[8]),
                    stoi(temp[9])
                );
                lstRazas.pushBack(raza);
            }
            archivo.close();
        }
    }
    catch(exception e)
    {
        cout << "Ocurrio un error al leer el archivo";
    }
}