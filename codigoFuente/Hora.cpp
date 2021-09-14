/* 
Salvador Salgado Normandia
septiembre 2021 
Actividad integral de conceptos básicos y algoritmos fundamentales
*/ 
#include "Hora.h"

Hora::Hora(){
  hora=0;
  min=0;
}

Hora::Hora(int _hora,int _min){
  hora=_hora;
  min=_min;
}

Hora::~Hora(){}

int Hora::getHor(){
  return hora;
}

int Hora::getMin(){
  return min;
}

void Hora::setHora(int _hora){
  hora=_hora;
}

void Hora::setMin(int _min){
  min=_min;
}

bool Hora::operator<(Hora h){
  int _hora=h.getHor();
  int _min=h.getMin();
  if(hora<_hora){
    return true;
  }
  else if(hora>_hora){
    return false;
  }
  if(min<_min){
    return true;
  }
  else if(min>_min){
    return false;
  }
  return false;
}

bool Hora::operator>(Hora h){
  int _hora=h.getHor();
  int _min=h.getMin();
  if(hora>_hora){
    return true;
  }
  else if(hora<_hora){
    return false;
  }
  if(min>_min){
    return true;
  }
  else if(min<_min){
    return false;
  }
  return false;
}

bool Hora::operator==(Hora h){
  int _hora=h.getHor();
  int _min=h.getMin();
  if(hora==_hora){
    return true;
  }
  else if(hora!=_hora){
    return false;
  }
  if(min==_min){
    return true;
  }
  else if(min!=_min){
    return false;
  }
  return false;
}

bool Hora::operator!=(Hora h){
  int _hora=h.getHor();
  int _min=h.getMin();
  if(hora==_hora){
    return false;
  }
  else if(hora!=_hora){
    return true;
  }
  if(min==_min){
    return false;
  }
  else if(min!=_min){
    return true;
  }
  return true;
}