#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
#include<set>
using namespace std ;
typedef long long Int;
int H[ 6055 ];
int dp[ 35 ][ 35 ][ 6005 ], a[ 35 ];
int s[ 35 ], n ;
Int  R = 0;
int F(int cur, int par, int sum ){
	if ( cur == n ){
		if ( H[ sum + 3000 ] == -1 ) {
			cout << sum << endl;
			R++;
			return H[  sum + 3000 ] = 1 ;
		}
		return 0;
	}
	int &res = dp[cur][par][sum + 3000] ;

	if ( res != -1 ) return res;

	int m = par % 2 ? -1 : 1;
	int m2 = (par+1) % 2 ? -1: 1;
	res = 0;
	if ( s[cur] == -1 ) res += F( cur + 1 , par + 1 , sum +  m2 * a[ cur ] ) ;
	res += F( cur + 1 , par ,  sum + m * s[ cur ] * a[ cur ]) ;
	res += F( cur + 1 , par ,  sum +  s[ cur ] * a[ cur ]) ;
	
	return dp[cur][par][sum + 3000] = res;
}

int main(){
	string tmp;
	while( getline( cin, tmp) ){
		tmp = "+ " + tmp ;
		istringstream is( tmp );
		R  = 0;
		n = 0;
		memset( dp, -1, sizeof dp );
		memset( H , -1 , sizeof H );
		memset( s , -1 , sizeof s );
		char c;
		while( is >> c  ){
			if ( c == '+' ) s[ n ] = 1;
			is >> a[ n ];
			//a[ n ] *= s[ n ] ;
			n++;
		}
		F( 0, 0 ,0  );
		cout << "res :"<<R << endl;
	}	
}
