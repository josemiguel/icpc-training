#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std ;

typedef pair<int,pair<int,int> > tre;
tree mp( int a, int b, int c){
	return make_pair(a,make_pair( c, b ) );
}
int main(){
	vector<tree> a;
	while( cin >> a >> b >> c ){
		a.push_back( tree( a, b , c) );
	}
	sort( a.begin(), a.end() );
	int i = 0, j = 0;
	while( i < n ){
		if ( intersect ( a[ i ] , a[ j ] ) ) {
			v[ p ].push_back ( a[ j ]);
			j++;
		}
		else {
			i = j + 1;
			if ( !insersect( a[ i ] , a[ j ] ) ){
				p++;
			}
		}
	}
	

	return 0;
}
