#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define MAX 100
#define max(x,y) (x) > (y) ? (x) : (y)
#define REPN(i,a,N) for(int i = a; i <= N; i++)
#define REP(i,N) REPN(i,0,N-1)
#define CLR(x) memset((x), 0, sizeof (x))
int dp[MAX+5][MAX+5];
int L[MAX+5][MAX+5];
int n,m;
bool todo;
int F(int u, int M){
	if (M <= 0 || u > n) return 0;
	if (dp[u][M] != 0) return dp[u][M];
	//for(int j = 1; j <= M; j++){
	REPN(j,1,M){
		if (L[u][j] < 5) continue;
		//cout<<L[u][j]<<endl;
		dp[u][M] = max(dp[u][M], L[u][j] + F(u+1,M-j));
	}
	if (!dp[u][M]) todo = false;
	return dp[u][M];
}

int main(){
	int r;
	scanf("%d",&r);
	while(r--){
		scanf("%d%d",&n,&m);
		REPN(i,1,n) REPN(j,1,m) scanf("%d",&L[i][j]);
/*		for(int i = 1;  i <= n ; i++)
			for(int j = 1; j <= m; j++)
				scanf("%d",&L[i][j]);*/
		CLR(dp);
		todo = true;
		int res = F(1,m);
		if (res >= 5*n && todo) printf("Maximal possible average mark - %.2lf.\n",res/(double)n+1e-9);
		else puts("Peter, you shouldn't have played billiard that much.");

	}

	return 0;
}
