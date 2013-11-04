#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int N,n;
int dp[ 2050 ][ 2050 ], usd[ 1050 ];
int a[ 2050 ], res[ 2050 ];
int sum ;

void play(int f, int val){
	usd[ val ] += f;
	sum += val * -f;
}

bool F(int u, int last){
	if ( dp[ u ][ last ] > 0) return dp[ u ][ last ] ;
	if ( u == N ){
		if ( sum % N ) return dp[ u ][ last ] = false;
		printf("Yes\n");
		bool first = true;
		
		for(int i = 0; i < N; i++){
			if (!first) putchar(' ');
			first = false;
			printf("%d",res[ i ]);
		}
		putchar(10);
		return dp[ u ][ last ] = true;
	}
	bool ans = false;
	for(int val = last; val <= 1000; val++){
		if (!usd[ val ]) continue;
		play( -1, val);
		res[ u ] = val; ans |= F( u + 1, val);
		if ( ans ) break;
		play( 1, val );
	}
	return dp[ u ][ last ] = ans; 
	
}

int main(){
	while( scanf("%d",&N) && N  ){
		memset( dp, -1, sizeof dp );
		memset( usd, 0 , sizeof usd );
		n = 2 * N - 1;
		for(int i = 0; i < n; i++){
			scanf( "%d ", a + i);
			usd[ a[ i ] ]++;
		}
		sum = 0;	
		if (! F(0, 0) ) puts("No") ;

	}
	return 0;
}
