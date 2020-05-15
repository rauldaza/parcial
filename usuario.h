#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <stdio.h>

using namespace std;

class usuario
{
private:
    string user;
    string sala;
    string Npelicula;
    string Nasiento;
    string Npago;
    string puesto;
    int id;
public:
    usuario();
    usuario(string user);
    void pelicula();
    void tipo_asiento();
    bool disponibilidad_asientos();
    void asiento(map <int, map<int, char[15][20]>> &asientostotal);
    bool pago(map <int, map<int, char[15][20]>> &asientostotal);
    string getNpelicula() const;
    void setNpelicula(const string &value);
    string getNasiento() const;
    void setNasiento(const string &value);
    string getNpago() const;
    void setNpago(const string &value);
    int getId() const;
    void setId(int value);
    string getPuesto() const;
    void setPuesto(const string &value);
    string getSala() const;
    void setSala(const string &value);
    string getUser() const;
    void setUser(const string &value);
};

#endif // USUARIO_H
