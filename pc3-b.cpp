#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void **crea_nodo( char *linea[], int n){
    void **nodo = new void*[ n + 2 ];
    int *size = new int[ 1 ] ;
    size[ 0 ] = n;
    nodo[ 0 ] = size;
    nodo[ n + 1 ] = NULL;
    for( int i = 1; i <= n ; i++) {
        nodo[ i ] = linea[ i - 1 ] ;

    }
    return nodo;
}

void insert( void **it , char *linea[], int n ){
    //CREAR NODO
    void **nodo = crea_nodo( linea, n );
    //INSERCION

    if ( it[ 1 ] == NULL){
        it[ 1 ] = nodo;
    }else{

        void **tmp = ( void ** ) it[ 1 ];
        int m = *(int * )tmp[ 0 ];
        while( tmp [ m + 1 ] != NULL ){

            tmp = (void **) tmp [ m + 1 ];
            m = *(int *) tmp[0] ;
        }
        tmp[ m + 1 ] = nodo;
    }
}


bool search2( void *ptr, char pal[]){
	if ( !ptr ) return false;
	bool res = false;
	void **tmp = (void **) ptr;
	int size = *(int *) tmp[0];
	bool esta = false;
	for( int i = 1; i <= size ; i++){
		char *s = (char *) tmp[i];
		if ( strcmp( s, pal) == 0 ) {
			esta = true;
			break;
		}
	}
	if ( esta ) {
		for( int i = 1; i <= size; i++){
			char *s = (char *) tmp[i];
			if ( strcmp( s, pal ) == 0 )continue;
			printf("\t%s\n", s ) ; 
		}
		res |= true;
	}else{
		res |= search2( tmp[ size + 1 ] , pal );
	}
	return res;
}


bool search( char pal[], void *ptr ){
	
	void **tmp = (void **) ptr;
	if ( !tmp ) return false;
	bool res = false;
	while( tmp ){
		res |= search2( tmp[ 1 ], pal ) ;
		tmp = (void **) tmp[2];
	}
	return res ;
}


int main(){



    int n = 0;
    char *dic[ 100 ][ 100 ];
    int ndic[ 100 ] = { 0 };
    while( true ){
        char tmp[ 100 ];
        int ret ;
        while( (ret = scanf("%s", tmp) ) != EOF && tmp[0] != '*'){
        	if ( tmp[0] == '-') break;
            int pos = ndic[ n ];
            dic[ n ][ pos ] = new char [ strlen( tmp ) + 1];
            strcpy( dic[ n ][ pos ], tmp );
            ndic[ n ]++;

        }
        if ( tmp[0] == '-' ) break;
        n++;
    }


    for( int i = 0; i < n; i++ ){
        for( int j = i + 1 ; j < n; j++){
            if ( strcmp( dic[i][0], dic[j][0]) > 0 ) {
	            swap( dic[i] , dic[j] );
	            swap( ndic[i] , ndic[j] );	            
            }
        }
    }




    void **it = new void* [ 3 ];

    it[ 0 ] = &dic[ 0 ][ 0 ][ 0 ];
    it[ 1 ] = NULL;
    it[ 2 ] = NULL;
    insert( it, dic[0], ndic[0]);
    
    
    void * diccDeSinonimos = it ;

    char ant = dic[ 0 ][ 0 ][ 0 ];


    for( int i = 1; i < n; i++){
        if ( dic[ i ][ 0 ][ 0 ] != ant ){
            it[ 2 ] = new void **[ 3 ];
            it = (void ** ) it[ 2 ];
            it[ 0 ] = &dic[ i ][ 0 ][ 0 ];
            it[ 1 ] = NULL;
            it[ 2 ] = NULL;
        }
        insert( it, dic[ i ], ndic[ i ] );
        ant = dic[ i ][ 0 ][ 0 ];
    }
	char pal[100];
	while( scanf("%s", pal ) != EOF ){
		printf("%s :\n ", pal );
		bool esta = search( pal, diccDeSinonimos );
		if ( !esta ) {
			puts("\tNo se encontró");
		}
		putchar('\n');
	}
	
    return 0;
}
