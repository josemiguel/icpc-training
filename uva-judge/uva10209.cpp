#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

double const pi = acos(-1);

int main(){
	double l;
	while(scanf("%lf",&l)!=-1){
		double A = (l*l*pi - 2*l*l)/4;
		double C = (4*l*l - l*l*pi - 4*A)/8;
		double B = l*l - 4;
		printf("%.3lf %.3lf %.3lf\n",4*A,B,4*C);
	}
}
