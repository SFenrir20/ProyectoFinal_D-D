#include <iostream>
#include <vector>
#include "../Model/Personaje.cpp"
#include "../Model/Enemigo.cpp"
#include "../Model/Clase.cpp"
#include "../Model/Lista.cpp"
#include "../Model/Dados.cpp"
#include "../Model/Tools.cpp"
#include "../Controller/ClasesController.h"
#include "../Controller/RazasController.h"

using namespace std;

ClasesController cController;
RazasController rController;

Tools tools;

Lista<Personaje> lstJugadores;
Lista<Enemigo> lstEnemigos;

void menuGameMaster();
void menuVerJugadores();
void listarJugadores();
void registrarJugador();
Raza elegirRaza();
Clase elegirClase();
void eliminarJugador();
void revivirJugador();
void actualizarJugador();
void menuEnemigos();
void listarEnemigos();
void registrarEnemigo();
void eliminarEnemigo();
void menuTirarDadosGM();

void menuGameMaster()
{
    int opt;

    do
    {
        system("cls");
        cout << " Bienvenido Game Master" << endl;
        cout << " [1] Ver jugadores" << endl;
        cout << " [2] Crear enemigos" << endl;
        cout << " [3] Tirar dados" << endl;
        cout << " [0] Finalizar partida" << endl;
        cout << " \t>";
        cin >> opt;

        switch (opt)
        {
        case 1:
            menuVerJugadores();
            break;
        case 2:
            menuEnemigos();
            break;
        case 3:
            menuTirarDadosGM();
            break;
        case 0:
            lstJugadores.~Lista();
            lstEnemigos.~Lista();
            break;

        default:
            break;
        }
    } while (opt != 0);
}
void menuVerJugadores()
{
    int opt;

    do
    {
        system("cls");
        cout << " JUGADORES" << endl;
        listarJugadores();
        cout << " [1] Registrar" << endl;
        cout << " [2] Eliminar" << endl;
        cout << " [3] Revivir" << endl;
        cout << " [4] Actualizar" << endl;
        cout << " [0] Volver" << endl;
        cout << " \t>";
        cin >> opt;

        switch (opt)
        {
        case 1:
            registrarJugador();
            break;
        case 2:
            eliminarJugador();
            break;
        case 3:
            revivirJugador();
            break;
        case 4:
            actualizarJugador();
            break;

        default:
            break;
        }
    } while (opt != 0);
}
void listarJugadores()
{
    Lista<Personaje> *temp = lstJugadores.getFront();
    while (temp)
    {
        if (temp->getData().getEstado())
        {
            cout << "  " << temp->getData().getNombre() << endl;
            cout << "    Raza: " << temp->getData().getRaza().getNombre() << endl;
            cout << "    Clase: " << temp->getData().getClase().getNombre() << endl;
            cout << "    Nivel: " << temp->getData().getNivel() << endl;
            cout << "    Exp: " << temp->getData().getPuntosExp() << endl;
            cout << "    Vida: " << temp->getData().getPuntosVida() << endl;
        }
        temp = temp->getBack();
    }
}
void registrarJugador()
{
    system("cls");

    string nombre;
    Raza raza;
    Clase clase;
    double vida;

    cout << " REGISTRAR JUGADOR" << endl;
    cout << " Nombre: ";
    cin >> nombre;
    raza = elegirRaza();
    clase = elegirClase();
    cout << " Vida: ";
    cin >> vida;

    lstJugadores.pushBack(Personaje(nombre, raza, clase, vida));
}
Raza elegirRaza()
{
    system("cls");

    Lista<Raza> *tempRaza = rController.readLstRazas();
    int i = 0;
    int opt;

    cout << " Raza: " << endl;

    while (tempRaza)
    {
        cout << " [" << i + 1 << "]" << tempRaza->getData().getNombre() << endl;
        tempRaza = tempRaza->getBack();
        i++;
    }

    cout << "    >";
    cin >> opt;

    return rController.getDataAtIndex(opt - 1);
}
Clase elegirClase()
{
    system("cls");

    Lista<Clase> *tempClase = cController.readLstClases();
    int i = 0;
    int opt;

    cout << " Clase: " << endl;

    while (tempClase)
    {
        cout << " [" << i + 1 << "]" << tempClase->getData().getNombre() << endl;
        tempClase = tempClase->getBack();
        i++;
    }

    cout << "    >";
    cin >> opt;

    return cController.getDataAtIndex(opt - 1);
}
void eliminarJugador()
{
    system("cls");

    Lista<Personaje> *temp = lstJugadores.getFront();
    int i = 0;
    int opt;

    cout << " ELIMINAR JUGADOR" << endl;

    while (temp)
    {
        if (temp->getData().getEstado())
        {
            cout << " [" << i + 1 << "]" << temp->getData().getNombre() << endl;
        }
        temp = temp->getBack();
        i++;
    }

    cout << " [0] Volver" << endl;
    cout << "    >";
    cin >> opt;

    if (opt == 0)
    {
        return;
    }

    Personaje pTemp = lstJugadores.getDataAtPosition(opt - 1);

    pTemp.setEstado(false);

    lstJugadores.modifyData(pTemp, opt - 1);
}
void revivirJugador()
{
    system("cls");

    Lista<Personaje> *temp = lstJugadores.getFront();
    int i = 0;
    int opt;

    cout << " REVIVIR JUGADOR" << endl;

    while (temp)
    {
        if (!temp->getData().getEstado())
        {
            cout << " [" << i + 1 << "]" << temp->getData().getNombre() << endl;
        }
        temp = temp->getBack();
        i++;
    }

    cout << " [0] Volver" << endl;
    cout << "    >";
    cin >> opt;

    if (opt == 0)
    {
        return;
    }

    Personaje pTemp = lstJugadores.getDataAtPosition(opt - 1);

    pTemp.setEstado(true);

    lstJugadores.modifyData(pTemp, opt - 1);
}
void actualizarJugador()
{
    system("cls");

    Lista<Personaje> *temp = lstJugadores.getFront();
    int i = 0;
    int opt;

    cout << " ACTUALIZAR JUGADOR" << endl;

    while (temp)
    {
        if (temp->getData().getEstado())
        {
            cout << " [" << i + 1 << "]" << temp->getData().getNombre() << endl;
        }
        temp = temp->getBack();
        i++;
    }

    cout << " [0] Volver" << endl;
    cout << "    >";
    cin >> opt;

    if (opt == 0)
    {
        return;
    }

    system("cls");

    Personaje pTemp = lstJugadores.getDataAtPosition(opt - 1);

    double vida;
    int nivel;
    int exp;

    cout << " " << pTemp.getNombre() << endl;
    cout << " Ingrese nueva vida: ";
    cin >> vida;
    pTemp.setPuntosVida(vida);
    cout << " Ingrese nuevo nivel: ";
    cin >> nivel;
    pTemp.setNivel(nivel);
    cout << " Ingrese nuevo exp: ";
    cin >> exp;
    pTemp.setPuntosExp(exp);

    lstJugadores.modifyData(pTemp, opt - 1);
}
void menuEnemigos()
{
    int opt;

    do
    {
        system("cls");
        cout << " ENEMIGOS" << endl;
        listarEnemigos();
        cout << " [1] Registrar" << endl;
        cout << " [2] Eliminar" << endl;
        cout << " [0] Volver" << endl;
        cout << " \t>";
        cin >> opt;

        switch (opt)
        {
        case 1:
            registrarEnemigo();
            break;
        case 2:
            eliminarEnemigo();
            break;

        default:
            break;
        }
    } while (opt != 0);
}
void listarEnemigos()
{
    Lista<Enemigo> *temp = lstEnemigos.getFront();
    while (temp)
    {
        cout << "  " << temp->getData().getNombre() << endl;
        cout << "    Tipo: " << temp->getData().getTipo() << endl;
        cout << "    Nivel: " << temp->getData().getNivel() << endl;
        cout << "    Vida: " << temp->getData().getVida() << endl;
        temp = temp->getBack();
    }
}
void registrarEnemigo()
{
    system("cls");

    string nombre;
    string tipo;
    int nivel;
    double vida;

    cout << " REGISTRAR ENEMIGO" << endl;
    cout << " Nombre: ";
    cin >> nombre;
    cout << " Tipo: ";
    cin >> tipo;
    cout << " Nivel: ";
    cin >> nivel;
    cout << " Vida: ";
    cin >> vida;

    lstEnemigos.pushBack(Enemigo(tipo, nombre, nivel, vida));
}
void eliminarEnemigo()
{
    system("cls");

    Lista<Enemigo> *temp = lstEnemigos.getFront();
    int i = 0;
    int opt;

    cout << " ELIMINAR ENEMIGO" << endl;

    while (temp)
    {
        cout << " [" << i + 1 << "]" << temp->getData().getNombre() << endl;
        temp = temp->getBack();
        i++;
    }

    cout << " [0] Volver" << endl;
    cout << "    >";
    cin >> opt;

    if (opt == 0)
    {
        return;
    }

    lstEnemigos.removeAt(opt - 1);
}
void menuTirarDadosGM()
{
    int opt;

    do
    {
        system("cls");
        cout << " MENU TIRAR DADOS" << endl;
        cout << " [1] Dado 4 caras" << endl;
        cout << " [2] Dado 6 caras" << endl;
        cout << " [3] Dado 8 caras" << endl;
        cout << " [4] Dado 10 caras" << endl;
        cout << " \t>";
        cin >> opt;

        switch (opt)
        {
        case 1:
            tools.dado4Caras();
            break;
        case 2:
            tools.dado6Caras();
            break;
        case 3:
            tools.dado8Caras();
            break;
        case 4:
            tools.dado10Caras();
            break;

        default:
            break;
        }
    } while (opt != 1 && opt != 2 && opt != 3 && opt != 4);
}