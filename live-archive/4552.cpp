#include<iostream>
#include<algorithm>
using namespace std ;

int main(){

	int T;
	cin >> T;
	while( T--){
		int r;
		cin >> r;
		int a[10];
		for( int i = 0; i < 10 ; i++){
			cin >> a[i];
		}
		sort( a,a+10);

		cout << r << " " << a[7] << endl;
	}

	return 0;
}
