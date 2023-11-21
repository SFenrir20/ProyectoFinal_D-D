#include <iostream>
#include <vector>
#include "../Model/Personaje.cpp"
#include "../Model/Clase.cpp"
#include "../Model/Dados.cpp"
#include "../Model/Mochila.cpp"
#include "../Model/Item.cpp"
#include "../Model/Tools.cpp"
#include "../Controller/ClasesController.h"
#include "../Controller/RazasController.h"
#include "../Controller/ItemsController.h"

using namespace std;

ItemsController iController;

Personaje player;
Mochila<int> mochila;
Item slots[5] = {Item(), Item(), Item(), Item(), Item()};
int itemCount = 0;
int turnCount = 0;

void menuPlayer();
void crearPersonaje();
Raza seleccionRaza();
Clase seleccionClase();
int dado();
void menuStats();
void canjearXP();
void viewAllPlayerData();
void menuTurno();
void accionAtacar();
void accionDefender();
void accionHablar();
void accionPasar();
void menuResultado();
void resultadoXp();
void resultadoObj();
Item obtenerCofre();
void saveItemBag(Item, bool);
void resultadoPerdi();
void menuInventario();
void menuComprar();
void comprarDM();
void comprarJugador();
Item comprarItem(int);
void menuVender();
void venderDM();
void venderJugador();
void menuIntercambiar();
int itemOfrecer();
Item itemRecibir();
void menuEquipamiento();
void accionArma();
void accionProteccion();
void accionArmadura();
void accionConsumible1();
void accionConsumible2();
void compararSkills(Item, bool &);
void menuTirarDadosPlayer();

void menuPlayer()
{
    int opt;
    int optM;

    system("cls");

    crearPersonaje();

    do
    {
        while (!player.getEstado())
        {
            system("cls");
            cout << " TE QUEDASTE SIN PUNTOS DE VIDA" << endl;
            cout << " [1] El DM me revivio" << endl;
            cout << " [0] Finalizar partida" << endl;
            cout << "\t>";
            cin >> optM;

            if (optM == 0)
            {
                return;
            }
            else if (optM == 1)
            {
                player.setEstado(true);
                player.setPuntosVidaPerdidos(0);
            }
        }

        system("cls");
        cout << " Bienvenido JUGADOR" << endl;
        cout << " Nombre: " << player.getNombre() << endl;
        cout << " Clase: " << player.getClase().getNombre() << endl;
        cout << " Raza: " << player.getRaza().getNombre() << endl;
        cout << " Vida: " << player.getPuntosVida() - player.getPuntosVidaPerdidos() << "/" << player.getPuntosVida() << endl;
        cout << " Nivel: " << player.getNivel() << endl;
        cout << " Oro: " << player.getOro() << endl;
        cout << " Turnos jugados: " << turnCount << endl;
        cout << " [1] Stats" << endl;
        cout << " [2] Jugar turno" << endl;
        cout << " [3] Inventario" << endl;
        cout << " [4] Equipamiento" << endl;
        cout << " [5] Tirar dados" << endl;
        cout << " [0] Finalizar partida" << endl;
        cout << " \t>";
        cin >> opt;

        switch (opt)
        {
        case 1:
            menuStats();
            break;
        case 2:
            menuTurno();
            break;
        case 3:
            menuInventario();
            break;
        case 4:
            menuEquipamiento();
            break;
        case 5:
            menuTirarDadosPlayer();
            menuResultado();
            break;

        default:
            break;
        }
    } while (opt != 0);
}

