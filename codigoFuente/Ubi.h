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


class Ubi{
  private:
    //atributos
    int id_start,id_end;
    string code;
  public:
    //Constructores
    Ubi();
    Ubi(int,string,int);
    //Deconstructor
    ~Ubi();
    //getters
    int getIdStart();
    string getCode();
    int getIdEnd();
    //setters
    void setIdStart(int);
    void setCode(string);
    void setIdEnd(int);
    //sobrecarga
    bool operator<(Ubi);
    bool operator==(Ubi);
    bool operator!=(Ubi);
    bool operator>(Ubi);
    /*operador para buscar patron en Ubi
    bool operator%=(int,string);
    */
};