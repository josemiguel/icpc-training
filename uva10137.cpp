#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
double a[1005];
int main(){
	int n;
	while(cin>>n && n){
		double s = 0.0;
		for(int i = 0; i < n; i++) cin>>a[i], s+=a[i];
		s /= n;
		double x = 0, y = 0;
		for(int i = 0; i < n; i++){ 
			double tmp = (double)(int)((a[i]-s)*100)/100;
			if (tmp < 0) y += tmp;
			else x += tmp;
		}
		printf("$%.2lf\n",max(x,-y));
	}
	return 0;
}
