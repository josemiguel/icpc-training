#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std ;

int dp[ 1005 ];

int F( int N ){
	if ( N == 0 ) return 0;
	if ( N == 1 ) return 1;
	if ( dp[N] != -1 ) return dp[N];
	int res = 1;
	for( int i = 0; i <= N; i++){
		if ( (N - i)%2 ) continue;
		res += F( ( N - i ) / 2 ) ;
	}
	return dp[N] = res;
}

int main(){
	int runs;
	scanf("%d",&runs);
	memset( dp , -1, sizeof dp );
	for( int r = 1; r <= runs; r++){
		int n ;
		scanf("%d",&n);
		printf("%d %d\n", r, F( n ));
	}

	return 0;
}
