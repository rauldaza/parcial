#include <iostream>
#include <queue>
#include "administrador.h"
#include "funciones.h"
#include "usuario.h"

using namespace std;

int main()
{
    administrador admi("Raul", "1234");
    admi.modificarPeliculas();
    usuario user("pepe");
    user.pelicula();
}
