#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

char S[ 100005 ];
char t[ 1003 ];
int b[ 100005], n , m;
bool kmp(){
	n = strlen( t );
	m = strlen( S );
	int i = 0, j = -1;
	b[ i ] = j;
	while( i < n ){
		while( j >= 0 && t[ i ] != t[ j ] ) j = b[ j ];
		b[ ++i ] = ++j;
	}
	i = 0, j = 0;
	while( i < m ) {
		while( j >= 0 && S[ i ] != t[ j ] ) j = b[ j ];
		i++, j++;
		if ( j == n ) {
			return true;
		}
	}
	return false;
}
int runs, q;
int main(){
	scanf("%d\n",&runs);
	while( runs-- ){
		gets( S );
		scanf("%d\n",&q);
		while( q-- ){
			gets( t );
			if ( kmp() ) putchar('y');
			else putchar('n');
			putchar(10);
		}
	}

	return 0;
}
