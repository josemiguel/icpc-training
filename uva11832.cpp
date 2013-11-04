#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
using namespace std ;
int N, sum; 
int a[ 45 ], op[ 45 ];
map<int,bool> dp[ 45 ];
bool F( int T, int u ){
	if ( u == N && T == sum) return true;
	if ( u == N ) return false;	
	if ( dp[ u ].count( T ) ) return dp[ u ][ T ];

	bool neg = F( T - a[u], u + 1);
	bool pos = F( T + a[u], u + 1);
	
	if ( neg && pos ) {
		op [ u ] += 3; // no sirve
	}
	if ( neg && !pos ){
		if ( op[ u ] == -1 ) op[ u ] = 0; //solo neg
		else if ( op[ u ] != 0 ) op[ u ] = 2;
	}
	if ( !neg && pos ){
		if ( op[ u ] == -1) op[ u ] = 1;// solo pos
		else if ( op[ u ] != 1 ) op[ u ] = 2;
	}

	return dp[ u ][ T ] = neg || pos;
}

int main(){
	string res = "";
	while (scanf("%d %d",&N,&sum)){
		if ( N == 0 && sum == 0) break;
		for( int i = 0; i < N; i++) scanf("%d",a+i), dp[ i ].clear();
		memset( op, -1, sizeof op );
		if ( F( 0 , 0 )  ){
			char c;
			for ( int u = 0; u < N; u++){
				if ( op[ u ] > 1 ){
					c = '?';
				}else if ( op[ u ] == 0 ){
					c = '-';
				}else if ( op[ u ] == 1){
					c = '+';
				}
				putchar( c );
			
			}
		}else{
			putchar('*');
		}
		putchar( 10 );
	}
	return 0;
}
