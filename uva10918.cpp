#include<iostream>
using namespace std ;
int main(){

	int n;
	while( cin >> n && n!=-1){
		int r = 0;
		while( n ){
			n /=2;
			r+=3;
			if ( n == 1) break;
		}
		cout << n + r << endl;
	}

	return 0;
}
