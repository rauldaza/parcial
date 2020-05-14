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

string usuario::getPuesto() const
{
    return puesto;
}

void usuario::setPuesto(const string &value)
{
    puesto = value;
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
    int id=1, total=0, id_user, contador=0;
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
    peliculas.clear();
    peliculas.seekg(0, peliculas.beg);
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

void usuario::asiento(map <int, map<int, char[15][20]>> &asientostotal)
{
    string puesto;
    int lugar;
    cout << "escoga un asiento" << endl;
    if(this->Nasiento=="2D") lugar=1;
    else if(this->Nasiento=="3D") lugar=2;
    else if(this->Nasiento=="4DX") lugar=3;
    imprimir_lugares(asientostotal[this->getId()][lugar]);
    puesto = reservar_lugares(asientostotal[this->getId()][lugar]);
    this->setPuesto(puesto);
}

bool usuario::pago(map <int, map<int, char[15][20]>> &asientostotal)
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
        int lugar;
        if(this->Nasiento=="2D") lugar=1;
        else if(this->Nasiento=="3D") lugar=2;
        else if(this->Nasiento=="4DX") lugar=3;
        cout << "compra cancelada" << endl;
        cancelar_lugares(asientostotal[this->getId()][lugar], (this->getPuesto())[0], int((this->getPuesto())[1])-48);
        this->~usuario();
    }
    return false;
}

