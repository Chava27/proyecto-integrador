#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Fecha{
  private:
    int dia;
    string mes;
    int anio;
  public:
    //constructores
    Fecha();
    Fecha(int,string,int);
    //destructor
    ~Fecha();
    //getters
    int getDia();
    string getMes();
    int getAnio();
    //setters
    void setDia(int);
    void setMes(string);
    void setAnio(int);
    //sobrecarga
    bool operator<(Fecha);
    bool operator==(Fecha);
    bool operator!=(Fecha);
    bool operator>(Fecha);
};