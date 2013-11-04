#include<iostream>
#include<cstdio>
using namespace std;

bool primo(int n){
	if ( n == 0) return false;
	for(int i = 2; i*i <= n; i++){
		if ( n % i == 0)  return false;
	}
	return true;
}

int main(){
	int ultimo = 0;
	int contador = 0;
	while(contador <= 100){
		int j = 0;
		int numerador, denominador;
		for(int i = ultimo; i <= 2000 && j != 2; i++){
			int n = i;
			if (primo(i)){
				if ( j == 0 ) numerador = i;
				else denominador = i;			
				j++;
			}
		}
		ultimo = denominador + 1;
		cout<<numerador<<"/"<<denominador<<" + ";
		contador++;
	}
	cout<<endl;
}





