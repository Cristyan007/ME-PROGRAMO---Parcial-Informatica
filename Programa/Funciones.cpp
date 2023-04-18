#include "Funciones.h"

unsigned int cantidadcursos()
{
    char *kk;
    fstream texto;
    texto.open("cursos.txt",ios_base::in | ios_base::binary);
    unsigned int cantidadL = 0;

    if(texto.is_open()){
        while (!texto.eof()){
            kk = get_line(texto);
            cantidadL ++;
            delete []kk;
        }
    }
    return cantidadL;
}

char *get_line(fstream &k)
{
    char u = ' ', *linea;
    unsigned int tam = my_length(k), i=0, cursor;
    linea = new char [tam+1];

    while (u!='\r'){
        u = k.get();
        linea[i] = u;
        i++;
    }
    linea[tam] = '\0';
    cursor = k.tellg();
    k.seekg(cursor+1);
    k.get();
    if(!k.eof()) k.seekg(cursor+1);

    return linea;
}

unsigned int my_length(fstream &k)
{
    char u = ' ';
    unsigned int tam=0,cursor;
    while (u!='\r'){
        u=k.get();
        tam++;
    }
    cursor = k.tellg();
    k.seekg(cursor-tam);
    return tam-1;
}


//funciones de strings

int long_string(char *i)
{
    int contador = 0;
    while (*(i+contador)!='\0') {
        contador++;
    }
    return contador;
}

int contar_caracter(char *i, char caracter)
{
  int longi = long_string(i);
  int contador = 0;
  for (int j = 0; j < longi; ++j) {
      if (i[j]==caracter){
        contador++;
      }
    }
  return contador;
}

char *eliminar_pos(char *i, int posicion)
{
    int longi = long_string(i);
    char *nueva = new char [longi];

    for (int j = 0,k=0; j < longi; ++j) {
      if(j!=posicion){
          nueva[k] = i[j];
          k++;
      }
    }
    nueva[longi-1] = '\0';
    return nueva;
}

char *eliminar_carac(char *i, char caracter)
{
    int longi = long_string(i);
    char *nueva=i, *nueva2;

    for (int j = 0; j < longi; ++j) {
        if (nueva[j]==caracter) {
           nueva2 = eliminar_pos(nueva,j);
           delete []nueva;
           nueva=nueva2;
           longi=longi-1;
        }
    }
    return nueva;
}

char **split_string(char *i, char caracter)
{
    int cantidad_ca = contar_caracter(i,caracter);
    int longui = long_string(i);
        char **nueva = new char *[cantidad_ca];

        int posicion_init = 0, contador;

        for (contador = 0; contador < cantidad_ca; ++contador) {
            int posicion = find(i,posicion_init,caracter);
            nueva[contador] = new char [posicion-posicion_init+1];
            for (int j = posicion_init; j < posicion; ++j) {
                nueva[contador][j-posicion_init] = i[j];
            }
            nueva[contador][posicion-posicion_init] = '\0';
            posicion_init=posicion+1;
        }
        nueva[contador] = new char [longui-posicion_init+1];
        for (int j = posicion_init; j<longui; ++j) {
            nueva[contador][j-posicion_init] = i[j];
        }
        nueva[contador][longui-posicion_init] = '\0';

        return nueva;
}

int find(char *i, int posicion, char elemento)
{
    int longui = long_string(i);
    for (int j = posicion; j < longui; ++j) {
        if (i[j]==elemento){
          return j;
        }
    }
    return 0;
}

//funciones del programa
unsigned int elementosarchivo(char *archivo)
{
    char *kk;
    fstream texto;
    texto.open(archivo,ios_base::in | ios_base::binary);
    int contadorpalabras = 0;
    if(texto.is_open()){
        while (!texto.eof()){
            kk = get_line(texto);
            contadorpalabras = contadorpalabras + long_string(kk)+1;
            delete []kk;
        }
    }
    return contadorpalabras;
}




char *leerarchivo(char *archivo)
{
    int longiArchivo = elementosarchivo(archivo);
    char *datosC = new char [longiArchivo+1];

    int i = 0;
    fstream texto;
    texto.open(archivo,ios_base::in | ios_base::binary);

    for (i = 0; i < longiArchivo; ++i) {
        texto.get(datosC[i]);
    }
    datosC[i] = '\0';
    char *datosm = eliminar_carac(datosC,'\r');
    return datosm;
}
