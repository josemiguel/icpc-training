#include<cmath>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std ;

struct point{
	int x, y;
	point(){}
	point( int x, int y ):x(x),y(y){}
	bool operator < (const point &p )const{
		if ( x == p.x ) 
			return y < p.y;
		return x < p.x;
	}
	point operator -( point p ){
		return point( x - p.x , y - p.y );
	}
	int operator %( point p ){
		return x * p.y - y * p.x;
	}

};

typedef vector<point> poly;


int ccw( point a, point b, point c) {
	return ( c - a ) % ( b - a );
} 

poly convexHull( poly p ){
	sort( p.begin(), p.end() ) ;
	int k = 0;
	poly res( p.size() * 2);
	for( int i = 0; i < p.size(); i++){
		while( k >= 2 && ccw( res[k-2], res[k-1], p[i]) <= 0) k--;
		res[k++] = p[i];
	}
	int tmp = k + 1;
	for( int i = p.size() - 2 ; i >= 0; i-- ){
		while( k >= tmp && ccw( res[k-2], res[k-1], p[i]) <= 0) k--; 
		res[k++] = p[i];
	}
	res.resize( k );
	return res;
}

double area( poly p ){
	int res = 0;
	for(int i = 0; i < p.size() ; i++) {
		res += p[i] % p[(i+1)%p.size()];
	} 
	return fabs( res ) / 2;
}


int main(){

	int n,r=1;
	while( cin >> n && n ) {  
		poly p( n ); 
		for(int i = 0; i < n; i++){
			cin >> p[i].x >> p[i].y;	
		}
		p.push_back( p[ 0 ] );
		double tmp = area( convexHull( p ) );
		double res = 1 - area( p ) / tmp;
		printf("Tile #%d\nWasted Space = %.02lf %%\n\n", r++, res * 100 );
	}
	

	return 0;

}
