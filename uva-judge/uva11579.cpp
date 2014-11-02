#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;

double area(double a,double b,double c){
	double s = (a+b+c)/2;
	double ta = s*(s-a)*(s-b)*(s-c);
	if (ta <= 0) return 0;
	return sqrt(ta);
}
double a[10020];
int main(){
	int r;
	scanf("%d",&r);
	while(r--){
		int n;
		scanf("%d",&n);
		for(int i = 0; i < n;i++){
			scanf("%lf",&a[i]);
		}
		sort(a,a+n);
		double best = 0.0;
		for(int i = n-1; i >= 2; i--){
			best = max(best,area(a[i],a[i-1],a[i-2]));
		}
		printf("%.2lf\n",best);
	}
	return 0;
}

