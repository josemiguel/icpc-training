#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double cx,cy;
double eps = 1e-9;
int cmp( double a, double b = 0 ){
	return a + eps < b ? -1 : a - eps > b ? 1 : 0;
}
double dist( double x, double y, double xx, double yy ){
	return sqrt( (x-xx)*(x-xx) + (y-yy)*(y-yy) );
}
bool incirc( double x, double y ){
	return cmp( dist( x,y , cx,cy ), 2.5 ) <= 0;
}
double x[505],y[505];
int solve(int n){
	int res = 1;
	for( int i = 0; i < n; i++ ){
		for( int j = 0; j < n; j++ ){
			if ( i == j ) continue;
			double d = dist( x[i] , y[i], x[j], y[j] ), t;
			if (cmp( d , 5) <= 0 ){
				double vx = (x[i]-x[j]) / d;
				double vy = (y[i]-y[j]) / d;
				
				t = sqrt(6.25 - d*d/4);

				cx = (x[i]+x[j])*0.5 + t * -vy;
				cy = (y[i]+y[j])*0.5 + t * vx;

				int tmp = 0;
				for( int k = 0; k < n; k++){
					tmp += incirc( x[k],y[k] );
				}
				res = max( res, tmp );
			}
		}
	}
	return res;
}


int main(){
	int n = 0;
	while( scanf("%lf %lf",&x[n],&y[n]) != -1 ) n++ ;
	printf("%d\n", solve( n ) );
	return 0;
}
