#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int dp[55][1005];

int F( int b , int m ){
	if ( b == 1 ) return m;
	if ( m == 0 || m == 1 ) return m;
	if ( dp[b][m] != -1 ) return dp[b][m];
	int res = m + 1;
	for( int i = 1; i <= m ; i++ ){
		int p1 = F( b - 1, i - 1 );
		int p2 = F( b , m - i );
		res = min( res , 1 + max( p1 , p2 ) );
	}
	return dp[b][m] = res;

}

int main(){

	int T;
	int r, b, m;
	memset( dp, -1, sizeof dp );
	F( 25, 500);
	scanf("%d",&T);
	while( T--){
		scanf("%d %d %d",&r, &b, &m );
		printf("%d %d\n", r , F( b, m ) );
	}

	return 0;
}
