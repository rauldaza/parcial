#include "usuario.h"

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

usuario::usuario()
{

}

usuario::usuario(string user)
{
    this->user=user;
}

void usuario::pelicula()
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
    this->setNpelicula(nombre);
}

void usuario::asiento()
{

}

void usuario::tipo_asiento()
{
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
        this->setNpago("20000");
    }
}

void usuario::pago()
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
    }
    else if(opcion=='N' || opcion=='n')
    {
        this->~usuario();
    }
}

