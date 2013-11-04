#include<iostream>
using namespace std ;
int F( int T, int u){
	if ( T == 0 ) return 0;
	if ( u == N ) return 0;
	if (dp[T][u] != -1)  return dp[T][u];
	return dp[T][u] = max( F( T - a[u], u+1) + 1, F(T + a[u], u+1));
}
int main(){

	int runs;

	cin >> runs;
	while ( runs-- ){
		int n ,t, M;
		cin >> M;	
		M*= 100;
		while ( cin >> t && t )	a[n++] = t;
		memset( dp, -1, sizeof dp);
		cout << F( T, 0) <<endl;
	}

	return 0;
}
