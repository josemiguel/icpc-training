#include<stdio.h>
#include<math.h>
#define min( x, y ) x < y ? x : y
int main(){
	int n, lo , hi,  mid, f;
	char c;
	while( true ){
		n = 0;
		while( (c = getchar()) != '\n' && c != -1 ) n = n * 10 + c-'0';
		if ( c == -1 ) break;
		lo = 0, hi = min( 44722 ,n );
		while ( lo <= hi ){
			mid = ( lo + hi ) >> 1;
			f = (mid * (mid + 1)) >> 1;
			if ( f == n ){
				printf( "%d\n", mid );
				goto hell;
			}
			if ( f > n ) hi = mid - 1;
			else lo = mid + 1;
			
		}
		puts("bad");
		hell:;
	}

	return 0;
}
