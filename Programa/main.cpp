#include <iostream>
#include "Funciones.h"
using namespace std;

int main()
{
//    int m = cantidadcursos();
//    char prueba[] ="012345;info 1;55;ll;090\n0145;info 2;o;090\n0125;info 3;090";
//    char **nueva = split_string(prueba,'\n');

//            cout<<nueva[0]<<endl;
//         char **nombre = split_string(nueva[0],';');
//         cout<<nombre[1]<<endl;
    char archivo[] = "cursos.txt";
    char *longi = leerarchivo(archivo);
    char **nueva = split_string(longi,'\n');

    cout<<nueva[0]<<endl;
    cout<<nueva[1]<<endl;
    cout<<nueva[2]<<endl;
    cout<<nueva[3]<<endl;
}
