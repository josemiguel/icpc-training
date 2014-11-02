#include<iostream>
using namespace std ;

int main(){

	int runs;
	cin >> runs;
	for( int r = 1; r <= runs;r++){
		long long prevn, res = 0, n;
		cin >> n;
		for( int i = 2; n ; i++){
			prevn = n;
			n/=i;
			cout << prevn << " " << n << endl;
			res += (i-1) * (prevn - n );
			n--;
		}
		
		cout << res << endl;
	}

	return 0;
}
