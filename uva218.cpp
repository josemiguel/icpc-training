#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std ;

struct point{
	double x, y;
	point() {}
	point( double x, double y ): x(x), y(y){}
	bool operator < (const point &p ) const{
		if (x == p.x ){
			return y < p.y;
		} 
		return x < p.x;
	}
	double operator % ( point p){
		return x * p.y - y * p.x;
	}
	point operator - ( point p ){
		return point( x - p.x, y - p.y );
	}

};
typedef vector<point> poly;

double dist( point a, point b ){
	return hypot( a.x - b.x , a.y - b.y );
}

double ccw( point a, point b, point c ){
	return ( b - a ) % ( c - a );
}

poly hull( poly p ){
	int k = 0; 
	poly res( p.size() * 2 );
	sort( p.begin(), p.end());
	int n = p.size();
	for(int i = 0; i < n; i++){
		while( k >= 2 && ccw( res[k-2], res[k-1] ,p[i] ) <= 0) k--;
		res[k++] = p[i];
	}
	int tmp = k + 1;
	for(int i = n - 2 ; i >= 0; i--){
		while( k >= tmp && ccw( res[k-2], res[k-1] ,p[i] ) <= 0) k--;
		res[k++] = p[i];
	}
	res.resize( k );
	return res;
}

int main(){
	int n, r = 1;
	while( cin >> n ){
		if ( r != 1 ) cout << endl;
		poly p( n );
		for(int i = 0; i < n; i++){
			cin >> p[i].x >> p[i].y;
		}
		poly res = hull( p );
		reverse( res.begin(), res.end() );	
		double len = 0.0;

		printf("Region #%d:\n", r++);
		for( int i = 0; i < res.size(); i++) {
			if ( i ){
				len += dist( res[i-1], res[i] );
				putchar('-');	
			}
			printf("(%.1lf,%.1lf)", res[i].x, res[i].y);
		}
		printf("\nPerimeter length = %.2lf\n", len );

	}

	return 0;
}
