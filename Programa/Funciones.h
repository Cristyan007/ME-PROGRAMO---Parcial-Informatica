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
//funciones del programa 2
char ** materiasUser(char **base_cursos,int num_materias,int total_cursos);
char* nombrecurso(char **cursos, int num_cursos, const char *codigo_buscado);
char **horarioMaterias(char **materias, int num_materias, char **base_cursos, int total_cursos);
int posicionHora(char hora);
void mostrarHorario(char **horarioMat);
int strToInt(const char* str);
int calcHestudio(char **cursos, char *codigo, int numerocursos);
void asignarhora(char **matrix, char *dia, char *hora, char *codigo, char **base_cursos, int total_cursos);
char letrainitcurso(char **base_cursos, int total_cursos,char *codigo);
//funca valida code
bool validarCodigo(char** matriz, int filas, int columnas, char codigo);
int strcmp(const char* str1, const char* str2);

const int MAX_SIZE = 100;
const int MAX_DIAS = 6;
const int MAX_HORAS = 17;
//////////////////////////////////
void get_time_indices(char* str, int& col_start, int& col_end);
int get_day_index(char* day_str);
char* find_char(char* str, char c);
int split(char s[], char delimiter, char splitStrings[][MAX_SIZE]);
void strcpy(char *dest, const char *src);
void my_strcpy(char dest[], char src[]);
int strcmp(const char* str1, const char* str2);
int contarCursos(char **cursos);
bool buscarCurso(char **cursos, int num_cursos, const char *codigo_buscado);
void strcpy_manual(char* destino, const char* fuente);
#endif // FUNCIONES_H
