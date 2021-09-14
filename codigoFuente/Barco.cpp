/* 
Salvador Salgado Normandia
septiembre 2021 
Actividad integral de conceptos básicos y algoritmos fundamentales
*/ 
#include "Barco.h"

Barco::Barco(){}

Barco::Barco(Fecha _fecha, Hora _hora,string _entrada, Ubi _ubi){
  f=_fecha;
  h=_hora;
  entrada=_entrada;
  ubi=_ubi;
}

Barco::~Barco(){}

Fecha Barco::getFecha(){
  return f;
}

Hora Barco::getHora(){
  return h;
}

string Barco::getEntrada(){
  return entrada;
}

Ubi Barco::getUbi(){
  return ubi;
}

void Barco::setFecha(Fecha _fecha){
  f=_fecha;
}

void Barco::setHora(Hora _hora){
  h=_hora;
}

void Barco::setEntrada(string _entrada){
  entrada=_entrada;
}

void Barco::setUbi(Ubi _ubi){
  ubi=_ubi;
}

bool Barco::operator<(Barco _b){
  if (ubi<_b.getUbi()){
    return true;
  }
  else if (ubi>_b.getUbi()){
    return false;
  }
  if (f<_b.getFecha()){
    return true;
  }
  else if (f>_b.getFecha()){
    return false;
  }
  if (h<_b.getHora()){
    return true;
  }
  else if (h>_b.getHora()){
    return false;
  }
  else{
    return false;
  }
}

bool Barco::operator>(Barco _b){
  if (ubi>_b.getUbi()){
    return true;
  }
  else if (ubi<_b.getUbi()){
    return false;
  }
  if (f>_b.getFecha()){
    return true;
  }
  else if (f<_b.getFecha()){
    return false;
  }
  if (h>_b.getHora()){
    return true;
  }
  else if (h<_b.getHora()){
    return false;
  }
  else{
    return false;
  }
}

bool Barco::operator==(Barco _b){
  if (ubi==_b.getUbi()){
    return true;
  }
  else if (ubi!=_b.getUbi()){
    return false;
  }
  if (f==_b.getFecha()){
    return true;
  }
  else if (f!=_b.getFecha()){
    return false;
  }
  if (h==_b.getHora()){
    return true;
  }
  else if (h!=_b.getHora()){
    return false;
  }
  else{
    return false;
  }
}

bool Barco::operator!=(Barco _b){
  if (ubi==_b.getUbi()){
    return false;
  }
  else if (ubi!=_b.getUbi()){
    return true;
  }
  if (f==_b.getFecha()){
    return false;
  }
  else if (f!=_b.getFecha()){
    return true;
  }
  if (h==_b.getHora()){
    return false;
  }
  else if (h!=_b.getHora()){
    return true;
  }
  else{
    return true;
  }
}
