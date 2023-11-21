#pragma once
#include <vector>

using namespace std;

class Dados
{
private:
    vector<int> caras;
public:
    Dados();
    Dados(vector<int>&);
    ~Dados();

    int tirarDados();
};