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
bool Tools::esNumeroValido(int numero, int min, int max)
{
    return (numero >= min && numero <= max);
}
bool Tools::validarNumero()
{
    int numero;
    cout << "\t>";
    cin >> numero;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return true;
}
bool Tools::esCadenaValida(const std::string &cadena)
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
bool Tools::validarCadena()
{
    string input;
    cout << "Ingresa una cadena: ";
    getline(cin, input);

    return esCadenaValida(input);
}
char Tools::obtenerOpcionValida()
{
    char opcion;
    cout << "Ingresa una opción: ";
    cin >> opcion;
    opcion = toupper(opcion);

    while (opcion != 'A' && opcion != 'B' && opcion != 'C')
    {
        cout << "Opción inválida. Ingresa A, B o C: ";
        cin >> opcion;
        opcion = toupper(opcion);
    }

    return opcion;
}
bool Tools::esDoubleValido(double numero, double min, double max)
{
    return (numero >= min && numero <= max);
}
bool Tools::validarDouble()
{
    double numero;
    cout << "Ingresa un número decimal: ";
    cin >> numero;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return true;
}
bool Tools::esCadenaLongitudValida(const string &cadena, size_t longitud)
{
    return (cadena.length() == longitud);
}
bool Tools::validarCadenaLongitud()
{
    string input;
    cout << "Ingresa una cadena de longitud específica: ";
    cin >> input;

    const size_t longitud_esperada = 10;

    return esCadenaLongitudValida(input, longitud_esperada);
}