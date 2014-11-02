#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std ;
typedef long long Int;
int main(){
	int k; string b;
	cin >> k >> b ;
	b = '$' + b;
	int n = b.size();
	vector<int> uno;
	for( int i = 0;  i < n; i++) if ( b[i] == '1' ) uno.push_back( i );
	uno.push_back( n );
	Int sum = 0;
	if ( k == 0 ){
		k = 1;
	}
	int ant = 1;
	for( int i = k - 1, j = 0 ; i < uno.size() - 1; i++, j++){
		Int izq = uno[ j ] - ant;
		Int der =  uno[ i + 1 ] - uno[ i ] - 1;
		sum += izq + der + izq*der + 1;
		ant = uno[ j ] + 1;
	}
	cout << sum << endl;



}
