#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std ;

struct point{
	double x, y; 
	point(){}
	point( double x, double y ) :x(x),y(y){}
	point operator -( point p ){
		return point(x - p.x , y - p.y );
	}
	double operator *( point p ){
		return x * p.x + y * p.y ;
	}
};


int cmp( double a, double b = 0){
	if ( fabs( a - b ) < 1e-6 ) return 0;
	if ( a < b + 1e-6 ) return -1;
	return 1;
}

double ccw( point a, point b, point c ){
	point p1 = b - a;
	point p2 = c - a;
	return (p1.x * p2.y - p1.y * p2.x) ;
}

bool co( point p, point a, point b ){
	point A = a - p;
	point B = b - p;

	if ( cmp(ccw( p, A, B)) == 0 ){
		if ( cmp( A * B ) < 0 ) return true;
	}
	return false;
	
}
double xmin, xmax, ymin, ymax;
bool in( point p, point t[] ){

	double sum = 0.0;
	for(int i = 0; i < 3; i++ ) sum += fabs( ccw( p, t[i], t[(i+1)%3] ) );
	if ( cmp(sum, fabs(ccw(t[0],t[1],t[2])) ) == 0 ) {
		if ( cmp( sum ) != 0 ) return true;
		if ( p.x >= xmin && p.x<=xmax  && p.y >= ymin && p.y <= ymax) {
			return true;	
		}
	
	}
	return false;
}

int main(){

	while( true ){
		point t[3];
		double sum = 0;
		xmax = ymax = 0.00;
		xmin = ymin = 150.0;
		for(int i = 0; i < 3; i++) {
			scanf( "%lf %lf", &t[i].x, &t[i].y);
			xmin = min(xmin, t[i].x);
			ymin = min(ymin, t[i].y);
			
			xmax = max(xmax, t[i].x);
			ymax = max(ymax, t[i].y);

			sum += t[i].x + t[i].y;
		}
		if ( cmp( sum ) == 0 ) break;
		int res = 0;
		for( int i = 1; i < 100; i++){
			for(int j = 1; j < 100; j++){
				point p( i , j);
				if ( in( p, t ) ) res++;
			}
		}
		printf("%4d\n", res );
	}

	return 0;
	
}
