#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std ;
const double pi = acos(-1.0);
double x[105],y[105];
int main(){
	int n;
	double r;
	cin >> n >> r;
	for( int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}
	double res = 0;
	for( int i = 0; i < n; i++){
		res += hypot( x[i] - x[(i+1)%n] , y[i] - y[(i+1)%n]);
	}
	
	res += 2*pi*r;
	printf("%.2lf\n",res);


	return 0;
}
