#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[200][1500][15];
int p[1500], pp[1500], N = 0 ;
int F( int u , int n, int k){
	if ( k == 0 && n == 0) return 1;
	if ( k < 0 || u == N  || n < 0 ) return 0;
	if ( dp[u][n][k] != -1) return dp[u][n][k];
	
	return dp[u][n][k] = F( u + 1, n , k ) + F( u + 1, n - pp[u] , k-1);
}

int main(){
	int n,k;
	p[0] = p[1] = 1;
	for( int i = 2; i <= 1200; i++){
		if (!p[i]){
			pp[N++] = i;
			for( int j = i*i; j <= 1200; j+=i){
				p[j] = 1;
			}
		}
	}
	for(int l = 0; l <= N; l++) 
		for( int i = 0; i <= 1500; i++) 
			for(int j = 0; j <= 15; j++) dp[ l ][ i ][ j ] = -1;

	while(scanf("%d %d",&n,&k) && n+k){
		printf("%d\n",F(0,n,k));
	}

	return 0;
}
