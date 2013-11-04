#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int N;
double p[15002],x[15002];

double f( double v ){
	double sum = 0;
	for(int i = 0; i < N; i++){
		sum += fabs( x[ i ] - v );
	}
	return -sum;
}

double F(double lo, double hi){
	if ( (fabs( hi - lo ) < 1e-7)){
		return (lo + hi) / 2;
	}
	double l = (2 * lo + hi) / 3.0;
	double r = (lo + 2 * hi) / 3.0;

	if ( f( l ) < f ( r ) )
		return F(l, hi);
	else
		return(lo, r);

}

int main(){


	cin >> N;
	double hi = -100;
	for(int i = 0; i < N; i++){
		cin >> p[ i ] >> x[ i ];
		hi = max( hi , x[ i ]);
	}
	printf("%.5lf\n", F( 0, hi  ) );
	return 0;
}
