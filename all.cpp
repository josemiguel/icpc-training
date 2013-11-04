#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std ;

char *mydup( char *cad ){
	char *res = new char[ strlen(cad) + 1 ];
	strcpy( res, cad );
	return res;
}

int main(){
	char cad[100][100]; // estatico temporal 
	char **listanom;
	int n = 0;
	while( gets(cad[n]) ) n++; // leemos todo donde n es la cantidad de lineas

	listanom = new char*[ n ]; // le damos el tamaño de la cantidad de lineas

	for( int i = 0; i < n; i++ ){
		listanom[i] = mydup( cad[i] ); // "copiamos", ver que hace mydup
	}
	puts("Este es el char**" );
	for( int i = 0; i < n; i++){
		puts( listanom[i]); // imprime
	}


	// lo del void**

	void **listaNombres = new void*[ n ]; // creamos n (void*)

	for( int i = 0; i < n; i++){
		listaNombres[i] = listanom[i];	// simplemente hacemos que apunte
		// void* = LO QUE SEA SIN CASTEAR 
	}

	puts("Este es el void**" );
	for( int i = 0; i < n; i++){
		puts( (char *) listaNombres[i] );
		// lo que sea = ( castear al tipo de "lo que sea" ) (el dato en void* )
	}

	return 0;
}
