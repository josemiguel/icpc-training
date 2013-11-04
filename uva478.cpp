#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std ;

struct point{
	double x, y;
	point(){}
	point( double x, double y ): x(x), y(y){}
	point operator - ( point p ){
		return point( x - p.x , y - p.y );
	}
	double operator * ( point p ){
		return x*p.x + y*p.y;
	}
	double operator % ( point p ){
		return x * p.y - y * p.x;
	}
	double dist( point p ){
		return hypot( x - p.x , y - p.y );
	}
};

struct poly{
	point a[4];
	int n;
	double r;
	bool circ;
	poly(){ circ = false;}
};

double ccw( point a, point b, point c ){
	return  ( b - a ) % ( c - a );
}

bool in( point p , poly po ){
	if ( po.circ ){
		if ( po.a[0].dist( p ) <= po.r ) return true;	
		return false;
	}else{
		int cross = 0;
		for( int i = 1; i <= po.n; i++){
			point q = po.a[ i - 1 ];
			point r = po.a[ i % po.n ];
			if ( abs(ccw( p, q, r ))  < 1e-10) {
				return false;
			}
			if ( q.y > r.y ) swap( q, r );
			if ( q.y < p.y && r.y >= p.y && ccw( p, q, r ) > 0 ) cross++;
		}
		return cross % 2;
	}
}

int main(){
	poly ps[ 12 ]; int n = 0 ;
	char c;
	while( cin >> c && c != '*'){
		if ( c == 'c' ) {
			cin >> ps[ n ].a[0].x >> ps[ n ].a[0].y;
			cin >> ps[ n ].r;
			ps[n].circ = true;
		}else if ( c == 'r'){
			point ul, lr;
			cin >> ul.x >> ul.y;
			cin >> lr.x >> lr.y;
			if ( ul.x < lr.x ) swap( ul, lr );
			ps[ n ].a[0] = ul;
			ps[ n ].a[1] = point( lr.x , ul.y);
			ps[ n ].a[2] = lr;
			ps[ n ].a[3] = point( ul.x , lr.y);
			ps[ n ].n = 4;

		}else {
			ps[ n ].n = 3;
			for(int i = 0; i < 3; i++){
				cin >> ps[ n ].a[i].x;
				cin >> ps[ n ].a[i].y;
			}
		}
		n++;	
	}
	point p;
	int idx = 1;
	while( cin >> p.x >> p.y ) {
		if ( p.x == 9999.9 && p.y == 9999.9) break;
		bool any = true;
		for(int i = 0; i < n ; i++){
			if ( in( p, ps[ i ] ) ){
				any = false;
				printf("Point %d is contained in figure %d\n", idx, i+1);
			}
		}
		if ( any ){
			printf("Point %d is not contained in any figure\n", idx );
		}
		idx++;
	}


	return 0;
}
