#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std ;

int n,s;
typedef long long Int;
Int  dp[66][2][66];
Int F( int u , int last ,int c) {
	if ( u == 0 && c == 0) return 1;
	if ( u == 0 ) return 0;
	if ( last == 1 && c == 0 ) return 1;
	if ( last == 0 && c == 0 ) return 0;

	if ( dp[u][last][c] >= 0) return dp[u][last][c] ;

	return dp[u][last][c] =  F( u - 1, 0 , c - 1) + F( u - 1, 1, c -!last);
}
int main(){
	memset( dp,-1,sizeof dp);
	while( cin >> n >> s ){
		if ( n <0  && s < 0 ) break;
		Int res = F( n - 1, 0, n - s -1 ) + F( n - 1, 1, n - s );
		printf("%lld\n",res);
	}
	return 0;

}
