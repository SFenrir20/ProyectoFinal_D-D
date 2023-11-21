#pragma once
#include "Dados.h"
#include <random>
#include <ctime>

// Implementación de los métodos de Dados

Dados::Dados()
{
}
Dados::Dados(vector<int>& _caras)
{
    caras = _caras;
}
Dados::~Dados()
{
}

int Dados::tirarDados()
{
    // Obtener una semilla aleatoria
    random_device rd;

    // Utilizar el generador Mersenne Twister como generador de números aleatorios
    mt19937 generador(rd());

    // Crear un distribuidor uniforme entre 0 y el tamaño del vector - 1
    uniform_int_distribution<size_t> distribucion(0, caras.size() - 1);

    // Generar un índice aleatorio
    size_t indiceSeleccionado = distribucion(generador);

    // Devolver la opción seleccionada
    return caras[indiceSeleccionado];
}