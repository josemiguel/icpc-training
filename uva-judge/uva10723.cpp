#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[32],b[32];
int g[32][32], f[32*32][32][32];

int G( int x, int y){
	if ( x == 0 || y == 0) return 0;
	if ( g[x][y] != -1 ) return g[x][y];
	if ( a[x] == b[y] ) return g[x][y] = G(x-1,y-1) + 1;
	return g[x][y] = max( G(x-1,y) , G(x,y-1) );
}

int F( int L, int x, int y ){
	if ( f[L][x][y] != -1) return f[L][x][y];
	if ( x == 0 || y == 0){
		if ( x + y == L ) return f[L][x][y] = 1;
		return f[L][x][y] = 0;
	}

	int res = 0;
	if ( a[x] == b[y] ) res = F( L-1, x-1,y-1);
	else res = F( L-1, x-1, y) + F( L-1, x,y-1);

	return f[L][x][y] = res;
}

int main(){

	int runs;
	scanf("%d",&runs);
	
	for( int r = 1; r <= runs; r++){

		scanf("%s\n%s",a+1,b+1);
		memset( g, -1, sizeof g);
		memset( f, -1, sizeof f);

		int n = strlen( a + 1);
		int m = strlen( b + 1);
		int shortest = n + m - G(n,m);
		printf("Case #%d: %d %d\n",r, shortest, F(shortest, n, m) );

	}

	return 0;
}
