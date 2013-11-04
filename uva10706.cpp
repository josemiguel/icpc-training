#include<iostream>
#include<cmath>
using namespace std;

long long dp[53010];
long long d[53010];
long long pot[12];
int ndig(int n){
	return (int)log10(n)+1;
}

int main(){
	pot[0] = 1;
	for(int i = 1; i <= 10; i++) pot[i] = pot[i-1]*10;
	dp[1] = 1; d[1] = 9;
	for(int i = 2; i <= 53000; i++){
		int dig = ndig(i);
		d[dig] = d[dig-1] + (i-pot[dig-1] +1)*dig;
		dp[i] = dp[i-1] + d[dig];
	}
	int r;
	cin>>r;
	while(r--){
		int n;
		cin>>n;
		int lo = 0, hi = 2*sqrt(n) + 1, i = 0;
		while(hi-lo != 1){
			int mid = (lo+hi)/2;
			if (dp[mid] < n) lo = mid;
			else hi = mid;
		}
		int k;
		for(int i = 0, j = 1; ;j++){
			int ii = j;
			int dig = ndig(j);
			while(dig--){
				k = ii / pot[dig];
				ii = ii % pot[dig];
				i++;
				if (i == n-dp[lo]) goto sale;
			}
		}
		sale: cout<<k<<endl;
	}	
	
	return 0;
}

