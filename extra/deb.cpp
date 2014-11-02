#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#define TAM 1<<24 

using namespace std;

int n ;
//string s1, s2 ;
char s1[ TAM ], s2[ TAM ] ;
int b[ TAM ] ;

void prekmp(){
	int i = 0 , j = -1 ;
	b[ i ] = j ;
	while( i < n ){
		while( j >= 0 && s1[ i ] != s1[ j ] ) j = b[ j ] ;
		b[ ++i ] = ++j ;
	}
}
int test = 1 ;

void match(){
	prekmp() ;
	int i = 0 , j = 0 ;
	int len = strlen( s2 );
	bool res = false;
	while( i < len ){
		while( j >= 0 && s2[ i ] != s1[ j ] ) j = b[ j ] ;
		i++ ; j++ ;
		if( j == n ){
			if ( !res && test++ > 1) putchar(10);
			printf("%d\n", i - j ) ;
			res = true;
			j = b[ j ] ;
		}
	}
}

int main(){


	while( scanf("%d\n", &n ) != -1 ){

		gets( s1 ) ;
		gets( s2 ) ;

		match();
	}
	return 0 ;
}
