#include<iostream>
#include<cstring>
using namespace std ;

typedef long long Int;
Int dp[7500][5];
int a[] = {50,25,10,5,1};
Int F( int T, int last ){
	if ( T == 0 ) return 1;
	if ( T < 0 ) return 0;
	if ( dp[ T ][last] != -1) return dp[ T ][last];
	Int res = 0;
	for( int i = last; i < 5; i++){
		res += F( T - a[ i ], i);
	}
	return dp[ T ][last] = res;

}

int main(){
	int amount;
	while( cin >> amount ){
		memset( dp, -1, sizeof dp);
		cout << F( amount , 0) <<endl;
	}

	return 0;
}
