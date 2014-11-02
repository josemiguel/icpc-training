#include<iostream>
#include<cstring>
using namespace std ;
#define MOD 1000000007LL

int main(){
	int n ;
	cin >> n;
	long long A=0,B=0,C=0,D=1,a,b,c,d;
	for( int i = 0; i < n; i++) {
		a = B + C + D;
		b = A + C + D;
		c = A + B + D;
		d = A + B + C;
		A = a % MOD;
		B = b % MOD;
		C = c % MOD;
		D = d % MOD;
	}
	cout << D << endl;
	return 0;
}
