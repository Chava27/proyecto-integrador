/* 
Salvador Salgado Normandia
septiembre 2021 
Actividad integral de conceptos básicos y algoritmos fundamentales
*/ 
#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Hora{
  private:
    int hora,min;
  public:
    //Constructores
    Hora();
    Hora(int,int);
    //Desconstructor
    ~Hora();
    //getters
    int getHor();
    int getMin();
    //setters
    void setHora(int);
    void setMin(int);
    //sobrecarga
    bool operator<(Hora);
    bool operator==(Hora);
    bool operator!=(Hora);
    bool operator>(Hora);
};