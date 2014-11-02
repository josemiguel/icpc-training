#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std ;


bool in ( long long a ){
	return fabs( a ) <= 32000;
}
int a[105];
int dp[ 105 ][ 64005 ];
int n;
bool F( int u , int acum ){
	if ( !in( acum ) ) return false;
	if ( u == n - 1 && acum == a[n-1]) return true;
	if ( u == n - 1) return false;
	if ( dp[ u ][ acum + 32000] != -1) return dp[u][acum + 32000];
	bool res = false;
	if ( in( acum - a[ u ] ) ){
		res |= F( u + 1, acum - a[ u ] );
	}
	if ( in( acum + a[ u ]) ){
		res |= F( u + 1, acum + a[ u ] );
	}
	if ( in( acum * a[ u ] ) ) {
		res |= F( u + 1, acum * a[ u ] );
	}
	if (  acum % a[ u ] == 0 ){
		res |= F( u + 1, acum / a[ u ] );
	}

	return dp[u][acum + 32000] = res;
}

void track( int u, int acum ){
	if ( u == n - 1 && acum == a[n-1] ) return;
	if ( u == n - 1) return;
	cout << a[ u - 1 ];
	if ( F(u + 1, acum - a[ u ] ) ){
		cout << '-';
		track( u + 1, acum - a[ u ]);
	}else if ( F( u + 1, acum + a[ u ] ) ){
		cout << '+';
		track( u + 1, acum + a[ u ] );
	
	}else if ( F( u + 1, acum * a[ u ] ) ){
		cout << '*';
		track( u + 1, acum * a[ u ] );

	}else if ( acum % a[ u ] == 0){
		if ( F( u + 1, acum / a[ u ] ) ){
			cout << '/';
			track( u + 1, acum / a[ u ] );
		}
	}

}

int main(){
	int runs;
	cin >> runs;
	while ( runs-- ){
		cin >> n;n++;
		for(int i = 0; i < n; i++ ) cin >> a[i];
		memset( dp, -1, sizeof dp);
		if ( F( 1, a[0] ) ){
			track( 1, a[0]);
			cout << a[n-2]<<"="<<a[n-1]<<endl;
		}else{
			cout << "NO EXPRESSION" << endl;
		}
	}
	return 0;
}
