#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <string>
#include <fstream>
#include <usuario.h>

using namespace std;

void imprimi_asientos();
void generar_lugares(char lugares[15][20]);
void imprimir_lugares(char lugares[15][20]);
string reservar_lugares(char lugares[15][20]);
void cancelar_lugares(char lugares[15][20], char fila, int columna);
int contador_peliculas();

#endif // FUNCIONES_H
