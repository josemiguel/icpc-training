#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int N,K;
int dp[105][105];
#define MOD 1000000
int F( int T, int k ){
	if ( k == 0 && T == 0) return 1;
	if ( k < 0 || T < 0) return 0;
	if ( dp[T][k] != -1) return dp[T][k];
	int res = 0;
	for( int i = 0; i <= N; i++){
		res = (res % MOD +  F( T - i , k - 1) % MOD ) % MOD;
	}
	return dp[T][k] = res % MOD;

}

int main(){
	memset( dp, -1, sizeof dp );
	while( cin >> N >> K && N + K){
		cout << F( N, K ) << endl;
	}

	return 0;
}
