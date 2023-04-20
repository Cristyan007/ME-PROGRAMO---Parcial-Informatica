#include <iostream>
#include "Funciones.h"
using namespace std;


const int MAX_MATERIAS = 100;
int main() {
    char archivo[] = "cursos.txt";
    char *longi = leerarchivo(archivo);

    char **base_cursos = split_string(longi, '\n');
    int total_cursos = cantidadcursos();
    cout<<"Bienvenido al gestionador de horario"<<endl;
    cout<<endl;
    // pedir al usuario el número de materias
    int num_materias = 0;
    cout << "Ingrese el numero de materias matriculadas: ";
    cin >> num_materias;

   char ** materias = materiasUser(base_cursos,num_materias,total_cursos);

   char ** horarioMat = horarioMaterias(materias,num_materias,base_cursos,total_cursos);

 //mostrar matriz con el horario del usuario

   for (int i = 0; i < num_materias; ++i){
         mostrarHorario(horarioMat);
       cout<<"vamos a comenzar a organizar el horario de estudio independiente de la materia: "<<nombrecurso(base_cursos,total_cursos,materias[i])<<endl;
       int HorasInd = calcHestudio(base_cursos,materias[i],total_cursos);
       cout<<nombrecurso(base_cursos,total_cursos,materias[i])<<" Necesita "<<HorasInd<<" horas independientes."<<endl;
       cout<<"Los espacios que poseen guiones son horas donde puedes acomodar las horas de estudio"<<endl;
       for (int i = 0; i < HorasInd; ++i) {
           char dia[1];
           char hora[10];
           cout<<"Ingrese el dia donde desea estudiar(ejemplo: L)"<<endl;
           cin>>dia;
           cout<<"Ingrese el la hora donde desea estudiar (6-7)";
           cin>>hora;
           asignarhora(horarioMat,dia,hora,materias[i],base_cursos,total_cursos);
           mostrarHorario(horarioMat);
       }

   }


return 0;
}
