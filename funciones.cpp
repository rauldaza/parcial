#include "funciones.h"

void imprimi_asientos()
{
    string asiento1 = "1. tipo: 2D . costo: 10000 pesos ";
    string asiento2 = "2. tipo: 3D . costo: 14000 pesos";
    string asiento3 = "3. tipo: 4DX. costo: 20000 pesos";
    cout << asiento1 << endl << asiento2 << endl << asiento3 << endl;
}

void generar_lugares(char lugares[15][20])
{
    for(int i=0; i<15; i++)
    {
        for(int j=0; j<20; j++)
        {
            lugares[i][j] = '-';
        }
    }
}

void imprimir_lugares(char lugares[15][20])
{
    cout << " ";
    for(int i=1; i<=20; i++)
    {
        if(i<10)
        {
            cout << "  "<< i;
        }
        else
        {
            cout << " " << i;
        }
    }
    cout << endl;
    for(int i=0; i<15; i++)
    {
        cout << char('A'+i);
        for(int j=0; j<20; j++)
        {
                cout << "  " << lugares[i][j];
        }
        cout << endl;
    }
}
string reservar_lugares(char lugares[15][20])
{
    char fila;
    int columna;
    string puesto;
    cout << "ingrese la fila: ";
    cin >> fila;
    cout << "ingrese la columna: ";
    cin >> columna;
    while(lugares[fila-65][columna-1]=='+')
    {
        cout << "ese lugar esta ocupado, por favor seleccione otro" << endl;
        cout << "ingrese la fila: ";
        cin >> fila;
        cout << "ingrese la columna: ";
        cin >> columna;
    }
    lugares[fila-65][columna-1] = '+';
    string a(1, fila);
    string b(1, char(columna+48));
    puesto = a + b;
    return puesto;
}

void cancelar_lugares(char lugares[15][20], char fila, int columna)
{
    lugares[fila-65][columna-1] = '-';
}

int contador_peliculas()
{
    ifstream peliculas;
    int cantidad=0;
    string linea;
    peliculas.open("peliculas.txt");
    while(peliculas.good())
    {
        getline(peliculas, linea);
        if(linea.empty()==false)
        {
            cantidad++;
        }
    }
    return cantidad;
}
