#include <queue>
#include <iostream>
#include "administrador.h"
#include "usuario.h"
#include "funciones.h"

using namespace std;

/**************************************************************
 *el usuario de administrador es "Raul" y la contrasena "1234"*
 **************************************************************/
int main()
{
    string user, password;
    administrador admi;
    cout << "Para iniciar el programa, ingrese como administrador" << endl;
    //se verifica si el usuario y contrasena ingresados son validos
    do{
        cout << "usuario: ";
        cin >> user;
        cout << "contasena: ";
        cin >> password;
        admi.setAdmi(user);
        admi.setPassword(password);
        //si es valido el programa sigue
        if(admi.confirmacion()==true)
        {
            break;
        }
        //si no es valido, el programa espera a que se ingrese uno valido
        else
        {
            cout << "usuario y/o contrasena invalida" << endl;
        }
    }while(true);
    //agrega una linea de asteriscos al reporte para diferenciar los reportes de distintos dias
    ofstream reporte;
    reporte.open("reporte.txt", ios::app);
    reporte << "********************************************************" << endl;
    reporte.close();
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
    /*
     * el mapa asientos contiene las tres distintas salas que hay por los tipos de asientos, el numero 1
     * es la sala 2D, la numero 2 es la sala 3D, la numero 3 es la sala 4DX
    */
    map <int, char[15][20]> asientos;
    /*
     * el mapa asientostotal contiene a todas las peliculas y sus tres distintas salas
     * *ilustacion
     *               |                           1|matriz de asientos 2D
     *              1|asientos(primera pelicula) 2|matriz de asientos 3D
     *               |                           3|matriz de asientos 4Dx
     *asientostotal  |---------------------------------------------------
     *               |                           1|matriz de asientos 2D
     *              2|asientos(segunda pelicula) 2|matriz de asientos 3D
     *               |                           3|matriz de asientos 4Dx
    */
    map <int, map<int, char[15][20]>> asientostotal;
    //se crean tres matrices y se generan en ellas los asientos
    for(int j=1; j<=3; j++)
    {
        asientos[j];
        generar_lugares(asientos[j]);
    }
    //se generan los mapas que contienen a las peliculas y sus salas
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
        //este ciclo vigila que el usuario escoja una sala que tenga asientos libres
        do{
        user.pelicula();
        user.tipo_asiento();
        }while(user.disponibilidad_asientos()==false);
        user.asiento(asientostotal);
        user.pago(asientostotal);
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
