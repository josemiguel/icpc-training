#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

int MOD;
inline int S( int a, int b ){  return (a % MOD + b % MOD) % MOD;}
inline int M( int a, int b ){  return (a % MOD * b % MOD) % MOD;}
int pot[ 102 ];

int dp[ 101 ][ 101 ][ 201 ];
bool done;
bool f( int unos, int n , int T ){
	if ( n > 100 ) return false;
	if ( unos && T == 0 ) return done = true;
	if ( dp[ unos ][ n ][ T ] != -1) return dp[unos][n][T] ;
	bool a = f( unos + 1 , n + 1, S( T , pot[ n ] ));
	bool b = f( unos , n + 1, T );
	return dp[ unos ][ n ][ T ] = a || b ;
}
string res;
void path( int u , int n, int t ){
	if ( n > 100 ) return ;
	if ( u && !t ) return;
	int val = pot[ n ];
	bool a = f ( u + 1, n + 1, S( t, val ) );
	bool b = f ( u , n + 1, t );
	if ( a ){
		path( u + 1 , n + 1, S( t, val ) );
		res +='1';
	}else if ( b ) {
		path( u , n + 1, t );
		res +='0';
	}
}

vector<string> mp( 202 );
int main(){

	for( MOD = 150; MOD <= 200; MOD++ ){
		memset( dp , -1, sizeof dp);
		res = "";
		pot[ 0 ] = 1 % MOD;
		for( int i = 1; i < 105; i++ ) pot[ i ] = M( pot[ i - 1 ], 10 );
		f( 0 ,0 , 0);
		path( 0 ,0 ,0 );
		mp[ MOD ] = res;
	}

	while( scanf("%d",&MOD ) && MOD ) {
		if ( mp[ MOD ] != "" ){
			cout << mp[ MOD ] << endl;
		}else{
			pot[ 0 ] = 1 % MOD;
			for( int i = 1; i < 105; i++ ) pot[ i ] = M( pot[ i - 1 ], 10 );
			memset( dp , -1, sizeof dp);
			res = "";
			f( 0 ,0 , 0);
			path( 0 ,0 ,0 );
			cout << res <<endl;
		}
	}
	

	return 0;
}
