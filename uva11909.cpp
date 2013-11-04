#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const double pi = 2*acos(0);
int main(){
	int l,w,h,a;
	while(scanf("%d%d%d%d",&l,&w,&h,&a)!=-1){
		double T = tan((a*pi)/180.00);
		double x = l*l*T;
		x /= 2.0;
		if ( l*T <= h )
			printf("%.3lf mL\n",(double)w*h*l - x * w);
		else{
			x = h*h;
			x /= T;
			x /= 2;

			printf("%.3lf mL\n",  w*x );
		}
	}
	return 0;
}
