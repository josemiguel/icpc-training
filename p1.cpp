#include<cstdio>
#include<iostream>
#include<cctype>
#include<cstring>

using namespace std;

char *mydup( char a[]){
	char *res = new char[strlen(a)+1];
	strcpy(res, a);
	return res;
}

int inserta_nodoA( char *t_tmp[] , char *s , int &n ){

	for( int i = 0 ; i < n; i++){

		if ( !strcmp(t_tmp[i] , s ) ) return i;
	}
	
	t_tmp[ n++ ] = s;
	
	return n;
}

double *crea_nodoB( double fecha , double val, int c ){
	double *nodo = new double[3];
	nodo[0] = fecha;
	nodo[1] = val;
	nodo[2] = c;
	return nodo;
}

void inserta_nodoB( double **&g , int pos, int szG[], int ult[], double *nodo ){

	double *cp[ ult[pos] ];
	if ( szG[pos] == 0 ){
		g = new double *[1];
		szG[ pos ]++;
	}else if ( ult[pos] >= szG[pos]){
		szG[pos] *=2 ;
		for( int i = 0; i < ult[pos]; i++) cp[ i ] = g[ i ];
		g = new double*[ szG[pos] ];
		for( int i = 0; i < ult[pos]; i++) g[ i ] = cp[ i ];

	}
	g[ ult[pos]++ ] = nodo;
	g[ ult[pos] ] = NULL;
}

void llena( char **&t, double ***&g){
	int d,m,a,c;
	double val;
	int sz = 0;
	char *t_tmp[ 3000 ] ;
	double **g_tmp[ 3000 ];
	int szG[ 3000 ] = {0};
	int ult[ 3000 ] = {0};
	while( scanf("%d/%d/%d %lf %d",&a,&m,&d,&val,&c) != -1 ){
		char s_tmp[ 101 ];
		gets( s_tmp ); 
		int pos = inserta_nodoA(  t_tmp, mydup( s_tmp ) , sz );

		double *nodo = crea_nodoB( a * 10000 + m * 100 + d, val , c );

		inserta_nodoB( g_tmp[pos],pos, szG , ult, nodo );
	}
	t = new char*[ sz ] ;
	g = new double **[sz];
	for( int i = 0; i < sz; i++) {
		t[ i ] = t_tmp[ i ];
		g[ i ] = g_tmp[ i ];
	}
	t[ sz ]  = NULL, g[ sz ] = NULL;


}


int main(){
	char **tarjetas;
	double ***gastos;
	
	llena(tarjetas, gastos);
	for( int i = 0; tarjetas[ i ] ; i++){
		cout << tarjetas[ i ]<<" : " << endl;
		for(int j = 0; gastos[ i ][ j ] ; j++){
			for( int k = 0; k < 3; k++){
				printf(" %.0lf ", gastos[i][j][k] );
			}
			putchar(10);
		}

	}
	

	return 0;
}