void crearPersonaje()
{
    system("cls");

    string nombre = "";
    Raza raza;
    Clase clase;
    int roleos[8];

    cout << " Creacion de Personaje" << endl;
    raza = seleccionRaza();
    clase = seleccionClase();

    int vida = raza.getVida();
    int mana = raza.getMana();
    int velocidad = raza.getVelocidad();
    int gracia = raza.getGracia();
    int danMagico = raza.getDanMagico();
    int danFisico = raza.getDanFisico();
    int defFisica = raza.getDefFisica();
    int defMagica = raza.getDefMagica();

    bool _vida = false;
    bool _mana = false;
    bool _velocidad = false;
    bool _gracia = false;
    bool _danFisico = false;
    bool _danMagico = false;
    bool _defFisica = false;
    bool _defMagica = false;

    for (int i = 0; i < 8; i++)
    {
        roleos[i] = dado();
    }

    tools.bubbleSortDes(roleos, 8);

    for (int i = 0; i < 8; i++)
    {
        if (vida == i + 1 && !_vida)
        {
            vida = roleos[i];
            _vida = true;
        }
        else if (mana == i + 1 && !_mana)
        {
            mana = roleos[i];
            _mana = true;
        }
        else if (velocidad == i + 1 && !_velocidad)
        {
            velocidad = roleos[i];
            _velocidad = true;
        }
        else if (gracia == i + 1 && !_gracia)
        {
            gracia = roleos[i];
            _gracia = true;
        }
        else if (danMagico == i + 1 && !_danMagico)
        {
            danMagico = roleos[i];
            _danMagico = true;
        }
        else if (danFisico == i + 1 && !_danFisico)
        {
            danFisico = roleos[i];
            _danFisico = true;
        }
        else if (defFisica == i + 1 && !_defFisica)
        {
            defFisica = roleos[i];
            _defFisica = true;
        }
        else if (defMagica == i + 1 && !_defMagica)
        {
            defMagica = roleos[i];
            _defMagica = true;
        }
    }

    player = Personaje(nombre, raza, clase, vida, mana, velocidad, gracia, defMagica, defFisica, danMagico, danFisico);

    system("cls");

    player.setSkills();
    player.updateStats();

    cout << "Ingrese su nombre: ";
    cin >> nombre;

    player.setNombre(nombre);

    system("cls");
    viewAllPlayerData();
    system("pause");
}
Raza seleccionRaza()
{
    int opt;
    int dec;
    Raza temp;

    do
    {
        int i = 0;
        Lista<Raza> *lstRazas = rController.readLstRazas();
        do
        {
            system("cls");

            cout << " RAZAS DISPONIBLES (seleccione para mas informacion)" << endl;

            while (lstRazas)
            {
                cout << " [" << i + 1 << "] " << lstRazas->getData().getNombre() << endl;
                lstRazas = lstRazas->getBack();
                i++;
            }

            cout << "\t>";
            cin >> opt;
        } while (opt < 1 || opt > i);

        system("cls");

        temp = rController.getDataAtIndex(opt - 1);

        cout << temp.getNombre() << endl;
        cout << " Descripcion: " << temp.getDescripcion() << endl;
        cout << " Prioridad de estadisticas (Del 1-8): " << endl;
        cout << "\tVida: " << temp.getVida() << endl;
        cout << "\tMana: " << temp.getMana() << endl;
        cout << "\tDano Fisico: " << temp.getDanFisico() << endl;
        cout << "\tDano Magico: " << temp.getDanMagico() << endl;
        cout << "\tDefensa Fisica: " << temp.getDefFisica() << endl;
        cout << "\tDefensa Magica: " << temp.getDefMagica() << endl;
        cout << "\tGracia: " << temp.getGracia() << endl;
        cout << "\tVelocidad: " << temp.getVelocidad() << endl;

        cout << "¿Desea seleccionar " << temp.getNombre() << " como su raza?" << endl;
        cout << "[1] SI" << endl;
        cout << "[2] NO" << endl;
        cin >> dec;
    } while (dec != 1);

    return temp;
}
Clase seleccionClase()
{
    int opt;
    int dec;
    Clase temp;

    do
    {
        int i = 0;
        Lista<Clase> *lstClases = cController.readLstClases();
        do
        {
            system("cls");

            cout << " Clases DISPONIBLES (seleccione para mas informacion)" << endl;

            while (lstClases)
            {
                cout << " [" << i + 1 << "] " << lstClases->getData().getNombre() << endl;
                lstClases = lstClases->getBack();
                i++;
            }

            cout << "\t>";
            cin >> opt;
        } while (opt < 1 && opt > i);

        system("cls");

        temp = cController.getDataAtIndex(opt - 1);

        cout << temp.getNombre() << endl;
        cout << " Descripcion: " << temp.getDescripcion();
        cout << " Multiplicador de skills " << endl;
        cout << "\tFuerza: x" << temp.getFuerza() << " a vida" << endl;
        cout << "\tInteligencia: x" << temp.getInteligencia() << " a mana" << endl;
        cout << "\tAgilidad: x" << temp.getAgilidad() << " a velocidad" << endl;
        cout << "\tFrenesi: x" << temp.getFrenesi() << " a dano fisico" << endl;
        cout << "\tSabiduria: x" << temp.getSabiduria() << " a dano magico" << endl;
        cout << "\tArmadura: x" << temp.getArmadura() << " a defensa fisica" << endl;
        cout << "\tVoluntad: x" << temp.getVoluntad() << " a defensa magica" << endl;
        cout << "\tCarisma: x" << temp.getCarisma() << " a gracia" << endl;
        cout << "\tAnimal Handling: x" << temp.getAnimalHandling() << " a gracia" << endl;
        cout << "\tVelocidad de ataque: x" << temp.getVelocidadAtaque1() << " a velocidad y x" << temp.getVelocidadAtaque2() << " a dano fisico" << endl;
        cout << "\tDestreza: x" << temp.getDestreza1() << " a vida y x" << temp.getDestreza2() << " a velocidad" << endl;
        cout << "\tArcano: x" << temp.getArcano() << " a gracia" << endl;

        cout << "¿Desea seleccionar " << temp.getNombre() << " como su clase?" << endl;
        cout << "[1] SI" << endl;
        cout << "[2] NO" << endl;
        cin >> dec;
    } while (dec != 1);

    return temp;
}
int dado()
{
    vector<int> opcionesD1 = {1, 2, 3, 4, 5, 6};
    Dados d1 = Dados(opcionesD1);
    int sum = 0;
    int menor = 6;
    int num;

    for (int i = 0; i < 4; i++)
    {
        num = d1.tirarDados();
        sum += num;
        if (num < menor)
        {
            menor = num;
        }
    }
    sum -= menor;

    return sum;
}
void menuStats()
{
    int opt;

    do
    {
        system("cls");
        cout << " MENU STATS" << endl;
        cout << " XP: " << player.getPuntosExp() << endl;
        viewAllPlayerData();
        cout << " [1] Canjear XP" << endl;
        cout << " [0] Volver" << endl;
        cout << "\t>";
        cin >> opt;

        switch (opt)
        {
        case 1:
            canjearXP();
            break;

        default:
            break;
        }

    } while (opt != 0);
}
void canjearXP()
{
    int opt;
    double xp;

    do
    {
        xp = player.getPuntosExp();

        system("cls");
        
        if (xp == 0)
        {
            cout << "No tienes puntos de experiencia por canjear." << endl;
            system("pause");
            return;
        }

        player.updateStats();
        cout << " CANJEAR XP" << endl;
        cout << " XP disponible: " << xp << endl;
        cout << " [1]  Subir de nivel (20 XP): " << player.getNivel() << endl;
        cout << " [2]  Fuerza: " << player.getFuerza() << endl;
        cout << " [3]  Inteligencia: " << player.getInteligencia() << endl;
        cout << " [4]  Agilidad: " << player.getAgilidad() << endl;
        cout << " [5]  Frenesi: " << player.getFrenesi() << endl;
        cout << " [6]  Sabiduria: " << player.getSabiduria() << endl;
        cout << " [7]  Armadura: " << player.getArmadura() << endl;
        cout << " [8]  Voluntad: " << player.getVoluntad() << endl;
        cout << " [9]  Carisma: " << player.getCarisma() << endl;
        cout << " [10] Animal Handling: " << player.getAnimalHandling() << endl;
        cout << " [11] Velocidad de ataque: " << player.getVelocidadAtaque() << endl;
        cout << " [12] Destreza: " << player.getDestreza() << endl;
        cout << " [13] Arcano: " << player.getArcano() << endl;
        cout << " [0]  Volver" << endl;
        cout << "\t>";
        cin >> opt;

        switch (opt)
        {
        case 1:
            if (xp >= 20)
            {
                player.lvlUp();
            }
            break;
        case 2:
            player.setFuerza(player.getFuerza() + 1);
            player.setPuntosExp(xp-1);
            break;
        case 3:
            player.setInteligencia(player.getInteligencia() + 1);
            player.setPuntosExp(xp-1);
            break;
        case 4:
            player.setAgilidad(player.getAgilidad() + 1);
            player.setPuntosExp(xp-1);
            break;
        case 5:
            player.setFrenesi(player.getFrenesi() + 1);
            player.setPuntosExp(xp-1);
            break;
        case 6:
            player.setSabiduria(player.getSabiduria() + 1);
            player.setPuntosExp(xp-1);
            break;
        case 7:
            player.setArmadura(player.getArmadura() + 1);
            player.setPuntosExp(xp-1);
            break;
        case 8:
            player.setVoluntad(player.getVoluntad() + 1);
            player.setPuntosExp(xp-1);
            break;
        case 9:
            player.setCarisma(player.getCarisma() + 1);
            player.setPuntosExp(xp-1);
            break;
        case 10:
            player.setAnimalHandling(player.getAnimalHandling() + 1);
            player.setPuntosExp(xp-1);
            break;
        case 11:
            player.setVelocidadAtaque(player.getVelocidadAtaque() + 1);
            player.setPuntosExp(xp-1);
            break;
        case 12:
            player.setDestreza(player.getDestreza() + 1);
            player.setPuntosExp(xp-1);
            break;
        case 13:
            player.setArcano(player.getArcano() + 1);
            player.setPuntosExp(xp-1);
            break;

        default:
            break;
        }

    } while (opt != 0);
}
void viewAllPlayerData()
{
    cout << "Nombre: " << player.getNombre() << endl;
    cout << "Raza: " << player.getRaza().getNombre() << endl;
    cout << "Clase: " << player.getClase().getNombre() << endl;
    cout << "Nivel: " << player.getNivel() << endl;
    cout << "Oro: " << player.getOro() << endl;
    cout << "Stats" << endl;
    cout << "\tVida: " << player.getPuntosVida() - player.getPuntosVidaPerdidos() << "/" << player.getPuntosVida() << endl;
    cout << "\tMana: " << player.getPuntosMana() << endl;
    cout << "\tDano fisico: " << player.getPuntosDanFisico() << endl;
    cout << "\tDano magico: " << player.getPuntosDanMagico() << endl;
    cout << "\tDefensa fisica: " << player.getPuntosDefFisica() << endl;
    cout << "\tDefensa magica: " << player.getPuntosDefMagica() << endl;
    cout << "\tGracia: " << player.getPuntosGracia() << endl;
    cout << "\tVelocidad: " << player.getPuntosVelocidad() << endl;
    cout << "Skills" << endl;
    cout << "\tFuerza: " << player.getFuerza() << endl;
    cout << "\tInteligencia: " << player.getInteligencia() << endl;
    cout << "\tAgilidad: " << player.getAgilidad() << endl;
    cout << "\tFrenesi: " << player.getFrenesi() << endl;
    cout << "\tSabiduria: " << player.getSabiduria() << endl;
    cout << "\tArmadura: " << player.getArmadura() << endl;
    cout << "\tVoluntad: " << player.getVoluntad() << endl;
    cout << "\tCarisma: " << player.getCarisma() << endl;
    cout << "\tAnimal Handling: " << player.getAnimalHandling() << endl;
    cout << "\tVelocidad de ataque: " << player.getVelocidadAtaque() << endl;
    cout << "\tDestreza: " << player.getDestreza() << endl;
    cout << "\tArcano: " << player.getArcano() << endl;
}
void menuTurno()
{
    int opt;

    do
    {
        system("cls");
        cout << " QUE HACER?" << endl;
        cout << " [1] Atacar" << endl;
        cout << " [2] Defender" << endl;
        cout << " [3] Hablar" << endl;
        cout << " [4] Pasar turno" << endl;
        cout << " [0] Volver" << endl;
        cout << " \t>";
        cin >> opt;

        switch (opt)
        {
        case 1:
            accionAtacar();
            break;
        case 2:
            accionDefender();
            break;
        case 3:
            accionHablar();
            break;
        case 4:
            accionPasar();
            break;

        default:
            break;
        }
    } while (opt != 0 && opt != 1 && opt != 2 && opt != 3 && opt != 4);
}
void accionAtacar()
{
    menuTirarDadosPlayer();
    menuResultado();
    turnCount++;
}
void accionDefender()
{
    menuTirarDadosPlayer();
    menuResultado();
    turnCount++;
}
void accionHablar()
{
    menuTirarDadosPlayer();
    menuResultado();
    turnCount++;
}
void accionPasar()
{
    menuTirarDadosPlayer();
    menuResultado();
    turnCount++;
}
void menuResultado()
{
    int opt;

    do
    {
        system("cls");
        cout << " QUE OCURRIO?" << endl;
        cout << " [1] Gane xp/oro" << endl;
        cout << " [2] Gane caja/oro" << endl;
        cout << " [3] Perdi vida" << endl;
        cout << " [4] Nada" << endl;
        cout << " \t>";
        cin >> opt;

        switch (opt)
        {
        case 1:
            resultadoXp();
            break;
        case 2:
            resultadoObj();
            break;
        case 3:
            resultadoPerdi();
            break;

        default:
            break;
        }
    } while (opt != 1 && opt != 2 && opt != 3 && opt != 4);
}
void resultadoXp()
{
    int exp;
    int oro;
    system("cls");
    cout << " AUMENTAR XP Y ORO" << endl;
    cout << " Cuantos puntos de experiencia ganaste?" << endl;
    cout << "\t>";
    cin >> exp;
    cout << " Cuanto oro ganaste?" << endl;
    cout << "\t>";
    cin >> oro;

    player.setPuntosExp(player.getPuntosExp() + exp);
    player.setOro(player.getOro() + oro);
}
void resultadoObj()
{
    int oro;
    system("cls");
    cout << " RECIBIR CAJA Y ORO" << endl;
    cout << " Cuanto oro ganaste?" << endl;
    cout << "\t>";
    cin >> oro;
    cout << " Abriendo caja..." << endl;

    Item temp = obtenerCofre();

    saveItemBag(temp, true);
    player.setOro(player.getOro() + oro);
}
Item obtenerCofre()
{
    int numeroAleatorio = rand() % 1001;

    if (numeroAleatorio < 500)
    {
        cout << " Obtuviste un item Comun." << endl;
        return iController.getRandomComun();
    }
    else if (numeroAleatorio < 750)
    {
        cout << " Obtuviste un item Raro." << endl;
        return iController.getRandomRaro();
    }
    else if (numeroAleatorio < 900)
    {
        cout << " Obtuviste un item Epico!!!" << endl;
        return iController.getRandomEpico();
    }
    else if (numeroAleatorio < 975)
    {
        cout << " Wow, Obtuviste un item Legendario." << endl;
        return iController.getRandomLegendario();
    }
    else if (numeroAleatorio < 999)
    {
        cout << " Felicidades, obtuviste un item tipo Inmortal!!!" << endl;
        return iController.getRandomInmortal();
    }
    else
    {
        cout << " Wow!!!!! Felicidades, obtuviste un item tipo Dios!!!" << endl;
        return iController.getRandomDios();
    }
}
void saveItemBag(Item item, bool isNew)
{
    bool hc = false;

    if (isNew)
    {
        itemCount++;
        item.setNumOrden(itemCount);
    }

    mochila.setRaiz(mochila.insertarItem(mochila.getRaiz(), item, item.getNumOrden(), hc));
}
void resultadoPerdi()
{
    double vida;
    system("cls");
    cout << " PERDER VIDA" << endl;
    cout << " Cuanta puntos de vida perdiste?" << endl;
    cout << "\t>";
    cin >> vida;

    player.setPuntosVidaPerdidos(player.getPuntosVidaPerdidos() + vida);
    if (player.getPuntosVida() <= player.getPuntosVidaPerdidos())
    {
        player.setEstado(false);
    }
}
void menuInventario()
{
    int opt;

    do
    {
        system("cls");
        cout << " MENU INVENTARIO" << endl;
        mochila.listarItemsMayor(mochila.getRaiz(), false);
        cout << " [1] Comprar" << endl;
        cout << " [2] Vender" << endl;
        cout << " [3] Intercambiar" << endl;
        cout << " [0] Volver" << endl;
        cout << " \t>";
        cin >> opt;

        switch (opt)
        {
        case 1:
            menuComprar();
            break;
        case 2:
            menuVender();
            break;
        case 3:
            menuIntercambiar();
            break;

        default:
            break;
        }
    } while (opt != 0);
}
void menuComprar()
{
    int opt;

    do
    {
        system("cls");
        cout << " MENU COMPRAR" << endl;
        cout << " [1] Comprar DM" << endl;
        cout << " [2] Comprar Jugador" << endl;
        cout << " [0] Volver" << endl;
        cout << " \t>";
        cin >> opt;

        switch (opt)
        {
        case 1:
            comprarDM();
            break;
        case 2:
            comprarJugador();
            break;

        default:
            break;
        }
    } while (opt != 0);
}
void comprarDM()
{
    int oroActual = player.getOro();
    int oroComprar;
    bool enough = false;
    int opt;
    Item temp;

    do
    {
        system("cls");
        cout << " COMPRAR AL DUNGEON MASTER" << endl;
        cout << " Tu oro: " << oroActual << endl;
        cout << " Ingrese el oro a pagar: ";
        cin >> oroComprar;

        temp = comprarItem(oroComprar);

        if (oroActual < oroComprar || temp.getNombre() == "")
        {
            cout << " Oro insuficiente..." << endl;
            system("pause");
            enough = false;
            return;
        }
        else
        {
            enough = true;
        }
    } while (!enough);

    do
    {
        system("cls");

        cout << " El item a recibir será de tipo:" << temp.getRareza().tipo << endl;
        cout << " [1] Comprar" << endl;
        cout << " [0] Cancelar compra" << endl;
        cout << "\t>";
        cin >> opt;

        if (opt == 1)
        {
            cout << " Compra exitosa, revise su mochila.";
            saveItemBag(temp, true);
            player.setOro(player.getOro() - oroComprar);
        }
    } while (opt != 0 && opt != 1);
}
void comprarJugador()
{
    int oroActual = player.getOro();
    int rareza;
    int i = 1;
    int usos;
    int precio;
    int opt;
    string nombre;
    string rarezaTemp;
    bool found = false;
    bool enough = false;
    Item temp;
    Lista<Item> *lst;

    do
    {
        system("cls");
        cout << " COMPRAR A OTRO JUGADOR" << endl;
        cout << " Tu oro: " << oroActual << endl;
        cout << " DATOS DEL ITEM A COMPRAR" << endl;
        cout << " Seleccione la rareza del item" << endl;
        cout << " [1] Comun" << endl;
        cout << " [2] Raro" << endl;
        cout << " [3] Epico" << endl;
        cout << " [4] Legendario" << endl;
        cout << " [5] Inmortal" << endl;
        cout << " [6] Dios" << endl;
        cout << " [0] Volver" << endl;
        cin >> rareza;

        if (rareza == 0)
        {
            return;
        }

    } while (rareza != 1 && rareza != 2 && rareza != 3 && rareza != 4 && rareza != 5 && rareza != 6);

    switch (rareza)
    {
    case 1:
        rarezaTemp = "Comun";
        lst = iController.readLstComun();
        break;
    case 2:
        rarezaTemp = "Raro";
        lst = iController.readLstRaro();
        break;
    case 3:
        rarezaTemp = "Epico";
        lst = iController.readLstEpico();
        break;
    case 4:
        rarezaTemp = "Legendario";
        lst = iController.readLstLegendario();
        break;
    case 5:
        rarezaTemp = "Inmortal";
        lst = iController.readLstInmortal();
        break;
    case 6:
        rarezaTemp = "Dios";
        lst = iController.readLstDios();
        break;

    default:
        break;
    }

    do
    {
        system("cls");
        cout << " COMPRAR A OTRO JUGADOR" << endl;
        cout << " Tu oro: " << oroActual << endl;
        cout << " DATOS DEL ITEM A COMPRAR" << endl;
        cout << "\tRareza: " << rarezaTemp << endl;
        cout << " Ingrese el nombre del objeto: " << endl;
        cin >> nombre;

        while (lst)
        {
            if (lst->getData().getNombre() == nombre)
            {
                found = true;
                temp = lst->getDataAtPosition(i);
            }
            lst = lst->getBack();
            i++;
        }
    } while (!found);

    do
    {
        system("cls");
        cout << " COMPRAR A OTRO JUGADOR" << endl;
        cout << " Tu oro: " << oroActual << endl;
        cout << " DATOS DEL ITEM A COMPRAR" << endl;
        cout << "\tRareza: " << temp.getRareza().tipo << endl;
        cout << "\tNombre: " << temp.getNombre() << endl;
        cout << "\tDescripcion: " << temp.getDescripcion() << endl;
        cout << " Ingrese el numero de usos restantes (-1 si es permanente): ";
        cin >> usos;

        if (usos == 0)
        {
            cout << " No puede comprar un item sin usos" << endl;
            system("pause");
        }

    } while (usos < -1 || usos == 0);

    temp.setUsos(usos);

    do
    {
        system("cls");
        cout << " COMPRAR A OTRO JUGADOR" << endl;
        cout << " Tu oro: " << oroActual << endl;
        cout << " DATOS DEL ITEM A COMPRAR" << endl;
        cout << "\tRareza: " << temp.getRareza().tipo << endl;
        cout << "\tNombre: " << temp.getNombre() << endl;
        cout << "\tDescripcion: " << temp.getDescripcion() << endl;
        cout << "\tUsos restantes: " << temp.getUsos() << endl;
        cout << "\tPrecio recomendado: " << temp.getPrecio() * temp.getRareza().valor << endl;
        cout << "Precio acordado: ";
        cin >> precio;

        if (oroActual < precio)
        {
            cout << "Oro insuficiente" << endl;
            system("pause");
        }
        else
        {
            enough = true;
        }
    } while (!enough);

    do
    {
        system("cls");
        cout << " COMPRAR A OTRO JUGADOR" << endl;
        cout << " Tu oro: " << oroActual << endl;
        cout << " DATOS DEL ITEM A COMPRAR" << endl;
        cout << "\tRareza: " << temp.getRareza().tipo << endl;
        cout << "\tNombre: " << temp.getNombre() << endl;
        cout << "\tDescripcion: " << temp.getDescripcion() << endl;
        cout << "\tUsos restantes: " << temp.getUsos() << endl;
        cout << "\tPrecio recomendado: " << temp.getPrecio() * temp.getRareza().valor << endl;
        cout << "\tPrecio acordado: " << precio << endl;
        cout << " Confirmar compra: ";
        cout << " [1] Comprar" << endl;
        cout << " [0] Cancelar compra" << endl;
        cout << "\t>";
        cin >> opt;

        if (opt == 1)
        {
            cout << " Compra exitosa, revise su mochila.";
            saveItemBag(temp, true);
            player.setOro(player.getOro() - precio);
        }
    } while (opt != 0 && opt != 1);
}
Item comprarItem(int monto)
{
    Item temp;

    if (50 <= monto && monto <= 100)
    {
        return iController.getRandomComun();
    }
    else if (150 <= monto && monto <= 300)
    {
        return iController.getRandomRaro();
    }
    else if (500 <= monto && monto <= 1000)
    {
        return iController.getRandomEpico();
    }
    else if (1500 <= monto && monto <= 3000)
    {
        return iController.getRandomLegendario();
    }
    else if (3000 <= monto && monto <= 5500)
    {
        return iController.getRandomInmortal();
    }
    else if (6000 <= monto)
    {
        return iController.getRandomDios();
    }
    else
    {
        return temp;
    }
}
void menuVender()
{
    int opt;

    do
    {
        system("cls");
        cout << " MENU VENDER" << endl;
        cout << " [1] Vender DM" << endl;
        cout << " [2] Vender Jugador" << endl;
        cout << " [0] Volver" << endl;
        cout << " \t>";
        cin >> opt;

        switch (opt)
        {
        case 1:
            venderDM();
            break;
        case 2:
            venderJugador();
            break;

        default:
            break;
        }
    } while (opt != 0);
}
void venderDM()
{
    int opt;
    int condicion;
    int precioVenta;
    bool hc = false;

    do
    {
        system("cls");

        do
        {
            system("cls");

            cout << " VENDER AL DM" << endl;
            mochila.listarItemsMenor(mochila.getRaiz(), true);
            cout << " [0] Volver" << endl;
            cout << " SELECCIONE EL ITEM A VENDER" << endl;
            cout << " \t>";
            cin >> opt;

            if (opt == 0)
            {
                return;
            }
        } while (opt <= 0 && itemCount <= opt);

        Bolsillo<int> *temp = mochila.buscarItem(mochila.getRaiz(), opt);
        precioVenta = temp->getItem().getPrecio() * temp->getItem().getRareza().valor;

        system("cls");
        cout << " Seguro que desea vender el siguiente item?" << endl;
        cout << " " << temp->getItem().getNombre() << endl;
        cout << "\tRareza: " << temp->getItem().getRareza().tipo << endl;
        cout << "\tPrecio de venta: " << precioVenta << endl;
        cout << " [1] Si, seguro." << endl;
        cout << " [0] No, volver." << endl;
        cout << "\t>";
        cin >> condicion;
    } while (condicion != 1);

    player.setOro(player.getOro() + precioVenta);
    mochila.eliminarItem(opt, hc);

    cout << " Item vendido con exito." << endl;
    system("pause");
}
void venderJugador()
{
    int opt;
    int condicion;
    int precioVenta;
    bool hc = false;
    Bolsillo<int> *temp;

    do
    {
        system("cls");

        do
        {
            system("cls");

            cout << " VENDER A OTRO JUGADOR" << endl;
            mochila.listarItemsMenor(mochila.getRaiz(), true);
            cout << " [0] Volver" << endl;
            cout << " SELECCIONE EL ITEM A VENDER" << endl;
            cout << " \t>";
            cin >> opt;

            if (opt == 0)
            {
                return;
            }
        } while (opt <= 0 && itemCount <= opt);

        temp = mochila.buscarItem(mochila.getRaiz(), opt);
        precioVenta = temp->getItem().getPrecio() * temp->getItem().getRareza().valor;

        system("cls");
        cout << " Seguro que desea vender el siguiente item?" << endl;
        cout << " " << temp->getItem().getNombre() << endl;
        cout << "\tRareza: " << temp->getItem().getRareza().tipo << endl;
        cout << "\tPrecio de venta base: " << precioVenta << endl;
        cout << "\tTipo: " << temp->getItem().getTipo() << endl;
        cout << " [1] Si, seguro." << endl;
        cout << " [0] No, volver." << endl;
        cout << "\t>";
        cin >> condicion;
    } while (condicion != 1);

    system("cls");
    cout << " PROPORCIONE LOS DATOS DEL ITEM AL COMPRADOR" << endl;
    cout << " " << temp->getItem().getNombre() << endl;
    cout << "\tRareza: " << temp->getItem().getRareza().tipo << endl;
    cout << "\tTipo: " << temp->getItem().getTipo() << endl;
    if (temp->getItem().getUsos() == -1)
    {
        cout << "\tUsos restantes: Permanente" << endl;
    }
    else
    {
        cout << "\tUsos restantes: " << temp->getItem().getUsos() << endl;
    }
    cout << "Ingrese el precio de venta: ";
    cin >> precioVenta;
    system("pause");

    player.setOro(player.getOro() + precioVenta);
    mochila.eliminarItem(opt, hc);

    cout << " Item vendido con exito." << endl;
    system("pause");
}
void menuIntercambiar()
{
    int opt;
    int index;
    Item temp;
    bool hc = false;

    do
    {
        system("cls");
        cout << " MENU INTERCAMBIAR" << endl;
        cout << " [1] Primero ofrecer item" << endl;
        cout << " [2] Primero recibir item" << endl;
        cout << " [0] Volver" << endl;
        cout << " \t>";
        cin >> opt;

        if (opt == 0)
        {
            return;
        }
    } while (opt != 0);

    if (opt == 1)
    {
        index = itemOfrecer();
        temp = itemRecibir();
    }
    else
    {
        temp = itemRecibir();
        index = itemOfrecer();
    }

    if (temp.getNombre() != "NULL" || index == 0)
    {
        return;
    }

    mochila.eliminarItem(index, hc);
    saveItemBag(temp, true);

    system("cls");
    cout << " Intercambio exitoso. Revise su mochila." << endl;
    system("pause");
}
int itemOfrecer()
{
    int opt;
    int condicion;
    int precioVenta;
    Bolsillo<int> *temp;

    do
    {
        system("cls");

        do
        {
            system("cls");

            cout << " INTERCAMBIO A OTRO JUGADOR" << endl;
            mochila.listarItemsMenor(mochila.getRaiz(), true);
            cout << " [0] Cancelar intercambio" << endl;
            cout << " SELECCIONE EL ITEM A INTERCAMBIAR" << endl;
            cout << " \t>";
            cin >> opt;

            if (opt == 0)
            {
                return 0;
            }
        } while (opt <= 0 && itemCount <= opt);

        temp = mochila.buscarItem(mochila.getRaiz(), opt);
        precioVenta = temp->getItem().getPrecio() * temp->getItem().getRareza().valor;

        system("cls");
        cout << " Seguro que desea intercambiar el siguiente item?" << endl;
        cout << " " << temp->getItem().getNombre() << endl;
        cout << "\tRareza: " << temp->getItem().getRareza().tipo << endl;
        cout << "\tPrecio de venta base: " << precioVenta << endl;
        cout << "\tTipo: " << temp->getItem().getTipo() << endl;
        cout << " [1] Si, seguro." << endl;
        cout << " [0] No, volver." << endl;
        cout << "\t>";
        cin >> condicion;
    } while (condicion != 1);

    system("cls");
    cout << " PROPORCIONE LOS DATOS DEL ITEM AL OTRO JUGADOR" << endl;
    cout << " " << temp->getItem().getNombre() << endl;
    cout << "\tRareza: " << temp->getItem().getRareza().tipo << endl;
    cout << "\tTipo: " << temp->getItem().getTipo() << endl;
    if (temp->getItem().getUsos() == -1)
    {
        cout << "\tUsos restantes: Permanente" << endl;
    }
    else
    {
        cout << "\tUsos restantes: " << temp->getItem().getUsos() << endl;
    }
    system("pause");

    return opt;
}
Item itemRecibir()
{
    int rareza;
    int i = 1;
    int usos;
    int opt;
    string nombre;
    string rarezaTemp;
    bool found = false;
    Item temp;
    Lista<Item> *lst;

    do
    {
        system("cls");
        cout << " INTERCAMBIO A OTRO JUGADOR" << endl;
        cout << " DATOS DEL ITEM A RECIBIR" << endl;
        cout << " Seleccione la rareza del item" << endl;
        cout << " [1] Comun" << endl;
        cout << " [2] Raro" << endl;
        cout << " [3] Epico" << endl;
        cout << " [4] Legendario" << endl;
        cout << " [5] Inmortal" << endl;
        cout << " [6] Dios" << endl;
        cout << " [0] Cancelar intercambio" << endl;
        cin >> rareza;

        if (rareza == 0)
        {
            temp.setNombre("NULL");
            return temp;
        }

    } while (rareza != 1 && rareza != 2 && rareza != 3 && rareza != 4 && rareza != 5 && rareza != 6);

    switch (rareza)
    {
    case 1:
        rarezaTemp = "Comun";
        lst = iController.readLstComun();
        break;
    case 2:
        rarezaTemp = "Raro";
        lst = iController.readLstRaro();
        break;
    case 3:
        rarezaTemp = "Epico";
        lst = iController.readLstEpico();
        break;
    case 4:
        rarezaTemp = "Legendario";
        lst = iController.readLstLegendario();
        break;
    case 5:
        rarezaTemp = "Inmortal";
        lst = iController.readLstInmortal();
        break;
    case 6:
        rarezaTemp = "Dios";
        lst = iController.readLstDios();
        break;

    default:
        break;
    }

    do
    {
        system("cls");
        cout << " INTERCAMBIO A OTRO JUGADOR" << endl;
        cout << " DATOS DEL ITEM A RECIBIR" << endl;
        cout << "\tRareza: " << rarezaTemp << endl;
        cout << " Ingrese el nombre del objeto: " << endl;
        cin >> nombre;

        while (lst)
        {
            if (lst->getData().getNombre() == nombre)
            {
                found = true;
                temp = lst->getDataAtPosition(i);
            }
            lst = lst->getBack();
            i++;
        }
    } while (!found);

    do
    {
        system("cls");
        cout << " INTERCAMBIO A OTRO JUGADOR" << endl;
        cout << " DATOS DEL ITEM A RECIBIR" << endl;
        cout << "\tRareza: " << temp.getRareza().tipo << endl;
        cout << "\tNombre: " << temp.getNombre() << endl;
        cout << "\tDescripcion: " << temp.getDescripcion() << endl;
        cout << " Ingrese el numero de usos restantes (-1 si es permanente): ";
        cin >> usos;

        if (usos == 0)
        {
            cout << " No puede comprar un item sin usos" << endl;
            system("pause");
        }

    } while (usos < -1 || usos == 0);

    temp.setUsos(usos);

    do
    {
        system("cls");
        cout << " INTERCAMBIO A OTRO JUGADOR" << endl;
        cout << " DATOS DEL ITEM A RECIBIR" << endl;
        cout << "\tRareza: " << temp.getRareza().tipo << endl;
        cout << "\tNombre: " << temp.getNombre() << endl;
        cout << "\tDescripcion: " << temp.getDescripcion() << endl;
        cout << "\tUsos restantes: " << temp.getUsos() << endl;
        cout << "\tPrecio recomendado: " << temp.getPrecio() * temp.getRareza().valor << endl;
        cout << " Confirmar intercambio" << endl;
        cout << " [1] Recibir" << endl;
        cout << " [0] Cancelar intercambio" << endl;
        cout << "\t>";
        cin >> opt;

        if (opt == 0)
        {
            temp.setNombre("NULL");
            return temp;
        }
    } while (opt != 0 && opt != 1);

    return temp;
}
void menuEquipamiento()
{
    int opt;

    do
    {
        system("cls");
        cout << " MENU EQUIPAMIENTO" << endl;
        for (int i = 0; i < 5; i++)
        {
            if (slots[i].getNombre() != "")
            {
                cout << " " << slots[i].getNombre() << endl;
                cout << "\t" << slots[i].getNombre() << endl;
                cout << "\t" << slots[i].getNombre() << endl;
            }
        }

        if (slots[0].getNombre() == "")
        {
            cout << " [1] Equipar arma" << endl;
        }
        else
        {
            cout << " [1] Desequipar arma" << endl;
        }
        if (slots[1].getNombre() == "")
        {
            cout << " [2] Equipar item defensivo" << endl;
        }
        else
        {
            cout << " [2] Equipar item defensivo" << endl;
        }
        if (slots[2].getNombre() == "")
        {
            cout << " [3] Equipar armadura" << endl;
        }
        else
        {
            cout << " [3] Desequipar armadura" << endl;
        }
        if (slots[3].getNombre() == "")
        {
            cout << " [4] Equipar consumible 1" << endl;
        }
        else
        {
            cout << " [4] Desequipar consumible 1" << endl;
        }
        if (slots[4].getNombre() == "")
        {
            cout << " [5] Equipar consumible 2" << endl;
        }
        else
        {
            cout << " [5] Desequipar consumible 2" << endl;
        }
        cout << " [0] Volver" << endl;
        cout << " \t>";
        cin >> opt;
        switch (opt)
        {
        case 1:
            accionArma();
            break;
        case 2:
            accionProteccion();
            break;
        case 3:
            accionArmadura();
            break;
        case 4:
            accionConsumible1();
            break;
        case 5:
            accionConsumible2();
            break;
        default:
            break;
        }
    } while (opt != 0);
}
void accionArma()
{
    int opt;
    Item temp;
    bool enough;
    bool hc = false;

    if (slots[0].getNombre() != "")
    {
        saveItemBag(slots[0], false);
        slots[0] = Item();
        return;
    }

    do
    {
        enough = true;
        system("cls");
        mochila.listarItemsArma(mochila.getRaiz(), true);
        cout << " Seleccione el arma a equipar: " << endl;
        cout << " [0] Volver" << endl;
        cin >> opt;

        if (opt == 0)
        {
            return;
        }

        temp = mochila.buscarItem(mochila.getRaiz(), opt)->getItem();
        compararSkills(temp, enough);
        system("pause");
    } while (!enough);

    slots[0] = temp;
    mochila.eliminarItem(temp.getNumOrden(), hc);
}
void accionProteccion()
{
    int opt;
    Item temp;
    bool enough;
    bool hc = false;

    if (slots[1].getNombre() != "")
    {
        saveItemBag(slots[1], false);
        slots[1] = Item();
        return;
    }

    do
    {
        enough = true;
        system("cls");
        cout << " Seleccione la proteccion a equipar: " << endl;
        mochila.listarItemsProteccion(mochila.getRaiz(), true);
        cout << " [0] Volver" << endl;
        cout << "\t>";
        cin >> opt;

        if (opt == 0)
        {
            return;
        }

        temp = mochila.buscarItem(mochila.getRaiz(), opt)->getItem();
        compararSkills(temp, enough);
        system("pause");
    } while (!enough);

    slots[1] = temp;
    mochila.eliminarItem(temp.getNumOrden(), hc);
}
void accionArmadura()
{
    int opt;
    Item temp;
    bool enough;
    bool hc = false;

    if (slots[2].getNombre() != "")
    {
        saveItemBag(slots[2], false);
        slots[2] = Item();
        return;
    }

    do
    {
        enough = true;
        system("cls");
        cout << " Seleccione la armadura a equipar: " << endl;
        mochila.listarItemsArmadura(mochila.getRaiz(), true);
        cout << " [0] Volver" << endl;
        cout << "\t>";
        cin >> opt;

        if (opt == 0)
        {
            return;
        }

        temp = mochila.buscarItem(mochila.getRaiz(), opt)->getItem();
        compararSkills(temp, enough);
        system("pause");
    } while (!enough);

    slots[2] = temp;
    mochila.eliminarItem(temp.getNumOrden(), hc);
}
void accionConsumible1()
{
    int opt;
    Item temp;
    bool enough;
    bool hc = false;

    if (slots[3].getNombre() != "")
    {
        saveItemBag(slots[3], false);
        slots[3] = Item();
        return;
    }

    do
    {
        enough = true;
        system("cls");
        cout << " Seleccione el consumible a equipar: " << endl;
        mochila.listarItemsConsumible(mochila.getRaiz(), true);
        cout << " [0] Volver" << endl;
        cout << "\t>";
        cin >> opt;

        if (opt == 0)
        {
            return;
        }

        temp = mochila.buscarItem(mochila.getRaiz(), opt)->getItem();
        compararSkills(temp, enough);
        system("pause");
    } while (!enough);

    slots[3] = temp;
    mochila.eliminarItem(temp.getNumOrden(), hc);
}
void accionConsumible2()
{
    int opt;
    Item temp;
    bool enough;
    bool hc = false;

    if (slots[4].getNombre() != "")
    {
        saveItemBag(slots[4], false);
        slots[4] = Item();
        return;
    }

    do
    {
        enough = true;
        system("cls");
        cout << " Seleccione el consumible a equipar: " << endl;
        mochila.listarItemsConsumible(mochila.getRaiz(), true);
        cout << " [0] Volver" << endl;
        cout << "\t>";
        cin >> opt;

        if (opt == 0)
        {
            return;
        }

        temp = mochila.buscarItem(mochila.getRaiz(), opt)->getItem();
        compararSkills(temp, enough);
        system("pause");
    } while (!enough);

    slots[4] = temp;
    mochila.eliminarItem(temp.getNumOrden(), hc);
}
void compararSkills(Item item, bool &enough)
{
    if (item.getNivelMin() > player.getNivel())
    {
        cout << " Nivel de jugador insuficiente." << endl;
        cout << "\tNivel de jugador: " << player.getNivel() << endl;
        cout << "\tNivel requerido: " << item.getNivelMin() << endl;
        enough = false;
    }
    if (item.getFuerzaMin() > player.getFuerza())
    {
        cout << " Fuerza de jugador insuficiente." << endl;
        cout << "\tFuerza de jugador: " << player.getFuerza() << endl;
        cout << "\tFuerza requerido: " << item.getFuerzaMin() << endl;
        enough = false;
    }
    if (item.getInteligenciaMin() > player.getInteligencia())
    {
        cout << " Inteligencia de jugador insuficiente." << endl;
        cout << "\tInteligencia de jugador: " << player.getInteligencia() << endl;
        cout << "\tInteligencia requerido: " << item.getInteligenciaMin() << endl;
        enough = false;
    }
    if (item.getAgilidadMin() > player.getAgilidad())
    {
        cout << " Agilidad de jugador insuficiente." << endl;
        cout << "\tAgilidad de jugador: " << player.getAgilidad() << endl;
        cout << "\tAgilidad requerido: " << item.getAgilidadMin() << endl;
        enough = false;
    }
    if (item.getDestrezaMin() > player.getDestreza())
    {
        cout << " Destreza de jugador insuficiente." << endl;
        cout << "\tDestreza de jugador: " << player.getDestreza() << endl;
        cout << "\tDestreza requerido: " << item.getDestrezaMin() << endl;
        enough = false;
    }
    if (item.getCarismaMin() > player.getCarisma())
    {
        cout << " Carisma de jugador insuficiente." << endl;
        cout << "\tCarisma de jugador: " << player.getCarisma() << endl;
        cout << "\tCarisma requerido: " << item.getCarismaMin() << endl;
        enough = false;
    }
    if (item.getAnimalHandlingMin() > player.getAnimalHandling())
    {
        cout << " Animal handling de jugador insuficiente." << endl;
        cout << "\tAnimal handling de jugador: " << player.getAnimalHandling() << endl;
        cout << "\tAnimal handling requerido: " << item.getAnimalHandlingMin() << endl;
        enough = false;
    }
    if (item.getArcanoMin() > player.getArcano())
    {
        cout << " Arcano de jugador insuficiente." << endl;
        cout << "\tArcano de jugador: " << player.getArcano() << endl;
        cout << "\tArcano requerido: " << item.getArcanoMin() << endl;
        enough = false;
    }
}
void menuTirarDadosPlayer()
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
