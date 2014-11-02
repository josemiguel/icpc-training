#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int M,C;
int dp[205][25];
int p[25][25];
int F(int m, int id){
    if (m < 0) return -1;
    if (id == C) return M-m;
    if (dp[m][id] != -1) return dp[m][id];
    for(int i = 1; i <= p[id][0]; i++){
        dp[m][id] = max(dp[m][id], F(m - p[id][i], id+1));
    }
    return dp[m][id];
}

int main(){
   	int r;
   	scanf("%d",&r);
   	while(r--){
   		int k;
   		scanf("%d%d",&M,&C);
   		memset(dp,-1,sizeof dp);
   		memset(p,0,sizeof p);   		
   		for(int i = 0; i < C ; i++){
   			scanf("%d",&k);
   			p[i][0] = k;
   			for(int j = 1; j <= k; j++){
   				scanf("%d",&p[i][j]);
   			}
   		}
   		int res = F(M,0);
   		if (res == -1) puts("no solution");
   		else printf("%d\n",res);
   	}
	return 0;
}
