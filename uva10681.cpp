#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int dp[105][205];
int E;
vector<vector<int> > g;
bool F(int u, int T){
	if (T < 0) return false;
	if (u == E && T == 0) return true;
	if (u == E) return false;
	if (dp[u][T] != -1) return dp[u][T];
	bool res = false;

	for(int i = 0; i < g[u].size(); i++){
		res |= F(g[u][i],T-1);
	}
	return dp[u][T] = res;
}

int main(){
	int C,L;
	while(scanf("%d %d",&C,&L)!=-1 && C+L){
		g = vector<vector<int> > (C);
		memset(dp,-1,sizeof dp);
		for(int i = 0; i < L; i++){
			int u,v;
			scanf("%d %d",&u,&v);
			u--,v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int S,D;
		scanf("%d %d %d",&S,&E,&D);
		S--,E--;
		if (F(S,D)){
			puts("Yes, Teobaldo can travel.");
		}else{
			puts("No, Teobaldo can not travel.");
		}
	}

	return 0;
}
