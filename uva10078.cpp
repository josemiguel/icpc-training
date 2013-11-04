#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

struct point{
	double x, y;
	point(){}
	point( double x, double y ): x(x), y(y){}
	point operator - (point p ){
		return point( x - p.x, y - p.y );
	}
	double operator *( point p ){
		return x * p.x + y * p.y;
	}
	double operator %( point p ){
		return x * p.y - y * p.x ;
	}
};

double ccw( point a, point b, point c ){
	return ( b - a ) % ( c - a );
}


bool convexo( point t[], int n ){
	for(int i = 0; i < n; i++){
		double a1 = ccw( t[ i ], t[ (i + 1) % n ], t[ (i + 2) % n ] );
		double a2 = ccw( t[ (i + 1) % n ], t[ (i + 2) % n ], t[ (i + 3) % n] );
		if ( a1 * a2 < 1e-7 ) return false;
	}
	return true;
}

int main(){

	int n;
	while( cin >> n && n ){
		point t[n];
		for(int i = 0; i < n ; i++) cin >> t[i].x >> t[i].y;
	
		if ( !convexo( t , n ) ){
			cout << "Yes"  << endl;
		}else{
			cout << "No"  << endl;
		}
	}

	return 0;
}
