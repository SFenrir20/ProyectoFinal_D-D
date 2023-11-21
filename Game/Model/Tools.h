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
    bool esNumeroValido(int numero, int min, int max)
    {
        return (numero >= min && numero <= max);
    }

    bool validarNumero()
    {
        int numero;
        std::cout << "Ingresa un número: ";
        std::cin >> numero;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return true;
    }
    bool esCadenaValida(const std::string &cadena)
    {
        for (char c : cadena)
        {
            if (!isalpha(c))
            {
                return false;
            }
        }
        return true;
    }

    bool validarCadena()
    {
        std::string input;
        std::cout << "Ingresa una cadena: ";
        std::getline(std::cin, input);

        return esCadenaValida(input);
    }
    char obtenerOpcionValida()
    {
        char opcion;
        std::cout << "Ingresa una opción: ";
        std::cin >> opcion;
        opcion = std::toupper(opcion);

        while (opcion != 'A' && opcion != 'B' && opcion != 'C')
        {
            std::cout << "Opción inválida. Ingresa A, B o C: ";
            std::cin >> opcion;
            opcion = toupper(opcion);
        }

        return opcion;
    }
    bool esDoubleValido(double numero, double min, double max)
    {
        return (numero >= min && numero <= max);
    }

    bool validarDouble()
    {
        double numero;
        std::cout << "Ingresa un número decimal: ";
        std::cin >> numero;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return true;
    }
    bool esCadenaLongitudValida(const std::string &cadena, size_t longitud)
    {
        return (cadena.length() == longitud);
    }

    bool validarCadenaLongitud()
    {
        std::string input;
        std::cout << "Ingresa una cadena de longitud específica: ";
        std::cin >> input;

        const size_t longitud_esperada = 10;

        return esCadenaLongitudValida(input, longitud_esperada);
    }
};