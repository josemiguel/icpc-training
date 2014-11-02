#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[20000];
int h[20000];
int w[20000];
#include<cstdio>
int n;
int F(){
	memset(dp,0,sizeof dp);
	int res = 0;
	for(int i = 0; i < n; i++){
		dp[i] = w[i];
		for(int j = 0; j < i; j++){
			if (h[i] < h[j]){
				if (dp[i] < dp[j] + w[i]) dp[i] = dp[j] + w[i];
			}
		}
		res = max(dp[i],res);
	}
	return res;
}

int main(){
	int runs;
	cin >> runs;
	for(int r = 1; r <= runs; r++){
		cin >> n;
		for(int i = 0; i < n; i++) cin >> h[i];
		for(int i = 0; i < n; i++) cin >> w[i];
		int lis = F();
		reverse(h,h+n);
		reverse(w,w+n);
		int lds = F();
		if ( lis <= lds){
			printf("Case %d. Increasing (%d). Decreasing (%d).\n",r,lds,lis);
		}else{
		
			printf("Case %d. Decreasing (%d). Increasing (%d).\n",r,lis,lds);
		}

	}
}
