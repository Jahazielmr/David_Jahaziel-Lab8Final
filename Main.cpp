#include "Real.h"
#include "Radical.h"
#include "Racional.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <typeinfo>
using namespace std;

void guardarTxt(string);

int main(){
  vector<Real*>banco;
  vector<string>operaciones;
	char resp = 's';
 	int option;
  
	while(resp=='s'||resp=='S'){

		cout <<"Menu"<<endl;
		cout <<"1-Agregar Real"<<endl;
		cout <<"2-Operar entre numeros del banco"<<endl;
		cout <<"3-Operar numero del banco con otro numero"<<endl;
		cout <<"4-Salir"<<endl;
		cin>> option;
		switch (option){
			case 1:{
				int op2;
				cout<<"Menu de Agregar Reales"<<endl;
				cout<<" "<<endl;
				cout<<"1-Agregar Racional"<<endl;
				cout<<"2-Agregar Radical"<<endl;
				cin>>op2;

				switch(op2){
					case 1:{
						//Agregar Racional
						int numerador;
						int denominador;
						cout<<"Ingrese el numerador: ";
						cin>>numerador;
						cout<<"Ingrese el denominador: ";
						cin>>denominador;
						Real* racional = new Racional(numerador,denominador);

						cout<<"Este es el racional que se acaba de añadir"<<endl;
						Racional* tem = dynamic_cast<Racional*>(racional);
						cout<<tem;

						cout<<" "<<endl;

						banco.push_back(racional);
						cout<<"Racional agregado!!"<<endl;
					break;
					}

					case 2:{
						//Agregar Radical
						int indice;
						int coeficiente;
						int radicando;
						cout<<"Ingrese el indice del radical: ";
						cin>>indice;
						cout<<"Ingrese el radicando: ";
						cin>>radicando;
						cout<<"Ingrese el coeficiente: ";
						cin>>coeficiente;
						Real* radical = new Radical(coeficiente,indice,radicando);

						cout<<"Este es el radical que se acaba de añadir"<<endl;
						Radical* tem = dynamic_cast<Radical*>(radical);
						cout<<tem;
						cout <<" "<<endl;


						banco.push_back(radical);
					break;
					}
				}//fin switch 2


				break;
			}

			case 2:{
				//Peracion entre dos numeros del banco
				Real* num1;
				Real* num2;
				int x;
				int y;
				for (int i = 0; i < banco.size(); i++){
					cout<<i<<": "<<banco[i]->toString()<<endl;
				}
				cout<<"Elija el numero 1: ";
				cin>> x;
				cout<<"Elija el numero 2: ";
				cin>> y;
				if(typeid(Racional)==typeid(*banco[x])&&typeid(Radical)==typeid(*banco[y])){
					num1 = banco[x];
					num2 = banco[y];
				}
				if(typeid(Racional)==typeid(*banco[y])&&typeid(Radical)==typeid(*banco[x])){
					num1 = banco[y];
					num2 = banco[x];
				}
				if(typeid(Racional)==typeid(*banco[x])&&typeid(Racional)==typeid(*banco[y])){
					num1 = banco[x];
					num2 = banco[y];
				}
				if(typeid(Radical)==typeid(*banco[x])&&typeid(Radical)==typeid(*banco[y])){
					num1 = banco[x];
					num2 = banco[y];
				}
				int op3;
				cout<<"Eljia la operacion que desea: "<<endl;
				cout<<"1. Suma"<<endl;
				cout<<"2. Resta"<<endl;
				cout<<"3. Multiplicacion"<<endl;
				cout<<"4. Division"<<endl;
				cin>>op3;
				switch(op3){

					case 1:{
						stringstream ss;
						string res = *num1 + num2;
						ss<<num1->toString()<<" + "<<num2->toString()<<" = "<<res<<endl;
						string a = ss.str();
						cout<< a;
						operaciones.push_back(a);

						guardarTxt(a);

						break;
					}
					case 2:{
						stringstream ss;
						string res = *num1 - num2;
						ss<<num1->toString()<<" - "<<num2->toString()<<" = "<<res<<endl;
						string a = ss.str();
						cout<< a;
						operaciones.push_back(a);
						guardarTxt(a);
						break;
					}
					case 3:{
						stringstream ss;
						string res = (*num1) * num2;
						ss<<num1->toString()<<" * "<<num2->toString()<<" = "<<res<<endl;
						string a = ss.str();
						cout<< a;
						operaciones.push_back(a);
						guardarTxt(a);
						break;
					}
					case 4:{
						stringstream ss;
						string res = (*num1) / num2;
						ss<<num1->toString()<<" / "<<num2->toString()<<" = "<<res<<endl;
						string a = ss.str();
						cout<< a;
						operaciones.push_back(a);
						guardarTxt(a);
						break;
					}
				}
				break;
			}//fin case 2
			case 3:{
				Real* num1;
				int x;
				int y;
				for (int i = 0; i < banco.size(); i++){
					cout<<i<<": "<<banco[i]->toString()<<endl;
				}
				cout<<"Elija el numero 1: ";
				cin>> x;
				cout<<"Ingrese el entero: ";
				cin>>y;
				num1 = banco[x];
				int op3;
				cout<<"Eljia la operacion que desea: "<<endl;
				cout<<"1. Suma"<<endl;
				cout<<"2. Resta"<<endl;
				cout<<"3. Multiplicacion"<<endl;
				cout<<"4. Division"<<endl;
				cin>>op3;
				switch(op3){

					case 1:{
						stringstream ss;
						string res = (*num1) + y;
						ss<<num1->toString()<<" + "<<y<<" = "<<res<<endl;
						string a = ss.str();
						cout<< a;
						operaciones.push_back(a);
						guardarTxt(a);
						break;
					}
					case 2:{
						stringstream ss;
						string res = (*num1) - y;
						ss<<num1->toString()<<" - "<<y<<" = "<<res<<endl;
						string a = ss.str();
						cout<< a;
						operaciones.push_back(a);
						guardarTxt(a);
						break;
					}
					case 3:{
						stringstream ss;
						string res = (*num1) * y;
						ss<<num1->toString()<<" * "<<y<<" = "<<res<<endl;
						string a = ss.str();
						cout<< a;
						operaciones.push_back(a);
						guardarTxt(a);
					}
					case 4:{
						stringstream ss;
						string res = (*num1) / y;
						ss<<num1->toString()<<" / "<<y<<" = "<<res<<endl;
						string a = ss.str();
						cout<< a;
						operaciones.push_back(a);
						guardarTxt(a);
						break;
					}
				}
				
				break;
			}



		}

		cout <<"Desea continuar[s/n]"<<endl;
		cin >>resp;

	}
	return 0;
}

void guardarTxt(string a){
	ofstream archivo;
    string ruta="Nombre.txt";
    stringstream ss;
    ss<<"Operaciones.txt";
    ruta=ss.str();
    archivo.open(ruta.c_str(),ios::app);            
    archivo<<a<<endl;            
    archivo.close();
}