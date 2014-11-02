#include<iostream>
using namespace std;
typedef long long Int;
Int x;

void f( int r, int d ){

	if ( x == r ){
		Int acc = 0;
		while( d ) acc += d, d /= 2;
		cout << x - acc <<" " << x + acc << endl;
		return ;
	}
	if ( x > r )    f( r + d, d / 2 );
	else 			f( r - d, d / 2 );
}

int main(){

	int runs;
	cin >> runs;
	while( runs-- ){
		cin >> x;
		if ( x & 1 ){
			cout << x << " " << x << endl;
			continue;
		}

		Int pot = 1;
		while( pot * 2 <= x ) pot *= 2;
		f( pot, pot / 2 );

	}

	return 0;
}
