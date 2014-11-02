#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int dp[1005];
int usd[35][1005], N[1005];
int p[35],b[35],r[35],n;


int main(){
	int T,w,rr = 1;
	
	while(cin>>T>>w){
		if (rr != 1) cout<<endl;
		rr++;
	
		memset(dp,0,sizeof dp);
		memset(usd,0,sizeof usd);
		memset(N,0,sizeof N);
		cin>>n;
		for(int i = 1; i <= n; i++){
			cin>>r[i]>>b[i];
			p[i] = r[i]*3*w;
		}
		int res = 0;
		for(int i = n; i >= 1; i--){
			for(int j = T; j >= p[i]; j--){
				if ( dp[j-p[i]] + b[i] > dp[j] ) {
					usd[i][j] = true;
					dp[j] =  dp[j-p[i]]+b[i];
					N[j] = N[j-p[i]] + 1;
				}
				
			}
		}
		cout<<dp[T]<<endl<<N[T]<<endl;
		for(int i = 1, j = T; i <= n; i++)	if (usd[i][j])	{	
			cout<<r[i]<<" "<<b[i]<<endl;
			j -= p[i];
		}
	}
	return 0;
}

