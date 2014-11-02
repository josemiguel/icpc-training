#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int a[60];
int main(){
	int n;
	while(cin>>n && n){
	
		for(int i = 0; i < n; i++) cin>>a[i];
		int k = 0, t = 0;
		for(int i = 0; i < n-1; i++) 
			for(int j = i+1; j < n; j++){
				if (__gcd(a[i],a[j]) == 1) k++;
				t++;
			}
		
		double res = sqrt((6*t) / (double)k);
		if (k > 0) printf("%.6lf\n",res);
		else printf("No estimate for this data set.\n");
	}
	return 0;
}
