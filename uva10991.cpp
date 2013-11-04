#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std ;

double ang( double a, double b, double c){
	double res = a*a + b*b - c*c;
	res /= (2*a*b);
	return acos( res );
}

double sec( double ang, double r ){
	return ang*r*r/2;
}


int main(){

	int runs;

	cin >> runs;
	while( runs--){
		double r1,r2,r3;
		cin >> r1 >> r2 >> r3;
		double a1 = ang( r1+r2, r1+r3, r2+r3);
		double a2 = ang( r1+r2, r2+r3, r1+r3);
		double a3 = ang( r1+r3, r2+r3, r1+r2);
		double S = sec( a1, r1 ) + sec( a2, r2 ) + sec( a3, r3 );

		double a = r1+r2;
		double b = r1+r3;
		double c = r2+r3;

		double p = a+b+c;
		p /= 2;

		double A = sqrt(p*(p-a)*(p-b)*(p-c));
		printf("%.6lf\n", A - S );
	
	}

	return 0;
}
