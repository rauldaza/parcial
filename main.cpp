#include <iostream>
#include <queue>
#include "administrador.h"
#include "funciones.h"
#include "usuario.h"
#include <map>
using namespace std;

int main()
{
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
        if(opcion=='a' || opcion=='A')
        {
            string nombre;
            cout << "nombre: ";
            usuario user(nombre);
            user.pelicula();

        }
        else if(opcion=='u' || opcion=='U')
        {
            string user, password;
            administrador admi(user, password);
            if(admi.confirmacion()==true)
            {

            }
            else
            {
                cout << "usuarario y/o contrasena invalido" << endl;
                admi.~administrador();
            }
        }
    }
}
