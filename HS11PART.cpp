#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std ;

int dp[ 30 ][ 500 ];
int n, a[ 30 ];
bool F( int u ,int sum ){
	if ( u == n ) {
		return sum == 0;
	}
	if ( dp[u][sum] != -1) return dp[u][sum];
	return dp[u][sum] = F( u + 1 , sum ) | F( u + 1, sum - a[u] );
}

int main(){
	int t;
	scanf("%d",&t);
	while( t-- ){
		scanf("%d",&n );
		int sum = 0;
		for(int  i = 0; i < n; i++) scanf("%d",a+i), sum+=a[i];
		if ( sum % 2 ) puts("NO");
		else {	
			memset( dp, -1,sizeof dp );
			if ( F( 0, sum / 2 ) ){
				puts( "YES");
			}else{
				puts("NO");
			}
		}
	}

	return 0;
}
