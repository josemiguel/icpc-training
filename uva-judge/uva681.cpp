#include<iostream>
#include<cstring>
#include<set>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std ;

struct point{
	int x,y, id;
	point(){}
	point( int x, int y ): x(x), y(y){}
	bool operator < ( const point &p) const{
		if ( y == p.y ) return x < p.x;
		return y < p.y;
	}
	point operator -( point p){
		return point( x - p.x, y - p.y );
	}
	int operator %( point p ){
		return x * p.y - y * p.x ;
	}
};
typedef vector<point> poly;
int ccw( point a, point b, point c ){
	return ( c - a ) % ( b - a );	
}

poly hull( poly p ){
	sort( p.begin(), p.end() );
	int k = 0;
	poly res( 2*p.size() ) ;
	int n = p.size();
	for(int i = 0; i < n; i++ ){
		while( k >= 2 && ccw( res[k-2], res[k-1], p[i])<=0) k--;
		res[k++] = p[i];
	}
	int tmp = k + 1;
	for(int i = n-2; i >= 0; i-- ){
		while( k >= tmp && ccw( res[k-2], res[k-1], p[i])<=0) k--;
		res[k++] = p[i];
	}
	
	res.resize( k );
	return res;
}

int cmp( point a, point b){
	return a.id < b.id;
}

int main(){

	int runs;
	cin >> runs;
	cout << runs << endl;
	while( runs-- ){
		int n, del; 
		cin >> n;
		poly p;
		set<point> S;
		point t;
		bool usd[600][600];
		memset( usd, 0, sizeof usd);
		for( int i = 0; i < n; i++){
			cin >> t.x >> t.y ;
	//		if ( usd[t.x][t.y] ) continue;
			usd[t.x][t.y] = true;
			t.id = i;
			p.push_back( t );
		}
		
		poly res = hull( p );
		
		reverse( res.begin(), res.end());

		cout << res.size() << endl;
		for(int i = 0; i < res.size(); i++){
			cout << res[i].x << " "  << res[i].y << endl;
		}
		if (cin >> del)	cout << del <<endl;
	}

	return 0;
}
