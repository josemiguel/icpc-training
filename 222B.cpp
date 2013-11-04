#include<iostream>
using namespace std;

int g[ 1005 ][ 1005 ];
int r[ 1005 ];
int c[ 1005 ];

int main(){
	
	int n , m , q;
	cin >> n >> m >> q;

	for( int i = 0; i < n; i++){
		r[i] = i;
		for( int j = 0; j < m; j++){
			c[j] = j;
			cin >> g[i][j];;
		}
	}
	
	while( q-- ){
		char k; int i , j;
		cin >> k >> i >> j;
		i--,j--;
		if ( k == 'g' ) cout << g[ r[i] ][ c[j] ] << endl;
		else if ( k == 'c' ) swap( c[i], c[j] );
		else if ( k == 'r' ) swap( r[i], r[j] );
	}

	return 0;
}
