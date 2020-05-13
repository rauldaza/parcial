#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

class usuario
{
private:
    string user;
    string Npelicula;
    string Nasiento;
    string Npago;
    int id;
public:
    usuario();
    usuario(string user);
    void pelicula();
    void asiento(map<int, char[15][20]>);
    void tipo_asiento();
    bool pago();
    string getNpelicula() const;
    void setNpelicula(const string &value);
    string getNasiento() const;
    void setNasiento(const string &value);
    string getNpago() const;
    void setNpago(const string &value);
    int getId() const;
    void setId(int value);
};

#endif // USUARIO_H
