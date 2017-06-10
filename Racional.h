#ifndef RACIONAL_H
#define RACIONAL_H
#include <string>
#include <iostream>
#include <sstream>
#include "Radical.h"
#include "Real.h"
#include <typeinfo>
using namespace std;

class Racional : public Real{

  private:
    int numerador;
    int denominador;
  
  public:

    Racional();
    Racional(int,int);
    
    int getNumerador();
    void setNumerador(int);

    int getDenominador();
    void setDenominador(int);

    virtual string operator+ (Real* real){
        
        if(typeid(Racional)==typeid(*real)){
            stringstream ss;

            Racional* resultado = new Racional();
            Racional* tem = dynamic_cast<Racional*>(real);
            string res="";
            if(denominador == tem->getDenominador()){
                resultado->setNumerador(numerador+tem->getNumerador());
                resultado->setDenominador(denominador);
            }else{
                int A1;
                int A2;
                int B;

                A1 = numerador * tem->getDenominador();
                A2 = tem->getNumerador() * denominador;

                B = tem->getDenominador() * denominador;

                resultado->setNumerador(A1+A2);
                resultado->setDenominador(B);
        }

            int resN = resultado->getNumerador();
            int resD = resultado->getDenominador();

            ss<<resN << "/" <<resD;
            res = ss.str();
            return res;

        }else{
            Radical* tem = dynamic_cast<Radical*>(real);
            stringstream ss;
            string ret = "";
            int coeficiente1 = tem->getCoeficiente() * denominador;

            int indice = tem->getIndice();
            int radicando = tem->getRadicando();
      
            ss<< "("<<numerador <<"+ ("<<coeficiente1<<")("<<radicando<<")^(1/"<<indice<<")) /"<<denominador;
            ret = ss.str();
            return ret;
        }

        
        

    }

    virtual string operator+(int entero){
        int suma = (entero*denominador) + numerador;
        stringstream ss;
        string res;
        ss<< suma <<"/" << denominador;
        res = ss.str();
        return res;

    }
    virtual string operator+ (double doble){
        double suma = (doble*denominador) + numerador;
        stringstream ss;
        string res;
        ss<< suma <<"/" << denominador;
        res = ss.str();
        return res;
    }

    virtual string operator- (Real* real){
        if(typeid(Racional)==typeid(*real)){
            stringstream ss;

            Racional* resultado = new Racional();
            Racional* tem = dynamic_cast<Racional*>(real);
            string res="";
            if(denominador == tem->getDenominador()){
                resultado->setNumerador(numerador-tem->getNumerador());
                resultado->setDenominador(denominador);
            }else{
                int A1;
                int A2;
                int B;

                A1 = numerador * tem->getDenominador();
                A2 = tem->getNumerador() * denominador;

                B = tem->getDenominador() * denominador;

                resultado->setNumerador(A1-A2);
                resultado->setDenominador(B);
        }

            int resN = resultado->getNumerador();
            int resD = resultado->getDenominador();

            ss<<resN << "/" <<resD;
            res = ss.str();
            return res;

        }else{
            Radical* tem = dynamic_cast<Radical*>(real);
            stringstream ss;
            string ret = "";
            int coeficiente1 = tem->getCoeficiente() * denominador;

            int indice = tem->getIndice();
            int radicando = tem->getRadicando();
      
            ss<< "("<<numerador <<"- ("<<coeficiente1<<")("<<radicando<<")^(1/"<<indice<<")) /"<<denominador;
            ret = ss.str();
            return ret;
        }
    }
    
    virtual string operator- (int entero){
        int suma = (entero*denominador) - numerador;
        stringstream ss;
        string res;
        ss<< suma <<"/" << denominador;
        res = ss.str();
        return res;
    }
    virtual string operator- (double doble){
        double suma = (doble*denominador) - numerador;
        stringstream ss;
        string res;
        ss<< suma <<"/" << denominador;
        res = ss.str();
        return res;
    }

    virtual string operator* (Real* real){
        if(typeid(Racional)==typeid(*real)){
            stringstream ss;
            string res="";
            Racional* tem = dynamic_cast<Racional*>(real);
            int denR = denominador * tem->getDenominador();
            int numR = numerador * tem->getNumerador();

            ss<<numR<<"/"<<denR;
            res =  ss.str();
            return res;
        }else{
            stringstream ss;
            string res="";
            Radical* tem = dynamic_cast<Radical*>(real);
            int coeficiente1 = denominador * tem->getCoeficiente();
            int indice1 = tem->getIndice();
            int radicando1 = tem->getRadicando();
            ss<<"("<<coeficiente1<<")("<<radicando1<<")^(1/"<<indice1<<")"<<"/"<<denominador;
            res = ss.str();
            return res;
        }

    }
    
    virtual string operator* (int entero){
        stringstream ss;
        int numR = numerador * entero;
        ss<<numR<<"/"<<denominador;
        return ss.str();
    }
    virtual string operator*(double doble){
        stringstream ss;
        double numR = numerador * doble;
        ss<<numR<<"/"<<denominador;
        return ss.str();
    }

    virtual string operator/(Real* real){
        if(typeid(Racional)==typeid(*real)){
            stringstream ss;
            string res="";
            Racional* tem = dynamic_cast<Racional*>(real);
            int denR = denominador * tem->getNumerador();
            int numR = numerador * tem->getDenominador();

            ss<<numR<<"/"<<denR;
            res = ss.str();
            return res;
        }else{
            stringstream ss;
            string res="";
            Radical* tem = dynamic_cast<Radical*>(real);
            int coeficiente1 = denominador * tem->getCoeficiente();
            int indice1 = tem->getIndice();
            int radicando1 = tem->getRadicando();
            ss<<"("<<coeficiente1<<")("<<radicando1<<")^(1/"<<indice1<<")"<<"/"<<denominador;
            res = ss.str();
            return res;
        }

    }
    
    virtual string operator/(int entero){
        stringstream ss;
        int denR = denominador* entero;
        ss<<numerador<<"/"<<denR;
        string res = ss.str();
        return res;
    }
    virtual string operator/(double doble){
        stringstream ss;
        int denR = denominador* doble;
        ss<<numerador<<"/"<<denR;
        string res = ss.str();
        return res;
    }

    virtual string toString(){
        string ret;
        stringstream ss;
        ss<<numerador<<"/"<<denominador;
        ret = ss.str();
        return ret;
    }
    
    friend ostream& operator <<(ostream &escribirDouble, Racional* r){

        stringstream ss;

        ss<<r->getNumerador()<<"/"<<r->getDenominador();

        return escribirDouble<<ss.str();

    }


};

#endif
