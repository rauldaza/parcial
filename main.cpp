#include <queue>
#include <iostream>
#include "administrador.h"
#include "usuario.h"
#include "funciones.h"

using namespace std;

int main()
{
    queue <usuario> usuarios;
    map <int, char[15][20]> asientos;

    for(int i=1; i<=contador_peliculas(); i++)
    {
        asientos[i];
        generar_lugares(asientos[i]);
    }
    while(true)
    {
        char opcion;
        cout << "desea ingresar como administrador(a) o como usuario regular(u)?" << endl;
        cin >> opcion;
        if(opcion=='u' || opcion=='U')
        {
            string nombre;
            cout << "nombre: ";
            usuario user(nombre);
            user.pelicula();
            user.asiento(asientos);
            user.tipo_asiento();
            if(user.pago()==true)
            {
                usuarios.push(user);
            }
        }
        else if(opcion=='a' || opcion=='A')
        {
            string user, password;
            cout << "Menu de administrador" << endl;
            cout << "inicio de sesion" << endl;
            cout << "usuario: ";
            cin >> user;
            cout << "contrasena: ";
            cin >> password;
            administrador admi(user, password);
            if(admi.confirmacion()==true)
            {
                int opcion;
                cout << "opciones" << endl;
                cout << "1. modificar la lista de peliculas" << endl;
                cout << "2. generar reporte de ganancial del dia" << endl;
                cin >> opcion;
                if(opcion==1)
                {
                    admi.modificarPeliculas();
                }
                else if(opcion==2)
                {
                    admi.guardar();
                }
            }
            else
            {
                cout << "usuarario y/o contrasena invalido" << endl;
                admi.~administrador();
            }
        }
    }
}
