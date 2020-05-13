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
};

#endif // ADMINISTRADOR_H
