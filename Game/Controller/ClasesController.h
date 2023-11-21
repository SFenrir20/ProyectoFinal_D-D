#pragma once

#include <iostream>
#include <fstream>
#include "../Model/Lista.cpp"
#include "../Model/Clase.cpp"

using namespace std;

class ClasesController
{
private:
    Lista<Clase> lstClases;

public:
    ClasesController();
    ~ClasesController();
    Clase getDataAtIndex(int);
    Lista<Clase>* readLstClases();
    void copyFile();
};

ClasesController::ClasesController()
{
    copyFile();
}

ClasesController::~ClasesController()
{
    lstClases.~Lista();
}

Clase ClasesController::getDataAtIndex(int _indice)
{
    return lstClases.getDataAtPosition(_indice);
}

Lista<Clase>* ClasesController::readLstClases()
{
    return lstClases.getFront();
}

// Funcion para leer datos de un csv
void ClasesController::copyFile()
{
    try
    {
        int i;
        size_t posi;
        string linea;
        fstream archivo;
        archivo.open("../Data/Clases.csv", ios::in);
        if (archivo.is_open())
        {
            while (!archivo.eof() && getline(archivo, linea))
            {
                string temp[16];
                i = 0;
                while ((posi = linea.find(";")) != string::npos)
                {
                    temp[i] = linea.substr(0, posi);
                    linea.erase(0, posi + 1);
                    i++;
                }
                Clase clase = Clase(
                    temp[0],
                    temp[1],
                    stod(temp[2]),
                    stod(temp[3]),
                    stod(temp[4]),
                    stod(temp[5]),
                    stod(temp[6]),
                    stod(temp[7]),
                    stod(temp[8]),
                    stod(temp[9]),
                    stod(temp[10]),
                    stod(temp[11]),
                    stod(temp[12]),
                    stod(temp[13]),
                    stod(temp[14]),
                    stod(temp[15])
                );
                lstClases.pushBack(clase);
            }
            archivo.close();
        }
    }
    catch(exception e)
    {
        cout << "Ocurrio un error al leer el archivo";
    }
}