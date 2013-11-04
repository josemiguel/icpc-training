#include<iostream>
#include<algorithm>
using namespace std ;
typedef long long Int;
int main(){

	Int S;
	Int pot[35];
	pot[0] = 1LL;
	for( int i = 1; i < 35; i++) pot[ i ] = 2LL * pot[ i - 1 ];
	while( cin >> S ){
		if ( S <= 1 ){
			cout << S << endl;
			continue;
		} 


		int res = 1;

		while( S % 2 == 0 ) S /= 2, res++;
		if ( S == 1 ){
			cout << res << endl;
			continue;
		}
		int idx ;
		for( idx = 0; pot[idx] < S; idx++);
		int b = idx, a = idx - 1;
		

		if ( pot[ b ] - S < S - pot[ a ] ) idx = b;
		else idx = a;

		res +=  idx + min( pot[ b ] - S , S - pot[ a ] );

		cout << res << endl;
		
	
	}
	return 0;
}
