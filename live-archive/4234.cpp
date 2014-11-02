#include <iostream>
#include <cstdio>
using namespace std;

void tobi( int n ){
	for( int i = 5; i >= 0; i-- ){
		printf("%d", ( n >> i ) & 1 );
	}
}

int main(){
	int runs;
	scanf("%d",&runs);
	for( int r = 1; r <= runs; r++){
		int h , m , s;
		scanf("%d:%d:%d",&h, &m, &s);
		printf("%d ",r);
		for( int i = 5; i >= 0; i-- ){
			printf("%d%d%d", 
			(h >> i) & 1 ,
			(m >> i) & 1 ,
			(s >> i) & 1);
		}
		putchar( 32 );
		tobi( h );
		tobi( m );
		tobi( s );
		putchar(10);
	}

	return 0;
}
