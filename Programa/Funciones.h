#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <fstream>
using namespace std;

unsigned int cantidadcursos();
char * get_line(fstream &k);
unsigned int my_length(fstream &k);
void datosCursos(char **Datos);
char **crearmatriz(char **Datos, int m);

// simulacuiones clase string
int long_string(char *i);
int contar_caracter(char *i, char caracter);
char * eliminar_pos(char *i, int posicion);
char * eliminar_carac(char *i, char caracter);
char ** split_string(char *i, char caracter);
int find(char *i, int posicion,char elemento);
//funciones del programa
unsigned int elementosarchivo(char *archivo);
char *leerarchivo(char *archivo);
#endif // FUNCIONES_H
