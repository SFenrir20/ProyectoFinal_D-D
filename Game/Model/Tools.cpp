#pragma once

#include "Tools.h"
#include "Dados.cpp"

Tools::Tools()
{
}

void Tools::swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Tools::bubbleSortAsc(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void Tools::bubbleSortDes(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void Tools::dado4Caras()
{
    system("cls");
    vector<int> opciones = {1, 2, 3, 4};
    Dados d = Dados(opciones);
    int numTiradas;

    cout << " TIRAR LOS DADOS" << endl;
    cout << " Ingrese el numero de tiradas: ";
    cin >> numTiradas;

    cout << "Resultados: ";

    for (int i = 0; i < numTiradas; i++)
    {
        cout << d.tirarDados() << " ";
    }
    cout << endl;

    system("pause");
}
void Tools::dado6Caras()
{
    system("cls");
    vector<int> opciones = {1, 2, 3, 4, 5, 6};
    Dados d = Dados(opciones);
    int numTiradas;

    cout << " TIRAR LOS DADOS" << endl;
    cout << " Ingrese el numero de tiradas: ";
    cin >> numTiradas;

    cout << "Resultados: ";

    for (int i = 0; i < numTiradas; i++)
    {
        cout << d.tirarDados() << " ";
    }
    cout << endl;

    system("pause");
}
void Tools::dado8Caras()
{
    system("cls");
    vector<int> opciones = {1, 2, 3, 4, 5, 6, 7, 8};
    Dados d = Dados(opciones);
    int numTiradas;

    cout << " TIRAR LOS DADOS" << endl;
    cout << " Ingrese el numero de tiradas: ";
    cin >> numTiradas;

    cout << "Resultados: ";

    for (int i = 0; i < numTiradas; i++)
    {
        cout << d.tirarDados() << " ";
    }
    cout << endl;

    system("pause");
}
void Tools::dado10Caras()
{
    system("cls");
    vector<int> opciones = {1, 2, 3, 4, 5, 6, 7, 8};
    Dados d = Dados(opciones);
    int numTiradas;

    cout << " TIRAR LOS DADOS" << endl;
    cout << " Ingrese el numero de tiradas: ";
    cin >> numTiradas;

    cout << "Resultados: ";

    for (int i = 0; i < numTiradas; i++)
    {
        cout << d.tirarDados() << " ";
    }
    cout << endl;

    system("pause");
}