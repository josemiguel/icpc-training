#include<iostream>
#include<vector>
#include<cstring>
#include<map>
using namespace std ;

int C( int n , int k ){
	if ( k == 0 ) return n;
	int fn = 1, fk = 1, fnk = 1;
	for( int i = 1; i <= n; i++) fn *= i;
	for( int i = 1; i <= k; i++) fk *= i;
	for( int i = 1; i <= ( n - k ) ; i++) fnk *= i;
	return fn/ (fnk*fk);
}
int a[10], pot[10];
int main(){
	pot[0] = 1;
	for( int i = 1; i < 10; i++) pot[i] = 10*pot[i-1];
	int T;
	cin >> T;
	while( T-- ){
		for ( int i = 1; i <= 9; i++) cin >> a[i];
		int res = 0;
		for ( int i = 1; i <= 9; i++){
			if ( a[i] == 0 ) continue;
			int sum = 0;
			for( int j = 1; j <= 9; j++){
				if ( i == j ) sum += a[i] - 1;
				else sum += a[j];
			}
			
			for( int j = 0; j <= sum ; j++ ){
				res += ( pot[j] * i ) * ( C(sum, j ) ) 
			}	
			
		}
		cout << res << endl;

	
	}

	return 0;
}
