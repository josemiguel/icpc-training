#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

int b[ 1000005 ], n , m;
char t[ 1000005 ];
char s[ 1000005 ];
bool kmp(){
	// t es substring de s
	bool done = false;
	int i = 0, j = -1;
	b[ i ] = j;
	while( i <= m ){
		while( j >= 0 && t[ i ] != t[ j ] ) j = b[ j ];
		i++, j++;
		b[ i ] = j;
	}
	/*for( int i = 0; i <= m; i++) cout << b[ i ] << " ";
	cout << endl;*/
	i = 0, j = 0;
	while( i < n ) {
		while( j >= 0 && s[ i ] != t[ j ] ) j = b[ j ];
		i++, j++;
		if ( j == m ){
			printf("%d\n", i - j );
			j = b[ j ];
			done = true;
		}
	}
	return done;
}

int main(){
	int x;
	while( scanf("%d\n",&x) != -1 ){
		gets( t );
		gets( s );
		m = strlen( t );
		n = strlen( s );
		if (!kmp( ) ) putchar(10);
	}

	return 0;
}
