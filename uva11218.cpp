#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
#define MAX 1LL<<55
typedef long long Int;

Int dp[1<<12];
int a[105][4],n;

Int F(int mask){
	if (mask == (1<<9)-1) return 0; 
	if (dp[mask] != -1) return dp[mask];
	Int res = 0;
	for(int i = 0; i < n; i++){
		Int S = a[i][3];	
		bool puede = true;
		int nmask = mask;
		for(int j = 0; j < 3; j++){
			int k = a[i][j]-1;
			nmask |= (1<<k);
			if (mask&(1<<k)) puede = false;
		}
		if (puede){
			res = max( res , S + F(nmask) );
		}
	}
	if (res == 0) return -MAX;
	return dp[mask] = res;
}

int main(){

	int r = 1;
	while(scanf("%d",&n) && n){
		memset(dp,-1,sizeof dp);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 4; j++){
				cin>>a[i][j];
			}
		}
		
		
		Int res = F(0);
		printf("Case %d: %lld\n",r++,res < 0 ? -1 : res);
	}
	return 0;
}
