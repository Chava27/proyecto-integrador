/* 
Salvador Salgado Normandia
septiembre 2021 
Actividad integral de conceptos básicos y algoritmos fundamentales
*/ 
#include "Ubi.h"

Ubi::Ubi(){
  id_start=0;
  code="AAA";
  id_end=0;
}

Ubi::Ubi(int start,string _code, int end){
  id_start=start;
  code=_code;
  id_end=end;
}

Ubi::~Ubi(){}

int Ubi::getIdStart(){
  return id_start;
}

string Ubi::getCode(){
  return code;
}

int Ubi::getIdEnd(){
  return id_end;
}

void Ubi::setIdStart(int start){
  id_start=start;
}

void Ubi::setCode(string _code){
  code=_code;
}

void Ubi::setIdEnd(int end){
  id_end=end;
}

bool Ubi::operator<(Ubi ubi){
  int id_s = ubi.getIdStart();
  int id_e = ubi.getIdEnd();
  string _code= ubi.getCode();
  if (id_start<id_s){
    return true;
  }
  else if (id_start>id_s){
    return false;
  }
  else{
    for(int i=0;i<_code.size();i++){
      if(code[i]<_code[i]){
        return true;
      }
      else if(code[i]>_code[i]){
        return false;
      }
    }
    if(id_end<id_e){
      return  true;
    }
    else if (id_end>id_e){
      return false;
    }
  }
  return false;
}

bool Ubi::operator>(Ubi ubi){
  int id_s = ubi.getIdStart();
  int id_e = ubi.getIdEnd();
  string _code= ubi.getCode();
  if (id_start>id_s){
    return true;
  }
  else if (id_start<id_s){
    return false;
  }
  else{
    for(int i=0;i<_code.size();i++){
      if(code[i]>_code[i]){
        return true;
      }
      else if(code[i]<_code[i]){
        return false;
      }
    }
    if(id_end>id_e){
      return  true;
    }
    else if (id_end<id_e){
      return false;
    }
  }
  return false;
}

 bool Ubi::operator==(Ubi ubi){
   int id_s = ubi.getIdStart();
   if(id_start==id_s){
     return true;
   }
   else if(id_start!=id_s){
     return false;
   }
   string _code= ubi.getCode();
   for(int i=0;i<_code.size();i++){
      if(code[i]==_code[i]){
        return true;
      }
      else if(code[i]!=_code[i]){
        return false;
      }
    }
    int id_e = ubi.getIdEnd();
    if(id_end==id_e){
      return  true;
    }
    else if (id_end!=id_e){
      return false;
    } 
    return false;
 }

 bool Ubi::operator!=(Ubi ubi){
   int id_s = ubi.getIdStart();
   if(id_start==id_s){
     return false;
   }
   else if(id_start!=id_s){
     return true;
   }
   string _code= ubi.getCode();
   for(int i=0;i<_code.size();i++){
      if(code[i]==_code[i]){
        return false;
      }
      else if(code[i]!=_code[i]){
        return true;
      }
    }
    int id_e = ubi.getIdEnd();
    if(id_end==id_e){
      return  false;
    }
    else if (id_end!=id_e){
      return true;
    } 
    return true;
 }

