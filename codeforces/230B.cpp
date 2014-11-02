#include<iostream>
#include<cmath>
using namespace std ;
typedef long long Int;

bool primo( Int x ){
	if ( x <= 2 ) return true;
	for( Int i = 2; i*i <= x; i++){
		if ( x % i == 0 ) return false;
	}
	return true;
}

int main(){

	int n;
	cin >> n;
	while( n-- ){
		Int x;
		cin >> x;
		if ( x == 1 ) {
			cout << "NO" << endl;
			continue;
		}
		Int sq = sqrt( x );

		if ( sq * sq != x ) cout << "NO" << endl;
		else{
			if ( !primo(sq) ) cout << "NO" << endl;
			else cout << "YES" << endl;

		}

	}

	return 0;
}
