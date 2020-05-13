#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class usuario
{
private:
    string user;
    string Npelicula;
    string Nasiento;
    string Npago;
public:
    usuario();
    usuario(string user);
    void pelicula();
    void asiento();
    void tipo_asiento();
    void pago();
    string getNpelicula() const;
    void setNpelicula(const string &value);
    string getNasiento() const;
    void setNasiento(const string &value);
    string getNpago() const;
    void setNpago(const string &value);
};

#endif // USUARIO_H
