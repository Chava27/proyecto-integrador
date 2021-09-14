/* 
Salvador Salgado Normandia
septiembre 2021 
Actividad integral de conceptos básicos y algoritmos fundamentales
Este programa se encarga de recibir un archvio con datos de distintos barcos para despues crear un nuevo archivo ya ordenado
*/ 
#include <iostream>
#include "Barco.h"
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
vector<Barco> barcos,barcosUbi;
string texto="canal.txt";

//declarar variables
void ordenaQuick(vector<Barco> &, int inicio, int fin);
int particion(vector<Barco> &,int inicio, int fin);
int revisionCin(string,int,int);
void busquedaUbi(int, string);
void llenarVector();
void llenar_nVector();
void imprimir();

int main() {
  llenarVector();
  cout<<"Vector de Barcos se ha llenado.....Iniciando acomodo"<<endl;
  int val,n_ids;
  string _code;
  int inicio=0;
  int fin=barcos.size();
  ordenaQuick(barcos, inicio, fin-1);
  cout<<"Ordenamiento terminado.....Creando nuevo txt ordenado"<<endl<<endl;
  llenar_nVector();
  cout<<"Menu de Busqueda por UBI"<<endl;
  cout<<"1) Buscar info de barcos por UBI"<<endl<<"2) Salir"<<endl;
  val=revisionCin("Digite opción",1,2);
  if (val==1){
    n_ids=revisionCin("Digite primer caracter del UBI a buscar (0-9)",0,9);
    cout<<"Digite siguientes 2 caracteres del UBI: ";
    cin>>_code;
    busquedaUbi(n_ids,_code);
   
    if(barcosUbi.size()!=0){
      cout<<"Coicnidencias encontradas:"<<endl;
      imprimir();
    }
    else{
      cout<<"No se encontraron coincidencias..."<<endl;
    }
  }
  else{
    return 0;
  }
}
//busquedaUbi se encarga de encontras las clases Barco que tengan el mismo incio de Ubi que el bridando en la entrada de la función
//entrada: variable int que especifica el valor que debe de tener el primer caracter de Ubi; variable string que especifica el segundo y tercer caracter que debe de tener Ubi
//salida: no regresa nada, simplemete genera un nuevo vector con los barcos que cumplen los requisitos
//Complejidad O(n^2)
void busquedaUbi(int _i, string _c){
  string _x;
  bool status=false;
  for(int i=0;i<barcos.size();i++){
    if (barcos[i].getUbi().getIdStart()==_i){
      _x=barcos[i].getUbi().getCode();
      if(_x[0]==_c[0]&&_x[1]==_c[1]){
        barcosUbi.push_back(barcos[i]);
      }
    }
  }
}

//imprimir se encarga de impirmir el vector con los barcos filtrados por la funcion busquedaUbi
//entrada: no recibe ningun parametro de entrada
//salida: despliega los datos de los barcos
//complejidad O(n)
void imprimir(){
  int dia,anio,hora,minutos,id_st,id_end;
  string mes,entrada,_c;
  for(int i=0;i<barcosUbi.size();i++){
    dia=barcosUbi[i].getFecha().getDia();
    mes=barcosUbi[i].getFecha().getMes();
    anio=barcosUbi[i].getFecha().getAnio();
    hora=barcosUbi[i].getHora().getHor();
    minutos=barcosUbi[i].getHora().getMin();
    id_st=barcosUbi[i].getUbi().getIdStart();
    id_end=barcosUbi[i].getUbi().getIdEnd();
    entrada=barcosUbi[i].getEntrada();
    _c=barcosUbi[i].getUbi().getCode();
    
    if (dia<10){
      cout<<0<<dia;
    }
    else{
      cout<<dia;
    }
    cout<<"-"<<mes<<"-";
    if(anio<10){
      cout<<0<<anio<<" ";
    }
    else{
      cout<<anio<<" ";
    }
    if(hora<10){
      cout<<0<<hora;
    }
    else{
      cout<<hora;
    }
    cout<<":";
    if(minutos<10){
       cout<<0<<minutos;
    }
    else{
      cout<<minutos;
    }
    cout<<" "<<barcosUbi[i].getEntrada()<<" "<<id_st<<_c<<id_end<<endl;
  }
}

//particion es una función que se encarga de seleccionar el pivote del vector ingresado para despues acomodarlo a la mitad
//entrada: vecotr<RFC> donde se encuentra y acomoda pivote; inicio int que establace la primera pos del vector; fin int que establece la ultima poscicion del vector
//salida: regresa la posicion donde se debe de seguir dividiendo el vector en futuras particiones
//Complejidad O(n)
int particion(vector<Barco> & Barcos,int inicio, int fin){
  Barco pivote = Barcos[inicio];
  int i = inicio + 1;
  for(int j = i; j <= fin; j++){
    if(Barcos[j] < pivote){
      swap(Barcos[i],Barcos[j]);
      i++;
    }
  }
  swap(Barcos[inicio],Barcos[i-1]);
  return i-1;
}

