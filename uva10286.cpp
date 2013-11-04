#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std ;
const double pi = 2*acos(0);
int main(){
	double d;
	while ( cin >> d ){
		double sin108 = sin( 108*(pi)/180);
		double sin63 = sin( 63*pi/180);

		printf("%.10lf\n",d*sin108/sin63);

	}

	return 0;
}
