#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

int b[ 1000005 ], n , m;
char t[ 1000005 ];
void kmp(int r){
	// t es substring de s
	int i = 0, j = -1;
	b[ i ] = j;
	while( i <= m ){
		while( j >= 0 && t[ i ] != t[ j ] ) j = b[ j ];
		i++, j++;
		b[ i ] = j;
	}
	int tmp = m - b[ m ] ;
	if ( m % tmp ) puts("1");
	else printf("%d\n",m / tmp);
}

int main(){
	while( gets( t ) && t[0] !='*') {
		m = strlen( t );
		kmp(0);
	}

	return 0;
}
