#include<iostream>
using namespace std ;
int main(){

	int n,t , res = 0;
	cin >> n;
	for( int i = 0;i < n; i++){
		int r = 0;
		for( int j = 0; j < 3; j++){
			cin >> t;
			r += t;
		}
		if ( r >= 2) res++;
	}
	cout << res << endl;

	return 0;
}
