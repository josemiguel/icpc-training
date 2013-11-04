#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std ;

char *mydup( char *cad ){
	char *res = new char[ strlen( cad ) + 1 ];
	strcpy( res, cad );
	return res;
}

void *creaNodo( int t_id, char *t_nombre, char *t_apellido ){
	char *nombre = mydup( t_nombre );
	char *apellido = mydup( t_apellido );
	int *id = new int;
	*id = t_id;

	void **nodo = new void*[4];

	nodo[0] = id;
	nodo[1] = nombre;
	nodo[2] = apellido;
	nodo[3] = NULL;


	return nodo; // no hace falta castear :3
}

void imprime( void *t_lista ){
	void **lista = ( void ** ) t_lista;
	int k = 0;
	while( lista && k++ <10){
		int id = *(int * )lista[0];
		char *nombre = (char * )lista[1];
		char *apellido = (char * )lista[2];

		printf("%d %s %s\n", id, nombre, apellido );
		lista = ( void ** ) lista[3];
	}
}

void inserta( void *&t_lista, void *t_nodo ){
	if ( t_lista == NULL ){
		t_lista = t_nodo;
		return ;
	}

	void **nodo = ( void **) t_nodo;

	void **cur = ( void **) t_lista;
	void **back = cur;
	while( cur && (*(int *) cur[0]) < (*(int *) nodo[0])  ) {
		back = cur;
		cur = ( void ** ) cur[3]; // aca si se castea;
	}
	back[3] = nodo;
	nodo[3] = cur;

}


int main(){
	void *lista = NULL;
	int id; 
	char nombre[100], apellido[100];
	while ( scanf("%d %s %s", &id, nombre, apellido ) != EOF ){
		void *nodo = creaNodo( id, nombre, apellido );
		inserta( lista, nodo );
	}
	imprime( lista );


	return 0;	
}



