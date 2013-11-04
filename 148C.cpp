#include<iostream>
using namespace std ;

int main(){

	int n,a,b;

	cin >> n >> a >> b;
	if ( n == 1 && !a && !b ){
		cout << 1 << endl;
		return 0;
	}
	if (!( b >= 0 && a < n-1 )){
		cout << -1 << endl;
		return 0;
	}
	int v[n+1];	
	int k = 0;
	
	for(int i = 0; i <= b; i++){
		v[k++] = 1 << i;
	}
	if ( b == 0 ) v[ k++ ] = 1;
	for(int i = 1; i <= a; i++){
		v[k++] = (1<<b)+(i);
	}
	
	int c = n-k;
	if ( n -k < 0 ){
		cout << -1 <<endl;
		return 0;
	}
	while( c-- ){
		v[k++] =  (1<<b)+(a) ;
	}
	
	for(int i = 0; i < k ; i++) cout << v[i] << " ";
	cout << endl;


	return 0;
}
