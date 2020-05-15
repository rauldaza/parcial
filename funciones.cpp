#include "funciones.h"

//imprime los tipos de asientos y sus costos
void imprimi_asientos()
{
    string asiento1 = "1. tipo: 2D . costo: 10000 pesos ";
    string asiento2 = "2. tipo: 3D . costo: 14000 pesos";
    string asiento3 = "3. tipo: 4DX. costo: 20000 pesos";
    cout << asiento1 << endl << asiento2 << endl << asiento3 << endl;
}

//convierte todos los elementos de una matriz a '-', estos representan lugares vacios
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

/*
 * imprime los lugares guardados en una matriz, las filas estan marcadas de la A hasta la O
 * y las columnas estan enumeradas del 1 al 20
*/
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

/*
 * recibe una fila y una columna, en ese lugar de la matriz se cambia de '-' a '+'
 * indicando que el lugar ahora esta ocupado
*/
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
    /*
     * se une la fila y la columna en un mismo string para guardarlo como el puesto seleccionado
     * por el usuario
    */
    string a(1, fila);
    string b = to_string(columna);
    puesto = a + b;
    return puesto;
}

/*
 * cambia de '+' a '-' un lugar en la matriz, indicando que ese lugar ahora esta disponible
 * esto ocurre cuando un comprador cancela el pago de la entrada
*/
void cancelar_lugares(char lugares[15][20], char fila, int columna)
{
    lugares[fila-65][columna-1] = '-';
}

//cuenta la cantidad de peliculas en archivo "peliculas.txt"
int contador_peliculas()
{
    ifstream peliculas;
    int cantidad=0;
    string linea;
    peliculas.open("peliculas.txt");
    while(peliculas.good())
    {
        getline(peliculas, linea);
        //ya que en las lineas vacias del archivo no hay peliculas, se omiten contarlas
        if(linea.empty()==false)
        {
            cantidad++;
        }
    }
    return cantidad;
}


