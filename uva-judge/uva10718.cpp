#include<iostream>
using namespace std ;

int bits(int n){
	for(int i = 31; i >= 0; i--){
		if ( n & ( 1 << i ) ) return i;
	}
	return 0;
}

int main(){

	int N,L,U;
	while( cin >> N >> L >> U ){

		int sz = bits(N);
		int M = 0;

		for(int i = 0; i < sz; i++){
			if (!( N & ( 1 << i) ) ){
				M |= (1 << i );
			}
		}
		cout << M << endl;
		while( M < L ){
			if ( M >= L && M <= U) break;
			M *= (1<<sz++);
			
		}
		cout << M << endl;
	}

	return 0;
}
