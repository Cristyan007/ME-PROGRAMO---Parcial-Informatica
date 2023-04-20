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
            contadorpalabras = contadorpalabras + long_string(kk)+2;
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

int strcmp(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return 0;
}

int split(char s[], char delimiter, char splitStrings[][MAX_SIZE]) {
    int splitCount = 0;
    int i = 0;
    int j = 0;

    while (s[i] != '\0') {
        if (s[i] == delimiter) {
            splitStrings[splitCount][j] = '\0';
            splitCount++;
            j = 0;
        } else {
            splitStrings[splitCount][j] = s[i];
            j++;
        }

        i++;
    }

    splitStrings[splitCount][j] = '\0';
    splitCount++;

    return splitCount;
}


void my_strcpy(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int contarCursos(char **cursos) {
    int num_cursos = 0;
    while (cursos[num_cursos] != NULL) {
        num_cursos++;
    }
    return num_cursos;
}


bool buscarCurso(char **cursos, int num_cursos, const char *codigo_buscado) {
    for (int i = 0; i < num_cursos; i++) {
        char **curso = split_string(cursos[i], ';');
        if (strcmp(curso[0], codigo_buscado) == 0) {
//            cout << "Curso encontrado: " << curso[1] << endl;
            return true;
        }
    }
    cout << "No se encontro el curso con codigo " << codigo_buscado << endl;
    return false;
}

void strcpy_manual(char* destino, const char* fuente) {
    while (*fuente != '\0') {
        *destino = *fuente;
        destino++;
        fuente++;
    }
    *destino = '\0';
}

char **materiasUser(char **base_cursos, int num_materias, int total_cursos)
{
    char **materias  = new char *[num_materias];
    char codigo[8];
    for (int i = 0; i < num_materias; ++i) {
        cout<<"Ingrese el codigo de la materia "<<(i+1)<<" que tiene matriculada"<<endl;
        cin>>codigo;
        codigo[7] = '\0';
        bool encontrado = buscarCurso(base_cursos, total_cursos, codigo);
        while (encontrado == false){
            cout<<"Intente nuevamente"<<endl;
            cin>>codigo;
            codigo[7] = '\0';
            encontrado = buscarCurso(base_cursos, total_cursos, codigo);
        }
        materias[i] = new char [8];
        int j = 0;
        for (j = 0; j < long_string(codigo); ++j) {
            materias[i][j] = codigo[j];
        }
        materias[i][j] = '\0';
    }
    return materias;
}

char* nombrecurso(char **cursos, int num_cursos, const char *codigo_buscado) {
    for (int i = 0; i < num_cursos; i++) {
        char **curso = split_string(cursos[i], ';');
        if (strcmp(curso[0], codigo_buscado) == 0) {
//            cout << "Curso encontrado: " << curso[1] << endl;
            return curso[1];
        }
    }
    cout << "No se encontro el curso con codigo " << codigo_buscado << endl;
    return nullptr;
}

int posicionHora(char *hora)
{
        if(strcmp(hora, "6") == 0) return 0;
        else if(strcmp(hora, "7") == 0) return 1;
        else if(strcmp(hora, "8") == 0) return 2;
        else if(strcmp(hora, "9") == 0) return 3;
        else if(strcmp(hora, "10") == 0) return 4;
        else if(strcmp(hora, "11") == 0) return 5;
        else if(strcmp(hora, "12") == 0) return 6;
        else if(strcmp(hora, "13") == 0) return 7;
        else if(strcmp(hora, "14") == 0) return 8;
        else if(strcmp(hora, "15") == 0) return 9;
        else if(strcmp(hora, "16") == 0) return 10;
        else if(strcmp(hora, "17") == 0) return 11;
        else if(strcmp(hora, "18") == 0) return 12;
        else if(strcmp(hora, "19") == 0) return 13;
        else if(strcmp(hora, "20") == 0) return 14;
        else if(strcmp(hora, "21") == 0) return 15;
        else if(strcmp(hora, "22") == 0) return 16;
}

int get_day_index(char* day_str) {
    if (strcmp(day_str, "L") == 0 || strcmp(day_str, "l") == 0) {
        return 0;
    }
    else if (strcmp(day_str, "M") == 0 || strcmp(day_str, "m") == 0) {
        return 1;
    }
    else if (strcmp(day_str, "W") == 0 || strcmp(day_str, "w") == 0) {
        return 2;
    }
    else if (strcmp(day_str, "J") == 0 || strcmp(day_str, "j") == 0) {
        return 3;
    }
    else if (strcmp(day_str, "V") == 0 || strcmp(day_str, "v") == 0) {
        return 4;
    }
    else if (strcmp(day_str, "S") == 0 || strcmp(day_str, "s") == 0) {
        return 5;
    }
    else {
        return -1;
    }
}
char letrainitcurso(char **base_cursos, int total_cursos,char *codigo){
    for (unsigned int i = 0; i < total_cursos; i++) {
        char **curso = split_string(base_cursos[i], ';');
        if (strcmp(curso[0], codigo) == 0) {
            return curso[1][0];
        }
    }

}

char **horarioMaterias(char **materias, int num_materias, char **base_cursos, int total_cursos)
{
    char ** horario = new char *[6];
    for (int i = 0; i < 6; ++i) {
        horario[i] = new char [16];
    }
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 16; ++j) {
            horario[i][j] = '-';
        }
    }

    cout<<"Vamos a comenzar a ingresar los horarios de las materias matriculadas"<<endl;
    char dias[10];
    char hora[20];
    for (int i = 0; i < num_materias; ++i) {
        cout<<"Vamos a comenzar con el curso de "<<nombrecurso(base_cursos,total_cursos,materias[i])<<endl;
        cout<<"ingrese los dias que tiene clase de la materia separados por guiones (L-M-W-J-V)"<<endl;
        cin>>dias;
        char **dias2 = split_string(dias,'-');
        char letra = letrainitcurso(base_cursos,total_cursos,materias[i]);
        for (int j = 0; j < (contar_caracter(dias,'-')+1); ++j) {
            int posiciondia = get_day_index(dias2[j]);
            cout<<"Ingrese el horario del "<<dias2[j]<< " En hora militar separados por guiones (16-17;17-18)"<<endl;
            cin>>hora;
            char **hora2 = split_string(hora,';');
            for (int i = 0; i < contar_caracter(hora,';')+1; ++i) {
                char **hora3 = split_string(hora2[i],'-');
                int posicionhora = posicionHora(hora3[0]);
                horario[posiciondia][posicionhora] = letra;
            }
        }
    }

