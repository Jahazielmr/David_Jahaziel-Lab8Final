#ifndef RADICAL_H
#define RADICAL_H
#include "Real.h"
#include <typeinfo>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Radical : public Real{

private:

  int coeficiente;
  int indice;
  int radicando;
  
  public:
    Radical();
    Radical(int,int,int);

    int getCoeficiente();
    void setCoeficiente(int);

    int getIndice();
    void setIndice(int);

    int getRadicando();
    void setRadicando(int);

    virtual string operator+(Real* racional){
  		
        stringstream ss;
        Radical* tem = dynamic_cast<Radical*>(racional);

        string resultado="";
        int suma;

        if(tem->getRadicando()==radicando){

        suma = tem->getCoeficiente()+ coeficiente;        

        ss <<"("<<suma<<")"<<" ("<<radicando<<") "<<"^"<<"(1/"<<indice<<")";
        resultado = ss.str();
        return resultado;

        }

      
    }



    virtual string operator+(int numero){
        //suma de un radical con un int

      stringstream ss;

      string resultado;

      ss<<numero<<"+"<<"("<<coeficiente <<") ("<<indice<<") "<<"^"<<"(1/"<<radicando<<")";

      resultado = ss.str();
      return resultado;
    }

    virtual string operator+(double numero){
      string resultado;

      stringstream ss;

      ss<<numero<<"+"<<"("+coeficiente <<") ("<<indice<<") "<<"^"<<"(1/"<<radicando<<")";
      
      resultado = ss.str();

      return resultado;

    }


    virtual string operator-(Real* real){
      //resta de un radical 
      stringstream ss;

      string resultado;
      int suma;

      Radical* tem = dynamic_cast<Radical*>(real);

      if(tem->getRadicando()==radicando){

        suma = tem->getCoeficiente()- coeficiente;
        
        

        ss<<"("<<suma<<")"<<" ("<<indice<<") "<<"^"<<"(1/"<<radicando<<")";

        resultado = ss.str();

        return resultado;


      }


    }

    
    virtual string operator-(int numero){
    
      stringstream ss;

      string resultado;

      ss<<numero<<"-"<<"("<<coeficiente <<") ("<<indice<<") "<<"^"<<"(1/"<<radicando<<")";

      resultado = ss.str();
      return resultado;


   }



   virtual string operator-(double numero){
      string resultado;

      stringstream ss;

      ss<<numero<<"+"<<"("+coeficiente <<") ("<<indice<<") "<<"^"<<"(1/"<<radicando<<")";
      
      resultado = ss.str();

      return resultado;


  }

  virtual string operator*(Real* radical){

    //multiplicacion con radical!
    stringstream ss;
    Radical* tem = dynamic_cast<Radical*>(radical);

    int operacion1;
    int operacion2;
    int operacion3;
    string resultado;

    if(tem->getRadicando()==radicando&&tem->getIndice()==indice){

    operacion1= tem->getCoeficiente()* coeficiente;
    operacion2 = (tem->getIndice()+indice); 
    operacion3= (tem->getIndice()*indice);
    

    ss<< "("<<operacion1<<")"<<" ("<<radicando<<") "<<"^"<<operacion2<<"/"<<operacion3<<")";
  
      resultado = ss.str();

      return resultado;


  } else{

    operacion1= tem->getCoeficiente()* coeficiente;
    ss<< "("<<operacion1<<")"<<" ("<<radicando<<") "<<"^"<<"1/"<<indice<<")"<<" ("<<tem->getRadicando()<<") 1/"<<tem->getIndice();
  
    resultado = ss.str();

    return resultado;

  }



  }

  
  virtual string operator*(int numero){
    stringstream ss;    
    int operacion1;
    int operacion2;

    string resultado;

    operacion1=coeficiente*numero;


    ss<< "("<<operacion1<<")"<<" ("<<indice<<") "<<"^"<<"("<<radicando<<")";

    resultado = ss.str();


    return resultado;

  }

  

  virtual string operator*(double numero){
    stringstream ss;    
    int operacion1;
    int operacion2;

    operacion1= coeficiente*numero;

    string resultado;

    ss<< "("<<operacion1<<")"<<" ("<<indice<<") "<<"^"<<"("<<radicando<<")";

    resultado = ss.str();


    return resultado;
    


  }

  
  virtual string operator/(Real* real){
  
    stringstream ss;
    Radical* tem = dynamic_cast<Radical*>(real);
    
    int operacion1;
    int operacion2;
    int operacion3;

    string resultado;


    if(tem->getRadicando()==radicando){

      operacion1= coeficiente/tem->getCoeficiente();
      operacion2 = indice/tem->getIndice(); 
      operacion3 = radicando*tem->getRadicando();


      ss<< "("<<operacion1<<")"<<" ("<<operacion2<<") "<<"^"<<"("<<operacion3<<")";
      resultado = ss.str();

     }
     return resultado;
    

  }

  

  virtual string operator/(int numero){
      
    int operacion1;
    int operacion2;

    stringstream ss;
    string resultado;

    operacion1= coeficiente/numero;

    ss<<"("<<operacion1<<")"<<" ("<<indice<<") "<<"^"<<"("<<radicando<<")";

    resultado = ss.str();


    return resultado;
    

  }

  virtual string operator/(double numero){
    int operacion1;
    int operacion2;

    stringstream ss;
    string resultado;

    operacion1= coeficiente/numero;


    ss<<"("<<operacion1<<")"<<" ("<<indice<<") "<<"^"<<"("<<radicando<<")";

    resultado = ss.str();


    return resultado;
        

  }
  virtual string toString(){
    stringstream ss;
    string ret;
    ss<<"("<<coeficiente<<")"<<" ("<<indice<<") "<<"^"<<"("<<radicando<<")";
    return ss.str();
  }


  friend ostream& operator <<(ostream &escribirDouble, Radical* r){

    stringstream ss;

    ss<<r->getCoeficiente()<<"("<<r->getRadicando()<<") ^(1/"<<r->getIndice()<<")";

    return escribirDouble<<ss.str();

  }


};

#endif
