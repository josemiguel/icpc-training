#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std ;

int dp[152][152][2];
int n, k ;
int F( int pos, int T , int b){
	if ( pos == n + 1 ) return T == 0;
	if ( dp[pos][T][b] != -1 ) return dp[pos][T][b];
	int res = 0;
	res += F( pos + 1, T - b, 1 );
	res += F( pos + 1, T , 0 );
	
	return dp[pos][T][b] = res;
}

int main(){
	int T, r;
	cin >> T;
	while( T--){
		cin >> r >> n >> k;
		memset( dp, -1, sizeof dp );
		int res = 0;
		cout << r << " " << F(2, k, 0 ) + F( 2, k , 1 ) << endl;
	}

	return 0;
}
