#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int dp[100005][2];
int row[100005];
int main(){

	int n,m;
	while(scanf("%d %d",&n,&m) && n+m){
		for(int j = 0; j < n; j++){
			int a;scanf("%d",&a);
			dp[0][1] = a;
			dp[0][0] = 0;
			for(int i = 1; i < m; i++){
				scanf("%d",&a);
				dp[i][1] = max(dp[i-1][1],a + dp[i-1][0]);
				dp[i][0] = max(dp[i-1][1],dp[i-1][0]);
			}
			
			row[j] = max(dp[m-1][1],dp[m-1][0]);
		}
		dp[0][1] = row[0];
		dp[0][0] = 0;
		int best = 0;
		for(int i = 1; i < n; i++){
			dp[i][1] = max(dp[i-1][1],row[i] + dp[i-1][0]);
			dp[i][0] = max(dp[i-1][1],dp[i-1][0]);
		}
		best = max(dp[n-1][1],dp[n-1][0]);
		printf("%d\n",best);
	
	}

	return 0;
}
