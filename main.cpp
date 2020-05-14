#include <queue>
#include <iostream>
#include "administrador.h"
#include "usuario.h"
#include "funciones.h"

using namespace std;

int main()
{
    string user, password;
    administrador admi;
    cout << "Para iniciar el programa, ingrese como administrador" << endl;
    do{
        cout << "usuario: ";
        cin >> user;
        cout << "contasena: ";
        cin >> password;
        admi.setAdmi(user);
        admi.setPassword(password);
        if(admi.confirmacion()==true)
        {
            break;
        }
        else
        {
            cout << "usuario y/o contrasena invalida" << endl;
        }
    }while(true);
    int opcion;
    cout << "CINE" << endl;
    cout << "Administrador, desea iniciar los registros de los usuarios o antes va a modificar "
            "la lista de peliculas" << endl;
    cout << "1. iniciar con registro de los usuarios" << endl;
    cout << "2. modificar lista de peliculas" << endl;
    cin >> opcion;
    if(opcion==2)
    {
        admi.modificarPeliculas();
    }
    admi.~administrador();
    queue <usuario> usuarios;
    map <int, char[15][20]> asientos;
    map <int, map<int, char[15][20]>> asientostotal;
    for(int j=1; j<=3; j++)
    {
        asientos[j];
        generar_lugares(asientos[j]);
    }
    for(int i=1; i<=contador_peliculas(); i++)
    {
        asientostotal[i] = asientos;
    }
    cout << "Menu de registro de usuarios" << endl;
    while(true)
    {
        int opcion;
        cout << "para comprar una entrada ingrese los siguientes datos" << endl;
        string nombre;
        cout << "nombre: ";
        cin >> nombre;
        usuario user(nombre);
        user.pelicula();
        user.tipo_asiento();
        user.asiento(asientostotal);
        if(user.pago(asientostotal)==true)
        {
            usuarios.push(user);
        }
        cout << "opciones" << endl;
        cout << "1. comprar una entrada" << endl;
        cout << "2. terminar el dia (se necesitan permisos de administrador)" << endl;
        cin >> opcion;
        if(opcion==2)
        {
            do
            {
                administrador admi;
                string user, password;
                cout << "usuario: ";
                cin >> user;
                cout << "contasena: ";
                cin >> password;
                admi.setAdmi(user);
                admi.setPassword(password);
                if(admi.confirmacion()==true)
                {
                    admi.guardar();
                    break;
                }
                else
                {
                    cout << "usuario y/o contrasena invalida" << endl;
                }
            }while(true);
            break;
        }
    }
}
