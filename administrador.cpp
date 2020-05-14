#include "administrador.h"

string administrador::getAdmi() const
{
    return admi;
}

void administrador::setAdmi(const string &value)
{
    admi = value;
}

string administrador::getPassword() const
{
    return password;
}

void administrador::setPassword(const string &value)
{
    password = value;
}

administrador::administrador()
{

}

administrador::administrador(string admi, string password)
{
    this->admi=admi;
    this->password = password;
}

bool administrador::confirmacion()
{
    string user, password;
    ifstream administradores;
    administradores.open("administradores.txt");
    while(administradores.good())
    {
        administradores >> user;
        if(user==this->admi)
        {
            administradores >> password;
            if(password==this->password)
            {
                return true;
            }
            return false;
        }
    }
    return false;
}

void administrador::modificarPeliculas()
{
    char decision;
    string nombre, genero, clasificacion, duracion, sala_uno, sala_dos, sala_tres , hora, asientos="0/140", linea;
    do{
        fstream peliculas;
        peliculas.open("peliculas.txt", ios::app | ios::in);
        cout << "elimiar(e) o agregar(a) pelicula: ";
        cin >> decision;
        if(decision=='a' || decision=='A')
        {
            cin.ignore();
            cout << "nombre: ";
            getline(cin, nombre);
            cout << "genero: ";
            getline(cin, genero);
            cout << "duracion: ";
            cin >> duracion;
            cout << "sala 2D: ";
            cin >> sala_uno;
            cout << "sala 3D: ";
            cin >> sala_dos;
            cout << "sala 4DX: ";
            cin >> sala_tres;
            cout << "hora: ";
            cin >> hora;
            cout << "clasificacion: ";
            cin >> clasificacion;
            peliculas << "Nombre: " << nombre << ". Genero: " << genero << ". Duracion: " << duracion
                      << ". Sala 2D: " << sala_uno << ", Asientos: " << asientos << ". sala 3D: "
                      << sala_dos << ", Asientos: " << asientos << ". sala 4DX: " << sala_tres
                      << ", Asientos: " << asientos << ". Hora: " << hora
                      << ". Clasificacion: " << clasificacion << "." << endl;
            peliculas.close();
        }
        else if(decision=='e' || decision=='E')
        {
            ofstream temp;
            temp.open("temp.txt");
            cout << "catalogo de peliculas" << endl;
            while(peliculas.good())
            {
                getline(peliculas, linea);
                if(!linea.empty())
                    cout << linea << endl;
            }
            peliculas.clear();
            peliculas.seekg(0, peliculas.beg);
            cout << "eliminar" << endl;
            cout << "nombre: ";
            cin >> nombre;
            while(peliculas.good())
            {
                getline(peliculas, linea);
                if(linea.find(nombre)==string::npos && !linea.empty())
                {
                    temp << linea << endl;
                }
            }
            peliculas.close();
            temp.close();
            remove("peliculas.txt");
            rename("temp.txt", "peliculas.txt");
        }
        cout << "desea seguir modificando la lista de peliculas? (s o n): ";
        cin >> decision;
    }while(decision=='s' || decision=='S');
}

void administrador::guardar()
{

}
