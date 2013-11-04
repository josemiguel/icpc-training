#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std ;
typedef long long Int;

Int dp[55][55];
int n,m,k;
Int F( int T, int j ){
	if ( T == 0 && j == k ) return 1;
	if ( T < 0 || j > k ) return 0;
	if ( dp[T][j] != -1) return dp[T][j];
	Int res = 0;
	for(int i = 1; i <= m; i++){
		res += F( T - i , j + 1 ) ;
	}
	return dp[T][j] = res;
}

int main(){
	while( cin >> n >> k >> m ){
		memset( dp, -1 ,sizeof dp );
		cout << F( n, 0 ) << endl;
	}

}
