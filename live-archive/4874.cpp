#include<iostream>
using namespace std ;

int f( int b, int x, int y ){
	int res = 0;
	int fact = 1;
	while( x || y ){
		int d1 = x % b ;
		int d2 = y % b ;
		x /= b;
		y /= b;
		res += fact *  ((d1 + d2) % b);
		fact *= b;
	}
	return res;
}


int main(){
	int T;
	cin >> T;
	while(T--){
		int r, b, x, y;
		cin >> r >> b >> x >> y ;
		cout << r << " "<< f( b,x,y) << endl;
	}
	return 0;
}
