#include<iostream>
#include<cstring>
using namespace std ;

int bit[32010], p[15001], n;

int get( int x ) {
	int res = 0;
	while( x ) res += bit[x], x -= x&-x;
	return res;
}

void update( int x, int v ){
	while( x < 32010 ) bit[x] += v , x += x&-x;
}

int main(){
	cin >> n;
	memset( p , 0, sizeof p );
	for( int i = 0; i < n; i++){
		int x,y;
		cin >> x >> y;
		p[ get(++x) ]++;
		update( x , 1 );
	}
	for( int i = 0; i < n; i++){
		cout << p[i] << endl;
	}
}
