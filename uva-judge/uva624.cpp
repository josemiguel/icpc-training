#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int dp[25][6005];
int a[25];
int pai[6005];

void tree(int v){
    if(v > 0){
        tree(pai[v]);
        if(v > pai[v])
            printf("%d ", v - pai[v]);
    }
}

int main(){
	int n,M;
	while(scanf("%d%d",&M,&n) != -1){
		for(int i = 1; i <= n ; i++) scanf("%d",&a[i]);
		int top = 0;
		memset(dp,0,sizeof(dp));
		for(int i = 1; i <= n ; i++){
			for(int j = 1; j <= M; j++){
				if(dp[i-1][j] < dp[i][j-1]) pai[j] = pai[j-1];
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				if (a[i] <= j){
					if (dp[i][j] < a[i] + dp[i-1][j-a[i]]) 	pai[j] = j - a[i];
					dp[i][j] = max(dp[i][j],a[i] + dp[i-1][j-a[i]]);
				}
			}
		}
		tree(dp[n][M]);
		printf("sum:%d\n",dp[n][M]);
	}
}
