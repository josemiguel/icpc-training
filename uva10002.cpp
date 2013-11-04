#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std ;

struct point{
	int x, y;
	point(){}
	point( int x, int y): x(x), y(y){}
	bool operator <( const point &p ) const{
		if ( x == p.x ){
			return y < p.y;
		}
		return x < p.x ;
	}
	int operator % ( point p ){
		return x * p.y - y * p.x;
	}
	point operator - ( point p ){
		return point( x - p.x , y - p.y );
	}
};

int ccw( point a, point b, point c){
	return ( b - a ) % ( c - a );
}

typedef vector<point> poly;

int main(){
	int n;
	while(  cin >> n && n >= 3 ){
		poly p( n );
		for(int i = 0; i < n; i++){
			cin >> p[i].x >> p[i].y;
		}
		sort( p.begin(), p.end() );
		poly hull( n * 2 );
		int k = 0;
		for(int i = 0; i < n; i++){
			while( k >= 2 && ccw( hull[k-2], hull[k-1], p[i]) <=0 ) k--;
			hull[ k++ ] = p[ i ] ;
		}
		int tmp = k + 1;
		for(int i = n - 2; i >= 0; i--){
			while( k >= tmp && ccw( hull[k-2], hull[k-1], p[i]) <=0 ) k--;
			hull[ k++ ] = p[ i ] ;
		}
		hull.resize( k );
		double area = 0.0, cx = 0, cy = 0;
		for(int i = 1; i < k; i++){
			double cross = hull[i] % hull[(i+1)%n];
			area += cross;
			cx += (hull[i].x + hull[(i+1)%n].x) * cross;
			cy += (hull[i].y + hull[(i+1)%n].y) * cross;
		}
		area *= 3;
		
		cx /= area; cy /= area;	
		printf("%.3lf %.3lf\n", cx, cy);
	}

	return 0;
}
