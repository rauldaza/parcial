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
public:
    usuario();
    usuario(string user);
    string pelicula();
    int asiento();
};

#endif // USUARIO_H
