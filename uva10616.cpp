#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long Int;
int a[201];
int dp[201][11][21];;
int D,N,Q,M;

int MOD( int a, int b){
	if ( a < 0 ) return -( -a % b - b) % b;
	return a % b;
}

int F( int u , int m, int sum){
	if ( sum == 0 && m == 0) return 1LL;
	if ( u == N || m <= 0) return 0LL;
	if ( dp[u][m][sum] != -1) return dp[u][m][sum];
	return dp[u][m][sum] = F( u + 1 , m , sum ) + F( u + 1,  m - 1,MOD( MOD( sum , D) + MOD ( a[u] , D) , D ));
}

int main(){
	int r = 1;

	while( scanf("%d %d",&N,&Q) && N+Q){
		for(int i = 0; i < N; i++) scanf("%d",a+i);
		printf("SET %d:\n",r++);
		for(int q = 1; q <= Q; q++){
			scanf("%d %d",&D,&M);
			memset( dp, -1, sizeof dp);
			printf("QUERY %d: %d\n",q,F(0,M,0));
		}
	}

	return 0;
}
