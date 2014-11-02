#include<iostream>
#include<cstring>
using namespace std ;
typedef long long Int;
Int dp[ 10 ][ 70 ];

Int F( int l , int n ){
	if ( n == 0 ) return 1;
	if ( dp[l][n] != -1) return dp[l][n];
	Int res = 0;
	for( int i = l ; i <= 9; i++){
		res += F( i , n - 1 );
	}
	return dp[l][n] = res;
}

int main(){
	int T;
	cin >> T;
	memset( dp, -1, sizeof dp );
	while( T-- ){
		int r, n;
		cin >> r >> n;
		cout << r << " " << F( 0 , n ) << endl;
	}

	return 0;
}
