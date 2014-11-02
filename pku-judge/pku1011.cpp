#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std ;
int a[70], usd[70];
int n, org;
bool done;
void back( int pos,int todos, int tar){
	if ( done ) return;
	if ( todos != n && tar == 0 ) {
		back( -1, todos , org );
		return;
	}
	if ( todos == n && tar == 0 ) done = true;
	if ( done ) return;
	if ( todos >= n ) return;
	for( int i = pos + 1 ; i < n; i++){
		if ( usd[i] ) continue;
		if ( tar - a[i] < 0 ) break;
		usd[i] = true;
		todos++;
		back( i, todos , tar - a[i] );
		if ( done ) return;
		todos--;
		usd[i] = false;
	}
}

int main(){

	while (cin >> n && n ){
		int sum = 0;
		for( int i = 0; i < n; i++) cin >> a[i], sum +=a[i];
		sort( a, a + n );	
		for( int i = sum/2 ; i >= 2; i--){
			if ( sum % i ) continue;
			done = false;
			org = sum / i;
			memset( usd, 0,sizeof usd);
			back( -1,0, org );
			if ( done ) {
				cout << org << endl;
				break;
			}
		}
	}
	

	return 0;
}


