#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 1000006
bool is[ MAX ]; // is dira si es o no primo
int p[ MAX ], sz; // p tendra los primos y sz sera el tamaño real

void criba(){
	//is[i] = 0 => es primo
	//is[i] = 1 => no es primo 
	//est tipo al reves, por qué? porque cuando declaras como global se llena con ceros, asi no pierdo tiempo
	//llenando con unos
	is[ 0 ] = is[ 1 ] = 1;//no son primos
	for( int i = 2; i*i < MAX; i++){
		if ( !is[ i ] ){ // si es primo
			for( int j = i + i ; j < MAX; j += i ){
				is[ j ] = 1; // marco como no primo
			}
		}
	}
	sz = 0;
	for( int i = 1; i < MAX; i +=2 ) if ( !is[i] ) p[ sz++ ] = i;
}

void solve( int n, int &a, int &b ){
	for( int i = upper_bound( p , p + sz, n) - p ; i >= 0; i-- ){
		if ( p[ i ] < n ){
			b = p[ i ];
			a = n - p[ i ];
			if ( a % 2 && !is[ a ] ) return;
		}
	}
	a = b = -1;
}

int main(){
	criba();
	int n;
	while( scanf("%d",&n ) && n) {
		int a,b;
		solve( n , a, b );
		if ( a != -1 ) 	printf("%d = %d + %d\n", n , a , b );
		else puts("Goldbach's conjecture is wrong."); //en teoria nunca pasaría xD su goldbach es anal
	}

	return 0;
}
