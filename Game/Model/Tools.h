#pragma once

#include <iostream>
#include <string>

using namespace std;

class Tools
{
public:
    Tools();
    void swap(int &, int &);
    void bubbleSortAsc(int arr[], int n);
    void bubbleSortDes(int arr[], int n);
    void dado4Caras();
    void dado6Caras();
    void dado8Caras();
    void dado10Caras();
    bool esNumeroValido(int, int, int);
    bool validarNumero();
    bool esCadenaValida(const string &);
    bool validarCadena();
    char obtenerOpcionValida();
    bool esDoubleValido(double, double, double);
    bool validarDouble();
    bool esCadenaLongitudValida(const string &, size_t);
    bool validarCadenaLongitud();
};