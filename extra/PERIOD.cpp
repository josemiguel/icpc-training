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
	printf("Test case #%d\n",r);
	for( int i = 2; i <= m; i++){
		if ( !b[ i ] ) continue;
		int tmp = i - b[ i ] ;
		if ( i % tmp ) continue;
		printf("%d %d\n", i,  i / tmp);
	}
	putchar(10);
}

int main(){
	int runs,x;
	scanf("%d\n",&runs);
	for( int r = 1; r <= runs; r++){
		scanf("%d\n",&x);
		gets( t );
		m = strlen( t );
		kmp(r);
	}

	return 0;
}
