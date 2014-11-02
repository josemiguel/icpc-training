#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std ;
int a[44723];
int main(){
	int n, lo , hi,  mid, f;
	char c;
	for( int i = 0; i <= 44722 ; i++) a[i] = (i*(i+1))>>1;
	while( true ){
		n = 0;
		while( (c = getchar()) != '\n' && c != -1 ) n = n * 10 + c-'0';
		if ( c == -1 ) break;
		int *p = find( a, a+ 44723 , n );
		if ( p-a == 44723 ) puts( "bad" );
		else printf("%d\n", p - a );
	}

	return 0;
}
