/* 
Salvador Salgado Normandia
septiembre 2021 
Actividad integral de conceptos básicos y algoritmos fundamentales
*/ 
#include "Fecha.h"

vector<string> meses{"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dic"};

Fecha::Fecha(){
  dia=0;
  mes="";
  anio=0;
}

Fecha::Fecha(int _dia, string _mes, int _anio){
  dia=_dia;
  mes=_mes;
  anio=_anio;
}

Fecha::~Fecha(){}

int Fecha::getDia(){
  return dia;
}

string Fecha::getMes(){
  return mes;
}

int Fecha::getAnio(){
  return anio;
}

void Fecha::setDia(int _dia){
  dia=_dia;
}

void Fecha::setMes(string _mes){
  mes=_mes;
}

void Fecha::setAnio(int _anio){
  anio=_anio;
}

bool Fecha::operator<(Fecha f){
  int _dia=f.getDia();
  int i_mes_1,i_mes_2;
  string _mes=f.getMes();
  int _anio=f.getAnio();
 
  if(anio<_anio){
    return true;
  }
  else if(anio>_anio){
    return false;
  }
  for(int i=0;i<mes.size();i++){
    if(mes==meses[i]){
      i_mes_1=i+1;
    }
    else if(_mes==meses[i]){
      i_mes_2=i+1;
    }
  }
  if(i_mes_1<i_mes_2){
    return true;
  }
  else if (i_mes_1>i_mes_2){
    return false;
  }
  if (dia<_dia){
    return true;
  }
  else if (dia>_dia){
    return false;
  }
  return false;
}

bool Fecha::operator>(Fecha f){
  int _dia=f.getDia();
  int i_mes_1,i_mes_2;
  string _mes=f.getMes();
  int _anio=f.getAnio();
  if(anio>_anio){
    return true;
  }
  else if(anio<_anio){
    return false;
  }
  for(int i=0;i<mes.size();i++){
    if(mes==meses[i]){
      i_mes_1=i+1;
    }
    else if(_mes==meses[i]){
      i_mes_2=i+1;
    }
  }
  if(i_mes_1>i_mes_2){
    return true;
  }
  else if (i_mes_1<i_mes_2){
    return false;
  }
  if (dia>_dia){
    return true;
  }
  else if (dia<_dia){
    return false;
  }
  return false;
}

bool Fecha::operator==(Fecha f){
  int _dia= f.getDia();
  string _mes= f.getMes();
  int _anio= f.getAnio();
  if (anio==_anio && mes==_mes && anio==_anio){
    return true;
  }
  else{
    return false;
  }
}

bool Fecha::operator!=(Fecha f){
  int _dia= f.getDia();
  string _mes= f.getMes();
  int _anio= f.getAnio();
  if (anio==_anio && mes==_mes && anio==_anio){
    return false;
  }
  else{
    return true;
  }
}
