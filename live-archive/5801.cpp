#include<iostream>
#include<cstring>

using namespace std ;

int R[50000][2];

int F( int n , int m ){
	if ( m == 0 || n == m ) return 1;
	int p1 = F( n - 1, m - 1);
	int p2 = F( n - 1, m );
	int p3 = F( n - 2, m - 1);
	return (p1*p2 + 1 ) / p3;
}

int main(){


	return 0;
}
