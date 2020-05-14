#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class administrador
{
private:
    string admi;
    string password;
public:
    administrador();
    administrador(string admi, string password);
    bool confirmacion();
    void modificarPeliculas();
    void guardar();
    string getAdmi() const;
    void setAdmi(const string &value);
    string getPassword() const;
    void setPassword(const string &value);
};

#endif // ADMINISTRADOR_H
