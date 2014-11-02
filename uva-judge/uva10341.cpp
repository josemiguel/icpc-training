#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int p,q,r,s,t,u;
 
double F(double x){
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}
bool P(double l, double u){
	return F(l)*F(u) <= 0;
}

int main(){
	while(cin>>p>>q>>r>>s>>t>>u){
		if (!P(0,1)) { puts("No solution"); continue; }
		double lo = 0, hi = 1.0;
		while (hi-lo >= 10e-8){
			double mid = (hi+lo)/2.0;
			if (P(lo,mid)) hi = mid;
			else lo = mid;
		}
		printf("%.4lf\n",(hi+lo)/2);
	}
	return 0;
}

