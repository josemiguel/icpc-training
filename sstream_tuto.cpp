#include<sstream>
#include<iostream>
using namespace std;

int main(){
	string linea;

	getline(cin,linea); // coge toda una linea de un archivo de texto o entrada standard
	
	//si linea es igual a 12 10 12 5
	//linea = "12 10 12 5";
	
	istringstream is(linea); //is es una variable que se comportará extactamente igual al "CIN"
	//con la diferencia que "is" leerá de línea
	
	int token;
	
	while(is>>token){ // mientras pueda leer algo de la linea
		cout<<token<<endl; //imprime lo que lee, en este caso un numero 12, 10, 12, 5
	}
	// a tu criterio queda que quieras leer, pueden ser doubles o strings, incluso este caso ::::
	cout<<"*************"<<endl;	
	linea = "12,12,5,3,34,12"; // si leiste algo asi -> numeros separados por comas
	
	//se cambia todos las comas por espacios para poder ser leido sin problemas con el is
	for(int i = 0; i < linea.size(); i++) 
		if (linea[i]==',') 
			linea[i] = ' ';
	
	istringstream otro_is(linea);
	
	while(otro_is>>token){
		cout<<token<<endl;
	}
	
}
