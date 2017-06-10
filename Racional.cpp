#include "Racional.h"

Racional::Racional(){

}

Racional::Racional(int num,int den){
  
  this->numerador = num;
  this->denominador = den;

}

int Racional::getNumerador(){
  return numerador;
}
void Racional::setNumerador(int num){
  numerador = num;
}

int Racional::getDenominador(){
  return denominador;
}
void Racional::setDenominador(int den){
  denominador = den;
}
