#include<iostream>
using namespace std ;

int main(){

	int d,n ;
	cin >> d >> n;
	int cur = 0, res= 0 ;
	int prev = 0;
	for( int i = 0; i < n - 1; i++) {
		int t;
		cin >> t;
		res += d - t;
	}
	cout << res << endl;

	return 0 ;
}
