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

//verifica si la cuenta ingresada es valida o no
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

//agrega o elimina peliculas del archivo "peliculas.txt"
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
            cout << "numero de sala 2D: ";
            cin >> sala_uno;
            cout << "numero de sala 3D: ";
            cin >> sala_dos;
            cout << "numero de sala 4DX: ";
            cin >> sala_tres;
            cout << "hora: ";
            cin >> hora;
            cout << "clasificacion: ";
            cin >> clasificacion;
            //agrega toda la informacion suministrada al archivo peliculas
            peliculas << "Nombre: " << nombre << ". Genero: " << genero << ". Duracion: " << duracion
                      << ". Sala 2D: " << sala_uno << ", Asientos ocupados: " << asientos << ". sala 3D: "
                      << sala_dos << ", Asientos ocupados: " << asientos << ". sala 4DX: " << sala_tres
                      << ", Asientos ocupados: " << asientos << ". Hora: " << hora
                      << ". Clasificacion: " << clasificacion << "." << endl;
            peliculas.close();
        }
        else if(decision=='e' || decision=='E')
        {
            ofstream temp;
            temp.open("temp.txt");
            cout << "catalogo de peliculas" << endl;
            //imprime el catalogo de peliculas para que sea mas facil ver cual eliminar
            while(peliculas.good())
            {
                getline(peliculas, linea);
                if(!linea.empty())
                {
                    cout << "---------------------------------" << endl;
                    cout << linea << endl;
                }
            }
            peliculas.clear();
            peliculas.seekg(0, peliculas.beg);
            cout << "eliminar" << endl;
            cout << "nombre: ";
            cin >> nombre;
            /*
             * elimina la pelicula nombrada por el administrador, pasa todas las peliculas a un archivo temp
             * excepto la pelicula nombrada (el archivo temp pasara a ser el nuevo archivo de peliculas)
            */
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

/*
 * guarda las peliculas reiniciando el contador de sillas ocupadas por sala para que la proxima vez que
 * se inicie el programa el contador de sillas este en cero
*/
void administrador::guardar()
{
    ifstream peliculas;
    ofstream temp;
    string linea;
    peliculas.open("peliculas.txt");
    temp.open("temp.txt");
    while(peliculas.good())
    {
        getline(peliculas, linea);
        int coma1 = linea.find(",");
        int coma2 = linea.find(",", coma1+1);
        int coma3 = linea.find(",", coma2+1);
        if(!linea.empty())
        {
            int initial_loc = coma1;
            int final_loc = linea.find("/140. sala 3D:");
            string sillas_ocup = "0";
            //modifica la linea original, reiniciando el contador de sillas "2D" ocupadas en la sala
            linea = linea.substr(0, initial_loc+21) + sillas_ocup + linea.substr(final_loc, linea.length()-final_loc);
            initial_loc = coma2;
            final_loc = linea.find("/140. sala 4DX:");
            sillas_ocup = "0";
            //modifica la linea original, reiniciando el contador de sillas "3D" ocupadas en la sala
            linea = linea.substr(0, initial_loc+21) + sillas_ocup + linea.substr(final_loc, linea.length()-final_loc);
            initial_loc = coma3;
            final_loc = linea.find("/140. Hora:");
            sillas_ocup = "0";
            //modifica la linea original, reiniciando el contador de sillas "4DX" ocupadas en la sala
            linea = linea.substr(0, initial_loc+21) + sillas_ocup + linea.substr(final_loc, linea.length()-final_loc);
            temp << linea << endl;
        }
    }
    peliculas.close();
    temp.close();
    remove("peliculas.txt");
    rename("temp.txt", "peliculas.txt");
}
