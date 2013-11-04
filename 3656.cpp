#include<iostream>
using namespace std ;

int main(){
	int n;
	while( cin >> n && n ){
		int a[n],b[n];
		for( int i = 0; i < n; i++) cin >> a[i];
		for( int i = 0; i < n; i++) cin >> b[i];
		int acum = 0, i;
		for( i = 0; i < n; i++){
			acum += a[i] + b[i];
			if ( acum & 1 );
			else break;
		}
		cout << i << endl;

	}

	return 0;
}