//ordenaQuick() se encarga de ordenar los valores del vector<RFC> de menor a mayor sigueindo el metdo de QuickSort
//entrada: vecotr<RFC> donde se encuentra y acomoda pivote; inicio int que establace la primera pos del vector; fin int que establece la ultima poscicion del vector
//salida: no regresa nada, simplemente se encarga de ordenar el vector que recibe en la entrada
//Complejidad O(n), sin embargo llama a partición que tiene por su parto una complejidad de n por lo que su complejidad total es O(n^2)
void ordenaQuick(vector<Barco> & arreglo, int inicio, int fin){
  if(inicio < fin){
    int pivote = particion(arreglo,inicio,fin);
    ordenaQuick(arreglo,inicio,pivote-1);
    ordenaQuick(arreglo,pivote+1,fin);
  }
}


//llenarVector se encarga de llenar nuestro vector de barcos con la informacion del archivo ("canal.txt")
//entrada: no recibe parametros de entrada
//salida: no regresa nada, simplemente llena un vector<Barco> 
//Complejidad O(n)
void llenarVector(){
  string date, hour, entry, acces_code;
  string day,month,year,hours,minutes,int_id,info,end_id;
  fstream archivo;
  archivo.open(texto,ios::in);
  while(archivo>>date>>hour>>entry>>acces_code){
    day=date.substr(0,2);
    int i_day=atoi(day.c_str());
    month=date.substr(3,3);
    year=date.substr(7,2);
    int i_year=atoi(year.c_str());
    //generar fecha
    Fecha f1(i_day,month,i_year);
    hours=hour.substr(0,2);
    int i_hour=atoi(hours.c_str());
    minutes=hour.substr(3,2);
    int i_minutes=atoi(minutes.c_str());
    Hora h1(i_hour,i_minutes);
    int_id=acces_code.substr(0,1);
    int i_int_id=atoi(int_id.c_str());
    info=acces_code.substr(1,3);
    end_id=acces_code.substr(4,1);
    int i_end_id=atoi(end_id.c_str());
    Ubi u(i_int_id,info,i_end_id);
    Barco b(f1,h1,entry,u);
    barcos.push_back(b);
  }
  archivo.close();
}

//llenar_nVector es la encargada de crear un nuevo archibo con los objetos Barcos ya ordenados
//entrada: no pide parametros de entrada
//salida: crea un nuevo archivo "canal_ordenado.txt" con los objetos Barco ordenados
//Complejidad O(n)
void llenar_nVector(){
  ofstream archivo;
  int dia,anio,hora,minutos,id_st,id_end;
  string mes,entrada,_c;
  archivo.open("canal_ordenado.txt",ios::out);
  for(int i=0;i<barcos.size();i++){
    dia=barcos[i].getFecha().getDia();
    mes=barcos[i].getFecha().getMes();
    anio=barcos[i].getFecha().getAnio();
    hora=barcos[i].getHora().getHor();
    minutos=barcos[i].getHora().getMin();
    id_st=barcos[i].getUbi().getIdStart();
    id_end=barcos[i].getUbi().getIdEnd();
    entrada=barcos[i].getEntrada();
    _c=barcos[i].getUbi().getCode();
    if (dia<10){
      archivo<<0<<dia;
    }
    else{
      archivo<<dia;
    }
    archivo<<"-"<<mes<<"-";
    if(anio<10){
      archivo<<0<<anio<<" ";
    }
    else{
      archivo<<anio<<" ";
    }
    if(hora<10){
      archivo<<0<<hora;
    }
    else{
      archivo<<hora;
    }
    archivo<<":";
    if(minutos<10){
      archivo<<0<<minutos;
    }
    else{
      archivo<<minutos;
    }
    archivo<<" "<<barcos[i].getEntrada()<<" "<<id_st<<_c<<id_end<<endl;
  }
  archivo.close();
}
//revisionCin es una funcion que se asegura que el tamaño del vector ingresado por el usuario sea correcto
//entrada: variable string que se despliega como mensaje al usuario; valorMin int y valorMax int definen el rango de valores que puede introducir el usuario
//salida: regresa el valor de n int una vez que se confirma que se encuentra entre valorMin y valorMax
//Complejidad O(n)
int revisionCin(string Variable,int valorMin,int valorMax){
  int n;
  while (true){
    cout<<Variable<<": ";
    cin>>n;
    //Checa si el valor está en rango
    if(n<=valorMax && n>=valorMin){
      break;
    }
    cout<<Variable<<" debe ser un número entre "<<valorMin<<" y "<<valorMax<<endl;
    //Borrar entrada anterior de cin
    cin.clear();
    cin.ignore(10000,'\n');
  }
  return n;
}