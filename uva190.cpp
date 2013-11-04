#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std ;

int main(){
	double x1,y1,x2,y2,x3,y3;
	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >>y3){

		if ( x1 == x2 ){
			swap( x1, x3 );
			swap( y1, y3 );
		}

		double c1 = x1*x1 + y1*y1 - x2*x2 - y2*y2;
		c1 /= 2;
		double c2 = x1*x1 + y1*y1 - x3*x3 - y3*y3;
		c2 /= 2;


		double k = c1*(x1-x3) - c2*(x1-x2);
		k /= ( (y1-y2)*(x1-x3)-(y1-y3)*(x1-x2) );

		double h = c1 - k*( y1 - y2) ;
		h /= (x1-x2);

		double r = hypot( (h-x1) , (k-y1) );

		char cx = '-', cy = '-', cc = '+';

		if ( h < 0 ) cx = '+'; 
		if ( k < 0 ) cy = '+'; 

		printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n", cx,fabs(h), cy, fabs(k), r);

		
		double x,y,c;
		cx = '+', cy = '+';
		x = 2 * h; y = 2 * k;
		if ( x > 0 ) cx = '-';
		if ( y > 0 ) cy = '-';

		c = h*h + k*k - r*r;
		if ( c < 0 ) cc = '-';
		printf("x^2 + y^2");

		if ( x != 0 ) printf(" %c %.3lfx", cx, fabs(x) );
		if ( y != 0 ) printf(" %c %.3lfy", cy, fabs(y) );
		if ( c != 0 ) printf(" %c %.3lf", cc, fabs(c) );
		printf(" = 0\n");
		putchar(10);	
		
	}

	return 0;
}
