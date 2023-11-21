#include <iostream>
#include "gameMaster.cpp"
#include "player.cpp"

using namespace std;

void menuPrincipal();
void serGameMaster();
void serJugador();
void cerrarJuego();

int main()
{
    menuPrincipal();
    return 0;
}

void menuPrincipal()
{
    int opt;

    do
    {
        system("cls");
        cout << " Bienvenido a una Nueva Aventura" << endl;
        cout << " [1] Ser Game Master" << endl;
        cout << " [2] Ser Jugador" << endl;
        cout << " [0] Cerrar juego" << endl;
        cout << " \t>";
        cin >> opt;

        switch (opt)
        {
        case 1:
            serGameMaster();
            cerrarJuego();
            break;
        case 2:
            serJugador();
            break;
        case 0:
            cerrarJuego();
            break;

        default:
            break;
        }
    } while (opt != 0 && opt != 1 && opt != 2);
}
void serGameMaster()
{
    cout << "Has seleccionado ser Game Master" << endl;
    menuGameMaster();
}
void serJugador()
{
    cout << "Has selecccionado ser Jugador" << endl;
    menuPlayer();
}
void cerrarJuego()
{
    cout << "Cerrando juego." << endl;
}