return horario;
}
void mostrarHorario(char **horarioMat){
    std::cout << "\nHorario de Calculo:\n\n";
    std::cout << "      ";
    for (int col = 0; col < 16; col++) {
        std::cout << col + 6 << "-" << col + 7 << "\t";
    }
    std::cout << std::endl;

    for (int row = 0; row < 6; row++) {
        switch (row) {
        case 0:
            std::cout << "Lunes ";
            break;
        case 1:
            std::cout << "Martes";
            break;
        case 2:
            std::cout << "Mierc.";
            break;
        case 3:
            std::cout << "Jueves";
            break;
        case 4:
            std::cout << "Viern.";
            break;
        case 5:
            std::cout << "Sabado";
            break;
        }
        for (int col = 0; col < 16; col++) {
            std::cout << "\t" << horarioMat[row][col];
        }
        std::cout << std::endl;
    }
}

int strToInt(const char* str) {
  int res = 0;  // Inicializamos el resultado a cero
  int sign = 1;  // Signo del número (positivo por defecto)

  // Si el primer carácter es un signo, lo almacenamos y avanzamos el puntero
  if (*str == '-' || *str == '+') {
    sign = (*str++ == '-') ? -1 : 1;
  }

  // Recorremos la cadena mientras no lleguemos al final ni encontremos un carácter no numérico
  while (*str >= '0' && *str <= '9') {
    // Multiplicamos el resultado por 10 y le sumamos el valor numérico del carácter actual
    res = res * 10 + (*str++ - '0');
  }

  return res * sign;
}

int calcHestudio(char **cursos, char *codigo,int numerocursos)
{
    for (int i = 0; i < numerocursos; i++) {
        char **curso = split_string(cursos[i], ';');
        if (strcmp(curso[0], codigo) == 0) {
            int Hestudio = ((strToInt(curso[2])*48)/16)-(strToInt(curso[3]));
            //cout<<Hestudio;
            return Hestudio;
        }
    }
}
void asignarhora(char **matrix, char *dia, char *hora, char *codigo, char **base_cursos, int total_cursos){
    char **hora2 = split_string(hora,'-');
    int posiciondia = get_day_index(dia);
    int posicionhora = posicionHora(hora2[0]);
    char letra = letrainitcurso(base_cursos,total_cursos,codigo);
    while (matrix[posiciondia][posicionhora]!='-') {
        cout<<"Esa hora en ese dia se encuentra ocupado"<<endl;
        cout<<"Ingrese el dia donde desea estudiar(ejemplo: L)"<<endl;
        cin>>dia;
        cout<<"Ingrese el la hora donde desea estudiar (6-7)";
        cin>>hora;
        char **hora2 = split_string(hora,'-');
        posiciondia = get_day_index(dia);
        posicionhora = posicionHora(hora2[0]);
    }
    matrix[posiciondia][posicionhora] = letra;
}

