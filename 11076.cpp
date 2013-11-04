#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){

	int n;
	long long f[20];
	f[0] = 1;
	for(int i = 1; i <= 18; i++){
		f[i] = i*f[i-1];
	}
	while(scanf("%d",&n) && n){

		long long a[n];
		for(int i = 0; i < n; i++){
			scanf("%lld",&a[i]);
		}

		long long res = 0;
		for(int i = 0; i < n; i++){
			long long tmp = 0;
			for(int j = 0; j < n; j++){
				tmp = tmp*10 + a[i];
			}
			res += tmp ;
		}
		
		cout << res * f[n-1] << endl;

	}
	
	

	return 0;
}
