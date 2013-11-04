#include<iostream>
using namespace std ;
int res[ 105 ], n,l , d;
int f( int p, int k ){
	int acum = 0, cur = p ? l : 1;

	for( int i = n-1; i >= 1; i--){
		if ( i < k ){
			if ( p ) cur = l;
			else cur = 1;
		}
		p = 1 - p;
		acum = cur - acum ;
		res[ i ] = cur; 
	}
	for( int i = 1; i <= l ; i++ ){
		if ( i - acum == d ) {
			res[ 0 ] = i ;
			return true;
		}
	}
	return false;
}

int main(){

	cin >> n >> d >> l;

	for( int i = 0; i < n ; i++ ){

		if ( f( 0, i ) || f( 1, i ) ){
			for( int i = 0; i < n; i++ ) cout << res[i] <<" ";
			cout << endl;
			return 0;
		}
	}	
	cout << -1 << endl;


	return 0;
}
