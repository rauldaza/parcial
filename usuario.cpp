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

string usuario::getSala() const
{
    return sala;
}

void usuario::setSala(const string &value)
{
    sala = value;
}

string usuario::getUser() const
{
    return user;
}

void usuario::setUser(const string &value)
{
    user = value;
}

usuario::usuario()
{

}

usuario::usuario(string user)
{
    this->user=user;
}

//Da a escoger las peliculas al usuario
void usuario::pelicula()
{
    int id=1, total=0, id_user, contador=0;
    string linea, nombre;
    total = contador_peliculas();
    ifstream peliculas;
    peliculas.open("peliculas.txt");
    cout << "*tenga en cuenta si hay o no asientos disponibles en la sala deseada" << endl;
    //imprime las peliculas disponibles
    while(id<=total)
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
        cout << "id" << ": " << id << ". " << endl << linea << endl;
        id++;
    }
    cout << "-------------------------------------------" << endl;
    cout << "escriba el id de la pelicula que desea ver: ";
    cin >> id_user;
    peliculas.clear();
    peliculas.seekg(0, peliculas.beg);
    //busca la pelicula seleccionada para posteriormente sacar el nombre
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

//da a escoger los tipos de asientos disponibles y guarda la sala en donde esta ese tipo de asiento
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
    else if(numero==3)
    {
        this->setNasiento("4DX");

    }
    ifstream peliculas;
    string linea;
    peliculas.open("peliculas.txt");
    //busca la pelicula seleccionada para sacar la sala en donde esta el asiento seleccionado
    while(peliculas.good())
    {
        getline(peliculas, linea);
        if(linea.find(this->getNpelicula())!=string::npos)
        {
            int initial_loc = linea.find(this->getNasiento());
            int final_loc = linea.find(",", initial_loc);
            string sala = linea.substr(initial_loc+4, final_loc-initial_loc-4);
            this->setSala(sala);
        }
    }
    peliculas.close();
}

//verifica si quedan todavia asientos en la sala seleccionada
bool usuario::disponibilidad_asientos()
{
    ifstream peliculas;
    string linea;
    string sillas_ocup;
    int initial_loc, final_loc;
    peliculas.open("peliculas.txt");
    //busca pelicula
    while(peliculas.good() && linea.find(Npelicula)==string::npos)
    {
        getline(peliculas, linea);
    }
    //verifica si la sala (que esta determinada por el tipo de asiento) esta llena o no
    int coma1 = linea.find(",");
    int coma2 = linea.find(",", coma1+1);
    int coma3 = linea.find(",", coma2+1);
    if(this->Nasiento=="2D")
    {
        initial_loc = coma1;
        final_loc = linea.find("/140. sala 3D:");
        sillas_ocup = linea.substr(initial_loc+21,final_loc-initial_loc-21);
        if(sillas_ocup=="140")
        {
            cout << "la sala esta completamente llena, por favor, eliga otra sala o pelicula" << endl;
            return false;
        }
        else
        {
            return true;
        }
    }
    else if(this->Nasiento=="3D")
    {
        initial_loc = coma2;
        final_loc = linea.find("/140. sala 4DX:");
        sillas_ocup = linea.substr(initial_loc+21,final_loc-initial_loc-21);
        if(sillas_ocup=="140")
        {
            cout << "la sala esta completamente llena, por favor, eliga otra sala o pelicula" << endl;
            return false;
        }
        else
        {
            return true;
        }
    }
    else if(this->Nasiento=="4DX")
    {
        initial_loc = coma3;
        final_loc = linea.find("/140. Hora:");
        sillas_ocup = linea.substr(initial_loc+21,final_loc-initial_loc-21);
        if(sillas_ocup=="140")
        {
            cout << "la sala esta completamente llena, por favor, eliga otra sala o pelicula" << endl;
            return false;
        }
        else
        {
            return true;
        }

    }
}

/*
 * da a escoger la posicion del asiento en la sala para poder guardarlo en la matriz que contiene los lugares
 * de la sala
*/
void usuario::asiento(map <int, map<int, char[15][20]>> &asientostotal)
{
    string puesto;
    int lugar;
    cout << "*los lugares con un '-' estan vacios, los lugares con un '+' se encuentran ocupados" << endl;
    cout << "escoga un asiento" << endl;
    //aqui se busca la matriz que contiene los lugares de la sala
    if(this->Nasiento=="2D") lugar=1;
    else if(this->Nasiento=="3D") lugar=2;
    else if(this->Nasiento=="4DX") lugar=3;
    imprimir_lugares(asientostotal[this->getId()][lugar]);
    puesto = reservar_lugares(asientostotal[this->getId()][lugar]);
    this->setPuesto(puesto);
}

