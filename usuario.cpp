#include "usuario.h"

usuario::usuario()
{

}

usuario::usuario(string user)
{
    this->user=user;
}

string usuario::pelicula()
{
    int id=1, total=0;
    string linea, nombre;
    ifstream peliculas;
    peliculas.open("peliculas.txt");
    while (peliculas.good())
    {
        getline(peliculas, linea);
        total++;
    }
    peliculas.clear();
    peliculas.seekg(0, peliculas.beg);
    while(id!=total)
    {
        cout << "-------------------------------------------" << endl;
        peliculas >> linea;
        cout << linea << " ";
        while(linea[linea.length()-1]!='.')
        {
            peliculas >> linea;
            cout << linea << " ";
        }
        cout << endl;
        getline(peliculas, linea);
        cout << "id" << ": " << id << ". " << linea << endl;
        id++;
    }
    cout << "-------------------------------------------" << endl;
    cout << "escriba la pelicula que desea ver: ";
    cin.ignore();
    getline(cin, nombre);
    peliculas.close();
    return nombre;
}

int usuario::asiento()
{

}

