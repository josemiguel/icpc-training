#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std ;

struct point{
	double x, y;
	point(){}
	point( double x, double y ): x(x), y(y){}
	bool operator < ( const point &p )const{
		if ( x == p.x ){
		
			return y < p.y;
		}
		return x < p.x;
	}
	point operator -( point p){
		return point( x - p.x , y - p.y);
	}
	double operator %(point p){
		return x * p.y - y * p.x ;
	}
};

typedef vector< point > poly;
double ccw( point a, point b, point c ){
	return ( b -  a ) % ( c - a);
}

poly hull( poly p ){
	sort( p.begin(), p.end() );
	int n = p.size(), k = 0;
	poly h( 2 * n );
	for(int i = 0; i < n; i++){
		while( k >= 2 && ccw( h[k-2],h[k-1], p[i]) <= 0 ) k--;
		h[k++] = p[i];
	}
	int tmp = k + 1;
	for(int i = n - 2; i >= 0; i--){
		while( k >= tmp && ccw( h[k-2],h[k-1], p[i]) <= 0 ) k--;
		h[k++] = p[i];
	}
	h.resize( k );
	return h;

}
double dist( point a, point b){
	point p = b - a ;
	return hypot( p.x , p.y );
}
double mindist( point p, poly P ){
	double res =  1e10;
	for( int i = 0; i < P.size(); i++ ){
		res =min(res,  dist( p, P[i]) );
	}
	return res;
}

double len( poly p ){
	double res = 0;
	for(int i = 0; i < p.size() - 1; i++){
		res += dist( p[ i ] , p[ i + 1 ] );
	}
	return res;
}

int main(){
	int runs, r = 0;
	cin >> runs;

	while( runs-- ){
		if ( r ) cout << endl;
		r = 1;
		int n ;
		cin >> n;
		poly p( n );
		for(int i = 0; i < n; i++){
			cin >> p[i].x >> p[i].y;
		}
		poly h = hull( p ) ;
		double res = mindist( point(0,0), h ) * 2 + len( h ) ;
		printf("%.2lf\n", res );
	}

	return 0;
}
