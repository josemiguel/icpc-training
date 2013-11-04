#include<iostream>
using namespace std ;
#define MAX 10000000
#define K 2000000
bool p[MAX];

int main(){

	p[0] = p[1] = 1;
	for( int i = 2; i * i < MAX ; i++){
		if ( p[i] ) continue;
		for( int j = i + i ; j < MAX ; j += i ){
			p[j] = 1;
		}
	}
	long long res = 0;
	for( int i = 2; i < MAX; i++){
		if ( p[i] ) continue;
		if ( i > K ) break;
		res += i;
	}
	cout << res << endl;

	return 0;
}
