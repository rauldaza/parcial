#include "usuario.h"
#include "funciones.h"

string usuario::getNpelicula() const
{
    return Npelicula;
}

void usuario::setNpelicula(const string &value)
{
    Npelicula = value;
}

string usuario::getNasiento() const
{
    return Nasiento;
}

void usuario::setNasiento(const string &value)
{
    Nasiento = value;
}

string usuario::getNpago() const
{
    return Npago;
}

void usuario::setNpago(const string &value)
{
    Npago = value;
}

int usuario::getId() const
{
    return id;
}

void usuario::setId(int value)
{
    id = value;
}

usuario::usuario()
{

}

usuario::usuario(string user)
{
    this->user=user;
}

void usuario::pelicula()
{
    int id=1, total=0, id_user, inicio, fin, contador=0;
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
    cout << "escriba el id de la pelicula que desea ver: ";
    cin >> id_user;
    while(peliculas.good() && id_user!=contador)
    {
        getline(peliculas, linea);
        contador++;
    }
    peliculas.close();
    this->setId(id_user);
    nombre = linea.substr(8, linea.find('.')-8);
    this->setNpelicula(nombre);
}

void usuario::asiento(map<int, char[15][20]> lugares)
{
    cout << "escoga un asiento" << endl;
    imprimir_lugares(lugares[this->getId()]);
    reservar_lugares(lugares[this->getId()]);
}

void usuario::tipo_asiento()
{
    imprimi_asientos();
    int numero;
    cout << "ingrese la enumeracion del asiento deseado: ";
    cin >> numero;
    if(numero==1)
    {
        this->setNasiento("2D");

    }
    else if(numero==2)
    {
        this->setNasiento("3D");

    }
    else if(numero==1)
    {
        this->setNasiento("4DX");

    }
}

bool usuario::pago()
{
    char opcion;
    cout << "confirmacion de pago" << endl;
    cout << "Para confirmar el pago ingrese 's', de lo contrario ingrese 'n': ";
    cin >> opcion;
    if(opcion=='S' || opcion=='s')
    {
        if(this->getNasiento()=="2D")
        {
            this->setNpago("10000");
        }
        else if(this->getNasiento()=="3D")
        {
            this->setNpago("14000");
        }
        else if(this->getNasiento()=="4D")
        {
            this->setNpago("20000");
        }
        return true;
    }
    else if(opcion=='N' || opcion=='n')
    {
        cout << "compra cancelada" << endl;
        this->~usuario();
    }
    return false;
}

