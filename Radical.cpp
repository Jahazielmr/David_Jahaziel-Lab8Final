#include "Radical.h"

using namespace std;

Radical::Radical(int coeficiente, int indice, int radicando){
  this->coeficiente=coeficiente;
  this->indice=indice;
  this->radicando=radicando;
  
  
  
}

Radical::Radical(){

}


void Radical::setCoeficiente(int coeficiente){

 this-> coeficiente=coeficiente;
}

int Radical::getCoeficiente(){
 return coeficiente;
}

void Radical::setIndice(int indice){

 this-> indice=indice;
}

int Radical::getIndice(){
 return indice;
}

void Radical::setRadicando(int radicando){

 this-> radicando=radicando;
}

int Radical::getRadicando(){
 return radicando;
}

