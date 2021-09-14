/* 
Salvador Salgado Normandia
septiembre 2021 
Actividad integral de conceptos básicos y algoritmos fundamentales
*/ 
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Ubi.h"
#include "Hora.h"
#include "Fecha.h"
using namespace std;



class Barco{
  private:
    Fecha f;
    Hora h;
    string entrada;
    Ubi ubi;
  public:
    //Constructor
    Barco();
    Barco(Fecha,Hora,string,Ubi);
    //Destructor
    ~Barco();
    //getters
    Fecha getFecha();
    Hora getHora();
    string getEntrada();
    Ubi getUbi();
    //setters
    void setFecha(Fecha);
    void setHora(Hora);
    void setEntrada(string);
    void setUbi(Ubi);
    //sobrecargas
    bool operator<(Barco);
    bool operator==(Barco);
    bool operator>(Barco);
    bool operator!=(Barco);
};