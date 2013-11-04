#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std ;
const double pi = 2*acos( 0 );
int main(){
	int a,b,m,n,s;
	while( cin >> a >> b >>s >> m >> n && a+b+m+n+s){
		double B = b * n;
		double A = a * m;
		double ang = atan2( B , A);

		double ve = sqrt(B*B + A*A) / s;
		printf("%.2lf %.2lf\n", 180* ang / pi, ve );
	
	}

	return 0;
}
