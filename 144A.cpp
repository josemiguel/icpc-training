#include<iostream>
#include<algorithm>
using namespace std ;

int main(){
	int N;
	cin >> N;
	int a[ N ];
	int mini = 0, maxi = 0;
	for( int i= 0; i < N; i++){
		cin >> a[ i ];
		if ( a[ i ] > a[ maxi ]) maxi = i;
		if ( a[ i ] <= a[ mini ]) mini = i;
	}
	maxi++, mini++;
	int res = N - mini;
	res += maxi - 1 ;
	if ( mini < maxi ) res--;
	cout << res << endl;

	

}