//le pregunta al usuario si confirma o cancela la compra de la entrada
bool usuario::pago(map <int, map<int, char[15][20]>> &asientostotal)
{
    char opcion;
    cout << "confirmacion de pago" << endl;
    cout << "Para confirmar el pago ingrese 's', de lo contrario ingrese 'n': ";
    cin >> opcion;
    if(opcion=='S' || opcion=='s')
    {
        //agrega el costo del tipo de asiento escogido por el usuario
        if(this->getNasiento()=="2D")
        {
            this->setNpago("10000");
        }
        else if(this->getNasiento()=="3D")
        {
            this->setNpago("14000");
        }
        else if(this->getNasiento()=="4DX")
        {
            this->setNpago("20000");
        }
        /*
        *ya que el usuario compro la entrada, aumenta en 1 la cantidad de sillas ocupadas en la sala
        *para ello se busca la pelicula en el archivo "peliculas.txt", se extrae la cantidad de sillas
        *cupadas para aumentarlas, luego se toma la informacion que habia antes y despues del numero
        *de sillas ocupadas y se vuelve a fusionar (ya con la cantidad de sillas modificadas). esa
        *informacion fusionada se agregar a un archivo temp que reemplazara al archivo peliculas
        */
        ifstream peliculas;
        ofstream temp;
        string linea;
        peliculas.open("peliculas.txt");
        temp.open("temp.txt");
        while(peliculas.good())
        {
            getline(peliculas, linea);
            if(linea.find(this->getNpelicula())!=string::npos)
            {
                int coma1 = linea.find(",");
                int coma2 = linea.find(",", coma1+1);
                int coma3 = linea.find(",", coma2+1);
                if(this->Nasiento=="2D")
                {
                    int initial_loc = coma1;
                    int final_loc = linea.find("/140. sala 3D:");
                    //aqui se extrae la cantidad de sillas
                    string sillas_ocup = linea.substr(initial_loc+21,final_loc-initial_loc-21);
                    //aqui se aumenta la cantidad de sillas
                    sillas_ocup = to_string(stoi(sillas_ocup)+1);
                    //aqui se vuelve a fusionar la informacion
                    linea = linea.substr(0, initial_loc+21) + sillas_ocup + linea.substr(final_loc, linea.length()-final_loc);
                }
                else if(this->Nasiento=="3D")
                {
                    int initial_loc = coma2;
                    int final_loc = linea.find("/140. sala 4DX:");
                    string sillas_ocup = linea.substr(initial_loc+21,final_loc-initial_loc-21);
                    sillas_ocup = to_string(stoi(sillas_ocup)+1);
                    linea = linea.substr(0, initial_loc+21) + sillas_ocup + linea.substr(final_loc, linea.length()-final_loc);
                }
                else if(this->Nasiento=="4DX")
                {
                    int initial_loc = coma3;
                    int final_loc = linea.find("/140. Hora:");
                    string sillas_ocup = linea.substr(initial_loc+21,final_loc-initial_loc-21);
                    sillas_ocup = to_string(stoi(sillas_ocup)+1);
                    linea = linea.substr(0, initial_loc+21) + sillas_ocup + linea.substr(final_loc, linea.length()-final_loc);
                }
            }
            if(!linea.empty())
            {
                temp << linea << endl;
            }
        }
        peliculas.close();
        temp.close();
        remove("peliculas.txt");
        rename("temp.txt", "peliculas.txt");
        /*
         * cuando el usuario finaliza su compra se genera un reporte de la compra con la informacion
         * importante, que se guardara en el archivo reporte
        */
        ofstream reporte;
        reporte.open("reporte.txt", ios::app);
        reporte << "nombre: "<< this->getUser() << ". pelicula: " << this->getNpelicula() << ". tipo de asiento: "
                << this->getNasiento() << ". sala: " << this->getSala() << ". puesto: " << this->getPuesto()
                << ". pago: " << this->getNpago() << endl;
        reporte.close();
        return true;
    }
    /*
     * si el usuario decide cancela la compra se elimina el usuario y se libera el asiento que anteriormente
     * habia escogido
    */
    else if(opcion=='N' || opcion=='n')
    {
        int lugar;
        //aqui se busca la matriz que contiene el asiento que habia escogido el usuario
        if(this->Nasiento=="2D")
        {
            lugar=1;
        }
        else if(this->Nasiento=="3D")
        {
            lugar=2;
        }
        else if(this->Nasiento=="4DX")
        {
            lugar=3;
        }
        cout << "compra cancelada" << endl;
        //aqui se libera el lugar escogido
        cancelar_lugares(asientostotal[this->getId()][lugar], (this->getPuesto())[0], int((this->getPuesto())[1])-48);

    }
    return false;
}

