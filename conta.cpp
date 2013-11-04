#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main(){

    char cad[100];
    int valor,suma=0;
    while(scanf("%s %d",cad,&valor)!=EOF){
        suma+=valor;
    }
    cout<<suma;
    return 0;    
}
