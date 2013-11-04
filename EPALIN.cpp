#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int b[100005];
char t[100005];
char r[100005];
int main(){
	while( gets(t)) {
		int i = 0, j = -1;
		b[ i ] = j;
		int n = strlen( t );
		for( int i = 0; i < n; i++ ) r[ n - 1 - i ] = t[ i ]; r[ n ] = 0;
		while( i < n ){
			while( j >= 0 && r[ i ] != r[ j ] ) j = b[ j ];
			i++, j++;
			b[ i ] = j;
		}
		i = 0, j = 0;
		while( i < n ){
			while( j >= 0 && t[ i ] != r[ j ] ) j = b [ j ];
			i++, j++;
			if ( n == j ) {
				break;
			}
		}
		printf("%s",t);
		for( int i = j; i < n ; i++ ) putchar(r[ i ] );
		putchar( 10 );	
	}
}
