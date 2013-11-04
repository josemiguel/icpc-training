#include<iostream>
#include<algorithm>
using namespace std ;

int main(){

	int runs;
	cin >> runs;
	for( int r = 1; r <= runs; r++){
		int a, b;
		cin >> a >> b;
		int p2= __gcd( a, b);
		int p1 = (a*b)/ p2;
		cout << r << " "<<p1<<" " << p2 << endl;
	}

	return 0;
}
