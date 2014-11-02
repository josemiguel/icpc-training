#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int a[10];
int n = 5;

bool poda;


bool F( int u, int T){
	
	if( u == n ) {
		return T == 23;
	}
	bool res = false;
	res |= F(u + 1,  T + a[u]);
	if ( res ) return true;
	res |= F(u + 1,  T - a[u]);
	if ( res ) return true;
	res |= F(u + 1,  T * a[u]);
	
	if ( res ) return true;

	return res;
}

int main(){
	while( 1 ) {
		int b = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			b |= a[i];
		}
		if ( !b ) break;
		
		


		sort( a, a + n );
		bool puede = false;
		do{
			puede  = F( 1, a[ 0 ] );
			if ( puede  ) break;
		}while( next_permutation( a , a + n ));
		if ( puede ){
			cout << "Possible" << endl;
		}else{
			cout << "Impossible" << endl;
		}
	
	}

	return 0;
}
